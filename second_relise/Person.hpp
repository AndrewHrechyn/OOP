#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Person {
private:
    string name;
    string surname;
public:
    void setName(string new_name);
    void showName();
    void setSurName(string new_surname);
    void showSurName();
    string getName();
    string getSurName();
};

#endif