#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // dp[i][j] = expected days to eat j apples starting with i apples
    // We need dp[n][m]
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0.0));
    
    // Base case: dp[i][0] = 0 for all i (0 apples to eat)
    // dp[0][j] = 0 for j > 0 (no apples left, can't eat more)
    
    // Fill the dp table
    for (int i = 1; i <= n; i++) {  // current number of apples
        for (int j = 1; j <= m; j++) {  // apples to eat
            double sum = 0.0;
            int terms = 0;
            
            // Try eating k apples (1 to min(i, j))
            for (int k = 1; k <= min(i, j); k++) {
                sum += dp[i - k][j - k];
                terms++;
            }
            
            // If we can eat more than j apples, those cases contribute 0 to expectation
            // since we only need to eat j apples
            dp[i][j] = 1.0 + sum / i;
        }
    }
    
    cout << fixed << setprecision(2) << dp[n][m] << endl;
    
    return 0;
}