//
// Created by dminzi-ldt on 1/20/20.
//

#ifndef HW_1_DANIEL_LEVI_MINZI_NEWMAP_H
#define HW_1_DANIEL_LEVI_MINZI_NEWMAP_H

#include <string>

using KeyType = std::string;
using ValueType = double;
const int DEFAULT_MAX_ITEMS = 240;

class Map {
public:
    Map(int size=DEFAULT_MAX_ITEMS);
                          // create an empty map (one with no key/value pairs)
    Map(const Map& other); // copy constructor
    Map& operator=(const Map& other);
    ~Map(); // destructor
    bool empty() const;   // if map is empty r_true else r_false
    int size() const;     // r_number of key/value pairs in the map
    bool insert(const KeyType& key, const ValueType& value);
    // if key != any_key_in_map & if key/value pair can be added to map,
    // then add key/value pair to map and r_true
    // else make no change to the map and r_false
    // note: r_false => key is already in map, or the map is past its
    // fixed capacity
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
    int index_of(const KeyType& key) const;
    // if key = any_key_in_map then r_index_of_key_in_array
    // else r_0
    struct key_value {
        KeyType key_m;
        ValueType value_m;
    };
    int curr_size;
    int max_size;
    key_value* kvp;
};


#endif //HW_1_DANIEL_LEVI_MINZI_NEWMAP_H
