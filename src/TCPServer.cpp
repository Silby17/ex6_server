/****************************************
* Yossi Silberhaft & Nava Shemoul		*
* Exercise 5							*
* File: TCPServer.cpp					*
****************************************/
#include "TCPServer.h"
#include "Cinema.h"

int TCPServer::server_socket;
int TCPServer::t_client_sock;
//Cinema* TCPServer::cinema;

/************************************************************************
 * This is the TCPServer Class constructor		        				*
 ************************************************************************/
TCPServer::TCPServer(int port){
  //  inUse = false;
    newSocket();
    bindTCP(port);
    listenTCP(2);
    acceptTCP();
}


/************************************************************************
 * This is the TCPServer Class destructor                               *
 ************************************************************************/
TCPServer::~TCPServer(){ }


/************************************************************************
 * This function will create a new socket		        				*
 ************************************************************************/
void TCPServer::newSocket() {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket  < 0){
        perror("error creating socket\n");
    }
}


/************************************************************************
 * This function will bind to all the IP Address of the host            *
 ************************************************************************/
void TCPServer::bindTCP(unsigned int server_port){
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    //binds to all ip address of the host
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(server_port);

    //Binds a socket to a port number
    if (bind(server_socket, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("error binding socket\n");
        //Exit the program if there is an error binding
        exit(1);
    }
}


/************************************************************************
 * This function will wait for incoming transmissions                   *
 ************************************************************************/
void TCPServer::listenTCP(int back_log){
    //The Host waits for incoming transmission
    if (listen(server_socket, back_log) < 0) {
        perror("error listening to socket\n");
    }
}


/************************************************************************
 * This function returns a dedicated socket descriptor to               *
 * communicate with the client                                          *
 ************************************************************************/
void TCPServer::acceptTCP(){
    while(true) {
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
void* TCPServer::connectionHandler(void *sock_desc) {
    static Cinema* cinema = NULL;
    bool inUse = false;
    int read_size;
    char client_message[BUFFER_SIZE];
    int clientSock = *(int*)sock_desc;
    Inputs* myInputs = new Inputs();
    pthread_mutex_t lock;

    // lock initialization
    if (pthread_mutex_init(&lock, NULL) != 0) {
        // error
    }

    while(true){
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
        read_size = recv(clientSock , client_message , BUFFER_SIZE , 0);

        //Set end of string marker
        client_message[read_size] = '\0';

        //Convert the message to string
        string str(client_message);
        //Convects the input string from the client to a string vector
        vector<string> usrInput = myInputs->getInputVector(str);
        //Sends the vector to the main server funciton
        string result = cinema->runCinema(usrInput);

        char* res = new char[BUFFER_SIZE];
        res[result.size()] = 0;
        memcpy(res, result.c_str(), result.size());

        //Send the message back to client
        write(clientSock , res , result.size()+ 1);

        //clear the message buffer
        memset(client_message, 0, 2000);
    }
}


/************************************************************************
* This function receives data from the client and returns it            *
 * as a string to the main program                                      *
************************************************************************/
string TCPServer::receiveTCP() {
    char buffer[BUFFER_SIZE];
    int read_bytes = recv(t_client_sock, buffer, BUFFER_SIZE, 0);

    if(read_bytes <= 0){
        cout << "Error reading bytes" << endl;
    }
    else{
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
    if(sent_bytes < 0){
        perror("error sending to client\n");
    }

}