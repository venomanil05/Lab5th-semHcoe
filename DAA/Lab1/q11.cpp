#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()
using namespace std;

// Partition function using Lomuto scheme with random pivot
int partition(int arr[], int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1); // Random pivot
    swap(arr[pivotIndex], arr[right]);                   // Move pivot to end
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {   // For stable sorting use "<="
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

// Randomized Quick Sort
void randomizedQuickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        randomizedQuickSort(arr, left, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    srand(time(0)); // Seed random number generator

    int n;
    cout<<"randomized quick sort";
    cout << "\nEnter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    randomizedQuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout<<"Name:Anil Pal Roll:5";
    return 0;
}
