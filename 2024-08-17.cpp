//Problem Name : Maximum Number of Points with Cost
//Link : https://leetcode.com/problems/maximum-number-of-points-with-cost/description/

//Brute Force
//Time Complexity -> O(n*m*m)
class Solution {
public:
    long long helper(int i, int prevJ, int rows, int cols, vector<vector<int>>&points , vector<vector<int>>&dp){
        
        if(i >= rows)
            return 0;

        if(dp[i][prevJ] != -1) return dp[i][prevJ];

        long long ans = LLONG_MIN;
        for(int j =0; j < cols; j++){
            long long pick = points[i][j] - abs(j - prevJ) + helper(i + 1, j, rows, cols, points,dp);
            ans = max(ans, pick);
        }
        return dp[i][prevJ] = ans;
    }
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<vector<int>>dp(rows, vector<int>(cols, -1));
        long long maxAns = LLONG_MIN;
        for(int j =0; j < cols; j++){
            
            maxAns = max(maxAns, points[0][j] + helper(1,j, rows, cols, points, dp));
        }
        return maxAns;
    }
};

//Optimal 
//Time Complexity-> O(m * n)
class Solution {
public:
    
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<long long> prev(cols);

        for(int j =0; j < cols; j++){
            prev[j] = points[0][j];
        }

        for(int i =1;  i < rows; i++){
            vector<long long>left(cols, 0);
            vector<long long>right(cols, 0);
            left[0] = prev[0];

            for(int j =1; j < cols; j++)
                left[j] = max(prev[j], left[j-1] - 1);
            
            right[cols - 1] = prev[cols - 1];

            for(int j = cols-2; j >= 0; j--)
                right[j] = max(prev[j], right[j + 1] - 1);

            vector<long long>curr(cols);
            for(int j =0; j < cols; j++)
                curr[j] = points[i][j] + max(left[j], right[j]);
            
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());   
    }
};