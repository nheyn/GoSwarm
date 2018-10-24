//
//  SwarmElement.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#include "SwarmElement.hpp"

// --- ElementBound helper functions ---
ofVec2f convertPosition(ElementBound bound, ofVec2f position) {
    return {
        bound.position.x + (bound.width * position.x),
        bound.position.y + (bound.height * position.y)
    };
}

ElementBound convertBound(ElementBound outerBound, ElementBound innerBound) {
    return {
        .width = outerBound.width * innerBound.width,
        .height = outerBound.height * innerBound.height,
        .position = convertPosition(outerBound, innerBound.position)
    };
}

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
