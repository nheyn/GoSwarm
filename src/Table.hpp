//
//  Table.hpp
//  GoSwarm
//
//  Created by Nick Heyn on 10/21/18.
//

#ifndef Table_hpp
#define Table_hpp

#include "ZooidManager.h"
#include "ZooidComponent.hpp"

class Table: public ZooidComponent {
public:
    virtual ZooidPack render();
};

#endif /* Table_hpp */
