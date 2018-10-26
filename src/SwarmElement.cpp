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
SwarmElement::SwarmElement(float _width, float _height, ofVec2f _position) {
    bound = {
        .width = _width,
        .height = _height,
        .position = _position
    };
}

ElementBound SwarmElement::getBound() {
    return bound;
}

// -- SwarmElementBot methods --
SwarmElementBot::SwarmElementBot(float _size, ofVec2f _center, ofColor _color)
: SwarmElement(_size, _size, _center) {
    color = _color;
}

BotSpec SwarmElementBot::getBot() {
    return {
        .position = { bound.position.x, bound.position.y },
        .color = color
    };
}

// -- PackSwarmElement methods --
SwarmElementPack::SwarmElementPack(float _width, float _height, ofVec2f _position, vector<SwarmElement*> _members)
: SwarmElement(_width, _height, _position) {
    members = _members;
}

vector<SwarmElement*> SwarmElementPack::getMembers() {
    return members;
}
