//
//  SwarmElementComponent.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#include "SwarmElementComponent.hpp"


SwarmElementComponent::SwarmElementComponent(float _width, float _height, ofVec2f _position, ofColor _color, SwarmComponent* _component)
: SwarmElement(_width, _height, _position, _color) {
    component = _component;
}

SwarmElement* SwarmElementComponent::render() {
    return component->render();
}
