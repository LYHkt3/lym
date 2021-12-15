#include <stdio.h>
#include<string.h>
//3072x1728,2720x1536,2560x1600,2560x1440,2304x1728,2048x1536,1920x1200,1920x1080,1440x900,1280x800,1280x720,1024x768,1024x640,800x600,800x500,800x450,640x480,640x400,640x360,480x360,480x300,480x270,320x240,320x200,320x180,240x180,176x144,160x120,160x100,160x90,
int main()
{
    char ress[2048];
    int x, y,lyh=0,lym=0;
    scanf("%s", ress);
    for(int i=0;i<=strlen(ress);i++)
    if(ress[i]==',')  lyh++;
    lyh++;
    scanf("%d %d", &x, &y);
    int i=1,j=1,a[101],b[101];
    for(int s=0;s<=100;s++)
        a[s]=0,b[s]=0;
    while(1){
        if(lym==lyh) break;
        char l[7],r[7];
        int e=0,f=0;
        sscanf(ress,"%[0-9]",l);
        sscanf(ress,"%*[^x]x%[0-9]",r);
        while(l[e]!='\0') {
            a[i]*=10;
            a[i]+=l[e]-'0';
            e++;
        }
        i++;
        while(r[f]!='\0') {
            b[j]*=10;
            b[j]+=(r[f]-'0');
            f++;
        }
        j++;
        int k;
        for(k=0;k<strlen(ress);k++)
        if(ress[k]==',') break;
        for(int t=k+1;t<strlen(ress);t++)
        ress[0+t-k-1]=ress[t];
        lym++;
    }
    int min=(x-a[1])*(y-b[1]),tre=1;
    if(min<=0) min=-min;
    for(int k=1;k<i-1;k++){
        if((a[k]-x)*(b[k]-y)<=min&&(x-a[k])*(b[k]-y)<=min) {
            tre=k;
            min=((a[k]-x)*(b[k]-y)>0?(a[k]-x)*(b[k]-y):(x-a[k])*(b[k]-y));
        }
    }
    printf("%dx%d\n", a[tre],b[tre]);
    return 0;
}