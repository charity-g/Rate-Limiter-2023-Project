#include "rateLimiter.h"

using namespace std;

rateLimiter::rateLimiter() {
   cout << "ratelimiter created." << endl;
}

//returns true if sent to server; false if denied
bool rateLimiter::sendRequestToServer(request r) {
   if (queueRemainder <= 0) {
      return false;
   } else {
      queueRemainder--;
      return true;
   }
}