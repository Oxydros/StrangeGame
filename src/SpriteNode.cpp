//
// Created by Louis Ventre on 7/17/17.
//

#include "SpriteNode.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

SpriteNode::SpriteNode(sf::Texture const &texture)
        : _sprite(texture)
{
}

SpriteNode::SpriteNode(sf::Texture const &texture, sf::IntRect &rect)
        : _sprite(texture, rect)
{
}

void SpriteNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
