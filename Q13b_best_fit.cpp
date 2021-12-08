#include <iostream>			//input output stream
using namespace std;
void sort(int mem[], int a)		//method for sorting memory block size
{
	int j,k;
	int temp;
	for(j=1; j<a; j++)					
	{
		temp=mem[j];
		for(k=j; k>0 && temp<mem[k-1]; k--)
		{
			mem[k]=mem[k-1];
		}
		
		mem[k]=temp;
	}
}

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

	int mem[mem_num], temp_mem[mem_num];
	
	for(int i=0; i<mem_num; i++)			//taking size of each memory blocks
	{
		cout<<"Enter size of memory block "<<i+1<<": ";
		cin>>mem[i];
		temp_mem[i]=mem[i];			//creating copy of mem[]

	}
	
	int val=0;
	cout<<"Process No.\tProcess size\tBlock no."<<endl;
	
	for(int i=0;i<prs_num;i++)
		{
			sort(mem,mem_num);			//sorting memory blocks
				for(int j=0;j<mem_num;j++)
                                    { 
					 if(prs[i]<=mem[j])	//finding in which memory block process fits
	 				  {
	  					 //for(int k=0;k<mem_num;k++)
	   					 //{
	   					   //if(temp_mem[k]==mem[j])
	   					   //val=k; 
	   					 //}
		               	cout<<"P"<<i+1<<"\t\t"<<prs[i]<<"\t\t"<<mem[j];//<<val+1;
		           		mem[j]=mem[j]-prs[i];
	                               prs[i]=0;
	                               break;
	                                       
					}
				}	
			cout<<endl;			
		}
	
	for(int i=0; i<prs_num; i++)					//printing process which are not allocated
	{
		if(prs[i]!=0)
			cout<<"P"<<i+1<<"\t"<<"\t"<<prs[i]<<"\t"<<"\t"<<"Not Allocated"<<endl;
	}
	
	return 0;
}	
			
			
			
			
	
