#include "Person.hpp"

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

    void Person::setName(string new_name) {
        name = new_name;
    }

    string Person::getName() {
        return name;
    }
    void Person::showName(){
        cout << name;
    }

    void Person::setSurName(string new_surname) {
        surname = new_surname;
    }

    string Person::getSurName() {
        return surname;
    }
    void Person::showSurName(){
        cout << surname;
    }
