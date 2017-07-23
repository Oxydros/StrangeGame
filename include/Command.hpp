//
// Created by Louis Ventre on 7/23/17.
//

#ifndef STRANGEGAME_COMMAND_HPP
#define STRANGEGAME_COMMAND_HPP


#include <SFML/System/Time.hpp>
#include <functional>
#include <cassert>
#include "Category.hpp"

//Forward declaration
class SceneNode;

struct Command
{
    Command();
    std::function<void(SceneNode&, sf::Time)>   action;
    Category::Type                              category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
    return [=](SceneNode &node, sf::Time dt)
    {
        assert(dynamic_cast<GameObject*>(&node) != nullptr);
        fn(static_cast<GameObject&>(node), dt);
    };
};

#endif //STRANGEGAME_COMMAND_HPP
