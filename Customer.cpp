#include "Customer.h"
#include <cstring>
#include <iostream>
using namespace std;

Customer::Customer(const char* n, const char* e, const char* a) {
    strcpy_s(name, n);
    strcpy_s(email, e);
    strcpy_s(address, a);
}

const char* Customer::getName() const { return name; }
const char* Customer::getEmail() const { return email; }
const char* Customer::getAddress() const { return address; }

void Customer::addOrder(const std::string& detail) {
    history.push_back(detail);
}

void Customer::viewHistory() const {
    cout << "Order History for " << name << ":";
    for (const auto& order : history) {
        cout << "- " << order << endl;
    }
}

ostream& operator<<(ostream& out, const Customer& c) {
    out << "Customer: " << c.name << ", Email: " << c.email << ", Address: " << c.address << endl;
    return out;
}
