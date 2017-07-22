//
// Created by Louis Ventre on 7/9/17.
//

#ifndef STRANGEGAME_APP_H
# define STRANGEGAME_APP_H

# include "World.hpp"

# include <string>
# include <iostream>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

# define FRAMERATE         60
# define BITS_PER_PIXEL    32


class App
{
public:
    static sf::Time const   TimePerFrame;
    static float const      PlayerSpeed;

private:
    sf::RenderWindow    window;
    std::string const   &appName;
    World               _world;
    sf::Font            font;
    sf::Text            text;
    sf::Time            statisticUpdateTime;
    unsigned int        statisticNumFrames;

public:
    App(int width, int height, std::string const &title);
    ~App();
    App(App const &foreign) = delete;
    App &operator=(App const &foreign) = delete;

public:
    sf::RenderWindow const &getWindow() const;
    void run();

private:
    void render();
    void processEvents();
    void update(sf::Time deltaTime);
    void updateStatistics(sf::Time deltaTime);

private:
    void handleKeyboardInput(sf::Keyboard::Key key, bool isPressed);
};

#endif //STRANGEGAME_APP_H
