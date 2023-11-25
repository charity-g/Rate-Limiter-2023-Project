#include "request.h"

request::request() {
   CreationTime = time(NULL);
}

time_t request::getCreationTime() {
   return CreationTime;
}