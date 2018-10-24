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

ofVec2f convertPosition(ElementBound bound, ofVec2f position);
ElementBound convertBound(ElementBound outerBound, ElementBound innerBound);

class SwarmElement {
public:
    SwarmElement(float _width, float _height, ofVec2f _position);
    ElementBound getBound();
    virtual ~SwarmElement() = default;
    
protected:
    ElementBound bound;
};

class SwarmElementBot: public SwarmElement {
public:
    SwarmElementBot(float _size, ofVec2f _center, ofColor _color);
    BotSpec getBot();
    
private:
    ofColor color;
};

class SwarmElementPack: public SwarmElement {
public:
    SwarmElementPack(float _width, float _height, ofVec2f _position, vector<SwarmElement*> _members);
    vector<SwarmElement*> getMembers();
    
private:
    vector<SwarmElement*> members;
};

#endif /* SwarmElement_hpp */
