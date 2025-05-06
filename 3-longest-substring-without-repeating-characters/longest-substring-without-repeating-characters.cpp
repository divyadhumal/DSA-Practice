class Solution {
public:
//TC-O(N)
//SC-O(N)
    int lengthOfLongestSubstring(string s) {

      unordered_map<int, int>mp;

        int maxLen =0;
        int left=0;

        for(int right=0; right<s.length(); right++){
          char ch=s[right];

          if(mp.find(ch) !=mp.end()){
            left =max(mp[ch]+1, left); 
          }
          mp[ch] = right;//store/update index of character
          maxLen =max(maxLen, right-left+1);
        }
        return maxLen;
    }
};