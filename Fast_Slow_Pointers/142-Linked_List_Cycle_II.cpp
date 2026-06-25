/*
    Problem: 142. Linked List Cycle II
    Difficulty: Medium
    Pattern: Fast & Slow Pointers (Floyd's Tortoise and Hare - Phase 2)
    
    My notes: 
    - This is the direct follow-up to finding a cycle. Now we need to find WHERE the cycle begins.
    - Phase 1: Use 'slow' and 'fast' (moving 1 and 2 steps) to detect if a cycle exists.
    - Phase 2: If they meet, a cycle exists. The mathematical secret  is that the distance from the head to the cycle start is the EXACT SAME as the distance from the meeting point to the cycle start.
    - So, we move 'slow' back to the 'head'.
    - We keep 'fast' exactly where it is (at the meeting point).
    - Now, we move BOTH pointers ONE step at a time. The exact node where they collide again is the start of the cycle!
    - Time Complexity: O(N)
    - Space Complexity: O(1)
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list (Provided by LeetCode).
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;
        
       
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                slow = head;
                hasCycle = true;
                break;
            }   
        }
        
        if (!hasCycle) {
            return NULL;
        }
            
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow; 
    }
};
