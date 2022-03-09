#ifndef USR_FCT_H
#define USR_FCT_H

#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

using namespace std;

extern void USR_FCT__GetRandomWords(vector<string>* words_vector);
extern void USR_FCT__ShuffleWords(vector<string>* words_vector);
extern void USR_FCT__DisplayAllWords(vector<string>* words_vector);

//extern void USR_FCT__RunServer();
extern int USR_FCT__RunClient();

#endif