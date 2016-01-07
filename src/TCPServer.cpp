/****************************************
* Yossi Silberhaft & Nava Shemoul		*
* Exercise 6							*
* File: TCPServer.cpp					*
****************************************/
#include <fstream>
#include "TCPServer.h"

int TCPServer::server_socket;
int TCPServer::t_client_sock;

/************************************************************************
 * This is the TCPServer Class constructor		        				*
 ************************************************************************/
TCPServer::TCPServer(int port) {
    newSocket();
    bindTCP(port);
    listenTCP(2);
    acceptTCP();
}


/************************************************************************
 * This is the TCPServer Class destructor                               *
 ************************************************************************/
TCPServer::~TCPServer() { }


/************************************************************************
 * This function will create a new socket		        				*
 ************************************************************************/
void TCPServer::newSocket() {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("error creating socket\n");
    }
}


/************************************************************************
 * This function will bind to all the IP Address of the host            *
 ************************************************************************/
void TCPServer::bindTCP(unsigned int server_port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    //binds to all ip address of the host
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(server_port);

    //Binds a socket to a port number
    if (bind(server_socket, (struct sockaddr *) &server, sizeof(server)) < 0){
        perror("error binding socket\n");
        //Exit the program if there is an error binding
        exit(1);
    }
}


/************************************************************************
 * This function will wait for incoming transmissions                   *
 ************************************************************************/
void TCPServer::listenTCP(int back_log) {
    //The Host waits for incoming transmission
    if (listen(server_socket, back_log) < 0) {
        perror("error listening to socket\n");
    }
}


/************************************************************************
 * This function returns a dedicated socket descriptor to               *
 * communicate with the client                                          *
 ************************************************************************/
void TCPServer::acceptTCP() {
    while (true) {
        struct sockaddr_in client;
        unsigned int addr_len = sizeof(client);
        t_client_sock = accept(server_socket, (struct sockaddr *) &client,
                               &addr_len);

        if (t_client_sock < 0) {
            perror("error accepting client\n");
        }
        pthread_t thread_id;
        int thread_status = pthread_create(&thread_id, NULL, connectionHandler,
                                           (void *) &t_client_sock);

        if (thread_status != 0) {
            perror("error creating thread\n");
        }
    }
}


/************************************************************************
* This function receives data from the client and returns it            *
* as a string to the main program                                       *
************************************************************************/
void *TCPServer::connectionHandler(void *sock_desc) {
    bool inUse = false;
    int read_size;
    char client_message[BUFFER_SIZE];
    int clientSock = *(int *) sock_desc;
    pthread_mutex_t lock;
    static Cinema *cinema = NULL;
    Inputs *myInputs = new Inputs();
    // lock initialization
    if (pthread_mutex_init(&lock, NULL) != 0) {
        cout << "error creating lock" << endl;
    }
    //This will check if this is the first time that cinema has been created
    if (cinema == NULL) {
        if (checkFile()) {
            if (!inUse) {
                // lock
                pthread_mutex_lock(&lock);
                if (!inUse) {
                    cinema = Cinema::getInstance();
                    restoreServer(cinema);
                    inUse = true;
                }
                //Release lock
                pthread_mutex_unlock(&lock);
            }
        }
    }

    while (true) {
        if (!inUse) {
            // lock
            pthread_mutex_lock(&lock);
            if (!inUse) {
                cinema = Cinema::getInstance();
                inUse = true;
            }
            // release lock
            pthread_mutex_unlock(&lock);
        }
        read_size = recv(clientSock, client_message, BUFFER_SIZE, 0);
        //If one of the clients enter in -1, then we will just break the
        // while loop and carry on with the running of the server
        if(client_message[0] == '-' && client_message[1] == '1'){
            break;
        }

        //Set end of string marker
        client_message[read_size] = '\0';

        //Convert the message to string
        string str(client_message);

        //Convects the input string from the client to a string vector
        vector<string> usrInput = myInputs->getInputVector(str);

        //Sends the vector to the main server function
        string result = cinema->runCinema(usrInput);

        //If the function returned Success
        //Then open this backup file and add in the input line
        if (result == "Success") {
            writeToFile(str);
        }
        //result.append("\n");
        char *res = new char[BUFFER_SIZE];
        res[result.size()] = 0;
        memcpy(res, result.c_str(), result.size());

        //Send the message back to client
        write(clientSock, res, result.size() + 1);

        //clear the message buffer
        memset(client_message, 0, 2000);
    }
}


/************************************************************************
* This function will restore the contents of the the server             *
* from the backup text file                                             *
************************************************************************/
void TCPServer::restoreServer(void *ptrCinema) {
    //Deceleration of variables
    bool inUse = false;
    Cinema *cinema = (Cinema *) ptrCinema;
    Inputs *myInputs = new Inputs();
    pthread_mutex_t lock;
    ifstream file;
    string line;

    //Initialize the mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        cout << "error creating lock" << endl;
    }

    //Opens the file and will read line by line and upload restore
    //the Server
    file.open("backup.txt");
    while (getline(file, line)) {
        if (!inUse) {
            // lock
            pthread_mutex_lock(&lock);
            if (!inUse) {
                cinema = Cinema::getInstance();
                inUse = true;
            }
            //Release lock
            pthread_mutex_unlock(&lock);
        }
        vector<string> vecFromFile = myInputs->getInputVector(line);
        cinema->runCinema(vecFromFile);
    }
}


/************************************************************************
* This function receives data from the client and returns it            *
 * as a string to the main program                                      *
************************************************************************/
string TCPServer::receiveTCP() {
    char buffer[BUFFER_SIZE];
    int read_bytes = recv(t_client_sock, buffer, BUFFER_SIZE, 0);

    if (read_bytes <= 0) {
        cout << "Error reading bytes" << endl;
    }
    else {
        buffer[read_bytes] = '\0';
        string str(buffer);
        //This will clear the buffer in order to receive the next input
        memset(&buffer, 0, sizeof(BUFFER_SIZE));
        return str;
    }
}


/************************************************************************
* This function sends data using the TCP server                         *
************************************************************************/
void TCPServer::sendTCP(char *data, unsigned int data_len, int clientSocket) {
    int sent_bytes = send(clientSocket, data, data_len, 0);
    if (sent_bytes < 0) {
        perror("error sending to client\n");
    }
}


/************************************************************************
* This function will write the received string to the backup file        *
************************************************************************/
void TCPServer::writeToFile(string str) {
    ofstream backFile;
    backFile.open("backup.txt", ios::app);
    backFile << str;
    backFile.close();
}


/************************************************************************
* This function will check if the backup file exists, if it does        *
 * then it will return TRUE, else it will create the text file and      *
 * return true                                                          *
************************************************************************/
bool TCPServer::checkFile() {
    if (ifstream("backup.txt")) {
        return true;
    }
    else {
        ofstream myFile("backup.txt");
        myFile.close();
        return false;
    }
}
