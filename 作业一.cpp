#include<stdio.h>
int num[7];
void splitnum(int );
int check1(int );
int check2(void);
int main(){
    int lyh=0,sum=0,tot=0,lym=0;
	int a[301];
    for(int i=100;i<=10000;i++){
        splitnum(i);
        lyh=check1(i);
        if(lyh) continue;
        lym=check2();
        if(lym==0)  {
            sum+=i;tot++;a[tot]=i;
        }
        lyh=lym=0;
    }
    printf("平均数：%lf\n",(double)sum/(double)tot);
    for(int i=1;i<=tot;i++)
    printf("%5d",a[i]);
    return 0;
}
void splitnum(int x){
    int i;
    for(i=0;i<=6;i++) num[i]=-1;
    for( i=0 ; ;){
        if(x==0) break;
        i++;
        num[i]=x%10;
        x/=10;
    }
    return ;
}
int check1(int x){
    for(int i=2;i*i<=x;i++)
    if(x%i==0) return 1;
    return 0;
}
int check2(){
    int sum=0,sumtol=0,lyh=0;
    for(int i=1;num[i]!=-1;i++){
        sum+=num[i];
        sumtol+=num[i]*num[i];
    }
    lyh=check1(sum);
    if(lyh) return 1;
    return check1(sumtol);
}