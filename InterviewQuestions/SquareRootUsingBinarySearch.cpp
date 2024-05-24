#include <iostream>
using namespace std;
long long int binarySearchSquareRoot(int n){
    int s = 0;
    int e = n;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;
    while (s <= e){
        long long int square = mid * mid;
        if (square == n){
            return mid;
        }
        if (square < n){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}
double precisionSquareRoot(int n, int precision, int tSol){
    double factor = 1;
    double ans = tSol;
    for (int i=0; i<precision; i++){
        factor = factor / 10;
        for (double j = ans; j*j < n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}
int main() {
    int result = binarySearchSquareRoot(27);
    cout << "The temporary square root is: " << result << endl;
    double pSqrt = precisionSquareRoot(27, 4, result);
    cout << "The precision sqrt is: " << pSqrt << endl;
    return 0;
}
