//
//  Table.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/21/18.
//

#include "Table.hpp"

ZooidPack Table::render() {
    // This only works when bound.pos = { 0, 0 }
    float xCenter = 5 * (bound.width / 6);
    
    vector<ZooidDescription> members;
    for(int i=0; i < ids.size(); i++) {
        unsigned int id = ids[i];
        float yOffset = bound.height / 4;
        
        if (i % 2 == 0) {
            members.push_back({ .id=id, .pos={xCenter, yOffset}, .color=ofColor::black });
        }
        else {
            members.push_back({ .id=id, .pos={xCenter, (yOffset * 3)}, .color=ofColor::white });
        }
    }
    return { .members = members };
}
