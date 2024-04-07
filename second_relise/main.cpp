#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

#include "Person.hpp"
#include "Person.cpp"

#include "Deliverer.hpp"
#include "Deliverer.cpp"

#include "Customer.hpp"
#include "Customer.cpp"

#include "Buchhalter.hpp"
#include "Buchhalter.cpp"

#include "Manager.hpp"
#include "Manager.cpp"

#include "global_functions.cpp"

#include "MVC_model.cpp"

#include "Order.cpp"

using namespace std;


    Manager manager;
    Customer customer;
    Deliverer deliverer;
    Buchhalter buchhalter;

    //Adding default restaurants
    

    // Створення контролера із моделями
    Controller controller(manager, customer, deliverer);



int main(){


    // Відображення інформації через контролер
    controller.viewRestaurants();
    controller.viewDeliveryStatus();
    controller.viewCustomerInfo();




    ///////MAIN MENU///////////////////////////MAIN VOID ///////////////////////////////////////////////////////


    vector<pair<string, int>> menu1 = {{"Cheese pizza", 119}, {"Chicken pizza", 109}, {"Meat pizza", 129},
                                       {"Vegan pizza", 99}, {"Veggie pizza", 109}, {"Pepperoni pizza", 99}, 
                                       {"Mozarrella pizza", 109}, {"Hawaiian pizza", 109}, {"Buffalo pizza", 109},
                                       {"Cola", 30}, {"Fanta", 30}, {"Sprite", 30}, {"Water", 30}};

    vector<pair<string, int>> menu2 = {{"Hamburger", 69}, {"Cheese burger", 70}, {"Burger", 58}, {"Meat burger", 79},
                                       {"Vegan burger", 59}, {"Veggie burger", 69}, {"Pepperoni burger", 59},
                                       {"Cola", 30}, {"Fanta", 30}, {"Sprite", 30}, {"Water", 30}};


    manager.addRestaurant("Pizza Place", "123 Main St", "9am - 9pm", "contact@pizzaplace.com", menu1);
    manager.addRestaurant("Burger Place", "456 Oak St", "10am - 11pm", "contact@burgerplace.com", menu2);

    cout << endl;
    cout << endl;

    cout << "You are welcome in our program of delivering food" << endl;

    // Main menu

    int choice_who_r_u;

    while (true){
    
        cout << "========== You are in main menu ==========" << endl;
        cout << "Please choose who you are (Customer(1), Deliverer(2), Manager(3) or Buchhalter(4)): " << endl;
        //int choice_who_r_u;
        cin >> choice_who_r_u;

        if (choice_who_r_u == 1) {
            // Customer part
            string new_change_cust_name;
            string new_change_cust_surname;

            cout << "========== You are in customer menu ==========" << endl;

            cout << "------Enter your name------" << endl;
            string new_name;
            cin >> new_name;

            cout << "------Enter your surname------" << endl;
            string new_surname;
            cin >> new_surname;

            customer.setName(new_name);
            customer.setSurName(new_surname);

            char choice_for_c_to_do;

            showVariantsToChooseCustomer();
            cin >> choice_for_c_to_do;

            int count_of_dishes = 0;
            string restaurantName_;
            vector<pair<string, int>> menures;


            if (choice_for_c_to_do == '1') {
                manager.printNameRestaurants();

                cout << "Enter restaurant name you want: ";

                cin.ignore();
                getline(cin, restaurantName_);

                vector<pair<string, int>> menures = View::displayMenu(manager, restaurantName_);

                int count_of_dishes = 0;
                for (auto i : menures) {
                    count_of_dishes++;
                    cout << count_of_dishes << ". " << i.first << " " << i.second << endl;
                }

                cout << "Want to order something(y/n)?" << endl;
                char order_choice;
                cin >> order_choice;

                if (order_choice == 'y') {

                    ////переписати в клас ордер
                    vector<pair<string, int>> order;

                    int sum = 0;
                    int choice;
                    while (true) {
                        cout << "Enter your order numbers (0 to finish order): ";
                        cin >> choice;
                        if (choice == 0) {
                            break; // Завершуємо замовлення, якщо введено 0
                        }
                        if (choice < 1 || choice > menures.size()) {
                            cout << "Invalid choice. Please enter a valid number." << endl;
                            continue; // Пропускаємо некоректне введення і повторюємо цикл
                        }
                        order.push_back(menures[choice - 1]);
                        sum += menures[choice - 1].second;
                    }
                    cout << endl;

                    cout << "Your order: " << endl;
                    for (auto i : order) {
                        cout << i.first << " " << i.second << endl;
                    }
                    cout << endl;

                    cout << "Total price: " << sum << endl;
                }
                else if (order_choice == 'n') {
                    cout << "Ok, see you next time" << endl;
                }
                else {
                    cout << "Wrong input. Exiting to main menu....." << endl;
                }
            }
            else if (choice_for_c_to_do == '2') {
                cout << "Rate your deliverer" << endl;

                int rate;
                cout << "1 - Very bad" << endl << "2 - Bad" << endl << "3 - Good" << endl << "4 - Very good" << endl;
                cin >> rate;
                deliverer.setOwnMark(rate);
                //controller.setRate_for_Deliverer(rate);
                cout << "Rate: " << deliverer.getOwnMark() << endl;
            }
            else if (choice_for_c_to_do == '3') {
                // Check account info and bonuses
                    cout << customer.getName() << endl;
                    cout << customer.getSurName() << endl;
                    cout << customer.getCustomerRate() << endl;
                    puts("");
                    
                    cout << "Want to change your name(n) or surname(s) or exit(e)?" << endl;
                    char change_choice;
                    cin >> change_choice;

                    switch (change_choice){
                    case 'n':
                        cout << "Set new name" << endl;
                        cin >> new_change_cust_name;
                        customer.setName(new_change_cust_name);
                        break;
                    case 's':
                        cout << "Set new surname" << endl;
                        cin >> new_change_cust_surname;
                        customer.setSurName(new_change_cust_surname);
                        break;
                    case 'e':
                        //exit from customer menu
                        break;
                default:
                    cout << "Wrong input" << endl;
                    break;
                }
            }
            else if (choice_for_c_to_do == '4') {
                string complaints;
                cout << "Enter your complaint (type 'exit' to finish): " << endl;
                
                while (true) {
                    string complaint;
                    getline(cin, complaint);
                    
                    if (complaint == "exit") {
                        break;
                    }
                    
                    complaints += complaint + "\n"; // Додати нову скаргу до загального списку скарг
                }

                deliverer.setComplaints(complaints);

                // controller.setComplaints_for_Deliverer(complaints);
                cout << "Complaints registered successfully!" << endl;
                cout << deliverer.getComplaints() << endl;
            }
            else {
                cout << "Invalid choice" << endl;
            }
        }
        else if (choice_who_r_u == 2) {
            // Deliverer menu
            cout << "You are in deliverer menu" << endl;
            showVariantsToChooseDeliverer();


            /*void showVariantsToChooseDeliverer() {
                cout << "------ Choose section ------" << endl;
                cout << "1 - Check orders to do" << endl;
                cout << "2 - Check my salary" << endl;
                cout << "3 - Check my rate" << endl;
                cout << "4 - Start work" << endl;
                cout << "5 - Finish work" << endl;
            }*/

            char choice_for_d_to_do;
            cout << "Enter your choice: " << endl;
            cin >> choice_for_d_to_do;

            if(choice_for_d_to_do == '1'){
                cout << deliverer.getOwnMark() << endl;
            }
            else if(choice_for_d_to_do == '2'){
                cout << deliverer.getComplaints() << endl;
            }
            else if(choice_for_d_to_do == '3'){
                
            }
        }
        else if (choice_who_r_u == 3) {
            // Manager menu
            cout << "You are in manager menu" << endl;
            showVariantsToChooseManager();
            
            // void showVariantsToChooseManager() {
            //     cout << "------ Choose section ------" << endl;
            //     cout << "1 - Add restaurant" << endl;
            //     cout << "2 - Delete restaurant" << endl;
            //     cout << "3 - Add menu for restaurant" << endl;
            //     cout << "4 - Delete menu for restaurant" << endl;
            //     cout << "5 - Check my salary" << endl;
            // }
            char choice_for_m_to_do;
            cout << "Enter your choice: " << endl;
            cin >> choice_for_m_to_do;

            if (choice_for_m_to_do == '1') {
                cout << "All restaurants" << endl;
                manager.printAllInfoRestaurants();

                cout << "Add restaurant and menu" << endl;

                vector<pair<string, int>> menu3 = {{"Sparkle water", 30}, {"Water", 30}, {"Cola", 30}, {"Fanta", 30}, {"Sprite", 30}, {"Water", 30}};

                manager.addRestaurant("Drinks Place", "123 New Street", "12am - 10pm", "contact@drinksplace.com", menu3);
                manager.printAllInfoRestaurants();
                //break;
                continue;

            }
            else if (choice_for_m_to_do == '2') {
                // cout << "Delete restaurant" << endl;
                // manager.printAllInfoRestaurants();
                // cout << endl;

                // manager.deleteRestaurant("Drinks Place");
                // cout << endl;
                // cout << "All restaurants" << endl;
                // manager.printAllInfoRestaurants();
                //break;
                continue;
            }
            else if (choice_for_m_to_do == '3') {
                cout << "Add menu for restaurant" << endl;
                cout << "\n\n\n\n";

                manager.printNameRestaurants();
                cout << endl;
                manager.printAllInfoRestaurants();
                cout << endl;
                
                vector<pair<string, int>> new_menu = {{"Pizza", 10}, {"Pasta", 12}};

                string new_name = "Burger Place";

                manager.updateRestaurantMenu(new_name, new_menu);
                manager.printAllInfoRestaurants();
                //break;
                continue;

            }
            else if (choice_for_m_to_do == '4') {
                cout << "Delete menu for restaurant" << endl;
                manager.printAllInfoRestaurants();

                cout << endl;

                manager.deleteMenuForRestaurant();
                cout << "All restaurants" << endl;
                manager.printAllInfoRestaurants();
                //break;
                continue;

            }
            else if (choice_for_m_to_do == '5') {
                cout << "Check my salary" << endl;
                cout << manager.getSalaryManager() << " $ " << endl;
                //break;
                continue;
            }
            else {
                cout << "Wrong choice" << endl;
                cout << "Exiting......." << endl;
                break;
            }
        }
        else if (choice_who_r_u == 4) {
            //Buchalter menu
            cout << "You are in buchhalter menu" << endl;
            showVariantsToChooseBuchhalter();

            char choice_for_b_to_do;
            cout << "Enter your choice: " << endl;
            cin >> choice_for_b_to_do;

            buchhalter.addWorker("Pupkin", "Ivan", 19161546,  20000, 5);
            buchhalter.addWorker("Bogdan", "Grad", 2423425,  70000, 90);
            buchhalter.addWorker("Genius", "Ivanova", 54321251,  60000, 10);

            if (choice_for_b_to_do == '1') {
                cout << "Count each worker salary" << endl;
                buchhalter.printAllWorkers();
                buchhalter.setSalary(19161546, 10000);
                buchhalter.printAllWorkers();
                continue;
            }
            else if (choice_for_b_to_do == '2') {
                // int doxid = 0;
                cout << "Count all doxid(also with percentage of each restaurant)" << endl;
                cout << buchhalter.getFullSalary() << endl;
                // cout << "Count all doxid(also with percentage of each restaurant)" << endl;
                // for (int i = 0; i < order.size(); i++) {
                //     cout << i + 1 << " " << order[i].first << " " << order[i].second << endl;
                //     doxid += order[i].second;
                // }

                // cout << doxid << endl;
                continue;
            }
            else if (choice_for_b_to_do == '3') {
                cout << "Count check for a bad work" << endl;
                buchhalter.printAllWorkers();
                cout << endl;
                buchhalter.giveCheck_for_Bad_work(19161546, 1000);
                cout << endl;
                buchhalter.printAllWorkers();
                continue;
            }
            else if (choice_for_b_to_do == '4') {
                cout << "Give a bonus for a worker" << endl;
                buchhalter.printAllWorkers();
                cout << endl;
                buchhalter.giveCheck_for_Good_work(1123541541, 7464);
                cout << endl;
                buchhalter.printAllWorkers();

                continue;
            }
            else if (choice_for_b_to_do == '5') {
                buchhalter.addWorker("Yana", "Ivanova", 1123541541,  20000, 5);

                buchhalter.printAllWorkers();
                continue;
            }
            else if (choice_for_b_to_do == '6') {
                buchhalter.printAllWorkers();

                //
                buchhalter.deleteWorker(1123541541);

                buchhalter.printAllWorkers();
                continue;
            }
            else {
                cout << "Wrong choice" << endl;
                cout << "Exiting......." << endl;
                break;
            }
            break;
        }
        else {
            cout << "Wrong choice" << endl;
            cout << "Exiting......." << endl;
            break;
        }
        break;
    }

   return 0;
}

