#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> sumMap; // prefix_sum -> indices
    vector<pair<int, int>> result;
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: If prefixSum itself is 0, subarray from 0 to i
        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        // Case 2: If prefixSum seen before, subarrays from prev+1..i
        if (sumMap.find(prefixSum) != sumMap.end()) {
            for (auto startIndex : sumMap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        // Store current index for this prefixSum
        sumMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    if (subarrays.empty()) {
        cout << "No subarray with zero sum found." << endl;
    } else {
        cout << "Zero-sum subarrays found at indices:" << endl;
        for (auto& p : subarrays) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }
    return 0;
}
