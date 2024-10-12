
//Leetcode - 2406 : Divide intervals into Mininmum Number of Groups
//Approach 1: Brute Force
//Time complexity -> O(n^2), Space Complexity -> O(2*n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
   
        set<int>time;
        for(auto interval : intervals){
            time.insert(interval[0]);
            time.insert(interval[1]);
        }

        int maxPart =0;
        for(auto t : time){
            int count = 0;
            for(auto interval : intervals){
                int start = interval[0];
                int end = interval[1];

                if(start == t || end == t || (start < t && end > t))
                    count++;
            }
            maxPart = max(maxPart, count);
        }
        return maxPart;
    }
    // optimal
    //Time complexity -> O(nlogn), Space Complexity -> O(2*n)
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>arrival, departure;
        for(auto interval : intervals){
            arrival.push_back(interval[0]);
            departure.push_back(interval[1]);
        }

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        int platforms = 1, curr_platforms = 1, i = 1, j =0, n = intervals.size();

        while(i < n && j < n){
            if(arrival[i] <= departure[j]){
                curr_platforms++;
                i++; 
            }
            else{
                curr_platforms--;
                j++;
            }
            platforms = max(platforms, curr_platforms);
        }
        return platforms;
    }
};