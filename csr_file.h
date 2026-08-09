#ifndef CSR_FILE_H
#define CSR_FILE_H

#include <vector>
#include <string>

struct CSR {
    std::vector<int> row_ptr;
    std::vector<int> col_idx;
    std::vector<int> values;
};

struct CSRGraph_withWeight {
    int vertices;
    int edges;

    std::vector<int> row_ptr;
    std::vector<int> col_idx;
    std::vector<int> values;
};

CSRGraph_withWeight readGraph_withWeight(
    const std::string& filename,
    int& source
);

void CSR_func();

#endif