#include<stdio.h>
#define newline (printf("\n"));
void getArray();
int calcBreakpoint();
int binarySearch();
void swap();
void leftRotatearray();
void reverse();
void printArray(int arr[],int start, int end){
    for(int i=0;i<end-start+1;i++){
        printf("%d ",arr[i+start]);
    }

}
void main()
{
    int n,value;
    scanf("%d",&n);
    int arr[n];
    getArray(arr,n);
    scanf("%d",&value);
    int breakpoint=calcBreakpoint(arr,n);
    leftRotatearray(arr,breakpoint,n);
    int index=binarySearch(arr,0,n-1,value);
    (index==-1)?printf("Element not found "):printf("%d found at %d",value,index+breakpoint+1);
}
int calcBreakpoint(int arr[],int n){
int index=0;
while(arr[index]<arr[index+1])
{
    index++;

}
return index;
}
int binarySearch(int arr[], int start,int end, int value){
    if(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==value)
        return mid;
        else if(arr[mid]<value)
        return binarySearch(arr,mid+1,end,value);
        else return binarySearch(arr,start,mid-1,value);
    }
    return -1;
}
void getArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Please enter %d value : ",i+1);
        scanf("%d",&arr[i]);
    }
}

void leftRotatearray(int arr[],int breakpoint,int n) {
    reverseArray(arr,0,breakpoint,breakpoint+1); //(array,start,end,no.of elements) reverses array from 0 to breakpoint
    reverseArray(arr,breakpoint+1,n-1,n-breakpoint-1); //and breakpoint +1 to end
    reverseArray(arr,0,n-1,n); // reverses complete array
}
void reverseArray(int arr[],int start,int end,int n){
    int j=0,i=n;
    int start2=start,end2=end;
    while(start2<end2){
        swap(&arr[start2],&arr[end2]); //reverses array by swaping first and last element and so on towards each other direction
        start2++;
        end2--;
    }

}
void swap (int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
