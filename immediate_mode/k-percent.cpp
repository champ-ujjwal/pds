#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
int minComplMachine(vector<pair<int,int>> &exec, vector<int> &readyTime, int task)
{
    int m = exec.size();
    int minTime = INT_MAX, res = 0;
    for (int i = 0; i < m; i++)
    {
        int x= exec[i].second;
        if (exec[i].first + readyTime[x] < minTime)
        {
            minTime = exec[i].first + readyTime[x];
            res = x;
        }
    }
    return res;
}
vector<pair<int,int>> getSubset(vector<vector<int>> &exec,int task,int sz)
{
    int m= exec[0].size();
    vector<pair<int,int>> tem;
    for (int i = 0; i <m; i++)
    {
        tem.push_back({exec[task][i],i});
    }
    sort(tem.begin(),tem.end());
    tem.erase(tem.begin()+sz,tem.end());
    return tem;
}
int main()
{
    int tasks, machines;
    cout << "Enter number of Machines : ";
    cin >> machines;
    cout << "Enter number of tasks  : ";
    cin >> tasks;
    double k = 0.0;
    vector<int> readyTime(machines, 0);
    cout << "Enter Intial Ready Time of Machines : ";
    for (int i = 0; i < machines; i++)
    {
        cin >> readyTime[i];
    }
    vector<vector<int>> exec(tasks, vector<int>(machines, 0));
    cout << "Enter the execution time of each task for all machines : \n";
    for (int i = 0; i < tasks; i++)
    {
        for (int j = 0; j < machines; j++)
        {
            cin >> exec[i][j];
        }
    }
    cout << "Enter the value of K : ";
    cin >> k;
    int sz= (machines*k)/100;
    for (int i = 0; i < tasks; i++)
    {
        vector<pair<int,int>> subset =getSubset(exec,i,sz);
        int mach = minComplMachine(subset, readyTime, i);
        cout << "Task  " << i << " assigned to machine  " << mach << " at " << readyTime[mach] << " ms  completed at " << readyTime[mach] + exec[i][mach] << "ms \n";
        readyTime[mach] = readyTime[mach] + exec[i][mach];
    }
}