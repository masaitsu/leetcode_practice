// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      int list_size = nums.size();
      std::vector<int> ret;

      for (int a_ind = 0; a_ind < (list_size - 1); a_ind++)
      {
        for(int b_ind = a_ind + 1; b_ind < list_size; b_ind++)
        {
            if (target == ( nums[a_ind] + nums[b_ind]))
            {
                ret.push_back(a_ind);
                ret.push_back(b_ind);
                return ret;
            }        
        }
      }
      return ret;
    }
};

int main (void)
{
  Solution s;
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> ret = s.twoSum(nums, target);

  std::cout << "[" << ret[0] << ", " << ret[1] << "]" << std::endl;

  return 0;
}