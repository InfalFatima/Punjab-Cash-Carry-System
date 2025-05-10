#include "Staff.h"
#include <cstring>

Staff::Staff(const char* n, const char* e, const char* p) {
    strcpy_s(name, n);
    strcpy_s(email, e);
    strcpy_s(position, p);
}

const char* Staff::getName() const { return name; }
const char* Staff::getEmail() const { return email; }
const char* Staff::getPosition() const { return position; }
