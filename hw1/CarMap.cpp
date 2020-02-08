//
// Created by dminzi-ldt on 1/20/20.
//

#include <iostream>
#include "CarMap.h"

CarMap::CarMap() {}

bool CarMap::addCar(std::string license) {
    bool result(false);
    if (!c_map.contains(license) && c_map.size() != 240) {
        c_map.insert(license, 0);
        result = true;
    }
    return result;
}

double CarMap::miles(std::string license) const {
    double result(-1);
    if (c_map.contains(license)) {
        c_map.get(license, result);
    }
    return result;
}

bool CarMap::drive(std::string license, double distance) {
    bool result(false);
    if (!c_map.contains(license) || miles(license) < 0) {}
    else {
        c_map.update(license, distance + miles(license));
        result = true;
    }
    return result;
}

int CarMap::fleetSize() const { return c_map.size(); }

void CarMap::print() const {
    int size = c_map.size();
    for (int i(0); i < size; i++) {
        std::string lic;
        double mil;
        c_map.get(i, lic, mil);
        std::cout << lic << " " << mil << std::endl;
    }
}
