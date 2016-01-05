/****************************************
* Yossi Silberhaft & Nava Shemoul		*
* Exercise 5							*
* File: TCPServer.h 					*
****************************************/
#ifndef EXERCISE_4_TCPSERVER_H
#define EXERCISE_4_TCPSERVER_H

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include "Cinema.h"
#include "Inputs.h"
#define BUFFER_SIZE 4096
using namespace std;

class TCPServer{

private:
    static int server_socket;
    static int t_client_sock;
    static void *connectionHandler(void *sock_desc);

public:

    /************************************************************************
	 * This is the TCPServer Class constructor		        				*
	 ************************************************************************/
    TCPServer(int port);


    /************************************************************************
	 * This function will create a new socket                               *
	 ************************************************************************/
    void newSocket();


    /************************************************************************
	 * This is the TCPServer Class destructor                               *
	 ************************************************************************/
    virtual ~TCPServer();


    /************************************************************************
	 * This function will bind to all the IP Address of the host            *
	 ************************************************************************/
    void bindTCP(unsigned int server_port);


    /************************************************************************
	 * This function will wait for incoming transmissions                   *
	 ************************************************************************/
    void listenTCP(int back_log);


    /************************************************************************
	 * This function returns a dedicated socket descriptor to               *
     * communicate with the client                                          *
	 ************************************************************************/
    void acceptTCP();


    /************************************************************************
	 * This function will send to the TCP Server                            *
	 ************************************************************************/
    static void sendTCP(char* data, unsigned int data_len, int clientSocket);


    /************************************************************************
	 * This will receive the info from the TCP Server                       *
	 ************************************************************************/
    static std::string receiveTCP();

};

#endif