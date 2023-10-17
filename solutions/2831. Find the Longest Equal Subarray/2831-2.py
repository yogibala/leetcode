class Solution:
  def longestEqualSubarray(self, nums: List[int], k: int) -> int:
    ans = 0
    count = collections.Counter()

    # l and r track max window instead of valid window.
    l = 0
    for r, num in enumerate(nums):
      count[num] += 1
      ans = max(ans, count[num])
      if r - l + 1 - k > ans:
        count[nums[l]] -= 1
        l += 1

    return ans
