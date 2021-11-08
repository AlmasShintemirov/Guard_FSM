#include "Locations.h"
#include "Guard.h"
#include <thread>


int main()
{
  //create a guard
  Guard guard;

  //run guard through a few Update calls
  for (int i=0; i<20; ++i)
  { 
    guard.Update();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  //wait for a keypress before exiting
  system("read");

  return 0;
}






