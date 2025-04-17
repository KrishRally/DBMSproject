#include<iostream>
using namespace std;
struct Process{
	int at,bt,tat,ct,rt,wt;
};
int main(){
	int n;
	cout<<"Enter number of processes :\n";
	cin>>n;
	
	Process processes[n];
	for(int i=0;i<n;i++){
		cout<<"Arrival time for process "<<i+1<<" is :";
		cin>>processes[i].at;
	    cout<<"Burst time for process "<<i+1<<" is :";
		cin>>processes[i].bt;
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(processes[i].at>processes[j].at){
				swap(processes[i],processes[j]);
			}
		}
	}
	
	int current_time=0;
	float sumWT=0;
	float sumTAT=0;
	for(int i=0;i<n;i++){
		if(current_time<processes[i].at){
			current_time=processes[i].at;
		}
		
		processes[i].ct=current_time+processes[i].bt;
		processes[i].rt=current_time-processes[i].at;
		processes[i].tat=processes[i].ct-processes[i].at;
		processes[i].wt=processes[i].tat-processes[i].bt;
		
		current_time=processes[i].ct;
		sumWT=sumWT+processes[i].wt;
		sumTAT=sumTAT+processes[i].tat;
	}
		cout<<"\nArrival Time\tBurst Time\tCompletion Time\tResponse Time\tTurn Around Time\tWaiting Time\n";
	for(int i=0;i<n;i++){
	

	cout<<processes[i].at<<"\t\t";
	cout<<processes[i].bt<<"\t\t";
	cout<<processes[i].ct<<"\t\t";
	cout<<processes[i].rt<<"\t\t";
	cout<<processes[i].tat<<"\t\t\t";
	cout<<processes[i].wt<<"\n";
	}
	float avgWT=sumWT/n;
	float avgTAT=sumTAT/n;
	cout<<"\n Average Waiting  Time is "<<avgWT;
	cout<<"\n Average Turn Around Time is "<<avgTAT;
}
