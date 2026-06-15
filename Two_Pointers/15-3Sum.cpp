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
