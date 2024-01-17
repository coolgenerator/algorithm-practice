#include "lcs.h"

size_t** buildTable(const std::string& s, const std::string& t){
    size_t m{s.size() + 1};
    size_t n{t.size() + 1};
    size_t** matrix = createMatrix(m, n);
    
    for(size_t i = 1; i < m; ++i)
        for(size_t j = 1; j < n; ++j)
            matrix[i][j] = (s[i - 1] == t[j - 1]) ? matrix[i - 1][j - 1] + 1 : std::max(matrix[i][j - 1], matrix[i - 1][j]);

    return matrix;
}

size_t** createMatrix(size_t rows, size_t cols){
    size_t** matrix = new size_t*[rows];
    for(size_t i = 0; i < rows; ++i)
        matrix[i] = new size_t[cols]{ };

    return matrix; 
}



std::string lcs(const std::string& s, const std::string& t){
    std::string rtnStr{};
    size_t** table = buildTable(s, t);
    
    size_t row{s.size()};
    size_t col{t.size()};
    
    while(row > 0 && col > 0){
        if(s[row - 1] == t[col - 1]){
            rtnStr = s[row - 1] + rtnStr;
            --row;
            --col;
        }
        else{
            (table[row][col - 1] > table[row - 1][col]) ? --col : --row;
        }
    }
    return rtnStr;
}