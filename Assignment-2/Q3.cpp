#include<iostream>
using namespace std;
template <class t>
class dq
{
public:
int b,f,size1,s;
t *a;
//////initilization///////////////
dq()
{
size1=5;
s=0;
b=-1;
f=-1;
a=new t[size1];
}
dq(int n,t x)
{
b=-1;
f=-1;
size1=n;
a=new t[n];
for(int i=0;i<n;i++)
a[i]=x;
}
///////////////////////
void resize1(int x,t d)
{
t *na;
na=new t[2*x];
int j=0;
int i=f;
while(i!=b)
{
na[j]=a[i];
i=(i+1)%size1;
j++;
}
na[j]=a[b];
f=0;
b=size1-1;
size1=2*x;
a=na;
}
/////////////////////////////////push////////////////
void pushf(t data)
{
if((f==0&&b==size1-1)||((b+1)%size1==f))    {
static t t1;
resize1(size1,t1);
pushf(data);s--;
}
else if(b==-1&&f==-1)
{
f=0;b=0;
a[f]=data;
}
else if(f==0)
{
f=size1-1;
a[f]=data;
}
else{f--;a[f]=data;}
s++;
}

void pushb(t data)
{
if((f==0&&b==size1-1)||((b+1)%size1==f))    {
static t t1;
resize1(size1,t1);
s--;
pushb(data);
}
else if(b==-1&&f==-1)
{
f=0;b=0;
a[b]=data;
}
else if(b==size1-1)
{
b=0;
a[b]=data;
}
else{b++;a[b]=data;}
s++;
}
////////////////////////pop/////
void popf()
{
if(f==-1&&b==-1)
cout<<"no elements";
else if(f==b)
{
f=-1;
b=-1;
}
else if(f==size1-1)
{
f=0;
}
else f++;
s--;
}
void popb()
{
if(f==-1&&b==-1)
cout<<"no elements";
else if(f==b)
{
f=-1;
b=-1;
}
else if(b==0)
b=size1-1;
else b--;
s--;
}
///////////////display///////////
void dis()
{int i=f;
while(i!=b&&i!=-1)
{
cout<<a[i]<<" ";
i=(i+1)%size1;
}
if(b!=-1)
cout<<a[b];
cout<<endl;
}
/////////////////////
t front1()
{
if(f!=-1)
return a[f];
return -1;
}
t back1()
{
if(b!=-1)
return a[b];
return -1;
}
bool empty1()
{
if(f==-1&&b==-1)
return true;
else return false;
}
void clear1()
{
f=-1;
b=-1;
}
int qsize()
{
//cout<<"f:"<<f;
//cout<<"b:"<<b;
return s;

}
t &operator[](int x)
{
if(x>=0&&x<s)
{
int y=(f+x)%size1;
return a[y];
}
static t t1;
return t1;
}
};
int main()
{
//dq<int> q=new dq<int>();
dq<char> q;
q.pushf('a');
q.pushf('b');
q.pushb('c');
q.dis();
q.pushf('d');
q.pushf('e');
q.dis();
q.pushb('f');
q.dis();
q.popb();
q.popf();
cout<<"size:"<<q.qsize()<<endl;

q.dis();

cout<<q[1];
return 0;
}
