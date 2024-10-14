//Leetcode - 2530 : Mximal Scor After Applying K Operations
// Time Complexity -> O(nlogn + klogn) => O((n+k)logn)
//Space Complexity -> O(n)


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>maxHeap;
        long long score = 0;

        for(auto num : nums)
            maxHeap.push(num);

        while(k){
            int top = maxHeap.top();
            maxHeap.pop();

            score += top;

            top = ceil((double)top / 3);
            maxHeap.push(top);
            k--;
        }
        return score;
    }
};