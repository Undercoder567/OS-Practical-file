//non-preemptive priority scheduling algorithm

#include <iostream>		//input output stream
using namespace std;
int main()
{
	int n,temp1,temp2,temp3;
	cout<<"Enter number of processes: ";
	cin>>n;						//taking number of process
	
	int burst[n],priority[n],process[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter burst time for process P"<<i+1<<" :";
		cin>>burst[i];					//taking burst time for each process
		process[i]=i+1;				
	}
	cout<<endl;
	
	for(int i=0; i<n; i++)
	{
		cout<<"Enter priority of P"<<i+1<<" :";
		cin>>priority[i];				//taking priority of each process
	}
	
	int x,y;	
	for(x=1; x<n; x++)					//sorting array on the basis of priority array
	{
		temp1=priority[x];
		temp2=process[x];
		temp3=burst[x];
		
		for(y=x; y>0 && temp1<priority[y-1]; y--)
		{
			priority[y]=priority[y-1];
			process[y]=process[y-1];		//swapping elements of process[] along with priority
			burst[y]=burst[y-1];			//swapping elements of burst[] along with priority
		}
			priority[y]=temp1;	
			process[y]=temp2;
			burst[y]=temp3;
	}
	
	int wait_time[n],turnaround_time[n];
	float avg_wt=0,avg_tt=0;
	
	wait_time[0]=0;
	for(int i=1; i<n; i++)
		wait_time[i]=wait_time[i-1]+burst[i-1];				//calculating wait time
		
	for(int i=0; i<n; i++)
		turnaround_time[i]=wait_time[i]+burst[i];				//calculating turnaround time
		

	cout<<"	Burst Time    Waiting Time    Turnaround Time"<<endl;	//printing wait time & turnaround time
	for(int i=0; i<n; i++)
	{
		cout<<"P"<<process[i]<<"	 "<<burst[i]<<"	 	"<<wait_time[i]<<"	 	"<<turnaround_time[i]<<endl;
		avg_wt+=wait_time[i];				//calculating total sum of wait time
		avg_tt+=turnaround_time[i];			//calculating total sum of turnaround time
	}

	avg_wt=avg_wt/n;								//calculating average wait time
	avg_tt=avg_tt/n;								//calculating average turnaround time

	cout<<"\nAverage waiting time= "<<avg_wt<<endl;
	cout<<"\nAverage turnaround time= "<<avg_tt<<endl;

	
	return 0;
}
	
	
	
	
	
