#include "Map.h"
#include "Map.cpp"
#include "SingletonDriver.h"
#include <iostream>

using namespace std;

void singletonExample() {
    cout << "============ Test Singleton ==============="<< endl;
    auto m1 = Singleton::instance();
    auto m2 = Singleton::instance();

    if (m1 == m2) {
        cout <<"Singleton works, both have the same instance." << endl;
    } else {
        cout <<"Singleton failed, they are different instances." << endl;
    }

}
