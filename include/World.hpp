//
// Created by Louis Ventre on 7/19/17.
//

#ifndef STRANGEGAME_WORLD_HPP
#define STRANGEGAME_WORLD_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Aircraft.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>

//Forward declaration
namespace sf
{
    class RenderWindow;
}

class World : private sf::NonCopyable
{
private:
    enum Layer : unsigned char
    {
        Background,
        Air,
        LayerCount
    };

private:
    sf::RenderWindow                    &_window;
    sf::View                            _worldView;
    TextureHolder                       _textures;
    SceneNode                           _sceneGraph;
    std::array<SceneNode*, LayerCount>  _sceneLayers;
    sf::FloatRect                       _worldBounds;
    sf::Vector2f                        _spawnPosition;
    float                               _scrollSpeed;
    Aircraft                            *_player;

public:
    explicit    World(sf::RenderWindow &window);

public:
    void        update(sf::Time dt);
    void        draw();

private:
    void        loadTextures();
    void        buildScene();
};

#endif //STRANGEGAME_WORLD_HPP
