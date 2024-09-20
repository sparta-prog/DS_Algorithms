#include <iostream>
#include <queue>

using namespace std;
/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.size() == 0 || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // push to min
        if (maxHeap.size() - minHeap.size() > 1)
        {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        else if(minHeap.size() > maxHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        int s1 = maxHeap.size();
        int s2 = minHeap.size();

        double result = 0;

        if ((s1 + s2) % 2 == 0)
        {
            // even elements
            int a = maxHeap.top();
            int b = minHeap.top();
            result = (double)(a + b) / 2;
        }
        else
        {
            result = (double)maxHeap.top();
        }
        return result;
    }
};

int main()
{
    MedianFinder medianFinder;
    medianFinder.addNum(1);            // arr = [1]
    medianFinder.addNum(2);            // arr = [1, 2]
    cout << medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    cout << endl;
    medianFinder.addNum(3);            // arr[1, 2, 3]
    cout << medianFinder.findMedian(); // return 2.0
}