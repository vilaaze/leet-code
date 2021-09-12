class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_len = len(nums)
        for i in range(num_len-1):
            for j in range(i+1,num_len):
                if((nums[i] + nums[j]) == target):
                    return [i,j]

#if __name__ == "__main__":
#    print(Solution().twoSum([2,7,11,15], 9))