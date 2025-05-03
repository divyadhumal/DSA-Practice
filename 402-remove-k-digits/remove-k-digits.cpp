class Solution {
public:
//TC-O(n)
//SC -O(1)(ignoring the space taken for result variable)

    string removeKdigits(string num, int k) {
        string result="";//it will act like stack
        int n=num.length();

        for(int i=0; i<n; i++){
          while(result.length() >0 && result.back()>num[i] && k>0){
            result.pop_back();
            k--;
          }
          if(result.length()>0 || num[i] != '0'){
            result.push_back(num[i]);//to avoid the case  starting /preceeding zeros
          }
        }
        while(result.length()>0 && k>0){
          result.pop_back();
          k--;
        }
        if(result ==""){//empty case
          return "0";
        }
        return result;
    }
};