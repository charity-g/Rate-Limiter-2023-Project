#ifndef _SLIDINGWINDOW_H_
#define _SLIDINGWINDOW_H_

#include <cmath>
#include <utility>
#include "server.h"

using namespace std;

//PURPOSE: act as a slidingWindow rateLimiter implementation 
class slidingWindow {
    //This solution will record the number of requests at the time of reception.
    //It will only take in n requests per x time interval.
    //How the application should limit the requests should be through look back at the amount of requests in the last x time interval and determining how many more requests it can take (how many compared to n). 
public:

    slidingWindow();
    slidingWindow(vector<server> vs);
    slidingWindow(server s);

    /**
     * Purpose: to determine if the server 
     * @see slidingWindow.cpp
     *
     * @param r The request .
     */
    string processRequest(request r);
private:
    //I want a data structure 
    vector<server> servers;

};

#endif