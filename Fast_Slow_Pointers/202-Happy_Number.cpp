/*
    Problem: 202. Happy Number
    Difficulty: Easy
    Pattern: Fast & Slow Pointers (Floyd's Cycle Detection on Math Operations)
    
    My notes: 
    - Another incredible crossover! We are using a Linked List cycle detection algorithm on a purely MATHEMATICAL problem.
    - A number is "happy" if repeatedly summing the square of its digits eventually reaches 1.
    - If it's NOT happy, it will loop endlessly in a CYCLE.
    - We can treat the `sq_sum` function as our "next" pointer.
    - 'slow' takes 1 step (1 sq_sum operation).
    - 'fast' takes 2 steps (2 sq_sum operations).
    - If they ever meet and they ARE NOT 1, we are stuck in an infinite cycle (return false).
    - If 'fast' reaches 1, the loop breaks and it is a happy number (return true).
    - Time Complexity: O(log N) — The sum of squares of digits shrinks the number logarithmically.
    - Space Complexity: O(1) — We avoid using a HashSet by utilizing two pointers!
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int sq_sum(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            sum += d * d;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        
        
        while (fast != 1) {
            slow = sq_sum(slow);         
            fast = sq_sum(fast);         
            fast = sq_sum(fast);         
            
            if (slow == fast && slow != 1) {
                return false;
            }
        }
        return true;
    }
};
