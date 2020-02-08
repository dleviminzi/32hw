//
// Created by dminzi-ldt on 1/18/20.
//

#include "Map.h"

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

Map::Map() : curr_size(0) {}

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
    if (size() < DEFAULT_MAX_ITEMS && !contains(key)) {
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
}