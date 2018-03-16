#include<stdio.h>
int main()
{
  int arr[100],i,j,a,temp,c,b,count,T,x;

scanf("%d",&T);
for(x=0;x<T;x++){
  scanf("%d",&a);
   for(i=0;i<a;i++){
    scanf("%d",&arr[i]);
   }


      count=0;
    for(b=0;b<a;b++){
          for(j=0;j<b;j++){
       if(arr[j]>arr[b]){
        temp=arr[j];
        arr[j]=arr[b];
        arr[b]=temp;
        count++;
       }
}
  }


    printf("Optimal train swapping takes %d swaps.\n",count);

}


return 0;
}