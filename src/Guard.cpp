#include "Guard.h"
#include <random>

//-----------------------------------------------------------------------------
void Guard::Update()
{
  //SetTextColor(FOREGROUND_RED| FOREGROUND_INTENSITY);

  //m_iThirst += 1;
  
  pStateMachine->Update();
}

bool Guard::Intrusion()
{
  float prob = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  if (prob < 0.5)
    IntruderDetected = true;
  else 
    IntruderDetected = false;

  return IntruderDetected;
}

bool Guard::UnderFire()
{
  float prob = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  if (prob < 0.5)
    IntruderFired = true;
  else 
    IntruderFired = false;

  return IntruderFired;
}
