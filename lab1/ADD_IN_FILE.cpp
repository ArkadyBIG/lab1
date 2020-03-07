#include <bits/stdc++.h>
#include <fstream>
#include <cmath>
#include <string>
#include "Product.h"
extern vector<type_product> product;
bool synchronize()
{

    if(product.size()>=2)
    for(int i=0;i<product.size()-1;++i)
        if(product[i].ID<product[i+1].ID)
    {
        type_product a=product[i];
        product[i]=product[i+1];
        product[i+1]=a;
        i--;
    }
    fstream f("PRODUCTS.txt",ios_base::out);

    string information;
    for(int i=0;i<product.size();++i)
    {
        information="";
        information+=to_string(product[i].ID)+" "+product[i].name+" "+to_string(product[i].type)+" "
            +to_string(product[i].amount)+" "+to_string(product[i].data.hour )+"."
            +to_string(product[i].data.minutes )+" "+to_string(product[i].data.day )+"."
            +to_string(product[i].data.month )+"."+to_string(product[i].data.year )+" "
            +to_string(product[i].expired_time )+"\n";
        f<<information;
    }
    f.close();
}
using namespace std;

