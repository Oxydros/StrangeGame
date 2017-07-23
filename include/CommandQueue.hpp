//
// Created by Louis Ventre on 7/23/17.
//

#ifndef STRANGEGAME_COMMANDQUEUE_HPP
#define STRANGEGAME_COMMANDQUEUE_HPP

#include <queue>
#include "Command.hpp"

class CommandQueue
{
private:
    std::queue<Command>     _queue;

public:
    void        push(Command const &command);
    Command     pop();
    bool        isEmpty() const;
};

#endif //STRANGEGAME_COMMANDQUEUE_HPP
