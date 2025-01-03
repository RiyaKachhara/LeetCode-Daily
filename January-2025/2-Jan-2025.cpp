// Leetcode 2559 : https://leetcode.com/problems/count-vowel-strings-in-ranges/
// T.C : O(n) S.C : O(1) (not considering the ans vector)

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int currCnt = 0, n = words.size();
        vector<int>prefix(n, 0);
        unordered_set<char>vowels = {'a','e', 'i', 'o', 'u'};
        int i =0;
        for(auto word : words){
            if(vowels.find(word[0]) != vowels.end() && vowels.find(word[word.size()- 1]) != vowels.end()){
                currCnt++;
            }
            prefix[i] = currCnt;
            i++;
        }
        vector<int>ans(queries.size());
        i=0;
        for(auto query : queries){
            ans[i] = prefix[query[1]] - (query[0] - 1 >= 0 ? prefix[query[0] - 1] : 0);
            i++;
        }
        return ans;
    }
};