//
// Created by kek on 18.07.19.
//

#pragma once

#include <string>

#include <boost/dynamic_bitset.hpp>

#include "model/RelationalSchema.h"

using std::string, boost::dynamic_bitset;

class Column {
friend RelationalSchema;

private:
    string name;
    int index;
    std::weak_ptr<RelationalSchema> schema;

public:
    Column(std::shared_ptr<RelationalSchema> schema, const string& name, int index) :
            name(std::move(name)),
            index(index),
            schema(schema) {}
    explicit operator Vertical() const;
    int getIndex() const;
    string getName() const;
    std::shared_ptr<RelationalSchema> getSchema();
    string toString() const;
    explicit operator std::string() const { return toString(); }
    bool operator==(const Column& rhs);
};