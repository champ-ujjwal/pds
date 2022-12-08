#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
int main()
{   
    int tasks , machines ;
    cout<<"Enter number of Machines : ";
    cin>>machines;
    cout<<"Enter number of tasks  : ";
    cin>>tasks;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > readyTime;
    cout<<"Enter Intial Ready Time of Machines : ";
    for (int i = 0; i <machines; i++)
    {
        int t;
        cin>>t;
        readyTime.push({t,i});
    }
    vector<vector<int>> exec(tasks,vector<int>(machines,0));
    cout<<"Enter the execution time of each task for all machines : \n ";
    for (int i = 0; i < tasks; i++)
    {
        for (int j = 0; j< machines; j++)
        {
            cin>>exec[i][j];
        }
    }
    for (int i = 0; i <tasks; i++)
    {
        int mach= readyTime.top().second;
        int time= readyTime.top().first;
        cout<<"Task : "<<i<<" assigned to machine : "<<mach<<" at "<<time<<" completed at : "<<time+exec[i][mach]<<"\n";
        readyTime.pop();
        readyTime.push({time+exec[i][mach],mach});
        // readyTime[mach]= readyTime[mach]+exec[i][mach];
    }
}