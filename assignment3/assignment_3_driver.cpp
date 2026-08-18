#include "assignment_3_driver.h"
#include "headers/kruskal.h"
#include "headers/prim.h"

void assignment3_func(){
    int choice;

    cout<< "---------------------------\n\n1. Kruskal's algorithm" <<"\n2. Prim's algorithm\n\n : ";

    cin>>choice;

    switch(choice){
        case 1:
            kruskal_fn();
            // for kruskal
            break;

        case 2:
            prim_fn();
            // prim
            break;

        default:
            cout<<"invalid choice";
    }
}