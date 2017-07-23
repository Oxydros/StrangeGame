//
// Created by Louis Ventre on 7/17/17.
//

#include <Entity.hpp>

void Entity::setVelocity(sf::Vector2f v)
{
    _velocity = v;
}

void Entity::setVelocity(float x, float y)
{
    _velocity.x = x;
    _velocity.y = y;
}

sf::Vector2f Entity::getVelocity() const
{
    return (_velocity);
}

void Entity::accelerate(sf::Vector2f v)
{
    _velocity += v;
}

void Entity::accelerate(float x, float y)
{
    _velocity.x += x;
    _velocity.y += y;
}

void Entity::updateCurrent(sf::Time dt)
{
    move(_velocity * dt.asSeconds());
}