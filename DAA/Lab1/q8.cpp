#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"min max algorithm";
    cout << "\nEnter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    cout << "Minimum element: " << minVal << endl;
    cout << "Maximum element: " << maxVal << endl;
    cout<<"name:Anil Pal Roll no:5";
    return 0;
}
