#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    if (s.length() == 1) {
      return 1;
    }

    int res = 0;
    int start_index = 0;
    int end_index = 0;
    int maxf = 0;

    unordered_map<char, int> encountered_chars;

    while (end_index < s.length()) {
      encountered_chars[s[end_index]] = 1 + encountered_chars[s[end_index]];
      maxf = max(maxf, encountered_chars[s[end_index]]);

      if ((end_index - start_index + 1) - maxf > k) {
        encountered_chars[s[start_index]] -= 1;
        start_index++;
      } else {
        res = max(res, end_index - start_index + 1);
      }

      end_index++;
    }

    return res;
  }
};

int main() {
  string s = "AABABBA";
  int k = 1;

  Solution *soln = new Solution();
  int res = soln->characterReplacement(s, k);
  cout << "result: " << res << endl;
}
