#include <windows.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <random>

#include "Product.h"
#include "choose_a_choise.h"

using namespace std;
void add_products(vector<type_product> &P,type_product &a,int num)
    {
        for(int i=P.size();i<num;++i)
        {

            if((++a.data.day)==31)
            {
                a.data.day=0;
                if((++a.data.month)==13)
                {
                    a.data.month=0;
                    a.data.year++;
                }
            }
            P.push_back(a);
        }
    }
void find_elemrnts(vector<type_product> product_test)
{
    srand(time(0)+product_test.size());

    for(int i=0;i<1000;++i)
    {

            int rand_day=rand()%product_test.size()%31;//cout<<1<<endl;
            int rand_month=product_test.size()<30 ? 0  : rand()%(product_test.size()/30)%12,rand_year=product_test.back().data.year<2 ? 0 : rand()%(product_test.back().data.year-1);


           // cout<<index<<ends;
           bool element_was_found=0;
            for(int k=0;k<product_test.size();++k)
                if(product_test[k].data.day==rand_day && product_test[k].data.month==rand_month && product_test[k].data.year==rand_year)
                {
                    element_was_found=1;
                    break;
                }

            if(!element_was_found)
                cout<<rand_day<<ends<<rand_month<<ends<<rand_year<<endl<<": "<<product_test[product_test.size()-1].data.day<<ends<<product_test[product_test.size()-1].data.month<<ends<< product_test[product_test.size()-1].data.year<<endl;
            //else cout<<"Good\n";

    }
    //cout<<endl;
}
void Dynamic_memory_test()
{
    vector<type_product> product_test(1);
    type_product a;
    a.name="TEST";
    a.ID=0;
    a.data.day=0;
    a.data.month=0;
    a.data.year=0;
    product_test[0]=a;

    int growth=2;
    clock_t Time=clock();
    while(true)
    {

        //_getch();

        //cout<<product_test.size()<<ends<<product_test[product_test.size()-1].data.day<<ends<<product_test[product_test.size()-1].data.month<<ends<<product_test[product_test.size()-1].data.year<<endl;
        //if(product_test.size()>1)cout<<product_test[product_test.size()-2].data.day<<ends<<product_test[product_test.size()-2].data.month<<ends<<product_test[product_test.size()-2].data.year<<endl;
        //if(product_test.size()==4)cout<<product_test[product_test.size()-3].data.day<<ends<<product_test[product_test.size()-3].data.month<<ends<<product_test[product_test.size()-3].data.year<<endl;
        Time=clock();
        find_elemrnts(product_test);
        int dTime= clock()-Time;
        cout<<"Number of products "<<product_test.size()<<ends<<".Memory taken "<<product_test.size()*sizeof(product_test)<<" bytes.Time "<<dTime<<endl;
        if(dTime>10000) return;
        add_products(product_test,a,product_test.size()*growth);
    }

}
void BENCHMARK()
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    cout<<"BENCHMARK MODE\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    switch(choose({"Dynamic memory test","File test","Binary File test"}))
    {
    case 0:
        Dynamic_memory_test();
        break;
    }


}

