#include "request.h"

request::request() {
   CreationTime = time(0);
}

time_t request::getCreationTime() {
   return CreationTime;
}