
#include <ctime> //time
#include <iostream> //input and output stream
#include <unistd.h>
#include <fstream> //filestream
#include <thread> //threading
#include <vector>
#include "request.h"

using namespace std;

void task1(string msg)
{
   request a;
   time_t recorded_time = a.getCreationTime();
   cout << "task says: " << msg << " and created request at " << asctime(localtime(&recorded_time)) << endl;
}

int main() {
   thread t1(task1, "hi"); 
   t1.join();
}