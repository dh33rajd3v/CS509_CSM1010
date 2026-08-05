#include "../headers/gemm_blocking.h"
using namespace std;

// const int tile_size_x = 4;
// const int tile_size_y = 4;
const int tile_size = 4;


void gemm_blocking(){
    auto start = chrono::high_resolution_clock::now();

    ifstream file("assignment1/tests/gemm_input.txt");

    if (!file) {
        cerr << "Error opening gemm_input.txt\n";
    }

    int row1, common, col2;

    file>> row1>> common>> col2;


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

    vector<vector<int>> result(row1, vector<int>(col2, 0));

    int end_i, end_j, end_k;

    for(int i=0; i<row1; i+=tile_size){
        end_i = min(i+tile_size, row1);
        for(int j=0; j<col2; j+=tile_size){
            end_j = min(j+tile_size, col2);
            for(int k=0; k<common; k+=tile_size){
                end_k = min(k+tile_size, common);

                for(int m=i; m<end_i; m++){
                    for (int n = k; n < end_k; n++) {
                        for(int o =j; o<end_j; o++){
                            result[m][o] += matrix1[m][n]*matrix2[n][o];
                        }
                    }

                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout<<"Algorithm: GEMM Blocking\nresult matrix:\n";

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Execution time: "<<duration.count() <<" microseconds";


}