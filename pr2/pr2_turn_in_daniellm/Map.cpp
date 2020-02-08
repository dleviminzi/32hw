#include "Map.h"

// standard constructor
Map::Map() : map_size(0) {
    dummy.next = nullptr;
    dummy.prev = nullptr;
}

// copy constructor
Map::Map(const Map &other) {
    map_size = 0;
    dummy.next = nullptr;
    dummy.prev = nullptr;
    KeyType k;
    ValueType v;
    int ms = 0;

    // get k/v pairs and place them in the map
    while (ms <= other.map_size) {
        other.get(ms, k, v);
        insert(k, v);
        ms++;
    }
}

// destructor
Map::~Map() {
    int m = map_size;
    KeyType k;
    ValueType v;

    // until no nodes exist, call erase to delete node
    while (!empty()) {
        get(m, k, v);
        erase(k);
        m--;
    }
}

// assignment operator
Map& Map::operator=(const Map &other) {
    // ensure that we do not erase map prematurely
    if (this != &other) {
        int m = map_size;
        KeyType k;
        ValueType v;
        // erasing map as done in destructor
        while (!empty()) {
            get(m, k, v);
            erase(k);
            m--;
        }

        // re initializing dummy node
        dummy.next = nullptr;
        dummy.prev = nullptr;

        // copying nodes from other map to cleaned map
        int ms = other.map_size - 1;
        while (ms >= 0) {
            other.get(ms, k, v);
            insert(k, v);
            ms--;
        }
    }
    return *this;
}

// helper function to loop through and find a node using its key
Map::node* Map::find_key(const KeyType &key) const {
    node *p;
    for (p=dummy.next; p!= nullptr && p->key_m != key && p != &dummy; p = p->next);
    return p;
}

bool Map::insert(const KeyType& key, const ValueType& value) {
    bool result(false);
    if (!contains(key)) {
        // first make a new node "tmp" and store the k/v pair
        node* new_node = new node;
        new_node->key_m = key;
        new_node->value_m = value;

        // if empty  [new_node] <- [dummy] <- [new_node]
        if (empty()) {
            dummy.next = new_node;
            new_node->prev = &dummy;
        }
        // not empty [curr_last] -><- [new node]
        else if (dummy.prev != nullptr) {
            node* curr_last = dummy.prev;
            curr_last->next = new_node;
            new_node->prev = curr_last;
        }

        // glue new node to end of dummy [new_node] -><- [dummy]
        dummy.prev = new_node;
        new_node->next = &dummy;

        map_size++;
        result = true;
    }
    return result;
}

int Map::size() const { return map_size; }

bool Map::empty() const { return !map_size; }  // only true when map_size 0

// function returns true if key in map
bool Map::contains(const KeyType &key) const {
    bool result(false);
    node* p = find_key(key);
    if (p != nullptr && p != &dummy) {
        result = true;
    }
    return result;
}

// finds the key in the map and then changes the value to the one specified
bool Map::update(const KeyType& key, const ValueType& value) {
    bool result(false);

    // check if its there
    if (contains(key)) {
        find_key(key)->value_m = value;  // update value
        result = true;
    }
    return result;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
    bool result(false);
    // if the key is in the map then is updated and otherwise insert
    contains(key) ? result = update(key, value) : result = insert(key, value);
    return result;
}

bool Map::erase(const KeyType &key) {
    bool result(false);

    // check if key in map, glue prev to next and vice versa then delete node
    if (contains(key)) {
        node* a = find_key(key);
        // need to make sure more than one node
        if (map_size > 1) {
            node* b = a->prev;
            node* d = a->next;
            b->next = d;
            d->prev = b;
            map_size--;
            result = true;
        }
        // if there is only one node
        else {
            node* d = a->prev;
            d->next = nullptr;
            d->prev = nullptr;
            map_size--;
            result = true;
        }
        delete a;
    }
    return result;
}

// retrieve the v of some k
bool Map::get(const KeyType& key, ValueType& value) const {
    bool result(false);
    if (contains(key)) {
        value = find_key(key)->value_m;
        result = true;
    }
    return result;
}

bool Map::get(int i, KeyType& key, ValueType& value) const {
    bool result(false);
    if (i < map_size && i >= 0) { // checking to see if index makes sense
        node *p;
        p = dummy.next;
        int z(0);
        while (z < i) { // loop to index
            p = p->next;
            z++;
        }
        key = p->key_m; // when we get there, store results
        value = p->value_m;
        result = true;
    }
    return result;
}

void Map::swap(Map& other) {
    if (this != &other) { // make sure we dont goof it, then swap parameters
        std::swap(map_size, other.map_size);
        std::swap(dummy, other.dummy);
    }
}

bool combine(const Map& m1, const Map& m2, Map& result) {
    // first erase whatever is inside result
    int m = result.size();
    KeyType k_o;
    ValueType v_o;
    while (!result.empty()) {
        result.get(m, k_o, v_o);
        result.erase(k_o);
        m--;
    }

    bool res(true);
    int i(0);
    KeyType k;
    ValueType v;
    ValueType vc;

    // now loop through m1 and add to result, checking if its in m2 as well
    while (i < m1.size()) {
        m1.get(i, k, v);
        if (m2.contains(k)) {
            m2.get(k, vc);
            if (v != vc) {  // value mismatch for identical keys
                res = false;
                i++;
                continue;
            }
        }
        if (!result.contains(k)) {
            result.insert(k, v);
        }
        i++;
    }

    i = 0;
    // now we loop through m2 and add to result, performing the same check again
    while (i < m2.size()) {
        m2.get(i, k, v);
        if (m1.contains(k)) {
            m1.get(k, vc);
            if (v != vc) {  // value mismatch for identical keys
                res = false;
                i++;
                continue;
            }
        }
        if (!result.contains(k)) {
            result.insert(k, v);
        }
        i++;
    }
    return res;
}

void reassign(const Map& m1, Map& result) {
    // first we erase everything in result map
    int m = result.size();
    KeyType k_o;
    ValueType v_o;
    while (!result.empty()) {
        result.get(m, k_o, v_o);
        result.erase(k_o);
        m--;
    }

    KeyType k;
    ValueType v;
    ValueType vc;
    int i = 0;

    // loop through our map and insert k of curr and v of next into result
    while (i < m1.size()) {
        if (m1.get(i+1, k, vc)) {
            m1.get(i, k, v);
            result.insert(k, vc);
        }
        else {  // previous get will fail when i > map_size => curr = last node
            m1.get(0, k, vc); // set last node value to first node value
            m1.get(i, k, v);
            result.insert(k, vc);
        }
        i++;
    }
}
