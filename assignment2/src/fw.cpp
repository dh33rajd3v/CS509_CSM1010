#include "../headers/fw.h"
#include <chrono>

using namespace std;

void floyd_w(){

    auto start = chrono::high_resolution_clock::now();

    int vertices;
    string filename = "assignment2/tests/fw_5.txt";
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cerr << "Unable to open file.\n";
        exit(1);
    }

    inputFile >> vertices;

    vector<vector<int>> fw_matrix(vertices, vector<int>(vertices, INT_MAX));

    string value;

    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            inputFile>>value;

            if (value == "INF")
                fw_matrix[i][j] = INT_MAX;
            else
                fw_matrix[i][j] = stoi(value);
        }
    }

    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (fw_matrix[i][k] < INT_MAX && fw_matrix[k][j] < INT_MAX)
                    fw_matrix[i][j] = min(fw_matrix[i][j], fw_matrix[i][k] + fw_matrix[k][j]); 
            }
        }
    }

    bool check_neg = false;

    for(int i=0; i<vertices; i++){
        if(fw_matrix[i][i] < 0){
            check_neg = true;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout<<"Algorithm: Floyd-Warshall";
    
    if(check_neg){
        cout<<"\nNegative cycle: true";
    } 
    else{
        cout<<"\nDistance matrix:\n";

        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){
                cout<<fw_matrix[i][j]<<"\t";
            }
            cout<<"\n";
        }

        cout<<"Negative cycle: none\n";
    }

    cout<<"\nExecution time: "<<duration.count() <<" microseconds\n";

}

// int main(){
//     floyd_w();
//     return 0;
// }