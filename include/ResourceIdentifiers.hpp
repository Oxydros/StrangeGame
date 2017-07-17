//
// Created by Louis Ventre on 7/17/17.
//

#ifndef STRANGEGAME_RESOURCEIDENTIFIERS_HPP
#define STRANGEGAME_RESOURCEIDENTIFIERS_HPP

//Forward declaration
namespace sf
{
    class Texture;
}

namespace Textures
{
    enum ID : unsigned int
    {
        Eagle,
        Raptor,
        Desert,
    };
}

//Forward declaration
template <typename  Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif //STRANGEGAME_RESOURCEIDENTIFIERS_HPP
