
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function (nums, k) {

    nums.sort((x, y) => x - y);
    const size = nums.length;

    let headPointer = 1;
    let tailPointer = 0;
    let countPairs = 0;

    while (headPointer < size && tailPointer < size) {

        if (tailPointer === headPointer || nums[headPointer] - nums[tailPointer] < k) {
            headPointer++;
        } else if (nums[headPointer] - nums[tailPointer] > k) {
            tailPointer++;
        } else {
            countPairs++;
            tailPointer++;
            while (tailPointer < size && nums[tailPointer] === nums[tailPointer - 1]) {
                tailPointer++;
            }
        }
    }
    return countPairs;
};
