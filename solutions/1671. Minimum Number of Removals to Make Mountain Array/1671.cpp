class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    vector<int> l = lengthOfLIS(nums);
    vector<int> r = reversed(lengthOfLIS(reversed(nums)));
    int maxMountainSeq = 0;

    for (int i = 0; i < nums.size(); ++i)
      if (l[i] > 1 && r[i] > 1)
        maxMountainSeq = max(maxMountainSeq, l[i] + r[i] - 1);

    return nums.size() - maxMountainSeq;
  }

 private:
  vector<int> lengthOfLIS(vector<int> nums) {
    // tail[i] := the min tail of all increasing subseqs having length i + 1
    // It's easy to see that tail must be an increasing array.
    vector<int> tail;
    // dp[i] := length of LIS ending at nums[i]
    vector<int> dp;

    for (const int num : nums) {
      if (tail.empty() || num > tail.back())
        tail.push_back(num);
      else
        tail[firstGreaterEqual(tail, num)] = num;
      dp.push_back(tail.size());
    }

    return dp;
  }

  int firstGreaterEqual(const vector<int>& A, int target) {
    return lower_bound(A.begin(), A.end(), target) - A.begin();
  }

  vector<int> reversed(const vector<int>& nums) {
    return {nums.rbegin(), nums.rend()};
  }
};
