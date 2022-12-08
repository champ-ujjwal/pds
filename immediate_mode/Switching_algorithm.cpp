// switching algo
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
int minExecTimeMach(vector<vector<int>> &exec, int task)
{
    int m = exec[0].size();
    int minTime = INT_MAX, res = 0;
    for (int i = 0; i < m; i++)
    {
        if (exec[task][i] < minTime)
        {
            minTime = exec[task][i];
            res = i;
        }
    }
    return res;
}

int minComplMachine(vector<vector<int>> &exec, vector<int> &readyTime, int task)
{
    int m = exec[0].size();
    int minTime = INT_MAX, res = 0;
    for (int i = 0; i < m; i++)
    {
        if (exec[task][i] + readyTime[i] < minTime)
        {
            minTime = exec[task][i] + readyTime[i];
            res = i;
        }
    }
    return res;
}
void updateMinMaxReadyTime(vector<int> &readytime,int &minr,int maxr)
{
    // cout<<"ready : ";
    int m=INT_MAX , M= INT_MIN;
    for(auto x: readytime)
    {
        // cout<<x<<"  ";
        m = min(m, x);
        M = max(M,x);
    }
    // cout<<"\n";
    minr= m; maxr= M;
}
int main()
{
    int tasks, machines;
    cout << "Enter number of Machines : ";
    cin >> machines;
    cout << "Enter number of tasks  : ";
    cin >> tasks;
    double load = 0.0;
    int minr = INT_MAX, maxr = INT_MIN;
    vector<int> readyTime(machines, 0);
    cout << "Enter Intial Ready Time of Machines : ";
    for (int i = 0; i < machines; i++)
    {
        cin >> readyTime[i];
        minr = min(minr, readyTime[i]);
        maxr = max(maxr, readyTime[i]);
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
    double minLoad, maxLoad;
    bool algo = true; // algo-> true ->MCT || algo->false->MET
    cout << "Enter min and max Load threshold respectively : ";
    cin >> minLoad >> maxLoad;
    for (int i = 0; i < tasks; i++)
    {
        if (load >= maxLoad && algo)
        {
            algo = false;
        }
        else if (load <= minLoad && !algo)
        {
            algo = true;
        }
        int mach;
        if (algo)
        {
            mach = minComplMachine(exec, readyTime, i);
        }
        else
        {
            mach = minExecTimeMach(exec, i);
        }
        cout << "Task  " << i << " assigned to machine  " << mach << " at " << readyTime[mach] << " ms  completed at " << readyTime[mach] + exec[i][mach] << "ms \n";
        readyTime[mach] = readyTime[mach] + exec[i][mach];
        updateMinMaxReadyTime(readyTime,minr,maxr);
        load= (double)minr/maxr;
        // cout<<"minr= "<<minr<<" "<<maxr<<"\n";
        // cout<<"Load : "<<load<<"\n";
    }
}