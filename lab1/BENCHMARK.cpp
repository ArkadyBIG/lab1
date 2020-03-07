#include <windows.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <fstream>

#include "Product.h"
#include "choose_a_choise.h"

using namespace std;

const int growth=2;
const int MAX_elements=8e6;
const int MAX_mSeconds=5e3;
CONSOLE_SCREEN_BUFFER_INFO c;


void add_products(vector<type_product> &P)
    {
        for(int i=P.size(),n=growth*P.size();i<n;++i)
        {
            P.push_back(P.back());
            P.back().ID++;
        }
    }
void find_elemrnts(vector<type_product> product_test)
{
    srand(time(0)+product_test.size());

    for(int i=0;i<1000;++i)
    {

            int rand_ID=rand()%product_test.size();//cout<<1<<endl;
            for(int i=0;i<product_test.size();++i)
            {

                if(product_test[i].ID==rand_ID)
                break;
                else if(i==product_test.size()-1) cout<<"Huston y nas problemi"<<endl;
            }


    }
    //cout<<endl;
}
void Dynamic_memory_test()
{
    vector<type_product> product_test(1);
    {
    type_product a;
    a.name="TEST";
    a.ID=0;
    a.data.day=0;
    a.data.month=0;
    a.data.year=0;
    product_test[0]=a;
    }

    clock_t Time=clock();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    cout<<"-----Number--|--"<<"Memory(bytes)--|---Time(miliSec)----"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    while(true)
    {
        Time=clock();
        find_elemrnts(product_test);
        int dTime= clock()-Time;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y});
        cout<<'#';
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{5,c.dwCursorPosition.Y});
        cout<<product_test.size();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{16,c.dwCursorPosition.Y});
        cout<<product_test.size()*sizeof(product_test);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{51,c.dwCursorPosition.Y});
        cout<<'#';
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{35,c.dwCursorPosition.Y});
        cout<<dTime<<endl;
        if(dTime>MAX_mSeconds || product_test.size()>MAX_elements) return;
        add_products(product_test);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void File_memory_test()
{
    fstream F("File_memory_test.txt",ios_base::out);
    if(!F.is_open())
    {
        cout<<"File wasnt found\n"<<endl;
        return;
    }
    srand(time(0));
    type_product a;
    a.ID=0;
    F<<a.ID++<<'+'<<a.amount<<'+'<<a.data.year<<'+'<<a.data.month<<'+'<<a.data.minutes<<'+'<<a.data.hour<<'+'<<a.data.day<<'+'<<a.expired_time<<'+'<<a.name<<'*';
    F.close();
    clock_t Time;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    cout<<"-----Number--|--"<<"Memory(bytes)--|---Time(miliSec)----"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    while(true)
    {
        Time=clock();
        for(int k=0;k<1000;++k)
        {
            F.open("File_memory_test.txt");
            //F.seekg(0,ios::beg);
            int rand_ID=rand()%a.ID;

            while(!F.eof())
            {
                char c=36;
                string ID="";
                F.get(c);
                while(c!='+')
                {
                    ID+=c;
                    F.get(c);
                }
                //if(ID!="0")cout<<ID<<endl;
                if(ID==to_string(rand_ID)) break;
                while(c!='*') F.get(c);

            }

            if(F.eof()) cout<<"Huston y nas problemi"<<endl;
            F.close();
        }
        int dTime= clock()-Time;
        F.open("File_memory_test.txt");
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y});
        cout<<'#';
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{5,c.dwCursorPosition.Y});
        cout<<a.ID;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{16,c.dwCursorPosition.Y});
        F.seekg(0,ios::end);
        cout<<F.tellg();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{51,c.dwCursorPosition.Y});
        cout<<'#';
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{35,c.dwCursorPosition.Y});
        cout<<dTime<<endl;
        F.close();
        if(dTime>MAX_mSeconds || a.ID>MAX_elements) return;
        {
            F.open("File_memory_test.txt",ios::app);
         for(int i=a.ID,n=a.ID*2;i<n;++i)
         {
             F<<a.ID++<<'+'<<a.amount<<'+'<<a.data.year<<'+'<<a.data.month<<'+'<<a.data.minutes<<'+'<<a.data.hour<<'+'<<a.data.day<<'+'<<a.expired_time<<'+'<<a.name<<'*';
         }
         F.close();

        }


    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

}

void File_binary_memory_test()
{
    fstream F("File_binary_memory_test.txt",ios::binary | ios::out);
    if(!F.is_open())
    {
        cout<<"File wasnt found\n"<<endl;
        return;
    }
    srand(time(0));
    type_product a;
    a.ID=0;

    F.write((char*) &a,sizeof(a));
    a.ID++;
    F.close();

    clock_t Time;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    cout<<"-----Number--|--"<<"Memory(bytes)--|---Time(miliSec)----"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    while(true)
    {
        Time=clock();
        for(int k=0;k<1000;++k)
        {

            ifstream R("File_binary_memory_test.txt",ios::binary );
            //F.seekg(0,ios::beg);
            int rand_ID=rand()%a.ID;

            while(!R.eof())
            {
                type_product c;
                R.read((char*)&c,sizeof(c));
                if(c.ID==rand_ID) break;
                //cout<<c.ID<<ends;
            }

            if(R.eof() && rand_ID!=a.ID-1) cout<<"Huston y nas problemi"<<endl;
            R.close();

        }
        int dTime= clock()-Time;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&c);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,c.dwCursorPosition.Y});
        cout<<'#';
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{5,c.dwCursorPosition.Y});
        cout<<a.ID;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{16,c.dwCursorPosition.Y});
        //F.seekg(0,ios::end);
        cout<<sizeof(a)*(a.ID-1);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{51,c.dwCursorPosition.Y});
        cout<<'#';
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{35,c.dwCursorPosition.Y});
        cout<<dTime<<endl;

        if(dTime>MAX_mSeconds || a.ID>MAX_elements) return;
        {
                        F.open("File_binary_memory_test.txt",ios::binary | ios::app);
         for(int i=a.ID,n=a.ID*2;i<n;++i)
         {
             F.write((char*) &a,sizeof(a));
             a.ID++;
         }
         F.close();

        }


    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

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
        system("cls");
        cout<<"DYNAMIC MEMORY TEXT"<<endl;
        Dynamic_memory_test();
        break;
    case 1:
        system("cls");
        cout<<"File MEMORY TEXT"<<endl;
        File_memory_test();
        break;
    case 2:
        system("cls");
        cout<<"File MEMORY TEXT"<<endl;
        File_binary_memory_test();
        break;
    }


}

