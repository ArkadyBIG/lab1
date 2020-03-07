#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cmath>
#include <windows.h>

#include "Product.h"
extern CONSOLE_SCREEN_BUFFER_INFO c;

using namespace std;

extern vector<type_product> product;
bool show_products()
{
    if(product.size()==0)
    return 0;


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<"ID          NAME    TYPE        AMOUNT      TIME        DATA               EXP. DATE\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    for(int i=0; i<product.size(); ++i)
    {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c);
        for(int l=0; l<5; ++l)
            if( (product[i].ID/pow(10,5-l)) <1)
                cout<<"0";
        cout<<product[i].ID<< "  ";

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {12,c.dwCursorPosition.Y});
        cout<<product[i].name<<" ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {20,c.dwCursorPosition.Y});
        if(product[i].type==0)
            cout<<"KG";
        if(product[i].type==1)
            cout<<"LITR";
        if(product[i].type==2)
            cout<<"PIES";
        if(product[i].type==3)
            cout<<"BAGS";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {30,c.dwCursorPosition.Y});
        cout<<"  "<<product[i].amount ;
        if(product[i].amount== (int) product[i].amount)
            cout<<".0";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {44,c.dwCursorPosition.Y});
        cout<<product[i].data.hour <<"."<< (product[i].data.minutes/10==0 ? "0" : "")<<product[i].data.minutes <<"    ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {56,c.dwCursorPosition.Y});
        cout<<(product[i].data.day/10==0 ? "0" : "") << product[i].data.day <<"."<<(product[i].data.month/10==0 ? "0" : "") <<product[i].data.month <<" ";
        cout<<product[i].data.year <<"         "<<product[i].expired_time <<"    \n";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    return 1;
}
bool show_products(vector<type_product> my_product)
{
    if(my_product.size()==0)
    {
        cout<<"No products were found.\n";
        return 0;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<"ID          NAME    TYPE        AMOUNT      TIME        DATA               EXP. DATE\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    for(int i=0; i<my_product.size(); ++i)
    {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c);
        for(int l=0; l<5; ++l)
            if( (my_product[i].ID/pow(10,5-l)) <1)
                cout<<"0";
        cout<<my_product[i].ID<< "  ";

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {12,c.dwCursorPosition.Y});
        cout<<my_product[i].name<<" ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {20,c.dwCursorPosition.Y});
        if(my_product[i].type==0)
            cout<<"KG";
        if(my_product[i].type==1)
            cout<<"LITR";
        if(my_product[i].type==2)
            cout<<"PIES";
        if(my_product[i].type==3)
            cout<<"BAGS";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {30,c.dwCursorPosition.Y});
        cout<<"  "<<my_product[i].amount ;
        if(my_product[i].amount== (int) my_product[i].amount)
            cout<<".0";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {44,c.dwCursorPosition.Y});
        cout<<my_product[i].data.hour <<"."<< (my_product[i].data.minutes/10==0 ? "0" : "")<<my_product[i].data.minutes <<"    ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {56,c.dwCursorPosition.Y});
        cout<<(my_product[i].data.day/10==0 ? "0" : "") << my_product[i].data.day <<"."<<(my_product[i].data.month/10==0 ? "0" : "") <<my_product[i].data.month <<" ";
        cout<<my_product[i].data.year <<"         "<<my_product[i].expired_time <<"    \n";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

bool show_products(type_product a)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<"ID          NAME    TYPE        AMOUNT      TIME        DATA               EXP. DATE\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c);
        for(int l=0; l<5; ++l)
            if( (a.ID/pow(10,5-l)) <1)
                cout<<"0";
        cout<<a.ID<< "  ";

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {12,c.dwCursorPosition.Y});
        cout<<a.name<<" ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {20,c.dwCursorPosition.Y});
        if(a.type==0)
            cout<<"KG";
        if(a.type==1)
            cout<<"LITR";
        if(a.type==2)
            cout<<"PIES";
        if(a.type==3)
            cout<<"BAGS";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {30,c.dwCursorPosition.Y});
        cout<<"  "<<a.amount ;
        if(a.amount== (int) a.amount)
            cout<<".0";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {44,c.dwCursorPosition.Y});
        cout<<a.data.hour <<"."<< (a.data.minutes/10==0 ? "0" : "")<<a.data.minutes <<"    ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {56,c.dwCursorPosition.Y});
        cout<<(a.data.day/10==0 ? "0" : "") << a.data.day <<"."<<(a.data.month/10==0 ? "0" : "") <<a.data.month <<" ";
        cout<<a.data.year <<"         "<<a.expired_time <<"    \n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
