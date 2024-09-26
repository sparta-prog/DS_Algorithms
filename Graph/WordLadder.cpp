#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (wordList.empty())
        {
            return 0;
        }
        // construct a vmap
        // for storing which words are present and also for tracking visited
        unordered_map<string, bool> vmap;
        for (auto &x : wordList)
        {
            // insert into map and mark visited false
            vmap[x] = false;
        }
        // check if end word and begin word are present
        if(vmap.count(beginWord) == 0 || vmap.count(endWord) == 0) {
            return 0;
        }
        //use bfs now
        queue<string> q;
        q.push(beginWord);
        vmap[beginWord] = true;
        //variable for storing depth
        int depth = 1;

        while(!q.empty()) {
            int s = q.size();
     
            while(s--) {
                string word = q.front();
                q.pop();
                //go through each character in the word
                for(int i=0;i<word.length();i++) {
                    //use a temp word to store the current, because you don't want to disturb the original word
                    string temp = word;
                    for(char c='a';c<='z';c++) {
                        temp[i] = c;
                        //if you reach at the same word
                        if(temp == word) {
                            continue;
                        }
                        //if you arrive at your targer
                        if(temp == endWord) {
                            return depth + 1;
                        }
                        //check visited and insert into queue
                        if(vmap.find(temp) != vmap.end() && (vmap[temp] == false)) {
                            q.push(temp);
                            //mark visited
                            vmap[temp] = true;
                        }
                    }
                }
            }
            //increment depth
            depth++;
        }
        return 0;
    }
};

int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string begin = "hit", end = "cog";
    Solution obj;

    cout << obj.ladderLength(begin, end, wordList);
}
