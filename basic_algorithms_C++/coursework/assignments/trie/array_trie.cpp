#include <iostream>
#include "array_trie.h"
#include "test.h"

int main() {
    ArrayTrie<std::string> trie;

    //test add 
    trie.add("bear");
    trie.add("tiger");
    trie.add("elephant");
    trie.add("catapult");
    trie.add("zebra");

    testTrue(trie.contains("bear"), "Trie contains bear");
    testTrue(trie.contains("tiger"), "Trie contains tiger");
    testTrue(trie.contains("elephant"), "Trie contains elephant");
    testTrue(trie.contains("catapult"), "Trie contains catapult");
    testTrue(trie.contains("zebra"), "Trie contains zebra");
    testFalse(trie.contains("cat"), "Trie does not contain cat");

    // test remove
    trie.remove("cataract");
    testFalse(trie.contains("cataract"), "Trie does not contain cataract");

    // test size
    std::cout << "Size of trie: " << trie.size() << std::endl;

    testFalse(trie.empty(), "Trie is not empty");

    return 0;
}

