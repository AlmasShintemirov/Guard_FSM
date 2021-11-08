#include "GuardStates.h"
#include "State.h"
#include "Guard.h"
#include "Locations.h"

#include <iostream>
using std::cout;


//--------------------------------------methods for OnBase

OnBase* OnBase::Instance()
{
  static OnBase instance;

  return &instance;
}

void OnBase::Enter(Guard* pGuard)
{
  //if the miner is not already located at the goldmine, he must
  //change location to the gold mine
  cout << "The guard is on the base\n";
  pGuard->SetTimeOnBase(0);
  if (pGuard->Location() != base)
  {
    pGuard->ChangeLocation(base);
  }
}


void OnBase::Execute(Guard* pGuard)
{  
  //if the miner is at the goldmine he digs for gold until he
  //is carrying in excess of MaxNuggets. If he gets thirsty during
  //his digging he packs up work for a while and changes state to
  //gp to the saloon for a whiskey.
  cout << "The guard is having a break \n";
  pGuard->IncreaseTimeOnBase();
  pGuard->SetTimeOnDuty(0);

  //if enough gold mined, go and put it in the bank
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
  if (pGuard->Location() != patrol_area)
  {
    pGuard->ChangeLocation(patrol_area);
    cout << "The guard is moving to a patrol area\n";
  }
}


void InPatrol::Execute(Guard* pGuard)
{
  //patrolling the area
  cout << "The guard is patrolling the area\n";
  pGuard->IncreaseTimeOnDuty();

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
    cout << "The guard finds cover\n";
  }
}

void ShootBack::Execute(Guard* pGuard)
{
  cout << "The guard found cover and is shooting back at the intruder\n";

  if (pGuard->UnderFire())
  { 
    cout << "The intruder continues attacking the guard\n";
    cout << "The guard decides to retreat to the base\n";
    pGuard->ChangeLocation(base);
    pGuard->GetFSM()->ChangeState( OnBase::Instance());
  }
  else 
  {
    cout << "The intruder has left the patrol area\n";
    pGuard->GetFSM()->ChangeState(InPatrol::Instance());
  }

}


void ShootBack::Exit(Guard* pGuard)
{ 
  cout << "The guard stops shoting and leaves the cover\n";
}

