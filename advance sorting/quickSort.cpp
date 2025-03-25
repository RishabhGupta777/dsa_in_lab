#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei) {
    int pivotElement = arr[(si+ei)/2];
    int count = 0;

    for (int i = si; i <= ei; i++) {
        if (i == (si+ei)/2) continue; // Skip the pivot element itself
        if (arr[i] < pivotElement) count++; // Count elements less than pivot
    }

    int pivotIdx = count + si; // Calculate pivot index
    swap(arr[(si+ei)/2], arr[pivotIdx]); // Swap pivot element with the element at the pivot index

    int i = si;
    int j = ei;

    while (i < pivotIdx && j > pivotIdx) {
        if (arr[i] < pivotElement) i++;
        else if (arr[j] > pivotElement) j--;
        else if (arr[i] >= pivotElement && arr[j] <= pivotElement) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}

void quicksort(int arr[], int si, int ei) {
    if (si >= ei) return; // Base case: if the subarray has one or zero elements

    int pi = partition(arr, si, ei); // Get the partition index
    quicksort(arr, si, pi-1); // Sort the left side
    quicksort(arr, pi+1, ei); // Sort the right side
}

int main() {
    int arr[] = {5, 1, 8, 2, 7, 6, 3, 4, -8};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print original array
    }

    cout << endl;
    quicksort(arr, 0, n-1); // Perform quicksort

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print sorted array
    }
}
