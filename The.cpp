#include<bits/stdc++.h> 
using namespace std;
int n,m,a[1001][1001][5],mapl[1001][1001],s[1005][2];
int dx[5]={0,0,-1,0,1},dy[5]={0,-1,0,1,0},tot=0,ans=0;
void bfs(int x,int y)
{
	int h,t,i,ac,bd;
	memset(s,0,sizeof(s));
	h=0;t=1;
	s[1][1]=x;
	s[1][2]=y;
	mapl[x][y]=1;
	do
	{
	 h++;
	 ac=s[h][1];
	 bd=s[h][2];
	 for(i=1;i<=4;i++)
	 {
		int xx=s[h][1]+dx[i],yy=s[h][2]+dy[i];
		if(a[ac][bd][i]==0)
		{
		 if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mapl[xx][yy]==0)
		 {
		 	t++;
		 	mapl[xx][yy]=1;
		 	s[t][1]=xx;
		 	s[t][2]=yy;
		 }
		}
	 }
	}
	while(h<=t);
	tot++;
	if(t>ans)ans=t;
	return ;	
}
int main()
{
	int i,j,lyh;
	memset(mapl,0,sizeof(mapl));
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	   for(j=1;j<=m;j++)
	{
		scanf("%d",&lyh);
		for(int t=1;t<=4;t++)
		{
			a[i][j][t]=lyh%2;
			lyh/=2;
		}
	}
    
	for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
	  {
		if(mapl[i][j]==0)
		bfs(i,j);
	  }
	printf("%d\n%d",tot,ans);
    return 0;
}
