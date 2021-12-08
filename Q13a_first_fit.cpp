//first fit

#include <iostream>			//input output stream
using namespace std;
int main()
{
	int prs_num,mem_num;
	
	cout<<"Enter number of process: ";		//taking number of process
	cin>>prs_num;
	
	int prs[prs_num];				//creating array for process		
	
	for(int i=0; i<prs_num; i++)			//taking size of each process
	{
		cout<<"Enter size of process P"<<i+1<<": ";
		cin>>prs[i];
	}
	
	cout<<"Enter number of memory blocks: ";		//taking number of memory blocks
	cin>>mem_num;

	int mem[mem_num];				//creating array for memory blocks
	
	for(int i=0; i<mem_num; i++)			//taking size of each memory blocks
	{
		cout<<"Enter size of memory block "<<i+1<<": ";
		cin>>mem[i];
	}
	
	cout<<"Process No"<<"  Process size   "<<"Block No"<<endl;		//printing
	for(int i=0; i<prs_num; i++)
	{
		for(int j=0; j<mem_num; j++)
		{
			if(prs[i]<=mem[j])					//finding block in which process will fit
			{
				cout<<i+1<<"\t"<<"\t"<<prs[i]<<"\t"<<"\t"<<j+1<<endl;	//printing block in which process will fit	
				mem[j]=mem[j]-prs[i];
				prs[i]=0;					
				break;
			}
		}				
	}
	
	for(int i=0; i<prs_num; i++)					//printing process which are not allocated
	{
		if(prs[i]!=0)
			cout<<i+1<<"\t"<<"\t"<<prs[i]<<"\t"<<"\t"<<"Not Allocated"<<endl;
	}
	
	return 0;
}	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
