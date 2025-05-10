#include "Product.h"
#include <cstring>

Product::Product(const char* n, const char* c, float p, int q, const char* s) {
    strcpy_s(name, n);
    strcpy_s(category, c);
    price = p;
    quantity = q;
    strcpy_s(supplier, s);
}

const char* Product::getName() const { return name; }
const char* Product::getCategory() const { return category; }
float Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
const char* Product::getSupplier() const { return supplier; }
void Product::setQuantity(int q) { quantity = q; }
