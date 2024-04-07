#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include "Person.hpp"
#include <vector>
#include <string>

using namespace std;

// class Manager;

class Customer : public Person{
private:
    int customer_rate = 5;
    string email_customer = "customerEmail@example.com";
    string complaints = "NO complaints";

public:
    // void viewRestaurants_Menu(Manager& manager);
    int getCustomerRate();
    string getCustomerEmail();
    string getComplaints();
    string makeComplaint();
    };

#endif
