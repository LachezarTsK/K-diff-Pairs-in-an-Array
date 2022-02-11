
import java.util.Arrays;

public class Solution {

    public int findPairs(int[] nums, int k) {

        Arrays.sort(nums);
        final int size = nums.length;

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
}
