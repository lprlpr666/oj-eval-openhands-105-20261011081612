#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <utility>
using namespace std;

// Memoization map: (apples_left, apples_to_eat) -> expected_days
map<pair<int, int>, double> memo;

double expected_days(int apples_left, int apples_to_eat) {
    // Base cases
    if (apples_to_eat == 0) {
        return 0.0;
    }
    if (apples_left == 0) {
        return 0.0; // Can't eat more apples
    }
    
    // Check memo
    pair<int, int> key = make_pair(apples_left, apples_to_eat);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    double sum = 0.0;
    // Try eating k apples (1 to min(apples_left, apples_to_eat))
    for (int k = 1; k <= min(apples_left, apples_to_eat); k++) {
        sum += expected_days(apples_left - k, apples_to_eat - k);
    }
    
    // For k > apples_to_eat (but k <= apples_left), we would eat more than needed,
    // so those contribute 0 to the expectation
    double result = 1.0 + sum / apples_left;
    
    memo[key] = result;
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    cout << fixed << setprecision(2) << expected_days(n, m) << endl;
    
    return 0;
}