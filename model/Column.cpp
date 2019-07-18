//
// Created by kek on 18.07.19.
//

#include "Column.h"
#include "RelationalSchema.h"
#include <utility>

using namespace std;

Column::Column(RelationalSchema *schema, string name, int index):
    Vertical(schema, index + 1),
    name(std::move(name)),
    index(index){
    columnIndices.set(index);
}

int Column::getIndex() { return index;}

string Column::getName() { return name; }

string Column::toString() { return "[" + name + "]";}

bool Column::operator==(const Column &rhs) {
    if (this == &rhs) return true;
    return index == rhs.index && schema == rhs.schema;
}