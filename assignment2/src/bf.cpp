#include "../headers/bf.h"
#include "../../csr_file.h"
#include <filesystem>

using namespace std;

void bellman_ford(
    const CSRGraph_withWeight& graph,
    int source)
{
    auto start = chrono::high_resolution_clock::now();
    bool is_neg = false;
    vector<int> distances;
    distances.assign(graph.vertices, INT_MAX);

    distances[source] = 0;

    for (int i = 0; i < graph.vertices - 1; i++)
    {
        bool changed = false;

        for (int vertex = 0; vertex < graph.vertices; vertex++)
        {
            if (distances[vertex] == INT_MAX)
                continue;

            for (int j = graph.row_ptr[vertex];
                 j < graph.row_ptr[vertex + 1];
                 j++)
            {
                int neighbour = graph.col_idx[j];
                int weight = graph.values[j];

                if (distances[neighbour] >
                    distances[vertex] + weight)
                {
                    distances[neighbour] =
                        distances[vertex] + weight;

                    changed = true;
                }
            }
        }

    
        if (!changed)
            break;
    }

    
    for (int vertex = 0; vertex < graph.vertices; vertex++)  
    {
        if (distances[vertex] == INT_MAX)
            continue;

        for (int j = graph.row_ptr[vertex];
             j < graph.row_ptr[vertex + 1];
             j++)
        {
            int neighbour = graph.col_idx[j];
            int weight = graph.values[j];

            if (distances[neighbour] >
                distances[vertex] + weight)
            {
                is_neg=true;       
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    if (is_neg)
    {   
        cout<<"Algorithm: Bellman-Ford\nSource: "<<source<<"\n\n";
        cout << "Negative cycle: true\n";
    }

    else{
        cout<<"Algorithm: Bellman-Ford\nSource: "<<source<<"\n\n";
        cout << left << setw(10) << "Vertex" << "Distance\n";

        for (int vertex = 0; vertex < graph.vertices; vertex++)
        {
            if (distances[vertex] == INT_MAX)
                cout << left << setw(10) << vertex << "INF\n";
            else
                cout << left << setw(10) << vertex << distances[vertex] << '\n';
        }

        cout<<"Negative cycle: none";
    }
    cout<<"\nExecution time: "<<duration.count() <<" * 10^-3 milliseconds\n";
}


void run_bf()
{
    int source;

    string folder = "assignment2/tests/bellman_ford_tests";
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

    cout << "Bellman-Ford test files:\n\n";

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

    string selectedFile = files[choice - 1];

    cout << "Selected file: "
         << filesystem::path(selectedFile).filename().string()
         << "\n\n";

    CSRGraph_withWeight graph =
        readGraph_withWeight(selectedFile, source);

    bellman_ford(
        graph,
        source
    );
}