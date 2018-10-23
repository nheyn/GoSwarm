//
//  Table.cpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/21/18.
//

#include "Table.hpp"

// --- Helper functions ---
vector<unsigned int> getBowlZooids(vector<unsigned int> tableIds, ofColor stoneColor) {
    if(stoneColor == ofColor::black) {
        vector<unsigned int> blackIds(tableIds.begin(), tableIds.begin() + (tableIds.size() / 2));
        return blackIds;
    }
    else if (stoneColor == ofColor::white) {
        vector<unsigned int> whiteIds(tableIds.begin() + (tableIds.size() / 2), tableIds.end());
        return whiteIds;
    }
    else {
        throw invalid_argument("Invalid stone color");
    }
}

Bound getBowlBound(Bound tableBound, ofColor stoneColor) {
    float bowlWidth = tableBound.width / 5;
    float bowlHeight = tableBound.height / 3;
    
    ofVec2f pos;
    if(stoneColor == ofColor::black) {
        pos = tableBound.pos;
    }
    else if (stoneColor == ofColor::white) {
        pos.x = tableBound.pos.x;
        pos.y = tableBound.pos.y + (tableBound.height - bowlHeight);
    }
    else {
        throw invalid_argument("Invalid stone color");
    }
    
    return {
        .width = bowlWidth,
        .height = bowlHeight,
        .pos = pos,
    };
}

// --- Table methods ---
Table::Table() {
    blackBowl = new GoBowl(ofColor::black);
    whiteBowl = new GoBowl(ofColor::white);
}

Table::~Table() {
    delete blackBowl;
    delete whiteBowl;
}

void Table::componentWillMount() {
    blackBowl->preformMount(getBowlZooids(ids, ofColor::black), getBowlBound(bound, ofColor::black));
    whiteBowl->preformMount(getBowlZooids(ids, ofColor::white), getBowlBound(bound, ofColor::white));
}

void Table::componentWillUpdate(vector<unsigned int> prevIds, Bound prevBound) {
    //TODO, check if something has changed to improve performace
    blackBowl->preformUpdate(getBowlZooids(ids, ofColor::black), getBowlBound(bound, ofColor::black));
    whiteBowl->preformUpdate(getBowlZooids(ids, ofColor::white), getBowlBound(bound, ofColor::white));
}

ZooidPack Table::render() {
    return {
        .packs = {
            blackBowl->render(),
            whiteBowl->render()
        }
    };
}
