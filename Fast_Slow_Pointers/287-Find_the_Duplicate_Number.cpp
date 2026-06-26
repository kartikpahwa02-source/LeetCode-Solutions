/*
    Problem: 287. Find the Duplicate Number
    Difficulty: Medium
    Pattern: Fast & Slow Pointers (Floyd's Cycle Detection on an Array)
    
    My notes: 
    - This is a mind-bending crossover: We are using a Linked List algorithm on an Array!
    - Because the numbers are in the range [1, n] and there are n+1 numbers, we can treat the array values as "pointers" to indices. (i.e., jump to index = nums[index]).
    - Multiple indices jumping to the exact same number creates a CYCLE.
    - This is the exact same Phase 1 & Phase 2 logic as Linked List Cycle II (LeetCode 142).
    - Phase 1: 'fast' jumps 2 steps (nums[nums[fast]]), 'slow' jumps 1 step (nums[slow]).
    - Phase 2: Once they meet, reset 'slow' to index 0. Move both 1 step at a time. Their collision point is the start of the cycle (the duplicate number)!
    - Time Complexity: O(N)
    - Space Complexity: O(1) — This perfectly satisfies the strict problem constraints!
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if (slow == fast) {
                slow = 0;
                while (slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                
                return slow;
            }
        }
        
        return -1; 
    }
};
