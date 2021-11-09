#ifndef MINER_H
#define MINER_H
//------------------------------------------------------------------------
//
//  Name:   Guard.h
//
//  Desc:   A class defining a guard.
//
//  Created by Almas Shintemirov 2021 (https://www.alaris.kz) based on the code template 
//  by Mat Buckland 2002 (https://www.amazon.com/-/es/Mat-Buckland/dp/1556220782)
//
//------------------------------------------------------------------------

#include <string>
#include <cassert>
#include "Locations.h"
#include "GuardStates.h"
#include "StateMachine.h"

//class State;

class Guard
{
private:

  //an instance of the state machine class
  StateMachine<Guard>*  pStateMachine;
  
  location_type         location;

  //time on duty in patrol
  int                   timeOnDuty;
  int                   timeOnBase;
  int                   maxTimeOnBase;
  int                   maxTimeOnDuty; 
  bool                  IntruderDetected;
  bool                  IntruderFired;


public:

  Guard() : location(base), 
            timeOnBase(0),
            maxTimeOnBase(3),
            timeOnDuty(0), 
            maxTimeOnDuty(8),
            IntruderDetected(false),
            IntruderFired(false)
  {
    pStateMachine = new StateMachine<Guard>(this);
    
    pStateMachine->SetCurrentState(OnBase::Instance()); 
  }

  ~Guard(){delete pStateMachine;}

  //this must be implemented
  void Update();

  StateMachine<Guard>*  GetFSM()const{return pStateMachine;}

  location_type Location()const{return location;}
  void          ChangeLocation(const location_type loc){location=loc;}
  
  int           TimeOnBase()const{return timeOnBase;}
  void          TimeOnBase(const int val){timeOnBase = val;}
  void          IncreaseTimeOnBase(){timeOnBase += 1;}
  bool          TimeOnBaseUp()const{return timeOnBase >= maxTimeOnBase;}

  int           TimeOnDuty()const{return timeOnDuty;}
  void          TimeOnDuty(const int val){timeOnDuty = val;}
  void          IncreaseTimeOnDuty(){timeOnDuty += 1;}
  bool          TimeOnDutyUp()const{return timeOnDuty >= maxTimeOnDuty;}

  bool          Intrusion();
  bool          UnderFire();
  
};

#endif
