#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;

    unordered_map<int, int> m;
    priority_queue<pair<int, int>> q;
    // TODO : Documentation says it uses Heap Data structure, so learn how to do that yourself.
    // in priority queue, top element ( highest) is always the greatest by default.

    for (auto i : nums)
    {
        m[i]++;
    }

    for (auto i = m.begin(); i != m.end(); i++)
    {
        q.push(make_pair(i->second, i->first)); // makes pair and sorts that high to low

        if (q.size() > m.size() - k)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    nums = topKFrequent(nums, 2);

    for (auto i : nums)
    {
        cout << i << " ";
    }

    return 0;
}