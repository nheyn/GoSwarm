//
//  GoBowl.hpp
//  GoSwarm
//
//  Created by Nicholas Heyn on 10/22/18.
//

#ifndef GoBowl_hpp
#define GoBowl_hpp

#include "ZooidComponent.hpp"

class GoBowl: public ZooidComponent {
public:
    GoBowl(ofColor _color);
    virtual void componentWillMount();
    virtual void componentWillUpdate(vector<unsigned int> prevIds, Bound prevBound);
    virtual ZooidPack render();
    
private:
    ofColor color;
    map<unsigned int, ofVec2f> locations;
};

#endif /* GoBowl_hpp */
