//
// Created by Louis Ventre on 7/23/17.
//

#include <Player.hpp>
#include <Aircraft.hpp>
#include <CommandQueue.hpp>

struct AircraftMover
{
    sf::Vector2f velocity;

    AircraftMover(float vx, float vy) : velocity(vx, vy)
    {
    }

    void operator()(Aircraft &aircraft, sf::Time dt) const
    {
        aircraft.accelerate(velocity);
    }
};

Player::Player()
{
    _keyBinding[sf::Keyboard::Left] = MoveLeft;
    _keyBinding[sf::Keyboard::Right] = MoveRight;
    _keyBinding[sf::Keyboard::Up] = MoveUp;
    _keyBinding[sf::Keyboard::Down] = MoveDown;

    initializeActions();
    for(auto &pair : _actionBinding)
        pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(sf::Event const &event, CommandQueue &cmd)
{
    if (event.type == sf::Event::KeyPressed)
    {
        auto found = _keyBinding.find(event.key.code);
        if (found != _keyBinding.end() && !isRealtimeAction(found->second))
            cmd.push(_actionBinding[found->second]);
    }
}

void Player::handleRealtimeInput(CommandQueue &cmd)
{
    for (auto pair : _keyBinding)
    {
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
            cmd.push(_actionBinding[pair.second]);
    }
}

void Player::assignKey(Action act, sf::Keyboard::Key key)
{
    for (auto it = _keyBinding.begin(); it != _keyBinding.end(); )
    {
        if (it->second == act)
            _keyBinding.erase((it++));
        else
            it++;
    }
    _keyBinding[key] = act;
}

sf::Keyboard::Key Player::getAssignedKey(Action act) const
{
    for (auto pair : _keyBinding)
    {
        if (pair.second == act)
            return (pair.first);
    }
    return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
    float const playerSpeed = 200.0f;

    _actionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.0f));
    _actionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(playerSpeed, 0.0f));
    _actionBinding[MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.0f, -playerSpeed));
    _actionBinding[MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.0f, playerSpeed));
}

bool Player::isRealtimeAction(Action act)
{
    switch (act)
    {
        case MoveLeft:
        case MoveRight:
        case MoveDown:
        case MoveUp:
            return (true);
        default:
            return (false);
    }
}