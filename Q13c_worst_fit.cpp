#include <iostream>			//input output stream
using namespace std;
void sort(int m[],int block[],int x)		//method for sorting memory block size
{
	int min,loc,i,j,temp1,temp2;

	for(i=0;i<x-1;i++)
	   {
               	min=m[i];
		loc=i;
			for(j=i+1;j<x;j++)
				{
					if(min<m[j])
					    {   min=m[j];
						loc=j; 
					    }
				}
		temp1=m[i];
		m[i]=m[loc];
		m[loc]=temp1;
		
		temp2=block[i];
		block[i]=block[loc];
		block[loc]=temp2;
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

	int mem[mem_num], block[mem_num];
	
	for(int i=0; i<mem_num; i++)			//taking size of each memory blocks
	{
		cout<<"Enter size of memory block "<<i+1<<": ";
		cin>>mem[i];
		block[i]=i+1;			//block[] to track each block after sorting

	}
	
	int val=0;
	cout<<"Process No.\tProcess size\tBlock no."<<endl;
	
	for(int i=0;i<prs_num;i++)
		{
			sort(mem,block,mem_num);		//sorting memory blocks
				for(int j=0;j<mem_num;j++)
                                    { 
					 if(prs[i]<=mem[j])	//finding in which memory block process fits
	 				  {
		               		cout<<"P"<<i+1<<"\t\t"<<prs[i]<<"\t\t"<<block[j];
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
			
			
			
			
	
