class Solution:
  def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
    potions.sort()

    def firstIndexSuccess(spell: int):
      """Returns the first index i s.t. spell * potions[i] >= success."""
      l = 0
      r = len(potions)
      while l < r:
        m = (l + r) // 2
        if spell * potions[m] >= success:
          r = m
        else:
          l = m + 1
      return l

    return [len(potions) - firstIndexSuccess(spell) for spell in spells]
