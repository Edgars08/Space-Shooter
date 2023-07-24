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
        for (auto *i : meteorsBig)
        {
            delete i;
        }
        for (auto *i : meteorsSmall)
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
            // FOR BIG METEORS
            meteorsBig.push_back((new Meteors(_data, "Meteor1", METEOR_1_FILEPATH)));
            meteorsBig.push_back((new Meteors(_data, "Meteor2", METEOR_2_FILEPATH)));
            this->clock_1.restart();
        }
        if (this->clock_2.getElapsedTime().asSeconds() > METEOR_SPAWNTIME_2)
        {
            // FOR SMALL METEORS
            meteorsSmall.push_back((new Meteors(_data, "Meteor3", METEOR_3_FILEPATH)));
            meteorsSmall.push_back((new Meteors(_data, "Meteor4", METEOR_4_FILEPATH)));
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
    void GameState::UpdateScore()
    {
        std::stringstream str;
        str << _score;
        // str()- To get and set string object whose content is present in the stream.
        pointtext.setString(str.str()); // here its the get function

        life_percent = static_cast<float>(pointsystem->getLife() / pointsystem->getLifeMax());
    }

    void GameState::CheckMeteorLaserCollisionBig()
    {
        // FOR BIG METEOR
        for (unsigned int i = 0; i < meteorsBig.size(); ++i)
        {
            bool meteor_deleted = false;
            for (unsigned int k = 0; k < lasers.size() && meteor_deleted == false; ++k)
            {
                if (lasers[k]->getBound().intersects(meteorsBig[i]->getBound()))
                {
                    delete meteorsBig[i];
                    delete lasers[k];
                    lasers.erase(lasers.begin() + k);
                    meteorsBig.erase(meteorsBig.begin() + i);
                    meteor_deleted = true;
                }
            }
        }
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
    void GameState::CheckMeteorPlayerCollision()
    {
        for (unsigned int i = 0; i < meteorsSmall.size(); i++)
        {
            if (meteorsSmall[i]->getBound().intersects(spaceship->getBound()))
            {
                delete meteorsSmall[i];
                meteorsSmall.erase(meteorsSmall.begin() + i);
                this->pointsystem->LoseLife(LOSE_POINTS);
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

    void GameState::UpdateMeteors(float dt)
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
        std::cout << "sizeBig: " << meteorsBig.size() << std::endl;
        // FOR SMALL METEORS
        for (unsigned int counter = 0; counter < meteorsSmall.size(); counter++)
        {
            this->meteorsSmall[counter]->UpdateMeteor(dt);
            if (meteorsBig[counter]->getBound().top > _data->window.getSize().y)
            {
                delete meteorsSmall[counter];
                meteorsSmall.erase(meteorsSmall.begin() + counter);
            }
        }
        std::cout << "sizeSmall: " << meteorsSmall.size() << std::endl
                  << std::endl;
    }

    void GameState::Update(float dt)
    {
        this->ShootLasers();
        this->InitMeteors();
        space->MoveSpace(dt);
        spaceship->MoveSpaceShip(dt);
        spaceship->CheckWindowCollision();
        this->UpdateLaser(dt);
        this->UpdateMeteors(dt);
        this->CheckMeteorLaserCollisionSmall();
        this->CheckMeteorPlayerCollision();
        // this->CheckMeteorLaserCollisionBig();
        this->UpdateScore();
        this->lifebar->UpdateLifeBar(life_percent);
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
        /*       for (auto *Big_m : meteorsBig)
               {
                   Big_m->DrawMeteors();
               }*/
        for (auto *Small_m : meteorsSmall)
        {
            Small_m->DrawMeteors();
        }
        this->DrawScore();
        this->lifebar->DrawLifeBar();
        _data->window.display();
    }
}