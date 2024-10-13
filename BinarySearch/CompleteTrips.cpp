#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    /**
     * You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.
     * Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. 
     * Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.
     * You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
     * Return the minimum time required for all buses to complete at least totalTrips trips.
    */
public:
    long long minimumTime(vector<int> &times, int totalTrips)
    {
        int n = times.size();

        long long l = 1;
        long long h = *min_element(times.begin(),times.end()) * totalTrips;

        long long ans = -1;

        while(l <= h) {
            auto midTime = l + (h - l)/2;

            long long possibleTrips = 0;

            for(int &x : times) {
                possibleTrips += midTime/x;

                if(possibleTrips >= totalTrips) break;
            }

            if(possibleTrips >= totalTrips) {
                ans = midTime;
                h = midTime - 1;
            }
            else {
                l = midTime + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> time = {1, 2, 3};
    int trips = 5;
    Solution obj;

    cout << obj.minimumTime(time, trips);
}