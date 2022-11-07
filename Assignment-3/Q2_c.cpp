#include<iostream>
#include<limits.h>
using namespace std;
char a[1000][1000];
int row,col;
int bfs(int x,int row1,int col1)
{
long long int ls,rs,us,ds;
ls=rs=us=ds=999;
if(row1==row||col1==col)return 0;
if(row1==1&&col1==0)return 0;
if(a[row1][col1]=='#')return 999;
char ch=a[row1][col1];
a[row1][col1]='#';
if(row1>0&&row1+1<row&&x!=3){us=1+bfs(4,row1-1,col1);}
if(row1>0&&row1+1<row&&x!=4){ds=1+bfs(3,row1+1,col1);}
if(col1>0&&col1+1<col&&x!=1){ls=1+bfs(2,row1,col1-1);}
if(col1>0&&col1+1<col&&x!=2){rs=1+bfs(1,row1,col1+1);}
a[row1][col1]=ch;
long long int mini;
if(ls<=rs&&ls<=us&&ls<=ds)mini=ls;
if(rs<=ls&&rs<=us&&rs<=ds)mini=rs;
if(us<=ls&&us<=rs&&us<=ds)mini=us;
if(ds<=ls&&ds<=us&&ds<=rs)mini=ds;
//cout<<ls<<" "<<rs<<" "<<us<<" "<<ds<<" "<<mini<<endl;
return mini;
}
int main()
{
long long int dist,d,minimum=999;
cin>>row>>col;
for(int i=0;i<row;i++)
for(int j=0;j<col;j++)
cin>>a[i][j];
//////
for(int i=0;i<row;i++)
{
for(int j=0;j<col;j++)
{
if(a[i][j]=='A')
{dist=bfs(0,i,j);}
else if(a[i][j]=='R')
{
d=bfs(0,i,j);
if(d<minimum)minimum=d;
}
}
}
if(dist>minimum)cout<<"no";
else {cout<<"yes"<<endl;cout<<dist;}
return 0;
}
