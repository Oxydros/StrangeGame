//
// Created by Louis Ventre on 7/9/17.
//

#include <App.hpp>

#include <SFML/Window/Event.hpp>

float const App::PlayerSpeed = 100.0f;
sf::Time const App::TimePerFrame = sf::seconds(1.0f / 60.0f);

App::App(int width, int height, std::string const &title)
        : window(sf::VideoMode(width, height, BITS_PER_PIXEL), title),
          appName(title),
          _world(window),
          font(),
          text(),
          statisticUpdateTime(),
          statisticNumFrames(0)
{
    font.loadFromFile("resources/fonts/OpenSans-Regular.ttf");
    text.setFont(font);
    text.setPosition(5.0f, 5.0f);
    text.setCharacterSize(10);
}

App::~App()
{

}

void App::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            this->processEvents();
            this->update(TimePerFrame);
        }
        updateStatistics(deltaTime);
        this->render();
    }
}

void App::update(sf::Time deltaTime)
{
    _world.update(deltaTime);
}

void App::processEvents()
{
    sf::Event   event;
    while(window.pollEvent((event)))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handleKeyboardInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handleKeyboardInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

void App::render()
{
    window.clear();
    _world.draw();
    window.setView(window.getDefaultView());
    window.draw(text);
    window.display();
}

void App::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::Escape && isPressed)
        window.close();
}

void App::updateStatistics(sf::Time deltaTime)
{
    statisticUpdateTime += deltaTime;
    statisticNumFrames += 1;

    if (statisticUpdateTime >= sf::seconds(1.0f))
    {
        text.setString(
                "Frames / Second = " + std::to_string(statisticNumFrames) + "\n" +
                "Time / Update = " + std::to_string(statisticUpdateTime.asMicroseconds() / statisticNumFrames) + "us");

        statisticUpdateTime -= sf::seconds(1.0f);
        statisticNumFrames = 0;
    }
}