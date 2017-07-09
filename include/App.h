//
// Created by Louis Ventre on 7/9/17.
//

#ifndef STRANGEGAME_APP_H
# define STRANGEGAME_APP_H

# include <SFML/Graphics.hpp>
# include <string>

# define FRAMERATE         60
# define BITS_PER_PIXEL    32


class App {
private:
    sf::RenderWindow    window;
    std::string const   &appName;

public:
    App(int width, int height, std::string const &title);
    ~App();
    App(App const &foreign) = delete;
    App &operator=(App const &foreign) = delete;

public:
    sf::RenderWindow const &getWindow() const;
    bool run();
};

#endif //STRANGEGAME_APP_H
