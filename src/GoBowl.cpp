//
//  GoBowl.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/22/18.
//

#include "GoBowl.hpp"

// -- helper functions --
map<unsigned int, ofVec2f> getLocations(vector<unsigned int> ids, Bound bound) {
    float xPadding = bound.width / 5;
    float yPadding = bound.height / 8;
    
    map<unsigned int, ofVec2f> locs;
    ofVec2f nextLoc = { bound.pos.x + xPadding, bound.pos.y + yPadding };
    for (int i=0; i<ids.size(); i++) {
        locs[ids[i]] = nextLoc;
        
        float nextY = nextLoc.y + yPadding;
        if (nextY < bound.pos.y + bound.height - yPadding) {
            nextLoc = { nextLoc.x, nextY };
        }
        else {
            float nextX = nextLoc.x + xPadding;
            if (nextX > bound.pos.x + bound.width) {
                throw invalid_argument("Given bound to small for the given Zooids");
            }
            
            nextLoc = { nextX, bound.pos.y + yPadding };
        }
    }
    return locs;
}

// -- GoBowl methods --
GoBowl::GoBowl(ofColor _color) {
    color = _color;
}

void GoBowl::componentWillMount() {
    locations = getLocations(ids, bound);
}

void GoBowl::componentWillUpdate(vector<unsigned int> prevIds, Bound prevBound) {
    //TODO, check if something has changed to improve performace
    locations = getLocations(ids, bound);
}

ZooidPack GoBowl::render() {
    vector<ZooidDescription> members;
    for (int i=0; i<ids.size(); i++) {
        unsigned int id = ids[i];
        /*//FOR TESTING, puts the first and second stone in the bowl's corner
        if (i == 0) {
            members.push_back({ .id = id, .pos = bound.pos, .color = color });
            continue;
        }
        else if (i == 1) {
            members.push_back({ .id = id, .pos = { bound.pos.x + bound.width, bound.pos.y + bound.height }, .color = color });
            continue;
        }//*/
        
        members.push_back({
            .id = id,
            .pos = locations[id],
            .color = color
        });
    }
    
    return { .members = members };
}

