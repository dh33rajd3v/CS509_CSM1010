#include "../headers/gemm_simple.h"
using namespace std;

void gemm_simple(){
    auto start = chrono::high_resolution_clock::now();

    int row1, common, col2;
    ifstream file("assignment1/tests/gemm_input.txt");
    if (!file) {
        cerr << "Error opening gemm_input.txt\n";
    }

    file>> row1>> common>> col2;

    // getline(file, line);

    vector<vector<int>> matrix1(row1, vector<int>(common, 0));
    vector<vector<int>> matrix2(common, vector<int>(col2, 0));

    for(int i=0; i<row1; i++){
        for(int j=0; j<common; j++){
            file>>matrix1[i][j];
        }
    }

    for(int i=0; i<common; i++){
        for(int j=0; j<col2; j++){
            file>>matrix2[i][j];
        }
    }

    file.close();

    vector<vector<int>> result(row1, vector<int>(col2, 0));

    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            for(int k=0; k<common; k++){
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout<<"Algorithm: GEMM Simple\nresult matrix:\n";

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Execution time: "<<duration.count() <<" microseconds";


}