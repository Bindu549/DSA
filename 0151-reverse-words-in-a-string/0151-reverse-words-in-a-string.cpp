class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int end = 0; end < s.length(); ++end) {
            if (s[end] != ' ') {
                if (start != 0) {
                    s[start++] = ' '; 
                }
                int wordStart = start;
                while (end < s.length() && s[end] != ' ') {
                    s[start++] = s[end++];
                }
                reverse(s.begin() + wordStart, s.begin() + start);
            }
        }
        s.resize(start);

        return s;
    }
};
