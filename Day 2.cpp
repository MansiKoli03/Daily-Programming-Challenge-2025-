#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void mergeInPlace(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int total = m + n;
    
    // Function to calculate next gap
    auto nextGap = [](int gap) {
        if (gap <= 1) return 0;
        return (gap / 2) + (gap % 2);
    };
    
    int gap = nextGap(total);
    while (gap > 0) {
        int i = 0, j = gap;
        
        while (j < total) {
            int a, b;
            // figure out which array element belongs to
            if (i < m) a = arr1[i];
            else a = arr2[i - m];
            
            if (j < m) b = arr1[j];
            else b = arr2[j - m];
            
            // swap if out of order
            if (a > b) {
                if (i < m && j < m) swap(arr1[i], arr1[j]);
                else if (i < m && j >= m) swap(arr1[i], arr2[j - m]);
                else swap(arr2[i - m], arr2[j - m]);
            }
            i++; j++;
        }
        gap = nextGap(gap);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    mergeInPlace(arr1, arr2);

    cout << "arr1: ";
    for (int num : arr1) cout << num << " ";
    cout << endl;

    cout << "arr2: ";
    for (int num : arr2) cout << num << " ";
    cout << endl;

    return 0;
}
