#ifndef STATE_H
#define STATE_H
//------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Originally created by Mat Buckland 2002 (https://www.amazon.com/-/es/Mat-Buckland/dp/1556220782)
//
//  Modified by Almas Shintemirov 2021 (https://www.alaris.kz)
//
//------------------------------------------------------------------------


template <class entity_type>
class State
{
public:

  virtual ~State(){}

  //this will execute when the state is entered
  virtual void Enter(entity_type*)=0;

  //this is the states normal update function
  virtual void Execute(entity_type*)=0;

  //this will execute when the state is exited. (My word, isn't
  //life full of surprises... ;o))
  virtual void Exit(entity_type*)=0;
};

#endif