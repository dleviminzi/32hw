//
// Created by dminzi-ldt on 1/18/20.
//

#ifndef PR_2_DANIEL_LEVI_MINZI_MAP_H
#define PR_2_DANIEL_LEVI_MINZI_MAP_H
#include <string>

using KeyType = std::string;
using ValueType = double;

class Map {
public:
    Map();                // create an empty map (one with no key/value pairs)
    Map(const Map& other);
    ~Map();               // destructor
    Map& operator=(const Map& other);
    bool empty() const;   // if map is empty r_true else r_false
    int size() const;     // r_number of key/value pairs in the map
    bool insert(const KeyType& key, const ValueType& value);
            // if key != any_key_in_map
            // then add key/value pair to map and r_true
            // else make no change to the map and r_false
            // note: r_false => key is already in map
    bool update(const KeyType& key, const ValueType& value);
            // if key = any_key_in_map then make that key map to value instead
            // of whatever it had previously mapped to and r_true
            // else make no change and r_false
    bool insertOrUpdate(const KeyType& key, const ValueType& value);
            // if key = any_key_in_map then make that key map to value instead
            // of whatever it had previously mapped to and r_true
            // elif key != any_key_in_map & key/value pair can be added to map
            // then add key/value pair to map and r_true
            // else make no change to the map and r_false
            // note: r_false => key is not already in the map and the map is
            // past its fixed capacity
    bool erase(const KeyType& key);
            // if key = any_key_in_map then remove the associated key/value pair
            // and r_true
            // else make no change to the map r_false
    bool contains(const KeyType& key) const;
            // if key = any_key_in_map r_true
            // else r_false
    bool get(const KeyType& key, ValueType& value) const;
            // if key = any_key_in_map then value (above) = key/value_value
            // and r_true
            // else make no change to value and r_false
    bool get(int i, KeyType& key, ValueType& value) const;
            // if Map.size() > i >= o then key (above) = key/value_key
            // and value (above) = key/value_value and r_true
            // else don't modify key and value (above) and r_false
    void swap(Map& other);
            // exchange contents of this map with the other (above) map
private:
    int map_size;
    struct node {
        KeyType key_m;
        ValueType value_m;
        node* next;
        node* prev;
    };
    node dummy;
    node* find_key(const KeyType& key) const;
};

bool combine(const Map& m1, const Map& m2, Map& result);
        // combines two maps m1 and m2 and places the resulting map in result

void reassign(const Map& m, Map& result);
        // in this implementation, if should shift every value down one in a
        // in a circular way such that the first node gets the value of the last

#endif //PR_2_DANIEL_LEVI_MINZI_MAP_H
