#include "Customer.hpp"

using namespace std;

int Customer::getCustomerRate() {
    return customer_rate;
}

string Customer::getCustomerEmail() {
    return email_customer;
}


string Customer::getComplaints() {
    return complaints;
}


string Customer::makeComplaint() {
    string complaints;
    cout << "Enter your complaint: ";
    getline(cin, complaints);
    return complaints;
}



