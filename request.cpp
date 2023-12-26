#include "request.h"

request::request() {
   CreationTime = time(NULL);
}

request::request(string m) {
   msg = m;
   CreationTime = time(NULL);
}


time_t request::getCreationTime() {
   return CreationTime;
}


string request::getRequestMsg() {
   return msg;
}