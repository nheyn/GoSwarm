//
//  SwarmComponent.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#ifndef SwarmComponent_hpp
#define SwarmComponent_hpp

#include "ofMain.h"
#include "SwarmElement.hpp"

class SwarmComponent {
public:
    vector<SwarmElement*> render();
};

class ComponentSwarmElement: public SwarmElement {
public:
    ComponentSwarmElement(float _width, float _height, ofVec2f _position, ofColor _color, SwarmComponent* _component);
    vector<SwarmElement*> render();
    virtual vector<BotSpec> getBots();
private:
    SwarmComponent* component;
};

#endif /* SwarmComponent_hpp */
