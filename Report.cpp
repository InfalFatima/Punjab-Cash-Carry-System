#include "Report.h"
#include <iostream>
using namespace std;

void Report::generateSalesReport(Order orders[], int orderCount) {
    float totalSales = 0;
    for (int i = 0; i < orderCount; ++i) {
        totalSales += orders[i].getTotal();
    }
    cout << "Total Sales: " << totalSales << endl;
}
