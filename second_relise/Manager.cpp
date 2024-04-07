#include "Manager.hpp"

Node::Node(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu)
    : restaurantName(restaurantName), address(address), hoursOfWork(hoursOfWork), gmail(gmail), menu(menu), next(nullptr), prev(nullptr) {}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

void DoublyLinkedList::pushFront(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu) {
    Node* newNode = new Node(restaurantName, address, hoursOfWork, gmail, menu);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::popFront() {
    if (head == nullptr) return;
    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Restaurant Name: " << temp->restaurantName << endl;
        cout << "Address: " << temp->address << endl;
        cout << "Hours of Work: " << temp->hoursOfWork << endl;
        cout << "Gmail: " << temp->gmail << endl;
        cout << "Menu:" << endl;
        for (auto& dish : temp->menu) {
            cout << " - " << dish.first << ": $" << dish.second << endl;
        }
        temp = temp->next;
        cout << "-----------------------" << endl;
    }
}



void DoublyLinkedList::printNameRestaurants() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Restaurant Name: " << temp->restaurantName << endl;
        temp = temp->next;
        cout << "-----------------------" << endl;
    }
}

void DoublyLinkedList::updateMenu(string& restaurantName, vector<pair<string, int>>& newMenu) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->restaurantName == restaurantName) {
            temp->menu = newMenu; // Оновлення меню
            cout << "Restaurant menu for \"" << restaurantName << "\" is updated.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Restaurant with name \"" << restaurantName << "\" do not exist.\n";
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != nullptr) {
        popFront();
    }
}


Node* DoublyLinkedList::getHead() const {
    return head;
}

void Manager::deleteMenuForRestaurant() {
    restaurantList.popFront();
}

void Manager::addRestaurant(string restaurantName, string address, string hoursOfWork, string gmail, vector<pair<string, int>> menu) {
    restaurantList.pushFront(restaurantName, address, hoursOfWork, gmail, menu);
}

void Manager::printAllInfoRestaurants() {
    restaurantList.printList();
}

void Manager::printNameRestaurants() {
    restaurantList.printNameRestaurants();
}

int Manager::getSalaryManager() {
    return salary_manager;
}

int Manager::getManagerPassword() {
    return managerPassword;
}


void Manager::updateRestaurantMenu(string& restaurantName, vector<pair<string, int>>& newMenu) {
    restaurantList.updateMenu(restaurantName, newMenu);
}


vector<pair<string, int>> Manager::findRestaurant(string& restaurantName) {
    Node* temp = restaurantList.getHead(); // Отримуємо початок списку ресторанів

    // Шукаємо ресторан за назвою
    while (temp != nullptr) {
        if (temp->restaurantName == restaurantName) {
            return temp->menu; // Повертаємо меню ресторану
        }
        temp = temp->next; // Переходимо до наступного ресторану
    }

    // Якщо ресторан не знайдено, повертаємо пустий вектор
    return {};
}


void Manager::deleteRestaurantByName(string& restaurantName) {
    Node* temp = restaurantList.getHead();

    while (temp != nullptr) {
        if (temp->restaurantName == restaurantName) {
            // Видаляємо зв'язані дані
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            // Видаляємо сам вузол
            if (temp == restaurantList.getHead()) {
                restaurantList.popFront(); // Якщо це перший елемент
            } else {
                delete temp;
            }
            cout << "Restaurant \"" << restaurantName << "\" and its information have been deleted.\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Restaurant with name \"" << restaurantName << "\" not found.\n";
}
