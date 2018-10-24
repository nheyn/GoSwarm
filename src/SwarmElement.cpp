//
//  SwarmElement.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#include "SwarmElement.hpp"

// -- SwarmElement methods --
SwarmElement::SwarmElement(float _width, float _height, ofVec2f _position, ofColor _color) {
    bound = {
        .width = _width,
        .height = _height,
        .position = _position
    };
    color = _color;
}

ElementBound SwarmElement::getBound() {
    return bound;
}

// -- SwarmElementBot methods --
SwarmElementBot::SwarmElementBot(float _size, ofVec2f _center, ofColor _color)
: SwarmElement(_size, _size, _center, _color) {}

BotSpec SwarmElementBot::getBot() {
    return {
        .position = bound.position,
        .color = color
    };
}

// -- PackSwarmElement methods --
SwarmElementPack::SwarmElementPack(float _width, float _height, ofVec2f _position, ofColor _color, vector<SwarmElement*> _members)
: SwarmElement(_width, _height, _position, _color) {
    members = _members;
}

vector<SwarmElement*> SwarmElementPack::getMembers() {
    return members;
}
