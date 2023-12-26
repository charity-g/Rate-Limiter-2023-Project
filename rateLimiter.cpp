#include "rateLimiter.h"

using namespace std;

rateLimiter::rateLimiter() {
   mtx = new mutex();
   cout << "ratelimiter created." << endl;
}

//returns true if sent to server; false if denied
bool rateLimiter::sendRequestToServer(request r) {
   bool result;
   mtx->lock();
   if (queueRemainder <= 0) {
      result = false;
   } else {
      queueRemainder--;
      sleep(2);//processing + call server here
      result = true;
   }
   mtx->unlock();
   return result;
}