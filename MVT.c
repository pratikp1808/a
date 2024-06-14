#include<stdio.h>
#include<math.h>
int main() 
{
    int i,j=1,k;
    int mrm[5],max=0,job[5];
    int os,sys;
	int fix=10; 
	int f[5],tf=0,rf[5];
   
    
    printf("Enter the maximum memory is: ");
    scanf("%d",&max);
    printf("\nThe Fix Part Of Memory Is %d: ",fix);
    os=(max*0.4);
    sys=(max*0.6);
    tf=sys/fix;
    for(i=0;i<5;i++) 
	{
		printf("\nEnter the Name of %d process:",i+1);
		scanf("%d", &job[i]);
        printf("Enter the Memory of %d Job: ",i+1);
        scanf("%d", &mrm[i]);
        rf[i]=mrm[i]/fix;
    }
    
    printf("\nJob\t\tMemorye\t\tFrames\n");
	for(i=0;i<5;i++) 
	{
        printf("\nJ%d\t\t%d\t\t%d",job[i],mrm[i],rf[i]);
        j++;
    }
    printf("\nThe Memory allocated to operating system is:%d",os);
	printf("\nThe Memory remaining to excute process is:%d",sys);
	printf("\nTotal frames avaliable is:%d",tf);
	printf("\nTotal size of each frame is:%d",fix);
    k=0;
    do
    {
    	if(sys>=mrm[k])
    	{
    		f[k]=job[k];
    		sys-=mrm[k];
    		k++;
		}
		else
		{
//			continue;
			break;
		}
	}while(k<5||sys==0);
	  
	for(i=0;i<k;i++)
	{
	  	printf("\n\nExcuted: J%d",f[i]);
	} 
	printf("\n\nRemaining memory is:%d",sys); 
}