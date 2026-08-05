#include "../headers/csr_file.h"

using namespace std;

struct CSR {
    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;
};

void CSR_func() {

    auto start = chrono::high_resolution_clock::now();

    ifstream file("assignment1/tests/csr_input.txt");

    if (!file) {
        cerr << "Error opening file!\n";
    }

    string line;
    vector<vector<int>> matrix;

    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> row;
        int x;

        while (ss >> x)
            row.push_back(x);

        if (!row.empty())
            matrix.push_back(row);
    }

    file.close();

    int n = matrix.size();
    vector<vector<pair<int, int>>> adj(n);

    // Build adjacency list
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] != 0)
                adj[i].push_back({j, matrix[i][j]});
        }
    }


    cout << "\nAdjacency List:\n";
    cout << "---------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " -> ";

        if (adj[i].empty()) {
            cout << "(empty)";
        } else {
            for (size_t j = 0; j < adj[i].size(); j++) {
                cout << "(" << adj[i][j].first   // destination vertex
                    << ", " << adj[i][j].second // edge weight/value
                    << ")";
                if (j + 1 < adj[i].size())
                    cout << " -> ";
            }
        }

        cout << '\n';
    }
    cout << "---------------------------\n";

    // Count total edges
    int m = 0;
    for (const auto &nbrs : adj)
        m += nbrs.size();

    CSR csr;
    csr.row_ptr.resize(n + 1);
    csr.col_idx.resize(m);
    csr.values.resize(m);

    int idx = 0;
    csr.row_ptr[0] = 0;

    for (int i = 0; i < n; i++) {
        for (auto [x, y] : adj[i]) {
            csr.col_idx[idx] = x;
            csr.values[idx] = y;
            idx++;
        }
        csr.row_ptr[i + 1] = idx;
    }

    cout << "row_ptr: ";
    for (int x : csr.row_ptr)
        cout << x << " ";
    cout << "\n";

    cout << "col_idx: ";
    for (int x : csr.col_idx)
        cout << x << " ";
    cout << "\n";

    cout << "values : ";
    for (int x : csr.values)
        cout << x << " ";
    cout << "\n";

    auto end = chrono::high_resolution_clock::now();
    cout << "\nTime: "
         << chrono::duration<double, milli>(end - start).count()
         << " ms\n";

}
