#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "Manager.hpp"
#include "Customer.hpp"
#include "Deliverer.hpp"

using namespace std;


class View {
public:
    static void displayRestaurants( Manager& manager) {
        manager.printAllInfoRestaurants();
    }

    static void displayDeliveryStatus( Deliverer& deliverer) {
        cout << "Delivery Status: " << deliverer.getOwnMark() << "/10" << endl;
    }

    static void displayCustomerInfo( Customer& customer) {
        cout << "Customer Email: " << customer.getCustomerEmail() << endl;
        cout << "Customer Complaints: " << customer.getComplaints() << endl;
    }

    
    
    static vector<pair<string, int>> displayMenu(Manager& manager, string& restaurantName) {
        return manager.findRestaurant(restaurantName);
    }

};


class Controller {
private:
    Manager manager;
    Customer customer;
    Deliverer deliverer;

public:
    Controller(Manager& m,  Customer& c,  Deliverer& d): manager(m), customer(c), deliverer(d) {}

    void addRestaurant(string& restaurantName, string& address, string& hoursOfWork, string& gmail, vector<pair<string, int>>& menu) {
        manager.addRestaurant(restaurantName, address, hoursOfWork, gmail, menu);
    }

    void viewRestaurants() {
        View::displayRestaurants(manager);
    }

    void viewDeliveryStatus() {
        View::displayDeliveryStatus(deliverer);
    }

    void viewCustomerInfo() {
        View::displayCustomerInfo(customer);
    }

    void setRate_for_Deliverer(int rate) {
        deliverer.setOwnMark(rate);
    }

    void setComplaints_for_Deliverer(string complaints) {
        deliverer.setComplaints(complaints);
    }



    // Інші методи для управління моделями і виглядами...
};