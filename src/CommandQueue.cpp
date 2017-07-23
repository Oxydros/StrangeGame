//
// Created by Louis Ventre on 7/23/17.
//

#include <CommandQueue.hpp>

void CommandQueue::push(Command const &command)
{
    _queue.push(command);
}

bool CommandQueue::isEmpty() const
{
    return (_queue.empty());
}

Command CommandQueue::pop()
{
    Command cmd = _queue.front();
    _queue.pop();
    return (cmd);
}