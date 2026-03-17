#include <iostream>
using namespace std;
void fibonacci(int n){
   int a = 0, b = 1, c;
    cout << "Fibonacci Sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    fibonacci(n);
    cout<<"Name:Anil Pal  Roll no:5";
    return 0;
}
