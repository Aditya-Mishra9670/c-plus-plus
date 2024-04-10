#include<iostream>
#include<vector>
using namespace std;

void findFirstAndLastOccurrence(vector<int> &arr, int low, int high, int target, vector<int> &occurrence) {
    int firstOccurrence = -1;
    int lastOccurrence = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            if (mid == 0 || arr[mid - 1] != target) {
                firstOccurrence = mid;
                break;
            } else {
                high = mid - 1;
            }
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    low = 0;
    high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            if (mid == arr.size() - 1 || arr[mid + 1] != target) {
                lastOccurrence = mid;
                break;
            } else {
                low = mid + 1;
            }
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    occurrence[0] = firstOccurrence;
    occurrence[1] = lastOccurrence;
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << endl << "Now Enter the array elements:" << endl;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }
    int target;
    cout << "Now enter the target: ";
    cin >> target;
    vector<int> occurrence(2, -1);
    int low = 0;
    int high = arr.size() - 1;

    //Now calling the function to find the first and last occurrence of the target element in the array
    findFirstAndLastOccurrence(arr, low, high, target, occurrence);

    cout << "First occurrence: " << occurrence[0] << endl;
    cout << "Last occurrence: " << occurrence[1] << endl;

    return 0;
}
