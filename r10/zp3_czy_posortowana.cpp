#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void sortArray(int arr[], int size);
int getLowestValueIndex(int arr[], int size, int idx);
void swapArrayValues(int arr[], int idx1, int idx2);
void printArray(int arr[], int size, std::string msg);
bool isSorted(int arr[], int size);

int main()
{
    srand(time(NULL));

    int size = 10;
    // int *nums = new int[size] {4, 10, 1, 1, 34, 16, 90, 8, 77, 78};
    // int *nums = new int[size] {4, 5, 8, 10, 67, 77, 89, 90, 91, 90};
    // int *nums = new int[size] {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    // int *nums = new int[size] {4, 4, 4, 4, 4, 5, 4, 4, 4, 4};
    int *nums = new int[size] {4, 6, 17, 18, 20, 32, 33, 58, 98, 98};

    printArray(nums, size, "Initial array");
    if (isSorted(nums, size)) {
        cout << "\tThe array is sorted...\n";
    } else {
        cout << "\tThe array is not sorted...\n";
        sortArray(nums, size);
        printArray(nums, size, "Sorted array");
    }

    return 0;
}

void printArray(int arr[], int size, std::string msg) {
    cout << msg << ": {";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "}\n";

}

void swapArrayValues(int arr[], int idx1, int idx2) {
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int getLowestValueIndex(int arr[], int size, int idx) {
    int lowest_idx = idx;
    for (int i = idx + 1; i < size; i++) {
        if (arr[lowest_idx] > arr[i]) {
            lowest_idx = i;
        }
    }
    return lowest_idx;
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int idx = getLowestValueIndex(arr, size, i);
        swapArrayValues(arr, i, idx);
    }
}

bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}