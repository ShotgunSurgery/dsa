#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, count = 0, t;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // we use 1LL to make the entire multiplication 64 bit multiplication to avoid integer overflow
            if (a[i] == 1LL * a[j] * a[j] || a[j] == 1LL * a[i] * a[i])
            {
                count += 1;
            }
        }
    }

    cout << count;

    return 0;
}