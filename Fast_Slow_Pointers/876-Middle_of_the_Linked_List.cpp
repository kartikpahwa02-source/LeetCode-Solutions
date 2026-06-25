/*
    Problem: 876. Middle of the Linked List
    Difficulty: Easy
    Pattern: Fast & Slow Pointers
    
    My notes: 
    - We need to find the middle node of a Linked List in a single pass.
    - We use the "Tortoise and Hare" approach.
    - 'slow' pointer moves 1 step at a time.
    - 'fast' pointer moves 2 steps at a time.
    - Because 'fast' travels exactly twice as fast, when 'fast' reaches the end (NULL), 'slow' will be exactly in the middle.
    - The condition `fast != NULL && fast->next != NULL` safely handles both even and odd length lists without throwing a segmentation fault.
    - Time Complexity: O(N) — We find the middle in exactly one pass.
    - Space Complexity: O(1) — Only two pointers used.
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list (Provided by LeetCode).
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Fast moves 2 steps, so we must check if the next two nodes exist
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps
        }
        
        // When fast hits the end, slow is exactly in the middle
        return slow;
    }
};
