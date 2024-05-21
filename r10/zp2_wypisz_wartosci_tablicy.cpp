#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void sortArray(int arr[], int size);
int getLowestValueIndex(int arr[], int size, int idx);
void swapArrayValues(int arr[], int idx1, int idx2);
void printArray(int arr[], int size, std::string msg);
int sumArrayValues(int arr[], int size);

int main()
{
    srand(time(NULL));

    // USING POINTERS
    int size = 50;
    int *nums = new int[size];
    // create an array with random numbers
    for (int i = 0; i < size; i++) {
        *(nums + i) = rand() % 100;
    }

    // using a for-each loop for a dynamic array is not that obvious!
    printArray(nums, size, "Array (all values, not sorted)");
    sortArray(nums, size);
    // printArray(nums, size, "Array (all values, sorted)");
    cout << "Maximum array value: " << *nums << '\n';
    cout << "Minimum array value: " << *(nums + size - 1) << '\n';
    cout << "Average array value: " << sumArrayValues(nums, size) / (double) size << '\n';

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

int sumArrayValues(int arr[], int size) {
    unsigned int sum = 0; 
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}