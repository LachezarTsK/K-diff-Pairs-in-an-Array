
import java.util.Map;
import java.util.HashMap;

public class Solution {

    public int findPairs(int[] nums, int k) {

        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int n : nums) {
            frequencyMap.put(n, frequencyMap.getOrDefault(n, 0) + 1);
        }

        int countPairs = 0;
        for (int n : frequencyMap.keySet()) {
            if (isValidPair(k, n, frequencyMap)) {
                countPairs++;
            }
        }
        return countPairs;
    }

    public boolean isValidPair(int k, int n, Map<Integer, Integer> frequencyMap) {
        return frequencyMap.containsKey(k + n) && (k > 0 || (frequencyMap.get(k + n) > 1));
    }
}
