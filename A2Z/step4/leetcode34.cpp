#include <iostream>
#include <vector>

using namespace std;

// non - descending order more than or equal to

class Solution
{
public:
    vector<int> searchRange(vector<int> &n, int s, int t)
    {
        int l = 0, h = s - 1, st = 0, up = 0;
        vector<int> ans;

        // while (l <= h)
        // {

        //     int m = l + (h - l) / 2;
        //     printf("%d, %d, %d, %d, %d \n", l, h, m, st, up);
        //     if (n[m] == t)
        //     {
        //         printf("check");
        //         st = m;
        //         h = m;
        //     }
        //     else if (n[m] < t)
        //         l = m + 1;
        //     else
        //         h = m - 1;
        // }

        while (l <= h)
        {
            int m = l + (h - l) / 2;
            if (n[m] >= t)
                h = m - 1;
            else
                l = m + 1;
        }
        if (l < s && n[l] == t)
            st = l;
        else
            st = -1;

        // while (l <= h)
        // {
        //     int m = l + (h - l) / 2;
        //     if (n[m] == t)
        //     {
        //         up = m;
        //         l = m + 1;
        //     }
        //     else if (n[m] < t)
        //         l = m + 1;
        //     else
        //         h = m - 1;
        // }
        l = 0, h = s - 1; // reset bounds
        while (l <= h)
        {
            int m = l + (h - l) / 2;
            if (n[m] <= t)
                l = m + 1;
            else
                h = m - 1;
        }
        if (h >= 0 && n[h] == t)
            up = h;
        else
            up = -1;

        if (st == -1 || up == -1 || st > up)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else
        {

            for (int i = st; i <= up; i++)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {5, 7, 7, 8, 8, 10};
    int t = 8, n = v.size();
    Solution s;

    int size = s.searchRange(v, n, t).size();

    vector<int> result = s.searchRange(v, n, t);
    for (int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
}