class Solution {
public:
    int minBitFlips(int start, int goal) {
       int XorResult  =start ^goal;
       int count=0;

       while(XorResult){
        count +=XorResult &1;
        XorResult >>=1;
       }
       return count;
    }
};