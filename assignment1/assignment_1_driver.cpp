#include "assignment_1_driver.h"

using namespace std;

void assignment1_func(){
    int choice;

    cout<< "1. GEMM Simple" <<"\n2. GEMM Blocking"<<"\n3. CSR Representation\n";

    cin>>choice;

    switch(choice){
        case 1: 
            gemm_simple();
            break;

        case 2:
            gemm_blocking();
            break;

        case 3:
            CSR_func();
            break;

        default:
            cout<<"invalid choice";

    }
}

// int main(){
//     assignment1_func();
// }