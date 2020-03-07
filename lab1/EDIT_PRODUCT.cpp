#include <bits/stdc++.h>
#include <vector>
#include <windows.h>
#include <cmath>
#include <random>
#include <ctime>

#include "choose_a_choise.h"
#include "show_products.h"
#include "Product.h"
#include "REED_FILE.h"
#include "ADD_IN_FILE.h"
#include "search_product.h"

using namespace std;
extern vector<type_product> product;
bool new_product_f()
{
    cout<<"Enter the name of the product:\n";
    type_product new_product;
    cin>>new_product.name;
    for(int i=0;i<product.size();++i)
        if(product[i].name==new_product.name)
    {
        cout<<"There is such product \n";
        return 0;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Chose the type of the product:    \n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    int p;
    p= choose({"KGRAM","LITER","PIESE","BAG"});
    if(p==0) new_product.type= KGRAM;
    if(p==1) new_product.type= LITER;
    if(p==2) new_product.type= PIESE;
    if(p==3) new_product.type= BAG;

    cout<<"Enter the amount of the product:\n";
    cin>>new_product.amount;
    cin.ignore();
    cout<<"Enter the time creation of the product:            As in example '13.45' \n";
    string time_creation;
    cin>>time_creation;

    string hour;
    for(int i=0;time_creation[i]!='.';++i)
        hour+=time_creation[i];
    time_creation.erase(0,hour.size()+1);
    new_product.data.hour=str_in_int(hour);
    new_product.data.minutes=str_in_int(time_creation);
    if(new_product.data.hour>24 || new_product.data.minutes>60)
    {
        cout<<"Mistake occurred : incorrect time entered\n";
        return 0;
    }
    cout<<"Enter the day creation :            As in example '25.01.1997' \n";
    cin>>time_creation;
    string day,month,year;
    for(int i=0;time_creation[i]!='.';++i)
        day+=time_creation[i];
    time_creation.erase(0,day.size()+1);
    for(int i=0;time_creation[i]!='.';++i)
        month+=time_creation[i];
    time_creation.erase(0,month.size()+1);
    new_product.data.day=str_in_int(day);
    new_product.data.month=str_in_int(month);
    new_product.data.year=str_in_int(time_creation);
    cout<<"Enter the expired time\n";
    cin>>new_product.expired_time;
    srand(time(0));
    new_product.ID=rand()%100000;
    cout<<"Your new product:\n";
    vector<type_product> copy_(0);
    copy_.push_back(new_product);
    show_products(copy_);
    switch(choose({"SAVE","DONT SAVE"}))
    {
    case 0:
        product.push_back(new_product);

        synchronize();

        break;
    case 1:
        return 1;
    }
    system("cls");
    if(choose({"Add more products","Go to main menu"})==0)
            new_product_f();
    return 1;
}
int choose_product()
{
    vector<type_product> my_product=product;
    switch(choose({"FILTR","CHOOSE PROPERLY"}))
    {
    case 0:
        my_product=search_products(my_product);
        if(my_product.size()!=0)
        break;
        cout<<"No products were found.\n";
        return 227;
    }


    vector<string> name_product(0);
    int it_my;
    if(my_product.size()==1) it_my=0;
    else
    {
        for(int i=0;i<my_product.size();++i)
        name_product.push_back(to_string(my_product[i].ID)+"  "+ my_product[i].name);
    cout<<"Choose:\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<" ID     Name\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    it_my=choose(name_product);
    }




    for(int i=0;i<product.size();++i)
        if(product[i].name==my_product[it_my].name)
        return i;
    return 228;

}
bool edit_product()
{
    int it;
    if(product.size()==1) it=0;
    else it=choose_product();
    if(it==228 || it==227)
    {
        if(it==228)cout<<"Something went wrong\n";
        return 0;
    }
    switch(choose({"EDIT","DELETE"}))
    {
    case 1:
        product.erase(product.begin()+it);
        synchronize();
        cout<<"Successfully deleted\n";
        return 1;
    case 0:
        while(1)
        {
            type_product new_product=product[it];
            system("cls");
            cout<<"EDITING\n";
            show_products(new_product);
            switch(choose({"NAME","TYPE","AMOUNT","TIME","DATA"}))
            {
                //NAME
                case 0:
                    cout<<"Enter the name of the product:\n";

                    cin>>new_product.name;
                    show_products(new_product);
                    switch(choose({"SAVE","TRY AGAIN"}))
                    {
                    case 0:
                        product[it]=new_product;
                        synchronize();
                        return 1;
                    case 1:
                        break;
                    }
                    break;
                ////TYPE
                case 1:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    cout<<"Chose the type of the product:    \n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    int p;
                    p= choose({"KGRAM","LITER","PIESE","BAG"});
                    if(p==0) new_product.type= KGRAM;
                    if(p==1) new_product.type= LITER;
                    if(p==2) new_product.type= PIESE;
                    if(p==3) new_product.type= BAG;


                    show_products(new_product);
                    switch(choose({"SAVE","TRY AGAIN"}))
                    {
                    case 0:
                        product[it]=new_product;
                        synchronize();
                        return 1;
                    case 1:
                        break;
                    }
                    break;
                //AMOUNT
                case 2:
                    cout<<"Enter the amount of the product:\n";
                    cin>>new_product.amount;
                    cin.ignore();

                    show_products(new_product);
                    switch(choose({"SAVE","TRY AGAIN"}))
                    {
                    case 0:
                        product[it]=new_product;
                        synchronize();
                        return 1;
                    case 1:
                        break;
                    }
                    break;
                case 3:
                    {


                    cout<<"Enter the time creation of the product:            As in example '13.45' \n";
                    string time_creation;
                    cin>>time_creation;
                    string hour;
                    for(int i=0;time_creation[i]!='.';++i)
                        hour+=time_creation[i];
                    time_creation.erase(0,hour.size()+1);
                    new_product.data.hour=str_in_int(hour);
                    new_product.data.minutes=str_in_int(time_creation);
                    if(new_product.data.hour>24 || new_product.data.minutes>60)
                    {
                        cout<<"Mistake occurred : incorrect time entered\n";
                        return 0;
                    }
                    show_products(new_product);
                    switch(choose({"SAVE","TRY AGAIN"}))
                    {
                    case 0:
                        product[it]=new_product;
                        synchronize();
                        return 1;
                    case 1:
                        break;
                    }
            }
                    break;
                case 4:
                    cout<<"Enter the data creation of the product:            As in example '12.03.1945' \n";
                    string data_creation;
                    cin>>data_creation;
                    string day;
                    for(int i=0;data_creation[i]!='.';++i)
                        day+=data_creation[i];
                    data_creation.erase(0,day.size()+1);
                    string mon;
                    for(int i=0;data_creation[i]!='.';++i)
                        mon+=data_creation[i];
                    data_creation.erase(0,mon.size()+1);
                    new_product.data.day=str_in_int(day);
                    new_product.data.month=str_in_int(mon);
                    new_product.data.year=str_in_int(data_creation);
                    if(new_product.data.day>31 || new_product.data.month>12 || new_product.data.year<0)
                    {
                        cout<<"Mistake occurred : incorrect data entered\n";
                        cout<<"D: "<<new_product.data.day<<" M: "<<new_product.data.month<<" Y: "<<new_product.data.year<<endl;
                        return 0;
                    }
                    show_products(new_product);
                    switch(choose({"SAVE","TRY AGAIN"}))
                    {
                    case 0:
                        product[it]=new_product;
                        synchronize();
                        return 1;
                    case 1:
                        break;
                    }
                    break;
            }
        }
    }
}
