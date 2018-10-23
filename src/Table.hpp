//
//  Table.hpp
//  GoSwarm
//
//  Created by Nick Heyn on 10/21/18.
//

#ifndef Table_hpp
#define Table_hpp

#include "ZooidComponent.hpp"
#include "GoBowl.hpp"

class Table: public ZooidComponent {
public:
    Table();
    ~Table();
    virtual void componentWillMount();
    virtual void componentWillUpdate(vector<unsigned int> prevIds, Bound prevBound);
    virtual ZooidPack render();
    
private:
    GoBowl* blackBowl;
    GoBowl* whiteBowl;
};

#endif /* Table_hpp */
