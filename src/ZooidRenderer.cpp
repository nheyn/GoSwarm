//
//  ZooidRenderer.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/22/18.
//

#include "ZooidRenderer.hpp"

// --- helper functions ---
typedef struct {
    vector<ZooidDescription> members;
    vector<ZooidTouchHandler*> touchHandlers;
} PackMemebers;
PackMemebers getAllPackMembers(ZooidPack pack) {
    vector<ZooidDescription> members = pack.members;
    vector<ZooidTouchHandler*> touchHandlers;
    for (int i=0; i<members.size(); i++) {
        // TODO, need to add id limit to these touch handlers
        touchHandlers.push_back(members[i].touchHandler);
    }
    
    for (int i=0; i<pack.packs.size(); i++) {
        PackMemebers subPack = getAllPackMembers(pack.packs[i]);
        
        members.insert(members.end(), subPack.members.begin(), subPack.members.end());
        
        // TODO, need to add id limit to these touch handlers
        touchHandlers.insert(touchHandlers.end(), subPack.touchHandlers.begin(), subPack.touchHandlers.end());
    }
    
    return { .members = members, .touchHandlers = touchHandlers };
}

void preformRender(ZooidComponent* root, ZooidManager* manager) {
    PackMemebers pack = getAllPackMembers(root->render());
    if (pack.members.size() > manager->getNbZooids()) {
        throw invalid_argument(
           "component has " +
           to_string(pack.members.size()) +
           " zooids and the manager only has " +
           to_string(manager->getNbZooids())
        );
    }
    
    // NOTE - pack.members.size() === 0 <-- START HERE
    for (int i=0; i<pack.members.size(); i++) {
        ZooidDescription member = pack.members[i];
        manager->updateZooid(member.id, member.pos, member.color);
    }
    
    //TODO, handle unussed zooids
    // manager->updateZooid(i, ofVec2f{ 0, 0 }, ofColor::red);
    //TODO, handle touch handlers
    // pack.touchHandlers
    
    manager->setAssignmentMode(AssignmentMode::NaiveAssignment);
    manager->sendUpdates();
}

vector<unsigned int> getAvailableZooids(ZooidManager* manager) {
    vector<unsigned int> ids(manager->getNbZooids());
    iota(ids.begin(), ids.end(), 0);
    
    return ids;
}

Bound getZooidsBound(ZooidManager* manager) {
    return {
        .width = manager->getRealWorldWidth(),
        .height = manager->getRealWorldHeight(),
        .pos = ofVec2f{ 0, 0 }
    };
}

// --- ZooidRenderer methods ---
void ZooidRenderer::initialize(int frameRate, float width, float height) {
    ofSetFrameRate(frameRate);
    manager.initialize(width, height);
    manager.useRealWorldCoordinates();
}

void ZooidRenderer::render(ZooidComponent* _root) {
    root = _root;
    
    root->preformMount(getAvailableZooids(&manager), getZooidsBound(&manager));
    preformRender(root, &manager);
}

void ZooidRenderer::checkForUpdates() {
    if (manager.receiveInformation()) {
        Bound bound = getZooidsBound(&manager);
        
        root->preformUpdate(getAvailableZooids(&manager), bound);
        preformRender(root, &manager);
    }
}
