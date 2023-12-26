#ifndef _SERVER_H_
#define _SERVER_H_

#include <cmath>
#include <utility>
#include "request.h"

using namespace std;

//PURPOSE: to process user requests and track how many requests it has left
class server {

public:
     /**
     * Constructor for a server.
     * @see server.cpp
     *
     */
     server();


     /**
     * Purpose: returns the request at random time intervals
     * Must modify requests during processing and after processing complete
     * @see server.cpp
     *
     * @param r is the user request being processed
     */
     bool processRequest(request r);
    
private:
     std::uniform_int_distribution<int> uni(min,max)


};

#endif