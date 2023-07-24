#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include <memory>
#include <stack>

namespace Edgars
{
    typedef std::unique_ptr<State> StateRef;
    class StateMachine
    {
    public:
        StateMachine(){};
        ~StateMachine(){};
        void AddState(StateRef newState, bool isReplacing = true);
        void RemoveState();
        void ProcessStateChanges();
        StateRef &GetActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;
        bool _isReplacing;
        bool _isAdding;
        bool _isRemoving;
    };
}

#endif
/*
add new state of the game on top of the stack
also check if the current state need to be removed of paused before we add a new one
*/