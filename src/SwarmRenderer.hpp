//
//  SwarmRenderer.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#ifndef SwarmRenderer_hpp
#define SwarmRenderer_hpp

#include <boost/variant.hpp>
#include "ofMain.h"
#include "SwarmElement.hpp"
#include "SwarmComponent.hpp"


class SwarmNode {
public:
    typedef struct {
        unsigned int key;
        vector<SwarmNode> children;
        ElementBound bound;
    } Internal;
    
    typedef struct {
        unsigned int key;
        ofVec2f position;
        ofColor color;
    } Leaf;
    
    SwarmNode(Internal _node);
    SwarmNode(Leaf _node);
    Internal getInternal();
    Leaf getLeaf();
    bool isLeaf();
    
    
private:
    enum { internal, leaf } type;
    boost::variant<Internal, Leaf> node;
};

class SwarmRenderer {
    
public:
    void render(SwarmElement* rootEl);
    virtual void updateSwarm(SwarmNode rootNode);
};

#endif /* SwarmRenderer_hpp */
