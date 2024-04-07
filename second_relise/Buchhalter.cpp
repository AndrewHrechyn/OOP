#include "Buchhalter.hpp"

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

    int Buchhalter::getBuchhalterPassword() {
        return buchhalterPassword;
    }

    int Buchhalter::getSalary() {
        return salary_buchhalter;
    }

    long long Buchhalter::getFullSalary() {
        return fullsalary;
    }
    void Buchhalter::setFullSalary(long long new_fullsalary){
        fullsalary = new_fullsalary;
    }

    void Buchhalter::addWorker(string name, string surname, int id, int salary, int mark) {
        Deliverers new_deliverer;
        new_deliverer.name = name;
        new_deliverer.surname = surname;
        new_deliverer.id = id;
        new_deliverer.salary = salary;
        new_deliverer.mark = mark;
        deliverers.push_back(new_deliverer);
    }

    void Buchhalter::printAllWorkers() {
        for (int i = 0; i < deliverers.size(); i++) {
            cout << "Name: " << deliverers[i].name << endl;
            cout << "Surname: " << deliverers[i].surname << endl;
            cout << "ID: " << deliverers[i].id << endl;
            cout << "Salary: " << deliverers[i].salary << endl;
            cout << "Mark: " << deliverers[i].mark << endl;
            cout << endl;
        }
    }

    void Buchhalter::deleteWorker(int id) {
        for (int i = 0; i < deliverers.size(); i++) {
            if (deliverers[i].id == id) {
                deliverers.erase(deliverers.begin() + i);
                break;
            }
        }
    }

    void Buchhalter::setSalary(int id, int new_salary) {
        for (int i = 0; i < deliverers.size(); i++) {
            if (deliverers[i].id == id) {
                deliverers[i].salary = new_salary;
                break;
            }
        }
    }


    void Buchhalter::giveCheck_for_Bad_work(int id, int check_for_bad_work) {
        for (int i = 0; i < deliverers.size(); i++) {
            if (deliverers[i].id == id) {
                deliverers[i].salary = deliverers[i].salary - check_for_bad_work;
                break;
            }
        }
    }

    void Buchhalter::giveCheck_for_Good_work(int id, int check_for_good_work){
        for (int i = 0; i < deliverers.size(); i++) {
            if (deliverers[i].id == id) {
                deliverers[i].salary = deliverers[i].salary + check_for_good_work;
                break;
            }
        }
    }


    //написати хеш_таблицю для знаходження працівника-доставщика

