//
//  ZooidTouchHandler.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/22/18.
//

#ifndef ZooidTouchHandler_hpp
#define ZooidTouchHandler_hpp

#include "ofMain.h"

class ZooidTouchHandler {
public:
    virtual void onStartTouch(unsigned int id);
    virtual void onEndTouch(unsigned int id);
};

class ZooidMergedTouchHandler {
public:
    ZooidMergedTouchHandler(vector<ZooidTouchHandler> _touchHandlers);
    virtual void onStartTouch(unsigned int id);
    virtual void onEndTouch(unsigned int id);
    
private:
    vector<ZooidTouchHandler> touchHandlers;
};

#endif /* ZooidTouchHandler_hpp */
