#include <iostream>

#include "lcs.h"
#include "lcs.cpp"

void printTable(size_t** table, const std::string& s, const std::string t){
    for(size_t i = 0; i < s.size() + 1; ++i){
        std::cout << "| ";
        for(size_t j = 0; j < t.size() + 1; ++j)
            std::cout << table[i][j] << "| ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(){

    std::string s{"jkjkjkjkjkkkjk"};
    std::string t{"jkjkkkkjkjkjk"};
    size_t** table = buildTable(s, t);
    printTable(table, s, t);

    // std::cout << "lcs = " << lcs(s, t) << std::endl;
    return 0;
}