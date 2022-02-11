
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function (nums, k) {

    const frequencyMap = new Map();
    for (let n of nums) {
        if (!frequencyMap.has(n)) {
            frequencyMap.set(n, 0);
        }
        frequencyMap.set(n, frequencyMap.get(n) + 1);
    }

    let countPairs = 0;
    for (let n of frequencyMap.keys()) {
        if (isValidPair(k, n, frequencyMap)) {
            countPairs++;
        }
    }
    return countPairs;
};

function isValidPair(k, n, frequencyMap) {
    return frequencyMap.has(k + n) && (k > 0 || (frequencyMap.get(k + n) > 1));
}
