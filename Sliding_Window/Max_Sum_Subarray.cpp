/*
    Problem: Max Sum Subarray of size K (GeeksforGeeks)
    Difficulty: Easy
    Pattern: Sliding Window (Fixed Size)
    My notes: 
    - We need to find a contiguous block (subarray) of exactly size 'K' that gives the maximum sum.
    - The brute force way (recalculating every block of K from scratch) is too slow.
    - The secret: Use a "Sliding Window". 
    - Step 1: Calculate the sum of the VERY FIRST window (the first K elements). This is our baseline.
    - Step 2: Slide the window forward by ONE element at a time.
    - As the window slides, we DO NOT recalculate everything. We just:
        1. ADD the new element coming into the window on the right.
        2. SUBTRACT the old element falling out of the window on the left.
    - Keep track of the 'max_sum' at each step.
    - Time Complexity: O(N) — We only slide across the array once!
    - Space Complexity: O(1) — No extra arrays needed.
*/
