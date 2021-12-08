#include<iostream> 			//input output stream
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of processes: ";
	cin>>n;						//taking number of processes
	
	int burst[n],process[n];

	for(int i=0; i<n; i++)
	{
		cout<<"Enter the burst time for process P"<<i+1<<" :";
		cin>>burst[i];					//taking burst time
		process[i]=i+1; 
	}
	
	int j,k;
	int temp1,temp2;
	for(j=1; j<n; j++)					//sorting burst time
	{
		temp1=burst[j];
		temp2=process[j];
		for(k=j; k>0 && temp1<burst[k-1]; k--)
		{
			burst[k]=burst[k-1];
			process[k]=process[k-1];
		}
		
		burst[k]=temp1;
		process[k]=temp2;
	}
	


	int wait_time[n],turnaround_time[n];
	
	wait_time[0]=0;
	for(int i=1; i<n; i++)
		wait_time[i]=wait_time[i-1]+burst[i-1];		//calculating wait time
		
	for(int i=0; i<n; i++)
		turnaround_time[i]=wait_time[i]+burst[i];		//calculating turnaround time
		
	
	
	float avg_wt=0,avg_tt=0;
	
	cout<<"	Burst Time    Waiting Time    Turnaround Time"<<endl;		//printing wait time & turnaround time
	for(int i=0; i<n; i++)
	{
		cout<<"P"<<process[i]<<"	 "<<burst[i]<<"	 	"<<wait_time[i]<<"	 	"<<turnaround_time[i]<<endl;
		avg_wt+=wait_time[i];
		avg_tt+=turnaround_time[i];
	}

	avg_wt=avg_wt/n;
	avg_tt=avg_tt/n;

	cout<<"\nAverage waiting time= "<<avg_wt<<endl;
	cout<<"\nAverage turnaround time= "<<avg_tt<<endl;

	return 0;
}

