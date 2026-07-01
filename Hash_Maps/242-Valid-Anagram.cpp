/*
    Problem: 242. Valid Anagram
    Difficulty: Easy
    Pattern: Hash Map (Frequency Counting)
    
    My notes: 
    - An anagram means both strings have the exact same characters in the exact same quantities.
    - Optimization 1: If the strings are different lengths, they CANNOT be anagrams. Return false immediately.
    - We use an unordered_map to build an "inventory" of characters from string 's'.
    - Then, we loop through string 't' and "consume" characters from our inventory.
    - If 't' needs a character that isn't in the map, or if the count has reached 0, it means 't' has extra/different characters. Return false.
    - Time Complexity: O(N) — We do one pass over 's' and one pass over 't'.
    - Space Complexity: O(1) — The map will store at most 26 lowercase English letters, which is constant space.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Early exit: Anagrams must be the exact same length
        if (s.size() != t.size()) {
             return false;
        }
             
        unordered_map<char, int> m;
    
        // Build the inventory from string s
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        
        // Consume the inventory using string t
        for (int i = 0; i < t.size(); i++) {
            // If the character is out of stock, it's not an anagram
            if (m[t[i]] == 0) {
                return false;
            }
            m[t[i]]--;
        }
        
        return true;
    }
};
