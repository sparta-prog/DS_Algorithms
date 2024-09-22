#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.**/
class Search
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        int n = searchWord.length();

        if (n == 0 || products.empty())
        {
            return {{}};
        }

        // sort the products array
        sort(products.begin(), products.end());
        vector<vector<string>> results;

        string prefix = "";

        for (auto c : searchWord)
        {
            //insert words in the temp vector
            vector<string> temp;
            prefix += c;
            // find the starting position of the prefix
            auto it = lower_bound(products.begin(), products.end(), prefix);
            // insert first 3 matching elements
            for(int i=0;i<3 && (it+i) != products.end() ;i++) {
                string& word = *(it + i);
                //return the index where it is found
                //if found at 0th index
                if(word.find(prefix) == 0) {
                    temp.push_back(word);
                }
                else {
                    //optimisation
                    break;
                }
            }
            results.push_back(temp);
            //clear temp
            temp.clear();
        }

        return results;
    }
};

int main()
{
    Search obj;

    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string search = "mouse";

    auto ans = obj.suggestedProducts(products,search);

    for(auto& s:ans) {
        for(auto & word : s) {
            cout<<word<<" ";
        }
        cout<<endl;
    }
}