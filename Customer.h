#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include <string>

class Customer {
    char name[50], email[50], address[100];
    std::vector<std::string> history;

public:
    Customer() {}
    Customer(const char* n, const char* e, const char* a);
    const char* getName() const;
    const char* getEmail() const;
    const char* getAddress() const;
    void addOrder(const std::string& detail);
    void viewHistory() const;
    friend std::ostream& operator<<(std::ostream& out, const Customer& c);
};

#endif
