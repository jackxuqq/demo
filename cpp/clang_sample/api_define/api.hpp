#pragma once

#include "base.hpp"

struct Addr{
    char province[TWENTY_BYTE];
    char city[TWENTY_BYTE];
    char street[FIFTY_BYTE];
    char road[HUNDRED_BYTE];
    int no;
};


struct Bank{
    char name[TWENTY_BYTE];
    Addr addr;
};

struct Account{
    int id;
    int amt;
    long open_ts;
    Bank bank;
};
struct Person{
    long id;
    char name[TEN_BYTE];
    int age;
    Addr  addr;
    Account accs[TEN];
};

/**
* @brief This function is a demo function
*
* @param[in]:                     id					is a id
* @param[out]									person               is a person
* @return error code(to be detailed)
*/
int GetPerson(long id, Person* person);
