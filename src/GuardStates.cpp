#include "GuardStates.h"
#include "State.h"
#include "Guard.h"
#include "Locations.h"

#include <iostream>
using std::cout;
using std::endl;

//--------------------------------------methods for OnBase

OnBase* OnBase::Instance()
{
  static OnBase instance;

  return &instance;
}

void OnBase::Enter(Guard* pGuard)
{
  
  cout << "The guard is on the base\n";
  pGuard->TimeOnBase(0);

  //if the guard is not already located at the base, he must
  //change location to the base
  if (pGuard->Location() != base)
  {
    pGuard->ChangeLocation(base);
  }
}


void OnBase::Execute(Guard* pGuard)
{  
  //The guard is on a breakuntil the break time is reached. 
  pGuard->IncreaseTimeOnBase();
  pGuard->TimeOnDuty(0);
  cout << "The guard is having a break - " << pGuard->TimeOnBase() << endl;

  //Once the break time is up, the guard moves out to patrol the area
  if (pGuard->TimeOnBaseUp())
  {
    pGuard->ChangeLocation(patrol_area);
    pGuard->GetFSM()->ChangeState(InPatrol::Instance());
  }

}

void OnBase::Exit(Guard* pGuard)
{
  cout << "The guard leaves the base\n";
}



//----------------------------------------methods for InPatrol

InPatrol* InPatrol::Instance()
{
  static InPatrol instance;

  return &instance;
}

void InPatrol::Enter(Guard* pGuard)
{ 
  //if the guard is not already in the patrol area, he must
  //change location to the patrol area
  if (pGuard->Location() != patrol_area)
  {
    pGuard->ChangeLocation(patrol_area);
    cout << "The guard is moving to the patrol area\n";
  }
}


void InPatrol::Execute(Guard* pGuard)
{
  //patrolling the area
  pGuard->IncreaseTimeOnDuty();
  cout << "The guard is patrolling the area - " << pGuard->TimeOnDuty() << endl;
  // If an intruder is detected, the guard starts pursuing him. 
  // Else the guard returns to the base when his duty time is up
  if (pGuard->Intrusion())
  {
    cout << "The guard detects an intruder \n";
    pGuard->GetFSM()->ChangeState(InPursuit::Instance()); 
  }
  else if (pGuard->TimeOnDutyUp())
  {
    cout << "The guard is going for a break\n";
    pGuard->ChangeLocation(base);
    pGuard->GetFSM()->ChangeState(OnBase::Instance()); 
  }

}

void InPatrol::Exit(Guard* pGuard)
{
  if (pGuard->Location() != patrol_area){
    cout << "The guard leaves the patrol area\n";
  }
}


//----------------------------------------methods for InPursuit

InPursuit* InPursuit::Instance()
{
  static InPursuit instance;

  return &instance;
}

void InPursuit::Enter(Guard* pGuard)
{
    
}

void InPursuit::Execute(Guard* pGuard)
{ 
  cout << "The guard is chasing the intruder\n";

  if (pGuard->UnderFire())
  { 
    cout << "The intruder is shooting at the guard\n";
    pGuard->GetFSM()->ChangeState( ShootBack::Instance());
  }
  else 
  {
    cout << "The intruder has left the patrol area\n";
    cout << "The guard returns to patroling the area\n";
    pGuard->GetFSM()->ChangeState(InPatrol::Instance());
  } 
}

void InPursuit::Exit(Guard* pGuard)
{ 
  cout << "The guard stops chasing the intruder\n";
}



//------------------------------------------------methods for ShootBack

ShootBack* ShootBack::Instance()
{
  static ShootBack instance;

  return &instance;
}

void ShootBack::Enter(Guard* pGuard)
{
  if (pGuard->Location() != cover)
  {    
    pGuard->ChangeLocation(cover);
    cout << "The guard looks for a cover\n";
  }
}

void ShootBack::Execute(Guard* pGuard)
{
  cout << "The guard has found a cover and is shooting back at the intruder\n";

  if (pGuard->UnderFire())
  { 
    cout << "The intruder continues attacking the guard\n";
    cout << "The guard decides to retreat to the base\n";
    pGuard->ChangeLocation(base);
    pGuard->GetFSM()->ChangeState( OnBase::Instance());
  }
  else 
  {
    cout << "The guard continues pursuing an intruder\n";
    pGuard->GetFSM()->ChangeState(InPursuit::Instance());
  }

}


void ShootBack::Exit(Guard* pGuard)
{ 
  cout << "The guard stops shooting and leaves the cover\n";
}

