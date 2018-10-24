//
//  ZooidSwarmRenderer.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#include "ZooidSwarmRenderer.hpp"

// --- Helper function ---
void renderNodeToZooids(SwarmNode node, ElementBound bound, ZooidManager* zooidManager) {
    if (node.isLeaf()) {
        SwarmNode::Leaf leaf = node.getLeaf();
        
        //TODO - get keys working better
        zooidManager->updateZooid((unsigned int)leaf.key, convertPosition(bound, leaf.position), leaf.color);
        return;
    }
    
    SwarmNode::Internal internal = node.getInternal();
    for(int i=0; i<internal.children.size(); i++) {
        renderNodeToZooids(internal.children[i], convertBound(bound, internal.bound), zooidManager);
    }
}

// --- ZooidSwarmRenderer methods ---
void ZooidSwarmRenderer::initialize(float width, float height) {
    zooidManager.initialize(width, height);
    zooidManager.useRealWorldCoordinates();
}

void ZooidSwarmRenderer::updateSwarm(SwarmNode node) {
    if (zooidManager.receiveInformation()) {
        renderNodeToZooids(
            node,
            {
                .width = zooidManager.getRealWorldWidth(),
                .height = zooidManager.getRealWorldHeight(),
                .position = { 0, 0 }
            },
            &zooidManager
        );
        
        zooidManager.setAssignmentMode(AssignmentMode::NaiveAssignment);
        zooidManager.sendUpdates();
    }
}
