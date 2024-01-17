#include <string>

#ifndef LCS_H
#define LCS_H

size_t** createMatrix(size_t, size_t);

size_t** buildTable(const std::string&, const std::string&);

std::string lcs(const std::string&, const std::string&);

#endif