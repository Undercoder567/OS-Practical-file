#include<iostream>	
using namespace std;			

int main()
{
	int n;

	cout<<"Enter number of process:";	
	cin>>n;
	
	int burst_time[n];
	for(int i=1; i<=n; i++)
	{
		cout<<"Enter Burst time for P"<<i<<": ";
		cin>>burst_time[i];
	}

	int wait_time[n];
	
	wait_time[1]=0;
	for(int i=2; i<=n; i++)
	{
		wait_time[i]=wait_time[i-1]+burst_time[i-1];
	}
	
	int turnaround_time[n];
	for(int i=1; i<=n; i++)
	{
		turnaround_time[i]=wait_time[i]+burst_time[i];
	}

	float avg_wait_time=0, avg_turnaround_time=0;

	for(int i=1;i<=n;i++)
	{
		avg_wait_time+= wait_time[i];
		avg_turnaround_time+= turnaround_time[i];
	}

	cout<<"	Burst Time    Waiting Time    Turnaround Time"<<endl;	
	for(int i=1; i<=n; i++)
	{
		cout<<"P"<<i+1<<"	 "<<burst_time[i]<<"	 	"<<wait_time[i]<<"	 	"<<turnaround_time[i]<<endl;
	}

	
	avg_wait_time= avg_wait_time/n;
	avg_turnaround_time= avg_turnaround_time/n;
	
	cout<<"\nAverage wait time ="<<avg_wait_time<<endl;
	cout<<"\nAverage turnaround time ="<<avg_turnaround_time<<endl;
return 0;
}





