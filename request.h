#ifndef _REQUEST_H_
#define _REQUEST_H_

#include <cmath>
#include <utility>
#include <ctime>

using namespace std;

//PURPOSE: a request made by a user
class request {
public:
   time_t getCreationTime();
    
private:
   time_t CreationTime;
   time_t SentToServerTime;
   time_t ProcessedTime;

};

#endif