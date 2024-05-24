#include <iostream>
using namespace std;
int main() {
    int n, j, count = 0;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++){
        j = i;
        while (j != 0){
            if (j % 2 != 0) {
                count++;
            }
            j = j >> 1;
        }
    }
    cout << "The total set bits from 1 to " << n << " are : " << count << endl;
    return 0;
}
