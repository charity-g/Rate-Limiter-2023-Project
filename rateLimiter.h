#ifndef _RATELIMITER_H_
#define _RATELIMITER_H_

#include <cmath>
#include <utility>
#include <ctime>
#include <iostream>

#include "request.h"


//PURPOSE: TODO: eventual abstract/interface for the different rateLimiter implementations 
class rateLimiter {

public:
   //constructor:
   rateLimiter();

   //returns true if sent to server; false if denied
   bool sendRequestToServer(request r);
   
   
   //request recieveResponse(request r); //TODO !!! 25Dec23 CG

private:
   int queueRemainder = 5;
   //server
   //log

};

#endif