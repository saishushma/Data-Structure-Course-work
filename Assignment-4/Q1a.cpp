#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int small(char a[],int n,int mini,int i)
{
for(int j=0;j<n;j++)
{
if(a[mini]<a[i])return 0;
else if(a[mini]>a[i])return 1;
else
{
mini=(mini+1)%n;
i=(i+1)%n;
}
}
}
int main()
{
string s;
cin>>s;
char a[s.size()+1];
strcpy(a,s.c_str());
int n=s.size();
int mini=0;
for(int j=0;j<s.size();j++)
{
int x=small(a,n,mini,j);
if(x==1)
mini=j;
}
//print
for(int i=0;i<s.size();i++)
{

int in=(mini+i)%n;
cout<<s[in];
}
return 0;
}
