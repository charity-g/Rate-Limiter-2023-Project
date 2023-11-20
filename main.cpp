#include <iostream> //input and output stream
#include <unistd.h>
#include <ctime> //time
#include <fstream> //filestream
#include <thread> //threading

using namespace std;

// The function we want to execute on the new thread.
void task1(string msg)
{
    cout << "task1 says: " << msg;
}

int main() {
   bool x = true;
   string introduction = "Welcome to the Rate Limiter Simulator (c) 2023 Charity Grey\nTo exit, please type \'!exit\'.";
   string user_input = "";
   time_t recorded_time;
   struct tm * timeinfo;
   cout << introduction << endl;
   while (x) {
      cin >> user_input;
      cout << time(&recorded_time) << " seconds has passed since 00:00 GMT, Jan 1, 1970" << endl;
      timeinfo = localtime(&recorded_time);
      cout << asctime(timeinfo) << endl;
      if (user_input == "!exit") {
         x = false;
      }
   }

   // Constructs the new thread and runs it. Does not block execution.
   thread t1(task1, "Hello");

   // Do other things...

   // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
   t1.join();
   return 1;
}