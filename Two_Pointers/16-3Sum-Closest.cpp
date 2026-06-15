/*
    Problem: 16. 3Sum Closest
    Difficulty: Medium
    Pattern: Sorting + Two Pointers
    
    My notes: 
    - The logic here is 90% identical to regular 3Sum: Sort the array, use a 'for' loop to lock the first number, and use Two Pointers for the rest.
    - The key difference: Instead of looking for an exact match, we track the 'closest_sum'.
    - At every step, calculate 'current_sum' = nums[i] + nums[left] + nums[right].
    - If the distance between 'current_sum' and 'target' is smaller than our current 'closest_sum' record, we update our record!
    - Pointer movement rules stay exactly the same:
      - If current_sum < target: we need to get bigger, so left++
      - If current_sum > target: we need to get smaller, so right--
    - Time Complexity: O(N^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int max_diff = INT_MAX; 
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                
                if(diff < max_diff){
                    max_diff = diff;
                    res = sum;
                }
                
                if(sum == target){
                    return sum; 
                }
                else if(sum < target){
                    j++; 
                }
                else{
                    k--; 
                }
            }
        }
        return res;
    }
};
