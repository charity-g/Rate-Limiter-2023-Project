#ifndef _SERVER_H_
#define _SERVER_H_

#include <cmath>
#include <utility>
#include <unistd.h> //sleep
#include <stdlib.h> //random

#include "request.h"
#include "rateLimiter.h"

class rateLimiter;

//PURPOSE: to process user requests
class server {

public:
     /**
     * Constructor for a server.
     * @see server.cpp
     *
     */
     server();

     /**
     * Purpose: processes the request asyncronously
     * Must modify requests during processing and after processing complete //TODO !!! 25Dec23 CG
     * @see server.cpp
     *
     * @param r is the user request being processed
     * @param rL is the rateLimiter who initiated request approval
     */
     bool processRequest(request r, rateLimiter* rL);
    
// private:

};

#endif