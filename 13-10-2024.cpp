//Leetcode - 632 : Samllest Range Covering Elements from K Lists


//Approach 1 : Using MIn Heap
//Time complexity -> O(Nlogk), Space Complexity -> O(k)
//N = total number of elements across all lists,
//k = number of lists.
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int,pair<int, int>>>>minHeap;


        int maxSoFar = INT_MIN;
        for(int i =0; i < nums.size(); i++){
            maxSoFar = max(maxSoFar, nums[i][0]);
            minHeap.push({nums[i][0], {i,0}});
        }

        vector<int>currRange = {minHeap.top().first, maxSoFar};
        int prev_range, new_range;

        if ((maxSoFar >= 0 && minHeap.top().first >= 0) || (maxSoFar < 0 && minHeap.top().first < 0))
            prev_range = abs(maxSoFar) - abs(minHeap.top().first);
        else 
            prev_range = abs(maxSoFar) + abs(minHeap.top().first);

        while(true){
            int list = minHeap.top().second.first;
            int index =  minHeap.top().second.second;

            minHeap.pop();

            if (index + 1 >= nums[list].size()) {
                break;
            }
            minHeap.push({nums[list][index + 1], {list, index + 1}});
            maxSoFar = max(maxSoFar, nums[list][index + 1]);

            if ((maxSoFar >= 0 && minHeap.top().first >= 0) || (maxSoFar < 0 && minHeap.top().first < 0))
                new_range = abs(maxSoFar) - abs(minHeap.top().first);
            else 
                new_range = abs(maxSoFar) + abs(minHeap.top().first);
            
            if(new_range < prev_range){
                currRange[0] = minHeap.top().first;
                currRange[1] = maxSoFar;
                prev_range = new_range;
            }

            
        }
        return currRange;

    }
};