#ifndef STATEMACHINE_H
#define STATEMACHINE_H

//------------------------------------------------------------------------
//
//  Name:   StateMachine.h
//
//  Desc:   State machine class. Inherit from this class and create some 
//          states to give your agents FSM functionality
//
//  Created by Almas Shintemirov 2021 (https://www.alaris.kz) based on the code template 
//  by Mat Buckland 2002 (https://www.amazon.com/-/es/Mat-Buckland/dp/1556220782)
//
//------------------------------------------------------------------------
#include <cassert>
#include <string>

#include "State.h"



template <class entity_type>
class StateMachine
{
private:

  //a pointer to the agent that owns this instance
  entity_type*          pOwner;

  State<entity_type>*   pCurrentState;

public:

  StateMachine(entity_type* owner):pOwner(owner),
                                   pCurrentState(NULL)
  {}

  virtual ~StateMachine(){}

  //use these methods to initialize the FSM
  void SetCurrentState(State<entity_type>* s){ pCurrentState = s;}
  
  //call this to update the FSM
  void  Update()const
  {
    if (pCurrentState) pCurrentState->Execute( pOwner );
  }

  //change to a new state
  void  ChangeState(State<entity_type>* pNewState)
  {
    assert(pNewState && "<StateMachine::ChangeState>: trying to change to NULL state");

    //call the exit method of the existing state
    pCurrentState->Exit( pOwner);

    //change state to the new state
    pCurrentState = pNewState;

    //call the entry method of the new state
    pCurrentState->Enter( pOwner);
  }

  //returns true if the current state's type is equal to the type of the
  //class passed as a parameter. 
  bool  isInState(const State<entity_type>& st)const
  {
    return typeid(*pCurrentState) == typeid(st);
  }

  State<entity_type>*  CurrentState()  const{return pCurrentState;}

};




#endif


