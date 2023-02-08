#include <iostream>

#include "datastructure/trie.h"

using namespace std;

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple");
    return 0;
}
