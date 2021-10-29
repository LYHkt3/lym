#include<bits/stdc++.h>
using namespace std;
 struct ln{
    char name[11],id[19],grade[4];
    int namel,idl,gradel,gradeint,PM,SX;
}a[101];
int cmp(const void *a,const void *b){   
    ln * f1=(ln *) a;ln * f2=(ln *) b;
    return f1->gradeint < f2->gradeint ? 1 : -1;
}
int cmpl(const void *a,const void *b){   
    ln * f1=(ln *) a;ln * f2=(ln *) b;
    return f1->SX > f2->SX ? 1 : -1;
}
void printl(int n){
	for(int j=0;j<=a[n].namel;j++)
    printf("%c",a[n].name[j]);   printf(" ");
    for(int j=0;j<=a[n].idl;j++)
    printf("%c",a[n].id[j]);   printf(" ");
    if(a[n].grade[0]=='n') printf("n/a n/a\n");
    else printf("%d %d\n",a[n].gradeint,a[n].PM);
    return ;
}
int main(){
    int n,max=0,min=101,sum=1,lyh=-1,lyhl=0;
    char b[21];
    scanf("%d",&n);
    getchar();
    do{ lyh++;
    	b[lyh]=getchar();
    }while(b[lyh]!='\n');lyh--;
    for(int i=0;i<n;i++){ 
        a[i].SX=i+1;
        a[i].namel=-1;
        do{  a[i].name[++a[i].namel]=getchar();
        }while(a[i].name[a[i].namel]!=' ');
        a[i].namel--;
        a[i].idl=-1;
		do{	a[i].id[++a[i].idl]=getchar();
        }while(a[i].id[a[i].idl]!=' ');
        a[i].idl--;
        a[i].gradel=-1;
        do{ a[i].grade[++a[i].gradel]=getchar();
        }while(a[i].grade[a[i].gradel]!='\n');
        a[i].gradel--;                       
	}
    for(int i=0;i<n;i++){
    	if(a[i].grade[0]=='n') {
    	  a[i].gradeint=-1;  continue;
        }
    	if(a[i].gradel==0) a[i].gradeint=(int)a[i].grade[0]-48;
    	if(a[i].gradel==1) 
		a[i].gradeint=(a[i].grade[0]-48)*10+ (a[i].grade[1]-48);
		if(a[i].gradel==2) a[i].gradeint=100;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    a[0].PM=sum;
    for(int i=1;i<n;i++){
    	sum++;
    	if(a[i].gradeint==a[i-1].gradeint) a[i].PM=a[i-1].PM;
        else a[i].PM=sum;
    }
    qsort(a,n,sizeof(a[0]),cmpl);
    if(lyh<=2 && ( b[0]<60 || b[1]=='/')){
    	int lym=0;
    	if(lyh==2 && b[0]=='n') lyhl=-1;
    	if(lyh==0) lyhl=b[0]-48;
    	if(lyh==1) lyhl=(b[0]-48)*10+ (b[1]-48);
		if(lyh==2 && lyhl!=-1) lyhl=100;
		for(int i=0;i<n;i++)
		    if(lyhl==a[i].gradeint){ 
			 printl(i);lym++;
		    }
		if(lym!=0) return 0;
    }
    if(b[0]<60){
    	for(int i=0;i<n;i++)
    	   for(int j=0;j<=a[i].idl-lyh;j++)
    	   if(b[0]==a[i].id[j]&&b[1]==a[i].id[j+1]){
		     int lym=0;
    	     for(int k=j;k<=j+lyh;k++)
    	   	    if(b[lym]==a[i].id[k]) lym++;
    	   	 lym--;
    	   	 if(lym==lyh) printl(i);
    	   }
    }
    else {
    	for(int i=0;i<n;i++)
    	   for(int j=0;j<=a[i].namel-lyh;j++)
    	   if(b[0]==a[i].name[j]&&b[1]==a[i].name[j+1]){
    	   	  int lym=0;
    	   	  for(int k=j;k<=j+lyh;k++)
    	   	     if(b[lym]==a[i].name[k]) lym++;
    	   	  lym--;
    	   	  if(lym==lyh) printl(i);
    	   }
    }
    return 0;
}