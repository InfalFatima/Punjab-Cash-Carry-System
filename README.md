# Punjab-Cash-Carry-System


A console-based C++ and OOP management system simulating operations of a retail store, including product inventory, customer orders, staff functionalities, and sales reporting. Developed by Infal Fatima as final project.

## 📌 Features

- **Product Management**  
  Staff can add or remove products from inventory and view all available products.

- **Customer Management**  
  Customers can sign up, log in, view products, add to cart, place orders, and see their order history.

- **Staff Management**  
  Staff members can log in, manage inventory, view customer order histories, and generate sales reports.

- **Order System**  
  Products can be added to a cart and checked out by customers. All placed orders are stored and used for reporting.

- **Reporting**  
  Staff can generate a basic sales report using the stored orders.

## 📁 File Structure

```
PunjabCashAndCarry/
│
├── main.cpp             # Main file (UI logic, loading/saving, menu system)
├── Product.h / .cpp     # Product class (name, category, price, quantity, supplier)
├── Customer.h / .cpp    # Customer class (details + order history)
├── Staff.h / .cpp       # Staff class (staff info)
├── Inventory.h / .cpp   # Inventory class (manages product collection)
├── Order.h / .cpp       # Order class (cart-like structure)
├── Report.h / .cpp      # Report class (sales reporting)
├── products.txt         # Product database
├── customers.txt        # Customer database
├── staff.txt            # Staff database
```

## 🛠️ Technologies

- C++ (Standard Library)
- OOP (Specification and Implementation files)
- File I/O (`fstream`)
- Console interface

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/<your-username>/PunjabCashAndCarry.git
cd PunjabCashAndCarry
```

### 2. Compile the code

You can use any C++ compiler. Example using `g++`:

```bash
g++ main.cpp Product.cpp Customer.cpp Staff.cpp Inventory.cpp Order.cpp Report.cpp -o CashAndCarry
```

### 3. Run the application

```bash
./CashAndCarry
```

### 4. File Dependencies

Ensure the following data files are in the same directory before running:

- `products.txt`
- `customers.txt`
- `staff.txt`

The system will read and write to these files automatically.

## 👩‍💻 Authors

Created by Infal Fatima  
OOP Lab Project – 2nd Semester

## 📃 License

This project is for educational purposes only.
