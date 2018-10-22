//
//  ZooidTouchHandler.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/22/18.
//

#include "ZooidTouchHandler.hpp"

// NOOP - theses should be subclassed
void ZooidTouchHandler::onStartTouch(unsigned int id) {}
void ZooidTouchHandler::onEndTouch(unsigned int id) {}


// -- ZooidMergedTouchHandler methods ---
ZooidMergedTouchHandler::ZooidMergedTouchHandler(vector<ZooidTouchHandler> _touchHandlers) {
    touchHandlers = _touchHandlers;
}

void ZooidMergedTouchHandler::onStartTouch(unsigned int id) {
    for (int i=0; i<touchHandlers.size(); i++) {
        touchHandlers[i].onStartTouch(id);
    }
}

void ZooidMergedTouchHandler::onEndTouch(unsigned int id) {
    for (int i=0; i<touchHandlers.size(); i++) {
        touchHandlers[i].onEndTouch(id);
    }
}
