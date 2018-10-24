//
//  SwarmComponent.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#include "SwarmComponent.hpp"

// --- SwarmComponent methods ---
vector<SwarmElement*> SwarmComponent::render() {
    throw logic_error("Cannot render(): the SwarmElement should not instantiated directly, use one of the sublcasses");
}

// --- ComponentSwarmElement methods ---
ComponentSwarmElement::ComponentSwarmElement(float _width, float _height, ofVec2f _position, ofColor _color, SwarmComponent* _component)
: SwarmElement(_width, _height, _position, _color) {
    component = _component;
}

vector<SwarmElement*> ComponentSwarmElement::render() {
    return component->render();
}
