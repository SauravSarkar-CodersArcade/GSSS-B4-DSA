#include <iostream>
using namespace std;

int main() {
    int n;
    int z = 0; // Correct guesses
    cout << "Enter the number of friends:" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array elements:" << endl;
    cout << "1st (Alice's Number):" << endl;
    cout << "Followed by the guesses by her friends." << endl;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=1; i<n; i++){
        if (arr[0] == arr[i])
            z++;
    }
    cout << "The number of wrong guesses: " << n - z - 1 << endl;
    return 0;
}
