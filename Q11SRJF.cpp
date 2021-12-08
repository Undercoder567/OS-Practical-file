//WAP to implement SRJF Scheduling Algorithm

#include <iostream>		//input output stream
using namespace std;

int main()
{
	int n, process[20], burst[20], wait[20], turn[20], arrival[20], ct[20], count=0, time, min, end;
	float avg_wait=0;
	
	cout<<"\nEnter number of processes: ";			//taking number of process
	cin>>n;
	cout<<endl;
	

	for(int i=0; i<n; i++)
	{						
		cout<<"Enter burst time for process P"<<i+1<<": ";		//taking burst time
		cin>>burst[i];
		cout<<"Enter arrival time for process P"<<i+1<<": ";		//taking arrival time
		cin>>arrival[i];
		process[i]=i+1;						//array to store process number
		cout<<endl;
	}
	
	
	int rt[n];
	for(int i=0; i<n; i++)
	{
		rt[i] = burst[i];					//copying burst array to a temp array
	}
	
	for(int time=0; count!=n; time++)
	{
		int i;
		min=19;
		for(i=0; i<n; i++)
		{
			if(arrival[i]<=time && burst[i]<burst[min] && burst[i]>0)	//if process with burst time smaller than burst[min] 											found then updating value of min with it
			{
				min=i;
			}
		}
		
		burst[min]--;		//decrementing burst[min] by 1 since it completed 1sec from its burst time
		
		if(burst[min]==0)		//when a process get executed completely
		{
			count++;
			end = time+1;
			ct[min] = end;
			wait[min] = end- arrival[min] - rt[min];		//calculating waiting time
			turn[min] = end - arrival[min];			//calculating turnaround time
		}
	}
	

	cout<<"\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\t\tWaiting Time\tTurn Around Time\n";	//printing details
	for(int i=0;i<n;i++)
    	{	
    		cout<<process[i] <<"\t\t"<< arrival[i] <<"\t\t"<< rt[i] <<"\t\t"<< ct[i]<<"\t\t\t"<< wait[i] <<"\t\t\t"<< turn[i];
    		cout<< endl;
    	}
	

	for(int i=0; i<n; i++)
	{
		avg_wait+=wait[i];			//calculating avg wait time
	}
	
	avg_wait/=n;
	cout<<"\n\nAverage Waiting Time: "<<avg_wait<<endl;
	
return 0;
}

	










