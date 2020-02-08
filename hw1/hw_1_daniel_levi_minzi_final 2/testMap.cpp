#include <iostream>
#include <cassert>
#include "Map.h"

int main() {
    KeyType ke;
    ValueType ve;
    Map te;
    te.insert("lalala", 1);
    te.insert("aad", 2);
    te.insert("la", 3);
    te.erase("la");
    te.erase("aad");
    std::cout << "should be 1: " << te.contains("lalala") << std::endl;
    // std::cout << te.get(0, ke, ve) << ke << ve << std::endl;
    std::cout << "should be 0: " << te.contains("la") << "\nshould be 0: " << te.contains("aad") << std::endl;

    Map La;
    std::cout << "should be 1: " << La.empty() << std::endl;
    std::cout << "should be 0: " << La.size() << std::endl;
    La.insert("Laura", 10);
    std::cout << "should be 1: " << La.size() << std::endl;
    std::cout << "should be 0: " << La.empty() << std::endl;
    std::cout << "should be 0: " << La.insert("Laura", 15) << std::endl;

    Map m;
    m.insert("A", 10);
    m.insert("B", 44);
    m.insert("C", 10);
    std::string all;
    double total = 0;
    for (int n = 0; n < m.size(); n++) {
        std::string k;
        double v;
        m.get(n, k, v);
        all += k;
        total += v;
    }
    std::cout << all << total << std::endl;
    assert(m.size() == 3);
    assert(m.contains("A"));
    assert(!m.update("Z", 123));
    assert(m.update("A", 12));
    std::string all2;
    double total2 = 0;
    for (int n = 0; n < m.size(); n++) {
        std::string k;
        double v;
        m.get(n, k, v);
        all2 += k;
        total2 += v;
    }
    std::cout << all2 << total2 << std::endl;

    Map g;  // maps strings to doubles
    assert(g.empty());
    ValueType v = -1234.5;
    assert( !g.get("abc", v)  &&  v == -1234.5); // v unchanged by get failure
    g.insert("xyz", 9876.5);
    std::cout << "should be 1: " << g.insertOrUpdate("xyz", 100) << std::endl;
    double l;
    g.get("xyz", l);
    std::cout << "should be 100: " << l << std::endl;
    assert(g.insertOrUpdate("lala", 5));
    assert(g.size() == 2);
    assert(g.insertOrUpdate("lala", 5));
    assert(g.insertOrUpdate("lala", 6));

    Map gpas;
    gpas.insert("Fred", 2.956);
    assert(!gpas.contains(""));
    gpas.insert("Ethel", 3.538);
    gpas.insert("", 4.000);
    gpas.insert("Lucy", 2.956);
    assert(gpas.contains(""));
    gpas.erase("Fred");
    std::cout << "should be 1: " << gpas.contains("Lucy") << std::endl;
    std::cout << "should be 1: " << gpas.contains("Ethel") << std::endl;
    std::cout << "should be 1: " << gpas.contains("") << std::endl;
    std::cout << "should be 0: " << gpas.contains("Fred") << std::endl;

    assert(gpas.size() == 3  &&  gpas.contains("Lucy")  &&  gpas.contains("Ethel")  &&
           gpas.contains(""));

    Map gpas2;
    gpas2.insert("Fred", 2.956);
    gpas2.insert("Ethel", 3.538);
    double q;
    std::string k1;
    assert(gpas.get(1,k1,q)  &&  (k1 == "Fred"  ||  k1 == "Ethel"));
    std::string k2;
    assert(gpas.get(1,k2,q)  &&  k2 == k1);

    std::cout << "SWAP" << std::endl;
    Map m1;
    m1.insert("m1a", 1);
    m1.insert("m1b", 1);
    Map m2;
    m2.insert("m2a", 2);
    m2.insert("m2b", 2);
    m2.insert("m2c", 2);
    m2.insert("m2d", 2);
    std::cout << "m2: " << m2.size() << "\n" << "m1: " << m1.size() << std::endl;
    std::cout << "UNSWAP" << std::endl;
    m1.swap(m2);
    std::cout << "m2: " << m2.size() << "\n" << "m1: " << m1.size() << std::endl;
    for (int n = 0; n < m1.size(); n++) {
        std::string k;
        double v;
        m1.get(n, k, v);
        std::cout << "M1: " << k << " " << v << std::endl;
    }
    for (int n = 0; n < m2.size(); n++) {
        std::string k;
        double v;
        m2.get(n, k, v);
        std::cout << "M2: " <<  k << " " << v << std::endl;
    }
    assert(m1.size() == 4  &&  m1.contains("m2a")  &&  m1.contains("m2b")  &&
           m2.size() == 2  &&  m2.contains("m1a"));
    m2.swap(m1);
    for (int n = 0; n < m1.size(); n++) {
        std::string k;
        double v;
        m1.get(n, k, v);
        std::cout << "M1: " << k << " " << v << std::endl;
    }
    for (int n = 0; n < m2.size(); n++) {
        std::string k;
        double v;
        m2.get(n, k, v);
        std::cout << "M2: " <<  k << " " << v << std::endl;
    }
    assert(m2.size() == 4  &&  m2.contains("m2a")  &&  m2.contains("m2b")  &&
           m1.size() == 2  &&  m1.contains("m1a"));

    // test for map being full (change DEFAULT_MAX_ITEMS TO 5 and uncomment

    /*
    Map m;  // maps ints to strings
    assert(m.empty());
    ValueType v = "Ouch";
    assert( !m.get(42, v)  &&  v == "Ouch"); // v unchanged by get failure
    m.insert(123456789, "Wow!");
    assert(m.size() == 1);
    KeyType k = 9876543;
    assert(m.get(0, k, v)  &&  k == 123456789  &&  v == "Wow!");
    std::cout << "Passed all tests" << std::endl;
     */
}