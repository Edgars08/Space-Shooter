#include "SplashState.h"
#include "MainMenuState.h"
#include <sstream>
#include <iostream>
#include "Definations.h"

namespace Edgars
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {
    }

    void SplashState::InitState()
    {
        // store them in a map ...then get
        _data->assets.LoadTexture("SplashStateBackground", SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("SplashStateBackground"));
        _background.setScale(1.33333333f, 1.166666667f);
    }

    void SplashState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
        }
    }
    void SplashState::Update(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            _data->machine.AddState(StateRef(new MainMenuState(_data)), true); // on stack
        }
    }
    void SplashState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }

}
/*

The new operator denotes a request for memory allocation on the Free Store. If sufficient memory is available, a new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable.
**Remember we using a stack**

unique_ptr<Rectangle> same as StateRef
P1 as as alias variable
Rectangle same as MainMenuState
_data is parameter passed same as (10,5);

 Example:
    class Rectangle {
    int length; int breadth;
    public:
    Rectangle(int l, int b) {length = l;breadth = b;}; Then in int main
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
 */