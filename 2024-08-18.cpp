//Problem Name : Ugly Number II
//Link : https://leetcode.com/problems/ugly-number-ii/description/

///Time Complexity : O(n))
//Space Complexity : O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>temp(n + 1);

        temp[1] = 1;
        int i2 = 1, i3 = 1, i5 = 1;

        for(int i =2; i <= n; i++){
            int i2th_ugly = temp[i2] * 2;
            int i3rd_ugly = temp[i3] * 3;
            int i5th_ugly = temp[i5] * 5;

            temp[i] = min(i2th_ugly, min(i3rd_ugly, i5th_ugly));

            if(temp[i] == i2th_ugly)
                i2++;
            if(temp[i] == i3rd_ugly)
                i3++;
            if(temp[i] == i5th_ugly)
                i5++;
        }
        return temp[n];
    }
};