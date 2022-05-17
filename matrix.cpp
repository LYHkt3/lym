#include<iostream>
#include"matrix.h"
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    Matrix a(N,M),b(N,M);
    Matrix c(0,0);
    a.IN();
    b.IN();
    c=mul(a,b);
    c.PUT();
    c=dot(a,b);
    c.PUT();
    c=add(a,b);
    c.PUT();
    c=sub(a,b);
    c.PUT();
    return 0;
}