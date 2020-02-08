//
// Created by dminzi-ldt on 1/20/20.
//

#ifndef HW_1_DANIEL_LEVI_MINZI_CARMAP_H
#define HW_1_DANIEL_LEVI_MINZI_CARMAP_H

#include <string>
#include "newMap.h"

class CarMap {
public:
    CarMap();
            // creates empty car map
    bool addCar(std::string license);
            // if car with given plate is not in the map and the map is not full
            // then add an entry for the car (0 miles driven) and r_true
            // else make no change and r_false
    double miles(std::string license) const;
            // if car with given plate in map
            // then r_miles_driven
            // else r_-1
    bool drive(std::string license, double distance);
            // if no car with license in map or distance is negative
            // make no change r_false
            // else increase number of miles driven by distance parameter and
            // r_true
    int fleetSize() const;
            // r_num_cars_in_map
    void print() const;
            // write "license miles" per line for each car in map
private:
    Map c_map;
};


#endif //HW_1_DANIEL_LEVI_MINZI_CARMAP_H
