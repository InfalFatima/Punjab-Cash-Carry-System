#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
    char name[50], category[50], supplier[50];
    float price;
    int quantity;

public:
    Product() {}
    Product(const char* n, const char* c, float p, int q, const char* s);
    const char* getName() const;
    const char* getCategory() const;
    float getPrice() const;
    int getQuantity() const;
    const char* getSupplier() const;
    void setQuantity(int q);
};

#endif
