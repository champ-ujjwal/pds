// MET
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
int minExecTimeMach(vector<vector<int>> &exec,int task)
{
    int m= exec[0].size();
    int minTime=INT_MAX , res=0;
    for (int i = 0; i < m; i++)
    {
        if (exec[task][i]<minTime)
        {
            minTime= exec[task][i];
            res= i;
        }
    }
    return res;
}
int main()
{   
    int tasks , machines ;
    cout<<"Enter number of Machines : ";
    cin>>machines;
    cout<<"Enter number of tasks  : ";
    cin>>tasks;
    vector<int> readyTime(machines,0);
    cout<<"Enter Intial Ready Time of Machines : ";
    for (int i = 0; i <machines; i++)
    {
        cin>>readyTime[i];
    }
    vector<vector<int>> exec(tasks,vector<int>(machines,0));
    cout<<"Enter the execution time of each task for all machines : \n";
    for (int i = 0; i < tasks; i++)
    {
        for (int j = 0; j< machines; j++)
        {
            cin>>exec[i][j];
        }
    }
    for (int i = 0; i <tasks; i++)
    {
        int mach= minExecTimeMach(exec,i);
        cout<<"Task : "<<i<<" assigned to machine : "<<mach<<" at "<<readyTime[mach]<<" completed at : "<<readyTime[mach]+exec[i][mach]<<"\n";
        readyTime[mach]= readyTime[mach]+exec[i][mach];
    }
}