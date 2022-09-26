class Solution:
  def closestDivisors(self, num: int) -> List[int]:
    for root in reversed(range(int(sqrt(num + 2)) + 1)):
      for cand in [num + 1, num + 2]:
        if cand % root == 0:
          return [root, cand // root]
