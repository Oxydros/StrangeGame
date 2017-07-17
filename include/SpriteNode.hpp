//
// Created by Louis Ventre on 7/17/17.
//

#ifndef STRANGEGAME_SPRITENODE_HPP
#define STRANGEGAME_SPRITENODE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "SceneNode.hpp"

class SpriteNode : public SceneNode
{
private:
    sf::Sprite      _sprite;

public:
    explicit SpriteNode(sf::Texture const &texture);
    explicit SpriteNode(sf::Texture const &texture, sf::IntRect &rect);

private:
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //STRANGEGAME_SPRITENODE_HPP
