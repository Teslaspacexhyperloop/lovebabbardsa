
unique no of occurence leetcode 1207

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
test caseInput: 
arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }
        
        for(auto it = m.begin(); it!=m.end(); it++){
            s.insert(it->second);
        }
        if(s.size() == m.size()){
            return true;
        }
        return false;


    }
};