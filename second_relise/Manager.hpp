// #ifndef MANAGER_HPP
// #define MANAGER_HPP

// #include "Person.hpp"
// // #include "Customer.cpp"
// #include <utility>

// using namespace std;

// class Node {
// public:
//     string restaurantName;
//     string address;
//     string hoursOfWork;
//     string gmail;
//     vector<pair<string, int>> menu;

//     Node* next;
//     Node* prev;

//     Node(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu);
// };

// class DoublyLinkedList {
// private:
//     Node* head;
//     Node* tail;
// public:
//     DoublyLinkedList();

//     void pushFront(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu);
//     void popFront();
//     void printList();
//     ~DoublyLinkedList();
// };

// class Manager: public Person {
//     // friend void Customer::viewRestaurants_Menu(Manager& manager);
// private:
//     DoublyLinkedList restaurantList;
//     int salary_manager;
//     int managerPassword = 22222;

// public:
//     void addRestaurant(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu);
//     void printRestaurants();
//     int getSalaryManager();
//     int getManagerPassword();
    
// };

// #endif // MANAGER_HPP


// file.hpp

#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Person.hpp"
#include <utility>

using namespace std;

class Node {
public:
    string restaurantName;
    string address;
    string hoursOfWork;
    string gmail;
    vector<pair<string, int>> menu;

    Node* next;
    Node* prev;

    Node(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu);
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList();

    void pushFront(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu);
    void popFront();
    void printList();


    void updateMenu(string& restaurantName, vector<pair<string, int>>& newMenu);


    void printNameRestaurants();

    ~DoublyLinkedList();


    Node* getHead() const;
};

class Manager: public Person {
private:
    DoublyLinkedList restaurantList;
    int salary_manager = 10000;
    int managerPassword = 22222;

public:

    void addRestaurant(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu);
    void printAllInfoRestaurants();
    void printNameRestaurants();
    int getSalaryManager();
    int getManagerPassword();
    void deleteMenuForRestaurant();
    void updateRestaurantMenu(string& restaurantName, vector<pair<string, int>>& newMenu);
    void deleteRestaurantByName(string& restaurantName);

    
    vector<pair<string, int>> findRestaurant(string& restaurantName);
};

#endif // MANAGER_HPP
