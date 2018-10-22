//
//  ZooidRenderer.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/22/18.
//

#ifndef ZooidRenderer_hpp
#define ZooidRenderer_hpp

#include "ofMain.h"
#include "ZooidComponent.hpp"
#include "ZooidManager.h"

class ZooidRenderer {
public:
    void initialize(int frameRate, float width, float height);
    void render(ZooidComponent* _root);
    void checkForUpdates();
    
private:
    ZooidManager manager;
    ZooidComponent* root;
};

#endif /* ZooidRenderer_hpp */
