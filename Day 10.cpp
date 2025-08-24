#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;
    
    for (string word : strs) {
        string key = word;
        sort(key.begin(), key.end());  // Sort the word to create key
        anagramMap[key].push_back(word);
    }
    
    vector<vector<string>> result;
    for (auto& entry : anagramMap) {
        result.push_back(entry.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> groups = groupAnagrams(strs);
    
    // Print result
    for (auto group : groups) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
