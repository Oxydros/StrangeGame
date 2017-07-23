//
// Created by Louis Ventre on 7/23/17.
//

#ifndef STRANGEGAME_PLAYER_HPP
#define STRANGEGAME_PLAYER_HPP


#include <SFML/Window/Event.hpp>
#include <map>
#include "Command.hpp"

//Forward declaration
class CommandQueue;

class Player
{
public:
    enum Action : unsigned char
    {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        ActionCount,
    };

private:
    std::map<sf::Keyboard::Key, Action> _keyBinding;
    std::map<Action, Command>            _actionBinding;

public:
    Player();

public:
    void                handleEvent(sf::Event const &event, CommandQueue &cmd);
    void                handleRealtimeInput(CommandQueue &cmd);

    void                assignKey(Action act, sf::Keyboard::Key key);
    sf::Keyboard::Key   getAssignedKey(Action act) const;

private:
    void                initializeActions();
    static bool         isRealtimeAction(Action act);
};

#endif //STRANGEGAME_PLAYER_HPP
