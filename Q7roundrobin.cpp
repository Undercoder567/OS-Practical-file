#include <iostream>
using namespace std;
int main()
{
	int n;

	cout<<"Enter the number of processes: ";
	cin>>n;

	int burst_time[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter burst time for P"<<i+1<<": ";
		cin>>burst_time[i]; 
	}

	int t;
	cout<<"Enter time slice: ";
	cin>>t;

	int max=burst_time[0];
	for(int i=1; i<n; i++)
	{
		if(max<burst_time[i])
			max=burst_time[i];
	}

	int turnaround_time[n],temp[n];
	int a=0;

	for(int i=0;i<n;i++)
		temp[i]=burst_time[i];
	

	for(int i=0; i<(max/t)+1; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(temp[j]!=0)
			{
				if(temp[j]<=t)
				{
					turnaround_time[j]=temp[j]+a;
					a=temp[j]+a;
					temp[j]=0;
				}
				else		
				{
					temp[j]=temp[j]-t;
					a=a+t;
				}
			}
		}
	}


	int wait_time[n];
	float avg_wt=0, avg_tt=0;

	for(int i=0; i<n; i++)
		wait_time[i]=turnaround_time[i]-burst_time[i];
	


	cout<<"	Burst Time    Waiting Time    Turnaround Time"<<endl;	
	for(int i=0; i<n; i++)
	{
		cout<<"P"<<i+1<<"	 "<<burst_time[i]<<"	 	"<<wait_time[i]<<"	 	"<<turnaround_time[i]<<endl;
		avg_wt+=wait_time[i];
		avg_tt+=turnaround_time[i];
	}

	avg_wt=avg_wt/n;
	avg_tt=avg_tt/n;

	cout<<"\nAverage waiting time= "<<avg_wt<<endl;
	cout<<"\nAverage turnaround time= "<<avg_tt<<endl;

	return 0;
}















