#include<stdio.h>
int calcHammingDistance();
int main(){
    int n1,n2;
printf("Enter number 1 : ");
scanf("%d",&n1);
printf("Enter number 2 : ");
scanf("%d",&n2);
printf("%d\n",calcHammingDistance(n1,n2));
}
int calcHammingDistance(int n1,int n2){
int x=n1^n2,setbits=0;
while(x>0){
    setbits+=x&1;
    x>>=1;
}
return setbits;
}
