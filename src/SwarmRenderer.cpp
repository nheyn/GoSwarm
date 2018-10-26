//
//  SwarmRenderer.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/23/18.
//

#include "SwarmRenderer.hpp"

// -- SwarmNode helper functions ---
SwarmNode getTreeFrom(SwarmElement* el, SwarmRenderer::KeyGen gen) {
    if (el == NULL) return;
    
    SwarmElementBot* bEl = dynamic_cast<SwarmElementBot*>(el);
    if (bEl != NULL) {
        BotSpec spec = bEl->getBot();
        
        return SwarmNode({
            .key = gen.nextKey(),
            .position = spec.position,
            .color = spec.color
        });
    }
    
    SwarmElementPack* pEl = dynamic_cast<SwarmElementPack*>(el);
    if (pEl != NULL) {
        vector<SwarmElement*> els = pEl->getMembers();
        vector<SwarmNode> children;
        for (int i=0; i<els.size(); i++) {
            children.push_back(getTreeFrom(els[i], gen));
        }
        
        return SwarmNode({
            .key = gen.nextKey(),
            .children = children,
            .bound = pEl->getBound(),
        });
    }
    
    SwarmElementComponent* cEl = dynamic_cast<SwarmElementComponent*>(el);
    if (pEl != NULL) {
        return SwarmNode(SwarmNode::Internal{
            .key = gen.nextKey(),
            .children = { getTreeFrom(cEl->render(), gen) },
            .bound = cEl->getBound(),
        });
    }
    
    throw invalid_argument("Invalid SwarmElement subclass");
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

// -- SwarmRender::KeyGen methods --
SwarmRenderer::KeyGen::KeyGen(unsigned int startIndex) {
    index = startIndex;
}

unsigned int SwarmRenderer::KeyGen::nextKey() {
    unsigned int currIndex = index;
    index += 1;
    
    return currIndex;
}

// -- SwarmRender methods ---
void SwarmRenderer::render(SwarmElement* _root) {
    root = _root;
    rerender();
}

void SwarmRenderer::rerender() {
    updateSwarm(getTreeFrom(root, KeyGen(0)));
}

void SwarmRenderer::updateSwarm(SwarmNode rootNode) {
    throw logic_error("Cannot updateSwarm(): the SwarmRenderer should not instantiated directly, use one of the sublcasses");
}
