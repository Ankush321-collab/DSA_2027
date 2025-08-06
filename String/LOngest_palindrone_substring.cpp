#include<bits/stdc++.h>
using namespace std;
    string longestPalindrome(string s) {
        string ans = "";
        if (s.length() < 1) return s;

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            int l = i - 1;
            int h = i + 1;

            while (l >= 0 && h < s.length() && s[l] == s[h]) {
                l--;
                h++;
            }
            string palindrome = s.substr(l + 1, h - l - 1);
            if (palindrome.length() > ans.length()) {
                ans = palindrome;
            }

            // Even length palindrome
            l = i;
            h = i + 1;

            while (l >= 0 && h < s.length() && s[l] == s[h]) {
                l--;
                h++;
            }
            palindrome = s.substr(l + 1, h - l - 1);
            if (palindrome.length() > ans.length()) {
                ans = palindrome;
            }
        }
        return ans;
    }

int main(){
    string s="babad";
    string ans=longestPalindrome(s);
    cout<<ans;

}