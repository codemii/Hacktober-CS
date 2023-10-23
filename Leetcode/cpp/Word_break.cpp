class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (dict.size() == 0) return false; // If the dictionary is empty, it's not possible to break the string.

        int longestWord = 0;
        for (string word : dict) {
            longestWord = max(longestWord, (int)word.size()); // Find the length of the longest word in the dictionary.
        }

        vector<bool> dp(s.size() + 1, false); // Initialize a dynamic programming (DP) array to keep track of valid substrings.
        dp[0] = true; // An empty string can be broken into words from the dictionary.

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= max(i - longestWord, 0); j--) {
                // Iterate over the string to check for valid substrings.
                if (dp[j]) {
                    string word = s.substr(j, i - j); // Extract a substring from j to i.
                    if (dict.find(word) != dict.end()) {
                        dp[i] = true; // If the extracted word is in the dictionary, mark dp[i] as true.
                        break; // Next i, as we found a valid word and don't need to check further.
                    }
                }
            }
        }

        return dp[s.size()]; // The final value in dp will indicate whether the entire string can be broken into words from the dictionary.
    }
};
