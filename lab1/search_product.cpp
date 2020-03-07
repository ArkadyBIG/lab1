#include <bits/stdc++.h>
#include <vector>
#include <windows.h>
#include <cmath>

#include "choose_a_choise.h"
#include "show_products.h"
#include "Product.h"
#include "REED_FILE.h"

using namespace std;

bool ending_right(string ending,string a)
{
    if(ending.size()>a.size() ) return 0;
    for (int i=0;i<ending.size();++i)
        if(ending[i]!=a[a.size()-ending.size()+i])
        return 0;
    return 1;
}
extern vector<type_product> product;
bool ending_name(vector<type_product> &searched_product)
{
    cout<<"Enter the ending:\n";
    string ending;
    cin>>ending;
    for(int i=0;i<searched_product.size();++i)
    {
        if(!ending_right(ending,searched_product[i].name))
            searched_product.erase(searched_product.begin()+i--);
    }
}
bool type_search(vector<type_product> &searched_product)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Chose:\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    int id=choose({"KGRAM","LITER","PIESE","BAG"});

        for(int i=0;i<searched_product.size();++i)
        if(searched_product[i].type!=id)
            searched_product.erase(searched_product.begin()+i--);


}
bool expired_data(vector<type_product> &searched_product)
{
    cout<<"Enter expired data:\n";
    int expired;
    cin>>expired;
    for(int i=0;i<searched_product.size();++i)
        if(searched_product[i].expired_time<expired)
        searched_product.erase(searched_product.begin()+i--);
}
bool data_below(DATA a,DATA compare)
{
    if(a.year<compare.year) return 1;
    if(a.year>compare.year) return 0;
    if(a.month<compare.month) return 1;
    if(a.month>compare.month) return 0;
    if(a.day<=compare.day) return 1;
    return 0;
}
bool check_data(DATA ob,DATA from,DATA to)
{
    if(!data_below(ob,from) && data_below(ob,to)) return 1;
    return 0;

}
bool creation_time(vector<type_product> &searched_product)
{
    DATA data_from,data_to;
    string from,to;
    cout<<"Enter data form:         As an example 12.12.2009\n";
    cin>>from;
    cout<<"Enter data to:         As an example 12.12.2009\n";
    cin>>to;
    string from_p;
    for(int i=0;from[i]!='.';++i)
        from_p+=from[i];
    from.erase(0,from_p.size()+1);
    data_from.day=str_in_int(from_p);
    from_p="";
    for(int i=0;from[i]!='.';++i)
        from_p+=from[i];
    from.erase(0,from_p.size()+1);
    data_from.month=str_in_int(from_p);
    from_p="";
    data_from.year=str_in_int(from);


    for(int i=0;to[i]!='.';++i)
        from_p+=to[i];
    to.erase(0,from_p.size()+1);
    data_to.day=str_in_int(from_p);
    from_p="";
    for(int i=0;to[i]!='.';++i)
        from_p+=to[i];
    to.erase(0,from_p.size()+1);
    data_to.month=str_in_int(from_p);
    from_p="";
    data_to.year=str_in_int(to);
    //cout<<data_from.day<<"."<<data_from.month<<'.'<<data_from.year<<endl;
    //cout<<data_to.day<<"."<<data_to.month<<'.'<<data_to.year<<endl;
    for(int i=0;i<searched_product.size();++i)
        if(!check_data(searched_product[i].data,data_from,data_to))
        searched_product.erase(searched_product.begin()+i--);
    return 1;


}
bool search_products()
{


    vector<type_product> searched_product(0);
    searched_product=product;
    vector<string> C={"ending of product's name","product type","expired date","creation time" };
    while(1){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Filter by:\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    switch(choose(C) + (C.size()==3 ? 1:0))
    {
    case 0:
        C.erase(C.begin());
        ending_name(searched_product);
        break;
    case 1:

        type_search(searched_product);
        break;
    case 2:
        expired_data(searched_product);
        break;
    case 3:

        creation_time(searched_product);
    }
    if(choose({"Show","Add filters"})==0)
        break;
    }

    show_products(searched_product);
}

vector<type_product> search_products(vector<type_product> my_product)
{


    vector<type_product> searched_product(0);
    searched_product=my_product;
    vector<string> C={"ending of product's name","product type","expired date",};
    while(1){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Filter by:\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    switch(choose(C) + (C.size()==3 ? 1:0))
    {
    case 0:
        C.erase(C.begin());
        ending_name(searched_product);
        break;
    case 1:

        type_search(searched_product);
        break;
    case 2:
        expired_data(searched_product);
        break;

    }
    cout<<"Product found "<<searched_product.size()<<endl;
    if(choose({"Finish " ,"Add filters"})==0)
        return searched_product;
    }


}
