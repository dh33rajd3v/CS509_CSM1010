#include "../headers/bf.h"
#include "../../csr_file.h"

using namespace std;

// struct CSRGraph_withWeight
// {
//     int vertices;
//     int edges;

//     vector<int> row_ptr;
//     vector<int> col_idx;
//     vector<int> values;
// };

// CSRGraph_withWeight readGraph_withWeight(
//     const string& filename,
//     int& source)
// {
//     ifstream inputFile(filename);

//     if (!inputFile)
//     {
//         cerr << "Unable to open file.\n";
//         exit(1);
//     }

//     CSRGraph_withWeight graph;

//     inputFile >> graph.vertices
//               >> graph.edges;

//     graph.row_ptr.push_back(0);

//     for (int i = 0; i < graph.vertices; i++)
//     {
//         int vertex;
//         int degree;
//         int weight;

//         inputFile >> vertex >> degree;

//         for (int j = 0; j < degree; j++)
//         {
//             int neighbour;

//             inputFile >> neighbour >> weight;

//             graph.col_idx.push_back(
//                 neighbour
//             );

//             graph.values.push_back(
//                 weight
//             );
//         }

//         graph.row_ptr.push_back(
//             graph.col_idx.size()
//         );
//     }

//     string label;

//     inputFile >> label >> source;

//     inputFile.close();

//     return graph;
// }

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

    
    for (int vertex = 0; vertex < graph.vertices; vertex++)   // One more pass to detect a negative-weight cycle
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
                is_neg=true;        // Negative-weight cycle reachable from source
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
    cout<<"\nExecution time: "<<duration.count() <<" microseconds\n";
}


void run_bf()
{
    int source;

    CSRGraph_withWeight graph =
        readGraph_withWeight("assignment2/tests/bf_5.txt", source);


    bellman_ford(
        graph,
        source
    );
}