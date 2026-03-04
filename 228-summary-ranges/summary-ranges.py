class Solution:
  def summaryRanges(self, nums: List[int]) -> List[str]:
    result = []
    
    if not nums:
        return result
    
    range_start = nums[0]
    
    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1] + 1:
            
            range_end = nums[i - 1]
            
            if range_start == range_end:
                result.append(str(range_start))
            else:
                result.append(str(range_start) + "->" + str(range_end))
            
            # ALWAYS move start forward (outside if-else)
            range_start = nums[i]
    
    # Close last range (after loop ends)
    range_end = nums[-1]
    
    if range_start == range_end:
        result.append(str(range_start))
    else:
        result.append(str(range_start) + "->" + str(range_end))
    
    return result