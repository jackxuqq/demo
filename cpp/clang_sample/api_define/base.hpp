#pragma once

struct Addr{
    char province[20];
    char city[20];
    char street[50];
    char road[100];
    int no;
};


struct Bank{
    char name[20];
    Addr addr;
};

struct Account{
    int id;
    int amt;
    long open_ts;
    Bank bank;
};

