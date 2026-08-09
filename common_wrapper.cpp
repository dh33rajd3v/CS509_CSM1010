#include <iostream>
#include "assignment1/assignment_1_driver.h"
#include "assignment2/assignment_2_driver.h"


using namespace std;

int main(){
    int choice;
    cout<<"---------------------------\n\nEnter your choice: \n 1. Assignment 1\n 2. Assignment 2 \n 0. Exit\n";

    cin>>choice;

    switch (choice){
        case 1:
            assignment1_func();
            break;
        case 2:
            assignment2_func();
            break;
        case 0:
            break;
        default:
            cout<<"invalid input";
    }


}