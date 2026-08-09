#include "assignment_2_driver.h"

using namespace std;

void assignment2_func(){
    int choice;

    cout<< "---------------------------\n\n1. Bellman-Ford" <<"\n2. Floyd-Warshall "<<"\n3. CSR Representation\n";

    cin>>choice;

    switch(choice){
        case 1: 
            run_bf();
            break;

        case 2:
            floyd_w();
            break;

        case 3:
            CSR_func();
            break;

        default:
            cout<<"invalid choice";
    }
}
