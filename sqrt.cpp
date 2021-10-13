#include<stdio.h>
int main(){
    double l,r,mid,n;
    int mm=0;
    scanf("%lf",&n);
    mid=n/2;
    l=0;r=n;
    while(mm<40){
        if(mid*mid>=n){
            r=mid;
            mid=(l+r)/2;
        }
        else{
            l=mid;
            mid=(l+r)/2;
        }
        mm++;
    }
    printf("%.5lf",mid);
    return 0;
}
