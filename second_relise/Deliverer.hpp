#ifndef DELIVERER_H
#define DELIVERER_H

#include "Person.hpp"

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Deliverer : public Person {
private:
    int ownMark;
    int awardBonus;
    int salary_deliverer;
    int delivererPassword = 11111;
    string ownComplaints;
public:
    int getOwnMark();
    int getAward();
    int getDelivererPassword();
    int getSalary();
    void setOwnMark(int new_mark);


    void setComplaints(string new_complaints);


    string getComplaints();
};


#endif