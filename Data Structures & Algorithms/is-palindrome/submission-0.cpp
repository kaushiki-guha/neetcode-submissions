class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(),[](unsigned char c) { return !isalnum(c); }),s.end());
        for (char &c : s) {
            c = tolower((unsigned char)c);
        }
        int i = 0;
        int j = (int)s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};
