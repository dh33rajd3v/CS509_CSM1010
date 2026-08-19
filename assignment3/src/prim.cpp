#include "../headers/prim.h"

struct Edge
{
    int weight;
    int vertex;
    int parent;

    bool operator>(const Edge& other) const
    {
        return weight > other.weight;
    }
};



void prim_fn()
{
    int source;

    string folder = "assignment3/tests/mst";
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

    cout << "Prims's algorithm test files:\n\n";

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


    auto start = chrono::high_resolution_clock::now();

    vector<Edge> edges;



    for (int u = 0; u < graph.vertices; u++)
    {
        int start = graph.row_ptr[u];
        int end = graph.row_ptr[u + 1];

        for (int i = start; i < end; i++)
        {
            int v = graph.col_idx[i];
            int weight = graph.values[i];

            if (u < v)
            {
                edges.push_back({u, v, weight});
            }
        }
    }



    int V = graph.vertices;

    if (V == 0)
    {
        cout << "Graph is empty.\n";
        return;
    }

    vector<int> key(V, INT_MAX);

    vector<int> parent(V, -1);

    vector<bool> inMST(V, false);

    priority_queue<
        Edge,
        vector<Edge>,
        greater<Edge>
    > pq;



    key[0] = 0;

    pq.push({0, 0, -1});


    vector<Edge> mst;

    long long totalWeight = 0;




    while (!pq.empty())
    {
        Edge current = pq.top();
        pq.pop();

        int u = current.vertex;


        if (inMST[u])
            continue;


        inMST[u] = true;


        if (current.parent != -1)
        {
            mst.push_back({
                current.weight,
                u,
                current.parent
            });

            totalWeight += current.weight;
        }



        int start = graph.row_ptr[u];
        int end = graph.row_ptr[u + 1];

        for (int i = start; i < end; i++)
        {
            int v = graph.col_idx[i];
            int weight = graph.values[i];


            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;

                pq.push({
                    weight,
                    v,
                    u
                });
            }
        }
    }


    if ((int)mst.size() != V - 1)
    {
        cout << "MST does not exist.\n";
        cout << "The graph is disconnected.\n";
        return;
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Algorithm: Prim's MST \n";
    cout << "MST Edges:\n";

    for (const Edge& edge : mst)
    {
        cout << edge.parent
             << " "
             << edge.vertex
             << " "
             << edge.weight
             << '\n';
    }

    cout << "\nTotal MST Weight: "
         << totalWeight
         << '\n';

    cout<<"\nExecution time: "<<duration.count() <<" * 10^-3 milliseconds\n";
}