
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    
public:

    int findPairs(vector<int>& nums, int k) {

        unordered_map<int, int> frequencyMap;
        for (int n : nums) {
            frequencyMap[n]++;
        }

        int countPairs = 0;
        for (const auto& n : frequencyMap) {
            if (isValidPair(k, n.first, frequencyMap)) {
                countPairs++;
            }
        }
        return countPairs;
    }

    bool isValidPair(int k, int n, unordered_map<int, int>& frequencyMap) {
        return frequencyMap.find(k + n) != frequencyMap.end() && (k > 0 || (frequencyMap[k + n] > 1));
    }
};
