#pragma once

#include <chrono>
#include <iostream>
#include <iomanip>
#include <list>
#include <memory>

#include "ColumnCombination.h"
#include "ColumnData.h"
#include "ColumnLayoutRelationData.h"
#include "RelationalSchema.h"
#include "CMAXSet.h"
#include "MAXSet.h"

class CMAXGen{
private:
    std::set<CMAXSet> cmaxSets;
    std::set<MAXSet> maxSets;
    const RelationalSchema* schema;
    void MaxSetsGenerate(std::set<Vertical> agreeSets);
    void CMaxSetsGenerate();
public:
    CMAXGen(const RelationalSchema* schema) : schema(schema){};
    CMAXGen() = default;
    ~CMAXGen() = default;
    void execute(std::set<Vertical> agreeSets);
    std::set<CMAXSet> getCmaxSets(){
        return this->cmaxSets;
    }
    std::set<MAXSet> getMaxSets(){
        return this->maxSets;
    }
};