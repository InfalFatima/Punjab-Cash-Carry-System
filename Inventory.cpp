#include "Inventory.h"
#include <iostream>
#include <cstring>
using namespace std;

void Inventory::addProduct(Product p) {
    if (count < 100) {
        products[count++] = p;
    }
}

void Inventory::removeProduct(const char* name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(products[i].getName(), name) == 0) {
            for (int j = i; j < count - 1; ++j) {
                products[j] = products[j + 1];
            }
            --count;
            cout << "Product removed.";
            return;
        }
    }
    cout << "Product not found.";
}

Product* Inventory::find(const char* name) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(products[i].getName(), name) == 0) {
            return &products[i];
        }
    }
    return nullptr;
}

Product Inventory::getProduct(int i) const { return products[i]; }
int Inventory::getCount() const { return count; }

void Inventory::showAll() const {
    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". " << products[i].getName() << " - " << products[i].getCategory()
             << " - Price: " << products[i].getPrice() << " - Quantity: " << products[i].getQuantity()
             << " - Supplier: " << products[i].getSupplier() << endl;
    }
}
