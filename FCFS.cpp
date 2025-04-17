#include<iostream>
using namespace std;
struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};
void completion_time(Process proc[],int n)
{
    proc[0].completion_time=proc[0].burst_time;
    for(int i=1;i<n;i++)
    {
        proc[i].completion_time=proc[i-1].completion_time+proc[i].burst_time;
    }
}
void turn_around_time(Process proc[],int n)
{
    for(int i=0;i<n;i++)
    {
        proc[i].turn_around_time=proc[i].completion_time-proc[i].arrival_time;
    }
}
void waiting_time(Process proc[],int n)
{
    proc[0].waiting_time=0;
    for(int i=1;i<n;i++)
    {
        proc[i].waiting_time=proc[i].turn_around_time-proc[i].burst_time;
    }
}
void fcfs(Process proc[],int n)
{
    completion_time(proc,n);
    turn_around_time(proc,n);
    waiting_time(proc,n);
}
void display(Process proc[],int n)
{
    cout<<"FCFS Scheduling:"<<endl;
    cout<<"PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<proc[i].pid<<"\t\t"<<proc[i].arrival_time<<"\t\t"<<proc[i].burst_time<<"\t\t"<<proc[i].completion_time<<"\t\t"<<proc[i].turn_around_time<<"\t\t"<<proc[i].waiting_time<<endl;

    }
}
    int main()
    {
        int n=5;
        Process proc[n]={{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};
        fcfs(proc,n);
        display(proc,n);
        return 0;
    }
