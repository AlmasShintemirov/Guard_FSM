#ifndef GUARD_STATES_H
#define GUARD_STATES_H
//------------------------------------------------------------------------
//
//  Name:   GuardStates.h
//
//  Desc:   All the states that can be assigned to the Guard class
//
//  Originally created by Mat Buckland 2002 (https://www.amazon.com/-/es/Mat-Buckland/dp/1556220782)
//
//  Modified by Almas Shintemirov 2021 (https://www.alaris.kz)
//
//------------------------------------------------------------------------
#include "State.h"


class Guard;

//------------------------------------------------------------------------
//
//  In this state the miner will walk to a goldmine and pick up a nugget
//  of gold. If the miner already has a nugget of gold he'll change state
//  to VisitBankAndDepositGold. If he gets thirsty he'll change state
//  to QuenchThirst
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
//  Entity will go to a bank and deposit any nuggets he is carrying. If the 
//  miner is subsequently wealthy enough he'll walk home, otherwise he'll
//  keep going to get more gold
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
//  miner will go home and sleep until his fatigue is decreased
//  sufficiently
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