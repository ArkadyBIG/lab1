#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <bits/stdc++.h>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;
enum TYPE {KGRAM,LITER,PIESE,BAG};
struct DATA
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minutes;

};
struct type_product
{
    unsigned int ID;
    string name;
    TYPE  type;
    unsigned int amount;
    DATA data;
    unsigned int expired_time;
};

#endif // PRODUCT_H_INCLUDED
