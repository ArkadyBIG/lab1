#include <iostream>
#include "choose_a_choise.h"
#include "Product.h"
#include "REED_FILE.h"
#include "ADD_IN_FILE.h"
#include "show_products.h"
#include "search_product.h"
#include "EDIT_PRODUCT.h"
#include "BENCHMARK.h"
#include "DEMONSTRTION.h"

using namespace std;
//
vector<type_product> product(0);
int main()
{
    GET_FILE();
    if(!show_products())
    {
        cout<<"No products were found.\nLets create new product\n";
        new_product_f();
    }
    while(1)
    {
        switch(choose({"SHOW ALL PRODUCTS","SEARCH","EDIT","BENCHMARK MODE","DEMONSTRATION","EXIT"}))
        {
        case 0:
            system("cls");
            if(!show_products())
                {
                    cout<<"No products were found.\nLets create new product\n";
                    new_product_f();
                }
            break;
        case 1:
            search_products();
            break;
        case 2:
            system("cls");
            switch(choose({"NEW PRODUCT","MAKE CHANGES"}))
            {
            case 0:
                new_product_f();
                break;
            case 1:
                edit_product();
                break;
            }
            break;
        case 3:
            BENCHMARK();

            break;
        case 4:
            DEMONSTRATION();
            system("cls");
            break;
        case 5:
            return 1;
        }
    }

    return 0;
}
