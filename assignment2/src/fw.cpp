#include "../headers/fw.h"
#include <chrono>
#include <filesystem>

using namespace std;

void floyd_w(){

    int vertices;
    string folder = "assignment2/tests/floydwarshall_tests";
    vector<string> files;

    for (const auto& entry : filesystem::directory_iterator(folder))
    {
        if (entry.is_regular_file())
        {
            files.push_back(entry.path().string());
        }
    }

    if (files.empty())
    {
        cout << "No files found in " << folder << "\n";
        return;
    }

    cout << "Floyd-Warshall test files:\n\n";

    for (size_t i = 0; i < files.size(); i++)
    {
        cout << i + 1 << ". "
             << filesystem::path(files[i]).filename().string()
             << "\n";
    }

    int choice;

    cout << "\nEnter serial number: ";
    cin >> choice;

    if (choice < 1 || static_cast<size_t>(choice) > files.size())
    {
        cout << "Invalid serial number.\n";
        return;
    }

    string filename = files[choice - 1];

    cout << "Selected file: "
         << filesystem::path(filename).filename().string()
         << "\n\n";

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

    auto start = chrono::high_resolution_clock::now();

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

    cout<<"\nExecution time: "<<duration.count() <<" * 10^-3 milliseconds\n";

}
