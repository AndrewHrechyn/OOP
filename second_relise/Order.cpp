#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Order {
private:
    vector<pair<string, int>> items;
public:
    void addItem(string& itemName, int price) {
        items.push_back({itemName, price});
    }

    vector<pair<string, int>>& getItems() {
        return items;
    }
};