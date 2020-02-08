//
// Created by dminzi-ldt on 1/20/20.
//

#include "newMap.h"

int Map::index_of(const KeyType& key) const {
    int i(-1);
    for (int n(0); n < curr_size; n++) {
        if (kvp[n].key_m == key) {
            if (kvp[n+1].key_m == key) {  // <- needed cus "" always default
                break;
            }
            i = n;
            break;
        }
    }
    return i;
}

Map::Map(int size) : curr_size(0) {
    kvp = new key_value[size];
    max_size = size;
}

Map::Map(const Map& other) {
    max_size = other.max_size;
    curr_size = other.curr_size;
    kvp = new key_value[max_size];
    for (int i(0); i < max_size; i++) {
        kvp[i].key_m = other.kvp[i].key_m;
        kvp[i].value_m = other.kvp[i].value_m;
    }
}

Map& Map::operator=(const Map& other) {
    if (this == &other) {
        return *this;
    }
    delete [] kvp;
    max_size = other.max_size;
    kvp = new key_value[max_size];
    for (int i(0); i < other.size(); i++) {
        KeyType k_other;
        ValueType v_other;
        other.get(i, k_other, v_other);
        insert(k_other, v_other);
    }
    return *this;
}

Map::~Map() {
    delete [] kvp;
}

bool Map::empty() const { return curr_size == 0; }

int Map::size() const{ return curr_size; }

bool Map::contains(const KeyType& key) const { return index_of(key) != -1; }

bool Map::get(const KeyType& key, ValueType& value) const {
    bool result(false);
    if (contains(key)) {
        value = kvp[index_of(key)].value_m;
        result = true;
    }
    return result;
}

bool Map::get(int i, KeyType& key, ValueType& value) const {
    bool result(false);
    if (size() > i && i >= 0) { // make sure this bool works for case of 1 kv
        key = kvp[i].key_m;
        value = kvp[i].value_m;
        result = true;
    }
    return result;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
    bool result(false);
    if (size() < max_size && !contains(key)) {
        kvp[curr_size].key_m = key;
        kvp[curr_size].value_m = value;
        curr_size++;
        result = true;
    }
    return result;
}

bool Map::update(const KeyType& key, const ValueType& value) {
    bool result(false);
    if (contains(key)) {
        kvp[index_of(key)].value_m = value;
        result = true;
    }
    return result;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
    bool result(false);
    contains(key) ? result = update(key, value) : result = insert(key, value);
    return result;
}

bool Map::erase(const KeyType& key) {
    bool result(false);
    if (contains(key)) {
        std::swap(kvp[curr_size-1], kvp[index_of(key)]);
        curr_size--;
        result = true;
    }
    return result;
}

void Map::swap(Map& other) {
    std::swap(kvp, other.kvp);
    std::swap(curr_size, other.curr_size);
    std::swap(max_size, other.max_size);
}