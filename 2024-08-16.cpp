
//Problem Name : Maximum Distance Array
//Link : https://leetcode.com/problems/maximum-distance-in-arrays/description/
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
    //brute force TC->O(n^2)
    
        int maxDiff = INT_MIN;
        int n = arrays.size();
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    int size = arrays[j].size();
                    int diff = abs(arrays[i][0] - arrays[j][size-1]);
                    maxDiff = max(maxDiff, diff);
                }
            }
        }
        return maxDiff;
   
    //better approach TC-> O(nlogn)
        int n = arrays.size();
        vector<pair<int,int>> minVec;
        vector<pair<int,int>> maxVec;
        
        for(int i = 0; i < n; i++) {
            minVec.push_back({arrays[i][0], i});
            int m = arrays[i].size();
            maxVec.push_back({arrays[i][m - 1], i});
        }
        
       
        sort(minVec.begin(), minVec.end());
        sort(maxVec.begin(), maxVec.end(), greater<pair<int,int>>());

       
        int i = 0, j = 0;
        while(minVec[i].second == maxVec[j].second) {
            if (i + 1 < n) i++;  
            else j++;  
        }
        int diff1 = abs(maxVec[j].first - minVec[i].first);

        
        i = 0; j = 0;
        while(minVec[i].second == maxVec[j].second) {
            if (j + 1 < n) j++;  
            else i++; 
        }
        int diff2 = abs(maxVec[j].first - minVec[i].first);
        
        return max(diff1, diff2);


    //Optimal Approach -> O(n)        
        int n = arrays.size();
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        
        int maxDist = 0;
        
        for(int i = 1; i < n; i++) {
        
            maxDist = max(maxDist, abs(arrays[i].back() - minVal));
            maxDist = max(maxDist, abs(maxVal - arrays[i][0]));
            
            
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }
        
        return maxDist;

    }
};