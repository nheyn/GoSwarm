//
//  SwarmComponent.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#include "SwarmComponent.hpp"

SwarmElement* SwarmComponent::render() {
    throw logic_error("Cannot render(): the SwarmElement should not instantiated directly, use/create a subclass");
}
