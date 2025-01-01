//Leetcode 1422: https://leetcode.com/problems/maximum-score-after-splitting-a-string/
//1)Brute Force
//T.C. : O(n^2), S.C. : o(1)
class Solution {
public:
    int solve(int index, string s){
        int one =0, zero =0;
        for(int i = 0; i < index; i++)
            if(s[i] == '0')
                zero++;
        for(int i = index; i < s.length(); i++)
            if(s[i] == '1')
                one++;
        return one + zero;
    }
    int maxScore(string s) {
        int maxScore = 0;
        for(int i = 1; i <= s.length() - 1; i++)
            maxScore = max(maxScore, solve(i, s));
        return maxScore;
    }
};
//2)Optimal 
//T.C. : O(n), S.C. : O(1)
class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0, n = s.length();

        int ones = 0;
        for(auto ch: s)
            if(ch == '1')
                ones++;
        int zeros = 0;
        for(int i =0; i < n-1; i++){
            if(s[i] == '1')
                ones--;
            else
                zeros++;
            maxScore = max(maxScore, ones + zeros);
        }
        return maxScore;
    }
};