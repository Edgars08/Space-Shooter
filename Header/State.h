#ifndef STATE_H
#define STATE_H

namespace Edgars
{

    class State
    {
    public:
        State(){};
        ~State(){};
        virtual void InitState() = 0;
        virtual void HandleInput() = 0;
        virtual void Update(float dt) = 0;
        virtual void Draw(float dt) = 0;

        virtual void Pause(){}
        virtual void Resume(){}
    };
}
#endif
/*
basically this abtract class.
each state of the game will implement is own function.
*/