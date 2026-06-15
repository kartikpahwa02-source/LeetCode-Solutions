/*
    Problem: 15. 3Sum
    Difficulty: Medium
    Pattern: Sorting + Two Pointers
    
    My notes: 
    - The problem asks for values, not indices, so we are free to SORT the array first! 
      Sorting is the secret that makes the Two Pointer approach possible.
    - We use a standard 'for' loop to lock in our first number (nums[i]).
    - Once the first number is locked, the problem just becomes "Two Sum II" for the rest of the array. We set 'left' = i + 1 and 'right' = end.
    - THE HARDEST PART: Avoiding duplicate triplets. 
      - If nums[i] is the same as the previous number, skip it.
      - When a valid triplet is found, move 'left' and 'right' past any duplicate numbers before searching again.
    - Time Complexity: O(N^2) — One loop for 'i', and the pointers scan the rest.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
  
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
  
          if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int j = i + 1, k = n - 1;
            
            while(j < k) {
                if(nums[j] + nums[k] == (-nums[i])) {
                     res.push_back({nums[i], nums[j], nums[k]});
                     j++;
                     k--;
                     
                     while(j < k && nums[j] == nums[j-1]) j++;
                     while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(nums[j] + nums[k] > (-nums[i])) {
                    k--; 
                }
                else {
                    j++; 
                }
            }
        }
        return res;
    }
};
