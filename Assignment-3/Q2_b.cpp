#include<iostream>
#include<limits.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n;
int a[10000][10000];
vector<pair<int,string>> paths;

void dfs(int vis[],int weight,int &ind,int p[],int s,int d)
{
vis[s]=1;
p[ind]=s;
ind++;
if(s==d)
{
string str="";
for(int i=0;i<ind;i++)
str=str+to_string(p[i]);
paths.push_back(make_pair(weight,str));
}
else {
 for(int i=0;i<n;i++)
 {//cout<<"hello"<<s;
     if(a[s][i]!=0&&vis[i]==0)
        dfs(vis,weight+a[i][s],ind,p,i,d);
 }

}
 ind--;
 vis[s]=0;
}
////////////////
bool comp(pair<int,string> &a1,pair<int,string> &a2)
{
/*if(a1.first==a2.first)
{
return ((a1.second).compare(a2.second))<0;
}
return a1.first<a2.first;*/
if(a1.first<a2.first or a1.first>a2.first )
{
  return a1.first<a2.first;
  }
  else{
    if(((a1.second).compare(a2.second))<0){
      return true;
    }
    else{
      return false;
    }
  }
return a1.first<a2.first;
}
////
void kpaths(int k)
{
int vis[n]={0};
int weight;
for(int i=0;i<n;i++)
{
for(int j=0;j<i;j++){
weight=0;
vis[0]=0;
//string s="";
int ind=0;
int *p=new int[n];
dfs(vis,weight,ind,p,j,i);
vis[0]=0;
}}
/*cout<<paths.size()<<endl;
for (int i = 0; i < paths.size(); i++) {
         cout<<paths[i].first<<" "<<paths[i].second<<endl;
}*/
sort(paths.begin(),paths.end(),comp);
int x=paths.size();
int k1;
if(x>k)k1=k;
else k1=x;
for (int i = 0; i < k1; i++) {
         //cout<<paths[i].first<<" "<<paths[i].second<<endl;
       string str=paths[i].second;
    for(int i=0;i<str.length();i++)
    {cout<<str[i]<<" ";
    }cout<<endl;
}
}
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
cin>>n1;
cin>>n2;
cin>>w;
a[n1][n2]=w;
a[n2][n1]=w;
}
int k;
cin>>k;
kpaths(k);
return 0;
}
