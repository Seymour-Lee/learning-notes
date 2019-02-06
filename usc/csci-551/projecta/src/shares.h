#ifndef _SHARES_H_
#define _SHARES_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

#include <signal.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netdb.h>
#include <net/if.h>
#include <linux/if_tun.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <fcntl.h>

using namespace std;

#define BUF_SIZE 128
#define MAXSIZE 2048
#define MAXPATHLENGTH 256
#define IPV4_OFFSET 20

namespace global{
    // process related
    const char* ip_address = "127.0.0.1";
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pid_t pid;
    // FILE *logfd;


    // config inf
    string config_file_name = "";
    int stage = -1;
    int num_routers = 0;

    // socket related
    // short unsigned int upd_port; // use sin.sin_port
    struct sockaddr_in sin;
    short unsigned int primary_port;

    

    sigset_t signal_set;
    // pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    // pthread_t proxy_thread, monitor_thread;

    // /* -------------- Global Variables for Proxy Only --------------- */
    // int sock;
    int tun_fd;

}

#endif