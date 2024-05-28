#include <iostream>
#include <ostream>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.length() == 0) {
      return 0;
    }

    if (s.length() == 1) {
      return 1;
    }

    int res = 1;
    int start_index = 0;
    int end_index = 1;

    int current_length = 1;
    std::unordered_set<char> encountered_chars = {s[start_index]};
    while (end_index < s.length()) {
      if (encountered_chars.find(s[end_index]) != encountered_chars.end()) {
        // printf("start index: %d\n", start_index);
        // printf("end index: %d\n", end_index);
        // for (char c : encountered_chars) {
        //   std::cout << c << std::endl;
        // }
        start_index++;
        end_index = start_index + 1;
        encountered_chars = {s[start_index]};
        current_length = 1;
        continue;
      }

      encountered_chars.insert(s[end_index]);
      end_index++;
      current_length++;
      if (current_length > res) {
        res = current_length;
      }
    }

    return res;
  }
};

int main() {
  std::string input = "abcabcbb";
  Solution *soln = new Solution();

  int res = soln->lengthOfLongestSubstring(input);
  printf("res: %d\n", res);
}
