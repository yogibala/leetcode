class Solution {
 public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> count;

    for (const string& word : words1)
      ++count[word];

    for (const string& word : words2)
      if (const auto it = count.find(word);
          it != count.cend() && it->second < 2)
        --it->second;

    return count_if(count.begin(), count.end(),
                    [](const auto& c) { return c.second == 0; });
  }
};
