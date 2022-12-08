#include <bits/stdc++.h>
using namespace std;

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
    return 0;
}