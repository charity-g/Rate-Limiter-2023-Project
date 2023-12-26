#include "server.h"
#include "rateLimiter.h" // with forward dec in server.h

using namespace std;

server::server() {

}

//process and send request back
bool server::processRequest(request r, rateLimiter* rL) {
   sleep(rand() % 4);
   //send response back
   cout << "task " << r.getRequestMsg() << ": response recieved";
   rL->recieveResponseFromServer();
   return true;
}