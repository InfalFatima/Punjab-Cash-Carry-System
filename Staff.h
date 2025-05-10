#ifndef STAFF_H
#define STAFF_H

class Staff {
    char name[50], email[50], position[50];

public:
    Staff() {}
    Staff(const char* n, const char* e, const char* p);
    const char* getName() const;
    const char* getEmail() const;
    const char* getPosition() const;
};

#endif
