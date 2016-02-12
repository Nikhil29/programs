#include<stdio.h>
#include<malloc.h>

//partition function to divide the arrary about a pivot
int partition(int *a,int i,int j){
    int v=j,u=i+1,w;
    while(v>=u){
        for(;u<=j;u++){
            if(a[u]>a[i])
               break;
        }
       for(;v>=i;v--){
            if(a[v]<a[i])
                break;
        }
       if(v>u){
         w=a[u];
         a[u]=a[v];
         a[v]=w;
       }
    }
    if(v==i-1){
        return u-1;
    }
    else{
        return v;
    }
}

//main quick sort function
int quicksort(int *a,int i,int j){
    if(i>=j)
        return 0;
    int u,w;
    u=partition(a,i,j);
    w=a[i];
    a[i]=a[u];
    a[u]=w;
    quicksort(a,i,u-1);
    quicksort(a,u+1,j);
    return 0;
}

int main(){
    int n,*a,i,s;
    
    //input
    printf("enter the no. of elements in array\n");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);

    printf("enter the elements of array\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //sort
    quicksort(a,0,n-1);
    
    //print the sorted array
    printf("the sorted array is \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    return 0;
}