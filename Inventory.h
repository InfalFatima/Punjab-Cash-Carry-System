#ifndef INVENTORY_H
#define INVENTORY_H
#include "Product.h"

class Inventory {
    Product products[100];
    int count = 0;

public:
    void addProduct(Product p);
    void removeProduct(const char* name);
    Product* find(const char* name);
    Product getProduct(int i) const;
    int getCount() const;
    void showAll() const;
};

#endif
