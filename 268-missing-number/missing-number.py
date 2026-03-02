class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        expected_sum= n*(n+1)//2
        actual_sum = 0
        for i in range(0,n):
          actual_sum = sum(nums)

          return expected_sum - actual_sum
