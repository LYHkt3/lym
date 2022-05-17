#include<iostream>
using namespace std;
bool check(int );
bool CK(int );
int main(){
    for(int i=100;i<=999;i++)
       if(check(i)) cout<<i<<endl;
    return 0;
}
bool check(int x){
    int a[10],r=x,lyh=0,sum=0,sum1=0;
    while(r){
       a[lyh++]=r%10;
       r/=10;
    }
    for(int i=0;i<=2;i++){
        sum+=a[i];
        sum1+=a[i]*a[i];
    }
    if(CK(sum)&&CK(sum1)&&CK(x)) return true;
    return false;
}
bool CK(int x){
    for(int j=2;j*j<=x;j++)
       if(!(x%j)) return false;
    return true;
}