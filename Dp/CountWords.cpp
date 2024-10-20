#include <iostream>
#include <vector>
#include <string>

using namespace std;

long countWords(string s, int index, vector<long>& memo) {
    int n = s.size();
    if (index >= n) {
        return 1; // Empty string can be considered a valid word
    }

    if (s[index] == '0') {
        return 0; // No valid words can start with '0'
    }

    if (memo[index] != -1) {
        return memo[index]; // Memoization: If the result is already cached, return it
    }

    long count = 0;
    for (int i = 1; i <= 2 && index + i <= n; i++) {
        int num = stoi(s.substr(index, i));
        if (num >= 1 && num <= 26) {
            count += countWords(s, index + i, memo);
        }
    }

    memo[index] = count; // Cache the result for future use
    return count;
}

int main() {
    string s = "2112";

    int n = s.size();
    vector<long> memo(n + 1, -1); // Initialize memoization table with -1

    long result = countWords(s, 0, memo);
    cout << result << endl;

    return 0;
}