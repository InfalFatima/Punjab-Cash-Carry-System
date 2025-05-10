#ifndef REPORT_H
#define REPORT_H
#include "Order.h"

class Report {
public:
    void generateSalesReport(Order orders[], int orderCount);
};

#endif
