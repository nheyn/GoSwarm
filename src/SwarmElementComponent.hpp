//
//  SwarmElementComponent.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#ifndef SwarmElementComponent_hpp
#define SwarmElementComponent_hpp

#include "ofMain.h"
#include "SwarmComponent.hpp"
#include "SwarmElement.hpp"

class SwarmElementComponent: public SwarmElement {
public:
    SwarmElementComponent(float _width, float _height, ofVec2f _position, ofColor _color, SwarmComponent* _component);
    SwarmElement* render();
    
private:
    SwarmComponent* component;
};

#endif /* SwarmElementComponent_hpp */
