#include <iostream> //input and output stream
#include <unistd.h>
#include <ctime> //time
#include <fstream> //filestream
#include <thread> //threading
#include <vector>

#include "request.h"

using namespace std;

// The function we want to execute on the new thread.
void task1(string msg)
{
   request a;
   time_t recorded_time = a.getCreationTime();
   cout << "task says: " << msg << " and created request at " << asctime(localtime(&recorded_time)) << endl;
}

int main() {
   vector<thread> threads = vector<thread>(); 
   bool x = true;
   string introduction = "Welcome to the Rate Limiter Simulator (c) 2023 Charity Grey\nTo exit, please type \'!exit\'.";
   string user_input = "";
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
               thread t1(task1, i);
               threads.push_back(t1);
            }
         }
         catch (exception e) {
            
         } 
      }
   }

   for (int i = 0; i < threads.size(); i++) {
      threads[i].join();
      cout << "thread " << i << "joined" << endl;
   }
   // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
   return 1;
}