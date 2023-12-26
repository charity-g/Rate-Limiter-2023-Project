#ifndef _RATELIMITER_H_
#define _RATELIMITER_H_

#include <cmath>
#include <utility>
#include <ctime>
#include <iostream>
#include <mutex>
#include <random>

#include "request.h"
#include "server.h"

#define LIMIT 5 

//PURPOSE: to limit amount of requests sent to server to ensure server is not overloaded
//TODO: 25Dec23 eventual abstract/interface for the different rateLimiter implementations 
//currently: leaky bucket implementation that connects caller to server
class rateLimiter {

public:
   //constructor:
   rateLimiter();

   //returns true if sent to server; false if denied
   bool sendRequestToServer(request r);
   
   //brings queue back up to LIMIT
   void recieveResponseFromServer();

private:
   int queueRemainder = LIMIT; //MUST BE LOCKED BY MUTEX BEFORE READING/WRITING
   std::mutex * mtx;
   
   //server
   server * svr;

   //log //TODO 25Dec23 CG

};

#endif