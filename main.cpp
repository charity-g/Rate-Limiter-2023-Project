#include <iostream>

using namespace std;

int main() {
   bool x = true;
   string introduction = "Welcome to the Rate Limiter Simulator (c) 2023 Charity Grey\nTo exit, please type \'!exit\'.";
   string user_input = "";
   cout << introduction << endl;
   while (x) {
      cin >> user_input;
      if (user_input == "!exit") {
         x = false;
      }
   }
   return 1;
}