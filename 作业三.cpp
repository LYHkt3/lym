#include<stdio.h>
int main(){
    int sum=0,m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int n=i;
        while(n>0){
            if(n%10==1) sum++;
            n/=10;
        }
        if(sum==i) printf("f(%d)=%d\n",i,i);
    }
    return 0;
}