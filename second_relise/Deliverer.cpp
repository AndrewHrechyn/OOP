#include "Deliverer.hpp"

#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

    int Deliverer::getOwnMark() {
        return ownMark;
    }

    int Deliverer::getAward() {
        return awardBonus;
    }

    int Deliverer::getDelivererPassword() {
        return delivererPassword;
    }

    int Deliverer::getSalary() {
        return salary_deliverer;
    }

    string Deliverer::getComplaints() {
        return ownComplaints;
    }

    void Deliverer::setComplaints(string new_complaints){
        ownComplaints = new_complaints;
    }



    void Deliverer::setOwnMark(int new_mark) {
        ownMark = new_mark;
    }
