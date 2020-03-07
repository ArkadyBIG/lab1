#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <cmath>

#include "Product.h"

using namespace std;

extern vector<type_product> product;
int str_in_int(string s)
{
    float out=0;
    for(int i=0;i<s.size();++i)
        out+=(s[i]-48)*pow(10,s.size()-1-i);
    return out;
}
double str_in_double(string s)
{
    bool dot=0;
    for(char c : s)
    if(c=='.'){dot=1;}
    if(!dot) return str_in_int(s);

    string part1;

    while( s.size()>0 )
    {
        if(s[0]=='.') break;
        part1+=s[0];
        s.erase(0,1);
    }

    s.erase(0,1);

    return str_in_int(part1) + str_in_int(s)*pow(10,(int) -s.size());
}
bool GET_FILE(string way="PRODUCTS.txt")
{
    fstream f(way);
    string s="";//,ios_base::out
    if(!f.is_open()) cout<<"pizad";    //while (getline(f,s))cout<<s<<endl;
    char c;
    while(f.get(c))  s+=c;
    f.close();
    if(s.size()==0) return 0;

    while(s.size()>0)
    {
        type_product c;
        product.push_back(c);
        string part;
        //ID

        for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.';++i)
            part+=s[i];
        s.erase(0,part.size()+1);

        product[product.size()-1].ID=str_in_int(part);
        part="";
        //NAME

       for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.';++i)
            part+=s[i];
        s.erase(0,part.size()+1);
        product[product.size()-1].name=part;
        part="";

        //TYPE
        for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.';++i)
            part+=s[i];
        s.erase(0,part.size()+1);
        if(part=="3" || part=="BAG") product[product.size()-1].type=BAG;
        if(part=="0" || part=="KGRAM") product[product.size()-1].type=KGRAM;
        if(part=="1" || part=="LITER") product[product.size()-1].type=LITER;
        if(part=="2" || part=="PIESE") product[product.size()-1].type=PIESE;
        part="";

        //AMOUNT
        for(int i=0;s[i]!= ' ' && s[i]!='\n';++i)
            part+=s[i];
        s.erase(0,part.size()+1);
        product[product.size()-1].amount=str_in_double(part);
        part="";
        //HOUR
        for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.';++i)
            part+=s[i];
        s.erase(0,part.size()+1);
        product[product.size()-1].data.hour=str_in_int(part);
        part="";
        //MINUTES
        for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.';++i)
            part+=s[i];
        s.erase(0,part.size()+1);
        product[product.size()-1].data.minutes=str_in_int(part);
        part="";
        //DAY
        for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.';++i)
            part+=s[i];
        s.erase(0,part.size()+1);
        product[product.size()-1].data.day=str_in_int(part);
        part="";
        //MONTH
        for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.';++i)
            part+=s[i];
        s.erase(0,part.size()+1);
        product[product.size()-1].data.month=str_in_int(part);
        part="";
        //YEAR
       for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.';++i)
            part+=s[i];
        s.erase(0,part.size()+1);
        product[product.size()-1].data.year=str_in_int(part);
        part="";
        //EXPIRED_TIME

        for(int i=0;s[i]!= ' ' && s[i]!='\n' && s[i]!='.' && s.size()>i;++i)
            part+=s[i];
        s.erase(0,part.size()+1);

        product[product.size()-1].expired_time=str_in_int(part);
        part="";

    }
    if(0)
    for(int i=0;i<product.size();++i)
    {
        cout<<product[i].ID<< "  "<<product[i].name<<" "<<product[i].type<<"  "<<product[i].amount <<"    ";
        cout<<product[i].data.hour <<"."<<product[i].data.minutes <<"    "<<product[i].data.day <<"."<<product[i].data.month <<"    ";
        cout<<product[i].data.year <<"    "<<product[i].expired_time <<"    \n";
    }
    return 1;
}
