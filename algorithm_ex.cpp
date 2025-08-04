#include <iostream>
#include <vector>
using namespace std;

// Sorts the input vector 'arr' in ascending order using Bubble Sort algorithm.
// Time Complexity: O(n^2), where n is the number of elements in 'arr'.
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// The main function demonstrates bubble sort on a sample array and prints the sorted result.
int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
