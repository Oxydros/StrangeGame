//
// Created by Louis Ventre on 7/17/17.
//

#ifndef STRANGEGAME_ENTITY_HPP
#define STRANGEGAME_ENTITY_HPP


#include "SceneNode.hpp"

class Entity : public SceneNode
{
private:
    sf::Vector2f    _velocity;
public:
    void            setVelocity(sf::Vector2f v);
    void            setVelocity(float x, float y);
    sf::Vector2f    getVelocity() const;

private:
    virtual void    updateCurrent(sf::Time dt);
};

#endif //STRANGEGAME_ENTITY_HPP
