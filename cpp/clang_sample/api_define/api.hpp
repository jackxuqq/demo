#pragma once

#include "base.hpp"

struct Person{
    long id;
    char name[10];
    int age;
    Addr  addr;
    Account accs[10];
};

int GetPerson(long id, Person* person);
