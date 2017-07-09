//
// Created by Louis Ventre on 7/9/17.
//

#ifndef STRANGEGAME_APP_H
# define STRANGEGAME_APP_H

# include <SFML/Graphics.hpp>
# include <string>
# include <iostream>

# define FRAMERATE         60
# define BITS_PER_PIXEL    32


class App {
public:
    static sf::Time const   TimePerFrame;
    static float const      PlayerSpeed;

private:
    sf::RenderWindow    window;
    std::string const   &appName;
    sf::Texture         texture;
    sf::Sprite          player;
    sf::Font            font;
    sf::Text            text;
    sf::Time            statisticUpdateTime;
    unsigned int        statisticNumFrames;
    bool                movingUp;
    bool                movingDown;
    bool                movingLeft;
    bool                movingRight;

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
