#include <iostream>
#include <vector>
#include <list>
#include <cmath> 
using namespace std;
vector<list<int>> AdityaPower(int arr[], int n) {
    vector<list<int>> subsets;
    
    int itr = pow(2, n);
    for (int i = 0; i < itr; i++) {
        list<int> lm;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                lm.push_back(arr[j]);
            }
        }
        subsets.push_back(lm);
    }
    
    return subsets;
}

int main() {
    int arr[] = {1, 2, 3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<list<int>> result = AdityaPower(arr, n);
    for (const auto& subset : result) {
        cout << "{ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "}\n";
    }
    return 0;
}
