class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangles;
        if(numRows >= 1)
          triangles.push_back({1});
          
          if(numRows>=2)
          triangles.push_back({1,1});

          for(int i=2; i<numRows; i++){
            vector<int>row(i+1,1);
            for(int j=1; j<i; j++){
              row[j] =triangles[i-1][j]+ triangles[i-1][j-1];
            }
            triangles.push_back(row);
          }
          return triangles;
    }
};