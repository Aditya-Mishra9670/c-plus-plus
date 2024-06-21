#include <iostream>
#include <algorithm>
using namespace std;

int findnumber(int arr[], int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n; i += 3) {
        
        if (i + 2 >= n || arr[i] != arr[i + 1] || arr[i] != arr[i + 2]) {
            return arr[i];
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {1, 1, 1, 3, 3,0, 3, 2, 2, 2}; // Example without a unique element
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findnumber(arr, n);
    return 0;
}
