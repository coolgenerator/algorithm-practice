#include "splay_tree.h"
#include "test.h"
#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

int main() {
    splayTree<int> st;

    // test size
    testEquals(size_t(0), st.size(), "Empty tree have size 0");
    st.add(10);
    st.add(20);
    st.add(30);
    st.add(40);
    st.add(50);
    
    // test add, contains
    testEquals(size_t(5), st.size(), "Tree size is 5");
    
    testTrue(st.contains(10), "Tree contains 10");
    testFalse(st.contains(60), "Tree do not contain 60");
    
    // test remove
    st.remove(10);
    testEquals(size_t(4), st.size(), "Tree size is 4 after removing");
    testFalse(st.contains(10), "Tree do not contain 10");

    return 0;
}