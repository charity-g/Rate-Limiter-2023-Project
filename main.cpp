#include <iostream> //input and output stream
#include <unistd.h> //string
#include <ctime> //time
#include <fstream> //filestream
#include <thread> //threading
#include <vector>

#include "request.h"
#include "rateLimiter.h"

using namespace std;

// The function we want to execute on the new thread.
void task1(rateLimiter* rL, string msg)
{
   request a(msg);
   time_t recorded_time = a.getCreationTime();
   rL->sendRequestToServer(a);
   cout << "task " << msg << ":  request sent";
}


//PURPOSE: to initialize server, rateLimiter, as well as all user requests and output log
int main() {
   vector<thread> threads = vector<thread>(); 
   bool x = true;
   string introduction = "Welcome to the Rate Limiter Simulator (c) 2023 charity-g\nPlease enter an INTEGER for the number of requests you would like to make (max 1000 for now)\nTo exit, please type \'!exit\'.";
   string user_input = "";
   rateLimiter * rLsolution = new rateLimiter();
   // // time_t recorded_time;
   // struct tm * timeinfo;
   cout << introduction << endl;
   while (x) {

      cin >> user_input;
      // cout << time(&recorded_time) << " seconds has passed since 00:00 GMT, Jan 1, 1970" << endl;
      // timeinfo = localtime(&recorded_time);
      // cout << asctime(timeinfo) << endl;
      if (user_input == "!exit") {
         x = false;
      } else {
         try {
            int n = stoi(user_input);
            for (int i = 0; i < n; i++) {
               threads.push_back(thread(task1, rLsolution, to_string(i)));
               x = false;
            }
         }
         catch (exception e) {
            cout << "User input was not an integer." << endl;
         } 
      }
   }

   for (unsigned int i = 0; i < threads.size(); i++) {
      // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
      threads[i].join();
      cout << "thread " << i << "joined" << endl;
   }
   
   delete rLsolution;
   return 1;
}