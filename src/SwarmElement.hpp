//
//  SwarmElement.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#ifndef SwarmElement_hpp
#define SwarmElement_hpp

#include "ofMain.h"

typedef struct {
    ofVec2f position;
    ofColor color;
} BotSpec;

typedef struct {
    float width;
    float height;
    ofVec2f position;
} ElementBound;

class SwarmElement {
public:
    SwarmElement(float _width, float _height, ofVec2f _position, ofColor _color);
    ElementBound getBound();
    virtual ~SwarmElement() = default;
    
protected:
    ElementBound bound;
    ofColor color;
};

class BotSwarmElement: public SwarmElement {
public:
    BotSwarmElement(float _size, ofVec2f _center, ofColor _color);
    BotSpec getBot();
};

class PackSwarmElement: public SwarmElement {
public:
    PackSwarmElement(float _width, float _height, ofVec2f _position, ofColor _color, vector<SwarmElement*> _members);
    vector<SwarmElement*> getMembers();
    
private:
    vector<SwarmElement*> members;
};

#endif /* SwarmElement_hpp */
