#include<iostream>
#include<string>
using namespace std;
struct node
{
//char data;
node *link[26];
int endstring;
};
class trie{
public:
node* createnode()
{
node *n=new node();
n->endstring=0;
for(int i=0;i<26;i++)
n->link[i]=NULL;
return n;
}
node *root=createnode();
int arr[100][100];
/////////////insert
void insert1(string s)
{
node *r=root;
//cout<<"hai";
for(int i=0;i<s.length();i++)
{//cout<<"hai";
    int x=s[i]-'a';
    //cout<<x;
    if(r->link[x]==NULL)
    {
        node *newn=createnode();

        r->link[x]=newn;
        r=r->link[x];
    }
    else{r=r->link[x];}

}
r->endstring=1;
}
///////////search/////spell check
int search1(string s)
{
    node *r=root;
    for(int i=0;i<s.length();i++)
    {
      int x=s[i]-'a';
      if(r->link[x]==NULL)return 0;
      r=r->link[x];
    }
    if(r->endstring==0)return 0;

  return 1;
}
//////////////auto complete////////////////
int search2(string s)
{
 node *r=root;
    for(int i=0;i<s.length();i++)
    {
      int x=s[i]-'a';
      if(r->link[x]==NULL)return 0;
      r=r->link[x];
    }
    //if(r->endstring==0)return 0;
char a[100];
display1(r,s,a,0);
  return 1;
}
//////display
void display1(node *n,string s,char a[],int ind)
{
if(n->endstring==1)
{
a[ind]='\0';
string s1=string(a);
string s2=s+s1;
cout<<s2<<" ";
}
for(int i=0;i<26;i++)
{
    if(n->link[i]!=NULL)
    {
        a[ind]=i+'a';
        display1(n->link[i],s,a,ind+1);
    }
}
}
//////////////////auto correct//////////
int getmin(int x,int y,int z)
{
if(x<=y&&x<=z)return x;
else if(y<=x&&y<=z)return y;
else if(z<=x&&z<=y)return z;
}
int dis(string s1,string s2,int m,int n,int start)
{

int i,j;
for(i=0;i<=m;i++)
{
for(j=start;j<=n;j++)
{
if(j==0)arr[i][j]=i;
else if(i==0)arr[i][j]=j;
else if(s1[i-1]==s2[j-1])arr[i][j]=arr[i-1][j-1];
else {
int x=getmin(arr[i-1][j-1],arr[i-1][j],arr[i][j-1]);
arr[i][j]=1+x;
}}}
return arr[m][n];
}
/////
void correct1(node *n,string &s,char a[],int ind,int x,string str)
{
if(n->endstring==1)
{
a[ind]='\0';
string s1=string(a);
//cout<<s1<<" "<<s<<endl;
int k=0,l=0,y=0;
while(k<s1.length()&&l<s.length())
{
    if(s1[k]==s[l])y++;
    else break;
    k++;
    l++;
}
//cout<<s1<<" "<<s<<" "<<y<<endl;

int d=dis(str,s1,str.length(),s1.length(),y);
if(d<=3)cout<<s1<<" "<<d<<endl;
s=s1;
}
for(int i=0;i<26;i++)
{
    if(n->link[i]!=NULL)
    {
        a[ind]=i+'a';
        x++;
        correct1(n->link[i],s,a,ind+1,x,str);
    }
}
}
};
int main()
{
trie* t=new trie();
/*t->insert1("sus");
//cout<<"the";
t->insert1("cat");
t->insert1("sush");
t->insert1("xyz");
t->insert1("sushm");
cout<<t->search1("hello");

cout<<endl;
//t->display1(t->root,"",a,0);
//t->search2("h");
cout<<endl;
string s="";
string str="abc";
t->correct1(t->root,s,a,0,0,str);*/
int n;
cin>>n;
for(int i=0;i<n;i++)
{
string s;
cin>>s;
t->insert1(s);
}
int x;string str,s="";char a[100];
cin>>x;
cin>>str;
if(x==1){cout<<t->search1(str);}
else if(x==2){t->search2(str);}
else if(x==3){t->correct1(t->root,s,a,0,0,str);}
return 0;
}
