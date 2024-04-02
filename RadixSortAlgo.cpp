/* What is Radix sort algo?
Radix Sort is a linear sorting algorithm that sorts elements by processing them digit by digit. 
It is an efficient sorting algorithm for integers or strings with fixed-size keys. */
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr, int n) {
    // To print the Array or vector
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find the max element
int getMax(vector<int> arr, int n) {
    int temp = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > temp) {
            temp = arr[i];
        }
    }
    return temp;
}

// Count sort algorithm to sort the digits at place value of the digit
void countsort(vector<int>& arr, int n, int exp) {
    vector<int> output(n);
    vector<int> frequency(10, 0);

    // Count occurrences of each digit
    for(int i = 0; i < n; i++) {
        frequency[(arr[i] / exp) % 10]++;
    }

    // Update frequency array to store the position of each digit in output array
    for(int i = 1; i < 10; i++) {
        frequency[i] += frequency[i - 1];
    }

    // Build the output array
    for(int i = n - 1; i >= 0; i--) {
        output[frequency[(arr[i] / exp) % 10] - 1] = arr[i];
        frequency[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix sort algorithm
void radixSort(vector<int>& arr, int n) {
    int max = getMax(arr, n);

    // Perform counting sort for every digit place
    for(int exp = 1; max / exp > 0; exp *= 10) {
        countsort(arr, n, exp);
    }
}

int main() {
    vector<int> arr = {23, 2, 1, 3, 5, 3, 56, 6, 5, 4, 33, 34556, 4, 3, 3, 4, 5, 56, 666, 6, 5, 4, 4, 34, 4, 5, 56};
    int n = arr.size();
    radixSort(arr, n);
    print(arr, n);
    return 0;
}
