//
//  ZooidComponent.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/21/18.
//

#include "ZooidComponent.hpp"

void ZooidComponent::preformMount(vector<unsigned int> _ids, Bound _bound) {
    ids = _ids;
    bound = _bound;
    
    componentWillMount();
}

void ZooidComponent::preformUpdate(vector<unsigned int> _ids, Bound _bound) {
    vector<unsigned int> prevIds = ids;
    Bound prevBounds = bound;
    
    ids = _ids;
    bound = _bound;
    
    componentWillUpdate(prevIds, prevBounds);
}

// NOOP - should be subclassed
void ZooidComponent::componentWillMount() {}
void ZooidComponent::componentWillUpdate(vector<unsigned int> prevIds, Bound prevBound) {}
ZooidPack ZooidComponent::render() { return {}; }

