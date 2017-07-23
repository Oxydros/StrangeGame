//
// Created by Louis Ventre on 7/17/17.
//

#ifndef STRANGEGAME_AIRCRAFT_HPP
#define STRANGEGAME_AIRCRAFT_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

class Aircraft : public Entity
{
public:
    enum Type : unsigned char
    {
        Eagle,
        Raptor,
    };

private:
    Type        _type;
    sf::Sprite  _sprite;

public:
    explicit Aircraft(Type type, TextureHolder const &textures);

    virtual Category::Type getCategory() const;

public:
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //STRANGEGAME_AIRCRAFT_HPP
