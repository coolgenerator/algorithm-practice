#include <cstddef>

#ifndef TRIE_NODE_H
#define TRIE_NODE_H

template<size_t S>
struct TrieNode
{
    bool terminal{};
    TrieNode* next[S]{};
};

#endif /* TRIE_NODE_H */
