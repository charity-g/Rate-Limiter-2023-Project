#include <iostream> //input and output stream
#include <unistd.h>
#include <ctime> //time
#include <fstream> //filestream

using namespace std;

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
   return 1;
}