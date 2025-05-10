#include "Order.h"
#include <iostream>
using namespace std;

void Order::addProduct(Product p) {
    if (count < 50) {
        items[count++] = p;
    }
}

void Order::showOrder() const {
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". " << items[i].getName() << " - Price: " << items[i].getPrice() << endl;
    }
    cout << "Total: " << getTotal() << endl;
}

float Order::getTotal() const {
    float total = 0;
    for (int i = 0; i < count; ++i) {
        total += items[i].getPrice();
    }
    return total;
}
