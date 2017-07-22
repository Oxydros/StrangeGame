//
// Created by Louis Ventre on 7/19/17.
//

#include "World.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

World::World(sf::RenderWindow &window)
        : _window(window), _worldView(window.getDefaultView()), _textures(), _sceneGraph(), _sceneLayers(),
          _worldBounds(0.0f, 0.0f, _worldView.getSize().x, 2000.0f),
          _spawnPosition(_worldView.getSize().x / 2.0f, _worldBounds.height - _worldView.getSize().y / 2.0f),
          _scrollSpeed(-50.0f), _player(nullptr)
{

    loadTextures();
    buildScene();
    _worldView.setCenter(_spawnPosition);
}

void World::loadTextures()
{
    _textures.load(Textures::Eagle, "resources/textures/Eagle.png");
    _textures.load(Textures::Desert, "resources/textures/Desert.png");
    _textures.load(Textures::Raptor, "resources/textures/Raptor.png");
}

void World::buildScene()
{
    //Init SceneNodes
    for (std::size_t i = 0; i < LayerCount; i++)
    {
        SceneNode::Ptr layer(new SceneNode());

        _sceneLayers[i] = layer.get();
        _sceneGraph.attachChild(std::move(layer));
    }

    //Create background texture
    sf::Texture &texture = _textures.get(Textures::Desert);
    sf::IntRect textureRect(_worldBounds);
    texture.setRepeated(true);

    //Link it to sceneGraph
    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(_worldBounds.left, _worldBounds.top);
    _sceneLayers[Background]->attachChild(std::move(backgroundSprite));

    //Create player
    std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle, _textures));
    _player = player.get();
    _player->setPosition(_spawnPosition);
    _player->setVelocity(40.0f, _scrollSpeed);

    //Link it to sceneGraph
    _sceneLayers[Air]->attachChild(std::move(player));

    //Create escort
    std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor, _textures));
    std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, _textures));
    rightEscort->setPosition(80.0f, 50.0f);
    leftEscort->setPosition(-80.0f, 50.0f);
    _player->attachChild(std::move(leftEscort));
    _player->attachChild(std::move(rightEscort));
}

void World::draw()
{
    _window.setView(_worldView);
    _window.draw(_sceneGraph);
}

void World::update(sf::Time dt)
{
    //Move view
    _worldView.move(0.0f, _scrollSpeed * dt.asSeconds());

    sf::Vector2f position = _player->getPosition();
    sf::Vector2f velocity = _player->getVelocity();

    if (position.x <= _worldBounds.left + 150 || position.x >= _worldBounds.left + _worldBounds.width - 150)
    {
        velocity.x *= -1;
        _player->setVelocity(velocity);
    }
    _sceneGraph.update(dt);
}
