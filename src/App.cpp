//
// Created by oxydros on 7/9/17.
//

#include "App.h"

App::App(int width, int height, std::string const &title) : window(sf::VideoMode(width, height, BITS_PER_PIXEL), title), appName(title) {
    window.setFramerateLimit(FRAMERATE);
}

App::~App() {

}

bool App::run() {
    while (window.isOpen()) {
        sf::Event   event;
        while(window.pollEvent((event))) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            window.clear(sf::Color::Black);
            window.display();
        }
    }
    return (true);
}