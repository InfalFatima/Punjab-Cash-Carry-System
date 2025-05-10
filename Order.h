#ifndef ORDER_H
#define ORDER_H
#include "Product.h"

class Order {
    Product items[50];
    int count = 0;

public:
    void addProduct(Product p);
    void showOrder() const;
    float getTotal() const;
};

#endif
