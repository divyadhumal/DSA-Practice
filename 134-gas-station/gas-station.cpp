class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int totalGas=0; 
      int totalCost=0;

int start=0, currGas=0;
      for(int i=0; i<gas.size(); i++){//TC-O(n)
        totalGas +=gas[i];
        totalCost +=cost[i];
        currGas +=(gas[i]-cost[i]);

        if(currGas<0){
          start =i+1;
          currGas = 0;
        }
      }
      return totalGas <totalCost ? -1: start;
    }
};//SC-O(1)