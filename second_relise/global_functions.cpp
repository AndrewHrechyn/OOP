#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

// Function to show variants for customer
void showVariantsToChooseCustomer() {
    cout << "------ Choose section ------" << endl;
    cout << "1 - Choose restaurant and menu" << endl;
    cout << "2 - Rate the deliverer" << endl;
    cout << "3 - Show my info and bonuses" << endl;
    cout << "4 - Make a complaint" << endl;
}

// Function to show variants for deliverer
void showVariantsToChooseDeliverer() {
    cout << "------ Choose section ------" << endl;
    cout << "1 - Check orders to do" << endl;
    cout << "2 - Check my salary" << endl;
    cout << "3 - Check my rate" << endl;
    cout << "4 - Start work" << endl;
    cout << "5 - Finish work" << endl;
}

// Function to show variants for manager
void showVariantsToChooseManager() {
    cout << "------ Choose section ------" << endl;
    cout << "1 - Add restaurant" << endl;
    cout << "2 - Delete restaurant" << endl;
    cout << "3 - Add menu for restaurant" << endl;
    cout << "4 - Delete menu for restaurant" << endl;
    cout << "5 - Check my salary" << endl;
}

// Function to show variants for buchhalter
void showVariantsToChooseBuchhalter() {
    cout << "------ Choose section ------" << endl;
    cout << "1 - Count each worker salary" << endl;
    cout << "2 - Count all doxid(also with percentage of each restaurant)" << endl;
    cout << "3 - Count check for a bad work" << endl;
    cout << "4 - Give a bonus for a worker" << endl;
    cout << "5 - Add new worker" << endl;
    cout << "6 - Delete worker" << endl;
}