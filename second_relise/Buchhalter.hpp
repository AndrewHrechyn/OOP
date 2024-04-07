#ifndef BUCHHALTER_H
#define BUCHHALTER_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#include "Person.hpp"
using namespace std;

struct Deliverers {
    string name;
    string surname;
    int id;
    int salary;
    int mark;
};

class Buchhalter : public Person {
private:
    
    int buchhalterPassword = 33333;
    int salary_buchhalter = 3456789;
    long long fullsalary = 100000000000000000;
    vector<Deliverers> deliverers;

public:
    int getBuchhalterPassword();
    int getSalary();
    long long getFullSalary();
    void setFullSalary(long long new_fullsalary);
    void addWorker(string name, string surname, int id, int salary, int mark);
    void printAllWorkers();
    void deleteWorker(int id);
    void setSalary(int id, int new_salary);
    void giveCheck_for_Bad_work(int id, int check_for_bad_work);
    void giveCheck_for_Good_work(int id, int check_for_good_work);
};


#endif