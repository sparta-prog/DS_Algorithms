#include <iostream>
#include <vector>

using namespace std;

class Travel
{
public:
    int find(vector<int> &days, int ind, int day)
    {
        int maxDay = days[ind] + day;
        int j = ind;

        while (days[j] <  maxDay)
        {
            j++;
        }
        return j;
    }
    int util(int ind, vector<int> &days, vector<int> &costs,vector<int>& cache)
    {
        // base case
        if (ind >= days.size())
        {
            return 0;
        }

        if(cache[ind] != -1)
            return cache[ind];

        int op1 = costs[0] + util(ind + 1, days, costs,cache);
        int x = find(days, ind, 7);
        int op2 = costs[1] + util(x, days, costs,cache);
        int y = find(days, ind, 30);
        int op3 = costs[2] + util(y, days, costs,cache);

        return cache[ind] = min({op1, op2, op3});
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {   
        int n = days.size();
        if(n == 0)
            return 0;

        vector<int> cache(n+1,-1);
        return util(0, days, costs,cache);
    }
};

int main()
{
    vector<int> days = {1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29};
    vector<int> cost = {3,14,50};

    Travel obj;

    cout << obj.mincostTickets(days, cost);

    return 0;
}