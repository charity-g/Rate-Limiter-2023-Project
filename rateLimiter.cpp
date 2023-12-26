#include "rateLimiter.h"

using namespace std;

rateLimiter::rateLimiter() {
   mtx = new mutex();
   svr = new server();
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
      svr->processRequest(r, this);
      result = true;
   }
   mtx->unlock();
   return result;
}

//increase queueRemainder because server can process more
void rateLimiter::recieveResponseFromServer() {
   mtx->lock();
   if (queueRemainder < LIMIT) {
      queueRemainder++;
   }
   mtx->unlock();

}