#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <cmath>
#include <string>
#include <ctime>

using namespace std;

//PURPOSE: a request made by a user; responsible for storing information by user and logging
class request {
public:
   //constructor: sets creation time and request information
   request();
   request(string m);
   time_t getCreationTime();
   string getRequestMsg();
    
private:
   time_t CreationTime;
   time_t SentToServerTime;
   time_t ServerTimeRecievedTime;
   time_t ProcessedTime;
   string msg;

};

#endif