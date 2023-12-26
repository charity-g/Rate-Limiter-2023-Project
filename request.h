#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <cmath>
#include <utility>
#include <ctime>

using namespace std;

//PURPOSE: a request made by a user
class request {
public:
   //constructor: sets creation time and request information
   request();
   time_t getCreationTime();
    
private:
   time_t CreationTime;
   time_t SentToServerTime; //wrong thing to put here
   time_t ProcessedTime; //wrong thing to put here

};

#endif