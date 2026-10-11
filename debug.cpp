#include <iostream>
#include <iomanip>
#include <map>
#include <utility>
using namespace std;

// Memoization map: (apples_left, apples_to_eat) -> expected_days
map<pair<int, int>, long double> memo;

long double expected_days(int apples_left, int apples_to_eat) {
    // Base cases
    if (apples_to_eat == 0) {
        return 0.0L;
    }
    if (apples_left == 0) {
        return 0.0L; // Can't eat more apples
    }
    
    // Check memo
    pair<int, int> key = make_pair(apples_left, apples_to_eat);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    long double sum = 0.0L;
    // Try eating k apples (1 to min(apples_left, apples_to_eat))
    for (int k = 1; k <= min(apples_left, apples_to_eat); k++) {
        sum += expected_days(apples_left - k, apples_to_eat - k);
    }
    
    // For k > apples_to_eat (but k <= apples_left), we would eat more than needed,
    // so those contribute 0 to the expectation
    long double result = 1.0L + sum / apples_left;
    
    memo[key] = result;
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    long double result = expected_days(n, m);
    // Round to 2 decimal places
    result = (long double)((int)(result * 100 + 0.5)) / 100;
    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}