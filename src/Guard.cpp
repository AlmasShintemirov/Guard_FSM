#include "Guard.h"
#include <random>

//-----------------------------------------------------------------------------
void Guard::Update()
{
  pStateMachine->Update();
}

// The function defines the presence of an intruder in the patrol area with 50% probability 
bool Guard::Intrusion()
{
  float prob = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  if (prob < 0.5)
    IntruderDetected = true;
  else 
    IntruderDetected = false;

  return IntruderDetected;
}


// The function defines if an intruder fires at the guard with 50% probability 
bool Guard::UnderFire()
{
  float prob = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  if (prob < 0.5)
    IntruderFired = true;
  else 
    IntruderFired = false;

  return IntruderFired;
}
