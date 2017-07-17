//
// Created by Louis Ventre on 7/17/17.
//

#ifndef STRANGEGAME_SCENENODE_HPP
#define STRANGEGAME_SCENENODE_HPP

#include <memory>
#include <vector>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

private:
    std::vector<Ptr>    _children;
    SceneNode           *_parent;

public:
    SceneNode();

public:
    void            update(sf::Time dt);
    void            attachChild(Ptr child);
    Ptr             detachChild(SceneNode const &node);

    sf::Vector2f    getWorldPosition() const;
    sf::Transform   getWorldTransform() const;

private:
    virtual void    updateCurrent(sf::Time dt);
    void            updateChildren(sf::Time dt);
    virtual void    draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    void            drawChildren(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //STRANGEGAME_SCENENODE_HPP
