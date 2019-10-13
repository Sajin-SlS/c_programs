#include <stdio.h>
#include <stdlib.h>

void quicksort(int a[],int l,int r)
{
    if (l<r)
    {
        int p = partition(a,l,r);
        quicksort(a,l,p);
        quicksort(a,p+1,r);
    }
}
void partition(int a[],int l,int r)
 {
    int i = l-1;
    int j = r+1;
    int pivot = a[l];
    while(1){
        do{
            ++i;
        }while (a[i] < pivot);

        do{
            --j;
        }while (a[j] > pivot);

        if (i >= j)
            return j;
        a[i]=a[i]+a[j]-(a[j]=a[i]);
        }
 }
void main()
{
int a[20],n,i;
printf("Enter the size :");
scanf("%d",&n);
printf("Enter the array elements :");

for(i=0;i<n;i++)
    scanf("%d",&a[i]);
quicksort(a,0,n-1);
printf("sorted array:\n");
for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
