//
// Created by Louis Ventre on 7/17/17.
//

#include "Aircraft.hpp"
#include "ResourceHolder.hpp"

Textures::ID toTextureID(Aircraft::Type type) {
    switch (type) {
        case Aircraft::Eagle:
            return Textures::Eagle;
        case Aircraft::Raptor:
            return Textures::Raptor;
    }
}

Aircraft::Aircraft(Type type, TextureHolder const &textures)
        : _type(type), _sprite(textures.get(toTextureID(type))) {
    sf::FloatRect bounds = _sprite.getLocalBounds();
    _sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void Aircraft::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}