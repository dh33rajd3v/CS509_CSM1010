#include "../headers/kruskal.h"

struct Edge
{
    int u;
    int v;
    int weight;
};

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        // Already in the same component
        if (rootA == rootB)
            return false;

        // Union by rank
        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }
};

void kruskal_fn()
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

    cout << "Kruskal's algorithm test files:\n\n";

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


    vector<Edge> edges;

    // ----------------------------------------------
    // Extract edges from CSR
    // ----------------------------------------------

    for (int u = 0; u < graph.vertices; u++)
    {
        int start = graph.row_ptr[u];
        int end = graph.row_ptr[u + 1];

        for (int i = start; i < end; i++)
        {
            int v = graph.col_idx[i];
            int weight = graph.values[i];

            // For an undirected graph, CSR contains
            // both (u,v) and (v,u).
            // Keep only one copy.
            if (u < v)
            {
                edges.push_back({u, v, weight});
            }
        }
    }


    // ----------------------------------------------
    // Sort edges by increasing weight
    // ----------------------------------------------

    sort(edges.begin(), edges.end(),
        [](const Edge& a, const Edge& b)
        {
            return a.weight < b.weight;
        });


    // ----------------------------------------------
    // DSU
    // ----------------------------------------------

    DSU dsu(graph.vertices);

    vector<Edge> mst;

    long long totalWeight = 0;


    // ----------------------------------------------
    // Kruskal's algorithm
    // ----------------------------------------------

    for (const Edge& edge : edges)
    {
        if (dsu.unite(edge.u, edge.v))
        {
            mst.push_back(edge);
            totalWeight += edge.weight;

            // MST has V-1 edges
            if ((int)mst.size() == graph.vertices - 1)
                break;
        }
    }



    if ((int)mst.size() != graph.vertices - 1)
    {
        cout << "MST does not exist.\n";
        cout << "The graph is disconnected.\n";
        return;
    }


    cout<<"Algorithm: Kruskal's MST\n";
    cout << "MST Edges:\n";

    for (const Edge& edge : mst)
    {
        cout << edge.u
             << " "
             << edge.v
             << " "
             << edge.weight
             << '\n';
    }

    cout << "\nTotal MST Weight: "
         << totalWeight
         << '\n';

    
}