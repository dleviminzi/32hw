#include "newMap.h"
#include "CarMap.h"
#include <iostream>
#include <cassert>

void test() {
    Map m;
    assert(m.insert("Fred", 2.956));
    assert(m.insert("Ethel", 3.538));
    assert(m.size() == 2);
    ValueType v = 42;
    assert(!m.get("Lucy", v) && v == 42);
    assert(m.get("Fred", v) && v == 2.956);
    v = 42;
    KeyType x = "Lucy";
    assert(m.get(0, x, v) &&
           ((x == "Fred" && v == 2.956) || (x == "Ethel" && v == 3.538)));
    KeyType x2 = "Ricky";
    assert(m.get(1, x2, v) &&
           ((x2 == "Fred" && v == 2.956) || (x2 == "Ethel" && v == 3.538)) &&
           x != x2);
}

/*
void test2()
{
    Map m;
    assert(m.insert(10, "diez"));
    assert(m.insert(20, "veinte"));
    assert(m.size() == 2);
    ValueType v = "cuarenta y dos";
    assert(!m.get(30, v)  &&  v == "cuarenta y dos");
    assert(m.get(10, v)  &&  v == "diez");
    v = "cuarenta y dos";
    KeyType x = 30;
    assert(m.get(0, x, v)  &&
           ((x == 10  &&  v == "diez")  ||  (x == 20  &&  v == "veinte")));
    KeyType x2 = 40;
    assert(m.get(1, x2, v)  &&
           ((x2 == 10  &&  v == "diez")  ||  (x2 == 20  &&  v == "veinte"))  &&
           x != x2);
}
*/

int main() {
    /* //key swap test
    test2();
     */
    /*                           MAP TEST                       */
    test();
    std::cout << "all tests passed" << std::endl;
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

    /*                           C_MAP TEST                 */
    CarMap foo;
    foo.addCar("l1");
    foo.addCar("l2");
    foo.addCar("l3");
    assert(foo.fleetSize() == 3);
    assert(foo.miles("l1") == 0);
    assert(foo.miles("lalala") == -1);
    foo.drive("l1", 1000);
    assert(foo.miles("l1") == 1000);
    foo.drive("l2", 438.987);
    foo.print();
    CarMap bar;
    bar.addCar("zipzip");
    bar.addCar("zoopzoop");
    bar.addCar("zapzap");
    bar.addCar("lionla");
    bar.drive("zipzip", 1000);
    bar.print();
    std::cout << "zipzip: " << bar.miles("zipzip") << "\n" << "fleetSize: " << bar.fleetSize() << std::endl;
    std::cout << "not in fleet: " << bar.miles("zizip") << std::endl;


    /*                           N_MAP TEST                 */
    Map a(1000);   // a can hold at most 1000 key/value pairs
    Map b(5);      // b can hold at most 5 key/value pairs
    Map c;         // c can hold at most DEFAULT_MAX_ITEMS key/value pairs
    KeyType k[6] = {"k1", "k2", "k3", "k4", "k5", "k6"};
    ValueType p  = 5;

    // No failures inserting pairs with 5 distinct keys into b
    for (int n = 0; n < 5; n++)
        assert(b.insert(k[n], p));

    c = b;
    for (int n = 0; n < b.size(); n++) {
        std::string k1;
        double v1;
        b.get(n, k1, v1);
        std::cout << "b: " <<  k1 << " " << v1 << std::endl;
    }
    for (int n = 0; n < c.size(); n++) {
        std::string ck1;
        double cv1;
        c.get(n, ck1, cv1);
        std::cout << "c: " <<  ck1 << " " << cv1 << std::endl;
    }

    // Failure if we try to insert a pair with a sixth distinct key into b
    assert(!b.insert(k[5], p));

    // When two Maps' contents are swapped, their capacities are swapped
    // as well:
    a.swap(b);
    assert(!a.insert(k[5], p)  &&  b.insert(k[5], p));

    ValueType x;
    Map r(b);
    r.get("k6", x);
    std::cout << "testing r.get: " << x << std::endl;
    Map o(a);
    assert(!o.insert(k[5], p));
    KeyType mkey;
    ValueType mvalue;
    std::cout << "should work: " << o.get(4, mkey, mvalue) << mkey << " " << mvalue << std::endl;
    std::cout << "should not work: " << a.get(6, mkey, mvalue) << std::endl;
}