#include "MainMenuState.h"
#include "GameState.h"
#include <sstream>
#include <iostream>
#include "Definations.h"

namespace Edgars
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
    }

    void MainMenuState::InitState()
    {
        // stored in a map
        _data->assets.LoadTexture("GameTitle", MAINMENU_TITLE_FILEPATH);
        _data->assets.LoadTexture("ExitButton", EXIT_BUTTON_FILEPATH);
        _data->assets.LoadTexture("StartButton", START_BUTTON_FILEPATH);

        _exitbutton.setTexture(this->_data->assets.GetTexture("ExitButton"));
        _title.setTexture(this->_data->assets.GetTexture("GameTitle"));
        _startbutton.setTexture(this->_data->assets.GetTexture("StartButton"));

        _title.setPosition(0, 0);
        _startbutton.setPosition((SCREEN_WIDTH - _startbutton.getGlobalBounds().width * 0.5) / 2, (SCREEN_HEIGHT + _startbutton.getGlobalBounds().height * 0.2) / 2);
        _exitbutton.setPosition((SCREEN_WIDTH - _exitbutton.getGlobalBounds().width * 0.5) / 2, SCREEN_HEIGHT / 2 + _exitbutton.getGlobalBounds().height * 0.75);

        _title.setScale(0.4166666667f, 0.6481481481f);
        _startbutton.setScale(0.2f, 0.2f);
        _exitbutton.setScale(0.2f, 0.2f);
    }

    void MainMenuState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
            if (_data->input.IsSpriteClicked(_startbutton, sf::Mouse::Left, _data->window))
            {
                _data->machine.AddState(StateRef(new GameState(_data)), true); // on stack
            }
            if (_data->input.IsSpriteClicked(_exitbutton, sf::Mouse::Left, _data->window))
            {
                _data->window.close();
            }
        }
    }
    void MainMenuState::Update(float dt)
    {
    }
    void MainMenuState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_title);
        _data->window.draw(_startbutton);
        _data->window.draw(_exitbutton);
        _data->window.display();
    }
}