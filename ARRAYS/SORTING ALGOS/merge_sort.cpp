// TODO: LEARN MERGE SORT
// Time complexity: O(n log n) in all cases

#include<iostream>
using namespace std;

// Function declarations
int* merge_sort(int* array, int size);
int* merge(int* array1, int* array2, int size1, int size2);
void display(int* array, int size);

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int* sorted = merge_sort(arr, size);
    cout << "Sorted Array: ";
    display(sorted, size);

    delete[] sorted; // Clean up dynamic memory
    return 0;
}

// Merge Sort function
int* merge_sort(int* array, int size) {
    if (size <= 1) {
        // Base case: copy the array and return
        int* single = new int[size];
        for (int i = 0; i < size; i++) {
            single[i] = array[i];
        }
        return single;
    }

    int mid = size / 2;

    // Create left and right subarrays
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    // Recursively sort both halves
    int* sorted_left = merge_sort(left, mid);
    int* sorted_right = merge_sort(right, size - mid);

    // Merge sorted halves
    int* merged = merge(sorted_left, sorted_right, mid, size - mid);

    delete[] sorted_left;
    delete[] sorted_right;

    return merged;
}

// Merge function
int* merge(int* array1, int* array2, int size1, int size2) {
    int* result = new int[size1 + size2];
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (array1[i] <= array2[j]) {
            result[k++] = array1[i++];
        } else {
            result[k++] = array2[j++];
        }
    }
    while (i < size1) {
        result[k++] = array1[i++];
    }
    while (j < size2) {
        result[k++] = array2[j++];
    }

    return result;
}

// Display function
void display(int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            cout << "[ " << array[i] << ", ";
        } else if (i == size - 1) {
            cout << array[i] << " ]" << endl;
        } else {
            cout << array[i] << ", ";
        }
    }
}
