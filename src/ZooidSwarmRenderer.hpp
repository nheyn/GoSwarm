//
//  ZooidSwarmRenderer.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#ifndef ZooidSwarmRenderer_hpp
#define ZooidSwarmRenderer_hpp

#include "ofMain.h"
#include "SwarmRenderer.hpp"
#include "ZooidManager.h"

class ZooidSwarmRenderer: public SwarmRenderer {
public:
    void initialize(float width, float height);
    
protected:
    virtual void updateSwarm(SwarmNode rootNode);
    
private:
    ZooidManager zooidManager;
};

#endif /* ZooidSwarmRenderer_hpp */
