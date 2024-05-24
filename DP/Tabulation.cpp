#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    // step 2
    vector<int> dp(n+1);
    // step 2 known values then store them
    dp[1] = 1;
    dp[0] = 0;

    // step 3
    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;

    return 0;
}
