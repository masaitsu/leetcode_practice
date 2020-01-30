# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# Example:
# Given nums = [2, 7, 11, 15], target = 9,
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        list_size = len(nums)
        for a_ind in range(0, list_size - 1):
            for b_ind in range(a_ind + 1, list_size):
                if target == (nums[a_ind] + nums[b_ind]):
                    return [a_ind, b_ind]
                    