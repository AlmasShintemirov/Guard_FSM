#include "Locations.h"
#include "Guard.h"
#include <thread>
#include <iostream>

using namespace std;

int main()
{
  //create a guard
  Guard guard;
  
  //run guard FSM through a few Update calls
  for (int i = 0; i < 30; ++i)
  { 
    guard.Update();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  //wait for a keypress before exiting
  cout << "\n" << "Press any key to stop the program ...\n";
  cin.get();

  return 0;
}






