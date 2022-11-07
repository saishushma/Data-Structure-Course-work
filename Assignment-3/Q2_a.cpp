#include<iostream>
#include<limits.h>
#include<vector>
#include<string>
using namespace std;
int n;
int a[10000][10000];
int mindist(int dis[],int vis[])
{
int mini=1000;int x;
for(int i=0;i<n;i++)
{
if(dis[i]<mini&&vis[i]==0){x=i;mini=dis[i];}
}
return x;
}
void disj(int dest)
{
vector<string> paths;
int vis[n]={0};
int dis[n];
for(int i=0;i<n;i++)
{
dis[i]=INT_MAX;
string s="";
s=s+to_string(i);
paths.push_back(s);
}
dis[dest]=0;
for(int i=0;i<n-1;i++)
{
int n2=mindist(dis,vis);
//cout<<n2;
vis[n2]=1;
for(int j=0;j<n;j++)
{
if(vis[j]==0&&a[j][n2]!=0)
{
if(dis[j]==dis[n2]+a[j][n2]){
//cout<<"HAI"<<n2;
string s="";
s=s+to_string(j);
string s2=s+paths[n2];
string s1=paths[j];
//cout<<"equal"<<s1<<" "<<s2<<endl;
if(s1>=s2)
paths[j]=s2;
else paths[j]=s1;
dis[j]=dis[n2]+a[j][n2];
}
else if(dis[j]>dis[n2]+a[j][n2])
{
string s=paths[j]+paths[n2];
//s=s+to_string(n2);
paths[j]=s;
dis[j]=dis[n2]+a[j][n2];
}

}
}
}
for(int i=0;i<n;i++){
    if(i!=dest){
    string s=paths[i];
    for(int i=0;i<s.length();i++)
    {cout<<s[i]<<" ";
    }cout<<endl;}
}
}
//////////////////////////
int main()
{
int edges;
cin>>n;
cin>>edges;

for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
a[i][j]=0;
for(int i=0;i<edges;i++)
{
int n1,n2,w;
cin>>n1>>n2>>w;
a[n1][n2]=w;
a[n2][n1]=w;
}
int dest;
cin>>dest;
disj(dest);
return 0;
}
