#include <iostream>
#include <GuardedQueue.hpp>
#include <thread>
#include <chrono>

using namespace DataModel;
using namespace std;

int main(){
  GuardedQueue resource{}; 
  string userInput{"Asmir"};
  
  [&]{ cout << "Lamda budalica called now!"; }();

  thread t1([&resource](){
        while(true){
          resource.readFromQueue();  
        }
      });
 
  while (true) {
    cout << "Inser message name: " << endl;
    getline(cin, userInput);
    resource.writeToQueue(userInput);  
  }
  
  if(t1.joinable()) t1.join();
}
