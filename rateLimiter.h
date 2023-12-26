#ifndef _RATELIMITER_H_
#define _RATELIMITER_H_

#include <cmath>
#include <utility>
#include <ctime>
#include <iostream>
#include <mutex>
#include <unistd.h> 
#include <random>

#include "request.h"
#include "server.h"

#define LIMIT 5 

//PURPOSE: TODO: eventual abstract/interface for the different rateLimiter implementations 
//currently: leaky bucket implementation that connects caller to server
class rateLimiter {

public:
   //constructor:
   rateLimiter();

   //returns true if sent to server; false if denied
   bool sendRequestToServer(request r);
   
   
   //request recieveResponse(request r); //TODO !!! 25Dec23 CG

private:
   int queueRemainder = LIMIT; //MUST BE LOCKED BY MUTEX BEFORE READING/WRITING
   std::mutex * mtx;
   
   //server
   //log

};

#endif