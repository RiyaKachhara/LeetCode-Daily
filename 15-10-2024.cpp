///Leetcode - 2938 : Separate Black and White Balls

//Time Complexity -> O(n), Space Complexity -> O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        long long zeros=0, swaps =0;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '0'){
                zeros++;
                continue;
            }
            
            swaps += zeros;
        }
        return swaps;
    }
};