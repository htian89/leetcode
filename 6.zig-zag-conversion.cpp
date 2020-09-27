/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.88%)
 * Likes:    1863
 * Dislikes: 4976
 * Total Accepted:    493K
 * Total Submissions: 1.3M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows <= 1) return std::move(s);
      string out;
      out.reserve(s.size());
      // 每次循环需要 k 个元素
      int k = 2 * numRows - 2;
      for (int r = 0; r < numRows; ++r) {
        // 第 n 个 zig-zag
        for (int n = 0;; ++n){
          int index = k * n + r;
          if (index >= s.size()) break;
          out += s[index];
          if (r == 0 || r == numRows - 1) continue;
          index = k * (n + 1) - r;
          if (index >= s.size()) break;
          out += s[index];
        }
      }
      return std::move(out);
    }
};
// @lc code=end

