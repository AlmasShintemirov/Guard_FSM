#ifndef GUARD_STATES_H
#define GUARD_STATES_H
//------------------------------------------------------------------------
//
//  Name:   GuardStates.h
//
//  Desc:   All the states that can be assigned to the Guard class
//
//  Created by Almas Shintemirov 2021 (https://www.alaris.kz) based on the code template 
//  by Mat Buckland 2002 (https://www.amazon.com/-/es/Mat-Buckland/dp/1556220782)
//
//------------------------------------------------------------------------
#include "State.h"


class Guard;

//------------------------------------------------------------------------
//
//  In this state the guard stays at a base for having a break. 
//  When a fixed break time is up the guard moves out to the patrol area (change to state InPatrol). 
//
//------------------------------------------------------------------------
class OnBase : public State<Guard>
{
private:
  
  OnBase(){}
  
  //copy ctor and assignment should be private
  OnBase(const OnBase&);
  OnBase& operator=(const OnBase&);
 
public:

  static OnBase* Instance();
  
public:
  
  virtual void Enter(Guard* pGuard);

  virtual void Execute(Guard* pGuard);

  virtual void Exit(Guard* pGuard);

};

//------------------------------------------------------------------------
//
//  In this state the guard patrols the area for a certain on duty period. 
//  When the time is up, the guard returns to the base for a break (change to state OnBase). 
//  If an intruder is detected, the guard start pursuing him (change to state InPursuit) 
//
//------------------------------------------------------------------------
class InPatrol : public State<Guard>
{
private:
  
  InPatrol(){}

  //copy ctor and assignment should be private
  InPatrol(const InPatrol&);
  InPatrol& operator=(const InPatrol&);
 
public:

  static InPatrol* Instance();

  virtual void Enter(Guard* pGuard);

  virtual void Execute(Guard* pGuard);

  virtual void Exit(Guard* pGuard);

};


//------------------------------------------------------------------------
//
//  The guard chases an intruder.  If intruder fired at the guard, the guard finds cover and shoots back (change to state ShootBack)
//  If an intruder left the area, the guard return to patrolling the territory (change to state InPatrol)
//  
//------------------------------------------------------------------------
class InPursuit : public State<Guard>
{
private:
  
  InPursuit(){}

  //copy ctor and assignment should be private
  InPursuit(const InPursuit&);
  InPursuit& operator=(const  InPursuit&);
 
public:

  static InPursuit* Instance();

  virtual void Enter(Guard* pGuard);

  virtual void Execute(Guard* pGuard);

  virtual void Exit(Guard* pGuard);

};


//------------------------------------------------------------------------
//  
//  The guard find cover and shoots back at an intruder. 
//  If an intruder continues attacking the guard, the guard retreats to the base (change to state OnBase).
//  Otherwise, the guard continues pursuing an intruder (change to state InPursuit) 
//  
//------------------------------------------------------------------------
class ShootBack : public State<Guard>
{
private:
  
  ShootBack(){}

  //copy ctor and assignment should be private
  ShootBack(const ShootBack&);
  ShootBack& operator=(const ShootBack&);
 
public:

  static ShootBack* Instance();

  virtual void Enter(Guard* pGuard);

  virtual void Execute(Guard* pGuard);

  virtual void Exit(Guard* pGuard);

};



#endif