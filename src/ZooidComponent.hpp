//
//  ZooidComponent.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/21/18.
//

#ifndef ZooidComponent_hpp
#define ZooidComponent_hpp

#include "ofMain.h"
#include "ZooidManager.h"
#include "ZooidTouchHandler.hpp"

typedef struct {
    unsigned int id;
    ofVec2f pos;
    ofColor color;
    ZooidTouchHandler* touchHandler;
} ZooidDescription;

typedef struct ZooidPack {
    vector<ZooidDescription> members;
    vector<ZooidPack> packs;
    ZooidTouchHandler* touchHandler;
} ZooidPack;

typedef struct {
    float width;
    float height;
    ofVec2f pos;
} Bound;

class ZooidComponent {
public:
    void preformMount(vector<unsigned int> _ids, Bound _bound);
    void preformUpdate(vector<unsigned int> _ids, Bound _bound);
    
    virtual void componentWillMount();
    virtual void componentWillUpdate(vector<unsigned int> prevIds, Bound prevBound);
    virtual ZooidPack render();
    
protected:
    vector<unsigned int> ids;
    Bound bound;
};

#endif /* ZooidComponent_hpp */
