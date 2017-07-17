//
// Created by Louis Ventre on 7/17/17.
//

#include <algorithm>
#include <assert.h>
#include "SceneNode.hpp"

SceneNode::SceneNode() {

}

void SceneNode::attachChild(SceneNode::Ptr child) {
    child->_parent = this;
    _children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(SceneNode const &node) {
    auto foundNode = std::find_if(_children.begin(), _children.end(),
                        [&] (Ptr &p) -> bool {return p.get() == &node; });
    assert(foundNode != _children.end());

    SceneNode::Ptr result = std::move(*foundNode);
    result->parent = nullptr;
    _children.erase(foundNode);
    return result;
}


void SceneNode::update(sf::Time dt) {
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt) {
    //EMPTY
}

void SceneNode::updateChildren(sf::Time dt) {
    for (Ptr const &child : _children) {
        child->update(dt);
    }
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    drawCurrent(target, states);
    drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    //EMPTY
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const {
    for(const SceneNode::Ptr &child : _children) {
        child->draw(target, states);
    }
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform trans = sf::Transform::Identity;

    for (SceneNode const *node = this; node != nullptr; node = node->_parent) {
        trans = node->getTransform() * trans;
    }
    return (trans);
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return (getWorldTransform() * sf::Vector2f());
}