#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
}};
//////////////////////////////////////////
int search2(string &curr, int i, int j,vector<string> &result, vector<vector<char>> &b, vector<vector<bool>> &vis, node *t)
{
int r=0;
if(t==NULL)
return 0;
if( i<0||j<0||i>=b.size()||j>=b[0].size()||vis[i][j])
return 0;
if(curr.back()!= b[i][j])
return 0;
if(t->endstring){
result.push_back(curr);
t->endstring=0;
}
for(int c=0; c<26; c++){
if(t->link[c] != NULL){
vis[i][j] = true;
curr.push_back((char)(c+'a'));
r=(search2(curr,i-1,j,result,b,vis,t->link[c])||search2(curr,i,j+1,result,b,vis,t->link[c])||search2(curr,i,j-1,result,b,vis,t->link[c])||search2(curr,i+1,j,result,b,vis,t->link[c]));
curr.pop_back();
vis[i][j] = false;
}
}
return r;
}
//////////////////////////////////////////
void fw(vector<string> l,vector<vector<char>> &b)
{
trie *t = new trie();
for(auto s: l)
t->insert1(s);
int f=0;
vector<vector<bool>> visited(b.size(), vector<bool>(b[0].size(), false));
vector<string> result;
string c="";
for(int i=0; i<b.size(); i++)
{
for(int j=0; j<b[0].size(); j++)
{
c = c+b[i][j];
int x=search2(c,i,j,result,b,visited,t->root->link[b[i][j]-'a']);
c="";
}
}
sort(result.begin(),result.end());
for(auto s:result)
cout<<s<<" ";
}
/////main////////////////
int main()
{
int row,col;
vector<vector<char>> board;
vector<string> l;
cin>>row;
cin>>col;
for(int i=0;i<row;i++)
{
vector<char> c;
c.clear();
for(int j=0;j<col;j++)
{
char ch;
cin>>ch;
c.push_back(ch);
}
board.push_back(c);
}
int n;
cin>>n;
for(int i=0;i<n;i++)
{
string s;
cin>>s;
l.push_back(s);
}
fw(l,board);
return 0;
}
