
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    
public:

    int findPairs(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        const size_t size = nums.size();
        
        int headPointer = 1;
        int tailPointer = 0;
        int countPairs = 0;

        while (headPointer < size && tailPointer < size) {

            if (tailPointer == headPointer || nums[headPointer] - nums[tailPointer] < k) {
                headPointer++;
            } else if (nums[headPointer] - nums[tailPointer] > k) {
                tailPointer++;
            } else {
                countPairs++;
                tailPointer++;
                while (tailPointer < size && nums[tailPointer] == nums[tailPointer - 1]) {
                    tailPointer++;
                }
            }
        }
        return countPairs;
    }
};
