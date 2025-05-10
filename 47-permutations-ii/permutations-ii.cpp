class Solution {
public:

void backtrack(vector<int>& nums,vector<bool >& visited, vector<int> & permutation , vector<vector<int>>& result){
  int n=nums.size();
  if(permutation.size()== nums.size()){
    result.push_back(permutation);
    return;
  }
  for(int i=0; i<n; i++){

  //skip already used elements
  if(visited[i]) continue;

  //skip duplicates
  if(i >0 && nums[i] ==nums[i-1] && !visited[i-1])continue;

  visited[i] =true;
  permutation.push_back(nums[i]);
  backtrack(nums, visited, permutation, result);
  permutation.pop_back();
  visited[i] =false;
  }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      int n=nums.size();
       sort(nums.begin(), nums.end());
       vector<vector<int>>result;
       vector<int>permutation;
       vector<bool>visited(nums.size(),false);
       backtrack(nums,visited,permutation, result);
       return result; 
    }
};