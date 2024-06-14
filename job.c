#include<stdio.h>
typedef struct {
    int pro_num;
    int profit;
    int deadline;
} Object;
void bubbleSort(Object arr[], int n) {
    for(int i = 0; i < n-1; i++) {     
        for (int j = 0; j < n-i-1; j++) { 
            if (arr[j].profit < arr[j+1].profit) {
                Object temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int max(Object a[],int n)
{
    int max = a[0].deadline;
    for(int i=1;i<n;i++)
    {
        if(a[i].deadline > max)
        {
            max = a[i].deadline;
        }
    }
    return max;
}
int main(){
    int n;
    printf("\nEnter the number of process:");
    scanf("%d",&n);
    int p[n];
    int d[n];
    Object objects[n];
    printf("\nEnter the profits: ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
        objects[i].profit=p[i];
        objects[i].pro_num = i+1;
    }
    printf("\nEnter the deadlines: ");
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
        objects[i].deadline=d[i];
    }
    bubbleSort(objects, n);
    int m=max(objects,n);
    int job[m];
    int maxp=0;
    for(int i=0;i<m;i++)
    {   
        if(objects[i].profit>objects[i+1].profit){
            job[i]=objects[i].pro_num; 
        }
        maxp+=objects[i].profit;
    }
    printf("\nThe max profit is: %d",maxp);
    printf("\nThe jobs are: ");
    for(int i=0;i<m;i++){
        printf("{J%d }",job[i]);
    } 
    return 0;
}