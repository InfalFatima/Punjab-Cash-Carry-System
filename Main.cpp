#include <iostream>
#include <fstream>
#include <string.h>
#include "Product.h"
#include "Customer.h"
#include "Staff.h"
#include "Inventory.h"
#include "Order.h"
#include "Report.h"

using namespace std;

Inventory inventory;
Customer customers[100];
Staff staffList[50];
Order orders[100];
int customerCount = 0;
int staffCount = 0;
int orderCount = 0;

void loadProducts() {
    ifstream fin("products.txt");
    if (!fin) return;
    char name[50], category[50], supplier[50];
    float price;
    int quantity;
    while (fin >> name >> category >> price >> quantity >> supplier) {
        Product p(name, category, price, quantity, supplier);
        inventory.addProduct(p);
    }
    fin.close();
}

void loadCustomers() {
    ifstream fin("customers.txt");
    if (!fin) return;
    char name[50], email[50], address[100];
    while (fin >> name >> email >> address) {
        customers[customerCount++] = Customer(name, email, address);
    }
    fin.close();
}

void loadStaff() {
    ifstream fin("staff.txt");
    if (!fin) return;
    char name[50], email[50], position[50];
    while (fin >> name >> email >> position) {
        staffList[staffCount++] = Staff(name, email, position);
    }
    fin.close();
}

void saveProducts() {
    ofstream fout("products.txt");
    for (int i = 0; i < inventory.getCount(); i++) {
        Product p = inventory.getProduct(i);
        fout << p.getName() << " " << p.getCategory() << " "
            << p.getPrice() << " " << p.getQuantity() << " "
            << p.getSupplier() << endl;
    }
    fout.close();
}

void saveCustomers() {
    ofstream fout("customers.txt");
    for (int i = 0; i < customerCount; i++) {
        fout << customers[i].getName() << " "
            << customers[i].getEmail() << " "
            << customers[i].getAddress() << endl;
    }
    fout.close();
}

void saveStaff() {
    ofstream fout("staff.txt");
    for (int i = 0; i < staffCount; i++) {
        fout << staffList[i].getName() << " "
            << staffList[i].getEmail() << " "
            << staffList[i].getPosition() << endl;
    }
    fout.close();
}

Customer* loginCustomer() {
    char email[50];
    cout << "Enter your email: ";
    cin >> email;
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].getEmail(), email) == 0) {
            return &customers[i];
        }
    }
    cout << "Customer not found!";
    return nullptr;
}

Staff* loginStaff() {
    char email[50];
    cout << "Enter staff email: ";
    cin >> email;
    for (int i = 0; i < staffCount; i++) {
        if (strcmp(staffList[i].getEmail(), email) == 0) {
            return &staffList[i];
        }
    }
    cout << "Staff not found!";
    return nullptr;
}

void signupCustomer() {
    if (customerCount >= 100) {
        cout << "Customer limit reached!";
        return;
    }
    char name[50], email[50], address[100];
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter email: ";
    cin >> email;

    cout << "Enter address: ";
    cin.ignore(); 
    cin.getline(address, 100); 

    customers[customerCount++] = Customer(name, email, address);
    cout << "Signup successful!";
}


void customerOrderMenu(Customer& customer) {
    Order cart;
    int choice;
    do {
        cout << "\n--- Customer Order Menu ---\n";
        cout << "1. View Order History\n2. Add Product to Cart\n3. Show Cart\n4. Place Order\n5. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            customer.viewHistory();
            break;
        case 2: {
            inventory.showAll();
            char productName[50];
            cout << "Enter product name to add: ";
            cin >> productName;
            Product* p = inventory.find(productName);
            if (p != nullptr) {
                cart.addProduct(*p);
                cout << "Product added to cart!\n";
            }
            else {
                cout << "Product not found!\n";
            }
            break;
        }
        case 3:
            cart.showOrder();
            break;
        case 4:
            if (cart.getTotal() > 0) {
                orders[orderCount++] = cart;
                customer.addOrder("Order placed successfully!");
                cout << "Order placed!\n";
            }
            else {
                cout << "Cart is empty!\n";
            }
            break;
        case 5:
            cout << "Exiting Customer Order Menu.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

void customerMenu() {
    int choice;
    do {
        cout << "\n--- Customer Menu ---\n";
        cout << "1. Login\n2. Signup\n3. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Customer* loggedIn = loginCustomer();
            if (loggedIn != nullptr) {
                customerOrderMenu(*loggedIn);
            }
            break;
        }
        case 2:
            signupCustomer();
            break;
        case 3:
            cout << "Exiting Customer Menu.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}

void staffMenu() {
    int choice;
    do {
        cout << "\n--- Staff Menu ---\n";
        cout << "1. Login\n2. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Staff* loggedIn = loginStaff();
            if (loggedIn != nullptr) {
                int option;
                do {
                    cout << "\n--- Staff Management Menu ---\n";
                    cout << "1. Add Product\n2. Remove Product\n3. Generate Sales Report\n4. View Customer Histories\n5. Exit\n";
                    cout << "Choice: ";
                    cin >> option;
                    switch (option) {
                    case 1: {
                        char name[50], category[50], supplier[50];
                        float price;
                        int quantity;
                        cout << "Enter name: "; cin >> name;
                        cout << "Enter category: "; cin >> category;
                        cout << "Enter price: "; cin >> price;
                        cout << "Enter quantity: "; cin >> quantity;
                        cout << "Enter supplier: "; cin >> supplier;
                        inventory.addProduct(Product(name, category, price, quantity, supplier));
                        cout << "Product added!\n";
                        break;
                    }
                    case 2: {
                        char name[50];
                        cout << "Enter product name to remove: ";
                        cin >> name;
                        inventory.removeProduct(name);
                        break;
                    }
                    case 3: {
                        Report report;
                        report.generateSalesReport(orders, orderCount);
                        break;
                    }
                    case 4:
                        for (int i = 0; i < customerCount; i++) {
                            cout << customers[i];
                            customers[i].viewHistory();
                        }
                        break;
                    case 5:
                        cout << "Exiting Staff Management Menu.\n";
                        break;
                    default:
                        cout << "Invalid choice!\n";
                    }
                } while (option != 5);
            }
            break;
        }
        case 2:
            cout << "Exiting Staff Menu.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 2);
}

void mainMenu() {
    int choice;
    do {
        cout << "\n=== Punjab Cash & Carry Main Menu ===\n";
        cout << "1. Customer Menu\n2. Staff Menu\n3. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            customerMenu();
            break;
        case 2:
            staffMenu();
            break;
        case 3:
            cout << "Thank you for using Punjab Cash & Carry System!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}

int main() {
    loadProducts();
    loadCustomers();
    loadStaff();
    mainMenu();
    saveProducts();
    saveCustomers();
    saveStaff();
    return 0;
}
