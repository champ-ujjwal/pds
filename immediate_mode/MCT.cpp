// minimum completion time
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;

int main()
{
    int tasks, machines;
    cout << "Enter number of Machines : ";
    cin >> machines;
    cout << "Enter number of tasks  : ";
    cin >> tasks;
    vector<int> readyTime(machines, 0);
    cout << "Enter  Ready Time of Machines : ";
    for (int i = 0; i < machines; i++)
    {
        cin >> readyTime[i];
    }
    vector<vector<int>> exec(tasks, vector<int>(machines, 0));
    cout << "Enter the execution time of each task  : \n ";
    for (int i = 0; i < tasks; i++)
    {
        for (int j = 0; j < machines; j++)
        {
            cin >> exec[i][j];
        }
    }
    for (int i = 0; i < tasks; i++)
    {
        int mach = 0;
        int m = exec[0].size();
        int minTime = INT_MAX, res = 0;
        for (int j = 0; j < m; j++)
        {
            if (exec[i][j] + readyTime[j] < minTime)
            {
                minTime = exec[i][j] + readyTime[j];
                res = j;
            }
        }
        mach = res;
        cout << "Task  " << i << " assigned to machine  " << mach << " at " << readyTime[mach] << " completed at " << readyTime[mach] + exec[i][mach] << "\n";
        readyTime[mach] = readyTime[mach] + exec[i][mach];
    }
}