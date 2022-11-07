#include<iostream>
using namespace std;
struct node
{
int last=0;
node *l=NULL;//zero
node *r=NULL;//one
};
bool c(long long int n, int i)
{
	return (bool)(n&(1<<i));
}
node *root=new node();
void ins(long long int x)
{
node *temp=root;
int i,t;
for(i=63;i>=0;i--)
{
//t=0;
t=c(x,i);
if(t==1)
{
if(temp->r==NULL)
{
    node *n=new node();
    n->l=NULL;
    n->r=NULL;
    n->last=0;
    temp->r=n;
}
temp=temp->r;
}
else if(t==0)
{
if(temp->l==NULL)
{
    node *n=new node();
    n->l=NULL;
    n->r=NULL;
    n->last=0;
    temp->l=n;
}
temp=temp->l;
}
}
temp->last=1;
}


long long int maxor(long long int x)
{
node *temp=root;
long long int res=0;
int i,t;
for(i=63;i>=0;i--)
{
t=c(x,i);
if(t==0&&temp->r!=NULL)
{   //cout<<"right"<<i;
    res=res+(1<<i);
    temp=temp->r;
}
else if(t==1&&temp->l!=NULL)
{
     //cout<<"left"<<i;
 res=res+(1<<i);
    temp=temp->l;
}
else if(t==0)
{
    temp=temp->l;
}
else if(t==1)temp=temp->r;

}
return res;
}
int main()
{
int n;
cin>>n;
int q;
cin>>q;
long long int a[n+1];
for(int i=0;i<n;i++)
    cin>>a[i];

for(int i=0;i<n;i++)
{
ins(a[i]);
}
for(int i=0;i<q;i++)
{
long long int val;
cin>>val;
long long res=maxor(val);
res=res/2;
cout<<res<<endl;
}
return 0;
}
