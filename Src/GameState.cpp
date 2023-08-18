#include "GameState.h"
#include "Definations.h"
#include <sstream>

namespace Edgars
{
    GameState::GameState(GameDataRef data) : _data(data)
    {
    }
    GameState::~GameState()
    {
        for (auto *i : lasers)
        {
            delete i;
        }
        for (auto *i : meteorsSmall)
        {
            delete i;
        }
        for (auto *i : meteorsBig)
        {
            delete i;
        }
        delete space;
        delete spaceship;
        delete pointsystem;
        delete lifebar;
    }
    void GameState::InitState()
    {
        // OBJECT
        spaceship = new SpaceShip(_data);
        spaceship->InitSpaceShip();

        space = new Space(_data);
        space->InitSpace();

        pointsystem = new PointSystem(_data);
        this->InitScore();

        lifebar = new LifeBars(_data);
        lifebar->InitLifeBar(1.0f);
        lifebar->InitLifeBarBack();
    }
    void GameState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                _data->window.close();
            }
        }
    }
    void GameState::ShootLasers()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            lasers.push_back(new Lasers(_data, sf::Vector2f(spaceship->getPosition().x, spaceship->getPosition().y)));
            lasers.push_back(new Lasers(_data, sf::Vector2f(spaceship->getPosition().x + spaceship->getBound().width * 0.9f, spaceship->getPosition().y)));
        }
    }
    void GameState::InitMeteors()
    {
        if (this->clock_1.getElapsedTime().asSeconds() > METEOR_SPAWNTIME_1)
        {
            // FOR SMALL METEORS
            meteorsSmall.push_back((new Meteors(_data, "Meteor3", METEOR_3_FILEPATH)));
            meteorsSmall.push_back((new Meteors(_data, "Meteor4", METEOR_4_FILEPATH)));
            this->clock_1.restart();
        }
        if (this->clock_2.getElapsedTime().asSeconds() > METEOR_SPAWNTIME_2)
        {
            // FOR BIG METEORS
            meteorsBig.push_back((new Meteors(_data, "Meteor1", METEOR_1_FILEPATH)));
            meteorsBig.push_back((new Meteors(_data, "Meteor2", METEOR_2_FILEPATH)));
            this->clock_2.restart();
        }
    }

    void GameState::InitScore()
    {
        this->_score = 0;
        _data->assets.LoadFont("font", FONT_FILEPATH);
        fontText = _data->assets.GetFont("font");
        pointtext.setFont(fontText);
        pointtext.setCharacterSize(40);
        pointtext.setFillColor(sf::Color::White);
    }

    void GameState::CheckMeteorLaserCollisionSmall()
    {
        // FOR SMALL METEOR
        for (unsigned int i = 0; i < meteorsSmall.size(); ++i)
        {
            bool meteor_removed = false;

            for (unsigned int k = 0; k < lasers.size() && meteor_removed == false; ++k)
            {
                if (lasers[k]->getBound().intersects(meteorsSmall[i]->getBound()))
                {
                    // delete the enemie
                    delete meteorsSmall[i];
                    delete lasers[k];
                    // delete pointer at that enemy i think
                    lasers.erase(lasers.begin() + k);
                    meteorsSmall.erase(meteorsSmall.begin() + i);
                    meteor_removed = true;
                    this->_score += this->pointsystem->getPoints();
                }
            }
        }
    }
    void GameState::CheckMeteorLaserCollisionBig()
    {
        // FOR BIG METEOR
        for (unsigned int i = 0; i < meteorsBig.size(); ++i)
        {
            bool meteor_removed = false;

            for (unsigned int k = 0; k < lasers.size() && meteor_removed == false; ++k)
            {
                if (lasers[k]->getBound().intersects(meteorsBig[i]->getBound()))
                {
                    // delete the enemie
                    delete meteorsBig[i];
                    delete lasers[k];
                    // delete pointer at that enemy i think
                    lasers.erase(lasers.begin() + k);
                    meteorsBig.erase(meteorsBig.begin() + i);
                    meteor_removed = true;
                    this->_score += this->pointsystem->getPoints();
                }
            }
        }
    }
    void GameState::CheckMeteorPlayerCollisionSmall()
    {
        for (unsigned int i = 0; i < meteorsSmall.size(); i++)
        {
            if (meteorsSmall[i]->getBound().intersects(spaceship->getBound()))
            {
                // Lose life when you get hit.
                this->lifebar->LoseLife();

                delete meteorsSmall[i];
                meteorsSmall.erase(meteorsSmall.begin() + i);
            }
        }
    }

    void GameState::CheckMeteorPlayerCollisionBig()
    {
        for (unsigned int i = 0; i < meteorsBig.size(); i++)
        {
            if (meteorsBig[i]->getBound().intersects(spaceship->getBound()))
            {
                // Lose life when you get hit.
                this->lifebar->LoseLife();

                delete meteorsBig[i];
                meteorsBig.erase(meteorsBig.begin() + i);
            }
        }
    }
    void GameState::UpdateLaser(float dt)
    {
        for (unsigned int counter = 0; counter < lasers.size(); counter++)
        {
            lasers[counter]->UpdateLasers(dt);
            if (lasers[counter]->getBound().top + lasers[counter]->getBound().height < 0)
            {
                delete lasers[counter];
                lasers.erase(lasers.begin() + counter);
            }
        }
        std::cout << "sizeLaser: " << lasers.size() << std::endl;
    }
    void GameState::UpdateMeteorsSmall(float dt)
    {
        // FOR SMALL METEORS
        for (unsigned int counter = 0; counter < meteorsSmall.size(); counter++)
        {
            this->meteorsSmall[counter]->UpdateMeteor(dt);
            if (meteorsSmall[counter]->getBound().top > _data->window.getSize().y)
            {
                delete meteorsSmall[counter];
                meteorsSmall.erase(meteorsSmall.begin() + counter);
            }
        }
        std::cout << "sizeSmall: " << meteorsSmall.size() << std::endl
                  << std::endl;
    }
    void GameState::UpdateMeteorsBig(float dt)
    {
        // FOR BIG METEORS
        for (unsigned int counter = 0; counter < meteorsBig.size(); counter++)
        {
            this->meteorsBig[counter]->UpdateMeteor(dt);
            if (meteorsBig[counter]->getBound().top > _data->window.getSize().y)
            {
                delete meteorsBig[counter];
                meteorsBig.erase(meteorsBig.begin() + counter);
            }
        }
        std::cout << "sizeBig: " << meteorsBig.size() << std::endl
                  << std::endl;
    }
    void GameState::UpdateScore()
    {
        std::stringstream str;
        str << _score;
        // str()- To get and set string object whose content is present in the stream.
        pointtext.setString(str.str()); // here its the get function
    }
    void GameState::Update(float dt)
    {
        this->ShootLasers();
        this->InitMeteors();
        space->MoveSpace(dt);
        spaceship->MoveSpaceShip(dt);
        spaceship->CheckWindowCollision();
        this->UpdateLaser(dt);
        this->UpdateMeteorsSmall(dt);
        this->UpdateMeteorsBig(dt); //
        this->CheckMeteorLaserCollisionSmall();
        this->CheckMeteorLaserCollisionBig(); //
        this->CheckMeteorPlayerCollisionSmall();
        this->CheckMeteorPlayerCollisionBig();
        this->lifebar->UpdateLifeBar();
        this->UpdateScore();
    }
    bool GameState::IsSpaceShipAlive()
    {
        if(this->lifebar->getLife() <= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void GameState::DrawScore()
    {
        _data->window.draw(pointtext);
    }
    void GameState::Draw(float dt)
    {
        _data->window.clear();
        space->DrawSpace();
        spaceship->DrawSpaceShip();
        for (auto *laser : lasers)
        {
            laser->DrawLasers();
        }
        for (auto *Small_m : meteorsSmall)
        {
            Small_m->DrawMeteors();
        }
        for (auto *Big_m : meteorsBig)
        {
            Big_m->DrawMeteors();
        }
        this->DrawScore();
        this->lifebar->DrawLifeBar();
        _data->window.display();
    }
}