// This code is to find the non-repeating number among all numbers that repeat thrice.
#include<iostream>
using namespace std;

int findnumber(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] & (1 << i)) {
                count++;
            }
        }
        if (count % 3 == 1) {
            ans = ans | (1 << i);
        }
    }
    return ans;
}

int main() {
    int arr[] = {5, 5, 5, 2, 2, 2, 3, 4, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << findnumber(arr, size);
    return 0;
}
