#include <iostream>
#include <time.h>
#include<math.h>
#include <iomanip> // Include this for precision
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

// Function to measure sorting time
double timemeasured(int arr[], int n) {
    int* temp = new int[n];  // Create a copy to avoid modifying the original
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    clock_t start, end;
    start = clock();
    quicksort(temp, 0, n - 1);
    end = clock();

    delete[] temp;  // Free memory
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int arrSizes[] = {10, 500, 1000, 10000, 90000}; // Different test sizes
    int n = sizeof(arrSizes) / sizeof(arrSizes[0]);

    for (int i = 0; i < n; i++) {
        int m = arrSizes[i]; 
        int* arr = new int[m];  // Dynamically allocate array

        for (int j = 0; j < m; j++) {
            arr[j] = rand() % 100;
        }

        double time_taken = timemeasured(arr, m);
        cout << fixed << setprecision(5) << "Time taken to sort " << m
             << " elements: " << time_taken << " seconds" << endl;

        delete[] arr;  // Free allocated memory
    }

    cout << endl;
    return 0;
}