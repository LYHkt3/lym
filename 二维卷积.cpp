#include<bits/stdc++.h>
using namespace std;

int a[101][101],b[21][21],c[101][101];
int n,m,h,l;

void JJHin();           //卷积核输入
void JZin();            //矩阵输入
void overturn();        //卷积核翻转
void JZMAX();           //矩阵扩边
void COUNT();           //卷积计算
int Count(int ,int );
void Print();           //输出卷积结果

int main(){

    JJHin();
    JZin();
    overturn();
    COUNT();
    Print();

    return 0;
}

void JJHin(){          //卷积核输入
    cout<<"输入卷积核行："<<endl;
    cin>>h;
    cout<<"输入卷积核列："<<endl;
    cin>>l;
    cout<<"输入卷积核:"<<endl;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=l;j++)
        cin>>b[i][j];
    return ;
}

void JZin(){           //矩阵输入

    int x=h/2,y=l/2;   //矩阵扩边

    cout<<"输入矩阵行："<<endl;
    cin>>n;
    cout<<"输入矩阵列："<<endl;
    cin>>m;
    cout<<"输入矩阵:"<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>a[i+x][j+y];
    
    for(int i=1;i<=x;i++)        //矩阵扩边后赋值为0
        for(int j=1;j<=y+m;j++)
        a[i][j]=0;
    for(int i=1;i<=y;i++)
        for(int j=1;j<=h+x;j++)
        a[j][i]=0;
    return ;
}

void overturn(){      //卷积核翻转180°
    //上下翻转
    for(int i=1;i<=l;i++)
        for(int j=1;j<=(h/2);j++){
            int t;
            t=b[j][i];b[j][i]=b[h-j+1][i];b[h-j+1][i]=t;
        }
    //左后翻转
    for(int i=1;i<=h;i++)
        for(int j=1;j<=(l/2);j++){
            int t;
            t=b[i][j];b[i][j]=b[i][l-j+1];b[i][l-j+1]=t;
        }
    return ;
}

void COUNT(){

    int x=h/2,y=l/2;

    for(int i=x+1;i<=n+x;i++)
        for(int j=y+1;j<=m+y;j++)
        c[i-x][j-y]=Count(i,j);    //计算当前小格的值

    return ;
}

int Count(int e,int f){           //计算当前小格的值
    int sum=0;
    int x=e-h/2-1;
    int y=f-l/2-1;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=l;j++)
        sum+=b[i][j]*a[x+i][y+j];
    return sum;
}

void Print(){                    //输出结果
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        cout<<c[i][j]<<" ";
        cout<<endl;
    }
    return ;
}