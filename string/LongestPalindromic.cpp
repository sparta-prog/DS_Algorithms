# include<iostream>
#include<string>

using namespace std;

/**
 * Given a string s, return the longest 
palindromic substring in s.
 * ***/

class Solution {
    string palindromeLength(string& s,int i,int j) {
        //expand around middle;
        string max = "";
        while(i>=0 and j<=s.length() - 1) {
            if(s[i] != s[j]) {
                break;
            }
            i--,j++;
        }
        return s.substr(i+1, (j-i-1));
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0)
            return "";

        string ans = "";
        int maxLen = 0;
        for(int i=0;i<n;i++) {
            string temp1 = palindromeLength(s,i,i);
            string temp2 = palindromeLength(s,i,i+1);

            if(temp1.length() > maxLen) {
                ans = temp1;
                maxLen = temp1.length();
            }
            if(temp2.length() > maxLen) {
                ans = temp2;
                maxLen = temp2.length();
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    string data = "babad";
    cout<<obj.longestPalindrome(data);
}