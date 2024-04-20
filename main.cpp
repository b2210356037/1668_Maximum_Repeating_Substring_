#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        //solution with sliding window
        int n = sequence.size();
        int m = word.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (i + j < n && sequence[i + j] == word[j % m]) {
                j++;
            }
            ans = max(ans, j / m);
        }
        return ans;
    }
};

int main() {
    vector<string> testCases = {
        "aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba"
    };
    for (int i = 0; i < testCases.size(); i += 2) {
        cout << Solution().maxRepeating(testCases[i], testCases[i + 1]) << endl;
    }
    return 0;
}
