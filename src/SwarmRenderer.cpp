//
//  SwarmRenderer.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#include "SwarmRenderer.hpp"

// -- Helper functions ---
SwarmNode getTreeFrom(SwarmElement* el);
SwarmNode getTreeFromElements(vector<SwarmElement*> els, ElementBound bound) ;

SwarmNode getTreeFrom(SwarmElement* el) {
    BotSwarmElement* bEl = dynamic_cast<BotSwarmElement*>(el);
    if (bEl != NULL) {
        BotSpec spec = bEl->getBot();
        
        return SwarmNode({
            .key = 0, //TODO, add keygen
            .position = spec.position,
            .color = spec.color
        });
    }
    
    PackSwarmElement* pEl = dynamic_cast<PackSwarmElement*>(el);
    if (pEl != NULL) {
        return getTreeFromElements(pEl->getMembers(), pEl->getBound());
    }
    
    ComponentSwarmElement* cEl = dynamic_cast<ComponentSwarmElement*>(el);
    if (pEl != NULL) {
        return getTreeFromElements(cEl->render(), cEl->getBound());
    }
    
    throw invalid_argument("Invalid SwarmElement subclass");
}

SwarmNode getTreeFromElements(vector<SwarmElement*> els, ElementBound bound) {
    vector<SwarmNode> children;
    for (int i=0; i<els.size(); i++) {
        children.push_back(getTreeFrom(els[i]));
    }
    
    return SwarmNode({
        .key = 0, //TODO, add keygen
        .children = children,
        .bound = bound,
    });
}

// -- SwarmRender node ---
SwarmNode::SwarmNode(SwarmNode::Internal _node) {
    type = internal;
    node = _node;
}

SwarmNode::SwarmNode(SwarmNode::Leaf _node) {
    type = leaf;
    node = _node;
}

SwarmNode::Internal SwarmNode::getInternal() {
    return boost::get<SwarmNode::Internal>(node);
}

SwarmNode::Leaf SwarmNode::getLeaf() {
    return boost::get<SwarmNode::Leaf>(node);
}

bool SwarmNode::isLeaf() {
    return type == leaf;
}

// -- SwarmRender methods ---
void SwarmRenderer::render(SwarmElement* rootEl) {
    updateSwarm(getTreeFrom(rootEl));
}

void SwarmRenderer::updateSwarm(SwarmNode rootNode) {
    throw logic_error("Cannot updateSwarm(): the SwarmRenderer should not instantiated directly, use one of the sublcasses");
}
