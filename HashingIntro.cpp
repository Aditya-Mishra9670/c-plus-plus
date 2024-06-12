#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class hashmap {
    vector<list<int>> hashtable;
    int buckets;

public:
    hashmap(int size) {
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key) {
        return key % buckets; // used division method
    }

    void insert(int key) {
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }

    bool searchkey(int key) {
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key) != hashtable[idx].end();
    }

    void deletekey(int key) {
        int idx = hashvalue(key);
        auto it = find(hashtable[idx].begin(), hashtable[idx].end(), key);
        if (it != hashtable[idx].end()) {
            hashtable[idx].erase(it);
            cout << key << " is deleted successfully" << endl;
        } else {
            cout << key << " is not present in the hashtable" << endl;
        }
    }
};

int main() {
    hashmap h(4);
    h.insert(1);
    h.insert(3);
    h.insert(4);

    if (h.searchkey(2)) {
        cout << "2 is found in the hashtable" << endl;
    } else {
        cout << "2 is not found in the hashtable" << endl;
    }

    h.deletekey(3);

    return 0;
}
