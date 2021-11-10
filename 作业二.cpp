#include<iostream>
#include<math.h>
using namespace std;
int check(int );
int Pd(int ,int );
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++){
            if( i<=j){
                if(Pd(i,j)) 
                cout<<i<<" "<<j<<endl;
            }
        }
    return 0;
}
int check(int x){
    int lyh=1;
    for(int i=2;i*i<=x;i++)
    if(x%i==0){
        lyh=0;break;
    }
    return lyh;
}
int Pd(int a,int b){
    return check(pow(a,b)+pow(b,a));
}