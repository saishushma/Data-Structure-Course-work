#include<iostream>
using namespace std;
string rev(string s1)
{ string s=s1;;
   int j=0;
    for(int i=s1.length()-1;i>=0;i--)
    {
     s[j]=s1[i];
     j++;
    }

    return s;
}
string add(string s1, string s2)
{
 s1=rev(s1);
 s2=rev(s2);
 //cout<<s1;
 int l1=s1.length();
 int l2=s2.length();
 string res;
 int l=(l1<l2)?l1:l2;
 int lar=(l1>l2)?l1:l2;
 int c=0,sum=0;
 for(int i=0;i<l;i++)
 {
  sum=(s1[i]-'0')+(s2[i]-'0')+c;
  //cout<<sum<<" ";
  c=sum/10;
  sum=sum%10;
  char s=sum+'0';
  res.push_back(s);
 }
 string r1;
 if(l1==l2&&c!=0)
    res.push_back('1');
  else{
       if(l1>l2)r1=s1;
       if(l1<l2)r1=s2;
       for(int i=l;i<r1.length();i++)
       {
          sum=(r1[i]-'0')+c;
          c=sum/10;
          sum=sum%10;
          char s=sum+'0';
          res.push_back(s);
         }
         if(c!=0)
         {res.push_back('1'); }

    }
 res=rev(res);
 //cout<<res;
 return res;
}
//=================================
int small(string s1,string s2)
{int l1,l2,i;
l1=s1.length();
l2=s2.length();
if(l1>l2)return 0;
if(l1<l2)return 1;
for(i=0;i<l1;i++)
{
    if(s1[i]<s2[i])return 1;
    else if(s1[i]>s2[i])return 0;
}
return 0;
}
string trail(string s)
{
    int i=0;
    while(i<s.length()-1&&s[i]=='0')
    {
        i++;
    }
    s=s.substr(i);
    return s;
}
string diff(string s1,string s2)
{
    int l1,l2;
     string sm,lr,res;
    if(small(s1,s2)){sm=s1;lr=s2;}
    else{sm=s2;lr=s1;}
    sm=rev(sm);
    lr=rev(lr);
    l1=sm.length();
    l2=lr.length();
    int sub=0,c=0;
    for(int i=0;i<l1;i++)
    {
        sub=((lr[i]-'0')-(sm[i]-'0')-c);
        if(sub<0)
        {
            c=1;
            sub=sub+10;
        }
        else c=0;
        res.push_back(sub+'0');
    }
    for(int i=l1;i<l2;i++)
    {
        sub=((lr[i]-'0')-c);
        if(sub<0)
        {
            c=1;
            sub=sub+10;
        }
        else c=0;
        res.push_back(sub+'0');
    }
    res=rev(res);
    res=trail(res);
    //cout<<res<<" ";
return res;
}
//============================================
string multi(string s1,string s2)
{
 int l1,l2;
 l1=s1.length();
 l2=s2.length();
 if((l1==0)||(l2==0))
    return "0";
 s1=rev(s1);
 s2=rev(s2);
 int l = l1+l2;
int res[l]={0};
for(int i=0; i<l1;i++)
{
    for(int j=0; j<l2;j++)
    {
        int p = (s1[i]) - '0';
        int q = (s2[j]) - '0';
        res[i+j]+=p*q;
        res[i+j+1]=res[i+j+1]+res[i+j]/10;
        res[i+j]%=10;
    }
}
string s="";

for(int i=0;i<l; ++i)
    s += (res[i]+'0');
s=rev(s);
s=trail(s);
//cout<<s<<" ";
return s;
}
void bmul(int *a,int &n,int num)
{   int car=0,val;
    for(int i=0;i<n;i++)
    {
      val=a[i]*num+car;
      a[i]=val%10;
      car=val/10;
    }
    while(car!=0)
    {
        a[n]=car%10;
        car=car/10;
        n++;
    }
}
//======================================
string bexpo(string base,unsigned long long int expo){
 if(expo==0 && base=="0")
        return "0";
    if(expo == 0)
        return "1";
    if(base == "1" || base == "0"|| expo == 1)
        return base;
    string res="1";
    while(expo)
    {
        if(expo & 1)
            res= multi(res, base);

        base = multi(base, base);
        expo = expo>>1;
    }
    return res;}
//===================================
string div2(string s)
{
    int r=0;
    for(int i=0;i<s.length();i++)
    {
        int x=r*10+(s[i]-'0');
        s[i]=(x/2+'0');
        r=x%2;
    }

    s=trail(s);
    //cout<<s<<" ";
    return s;
}
string bgcd(string a,string b){
    //cout<<"ha";
    //cout<<"a-"<<a<<" ";
    //cout<<"b-"<<b<<" ";
    if(a==b)
        return a;
    if(a.length()==1&&a[0]=='0')return b;
    if(b.length()==1&&b[0]=='0')return a;
    int x=(a[a.length()-1]-'0');
    //cout<<x<<" ";
    if(x%2==0)
    {
        int y=(b[b.length()-1]-'0');
        //cout<<y<<" ";

        if(y%2!=0)

            return bgcd(div2(a),b);
        else
            return multi(bgcd(div2(a),div2(b)),"2");

    }
    else{
    int y=(b[b.length()-1]-'0');

    if(y%2==0)
        return bgcd(a,div2(b));
    else{
            //string t=div2(diff(a,b));

       return bgcd(b,div2(diff(a,b)));
       }

}}
//=================================
void bfact(string y)
{   int x=(y[0]-'0');

    for(int i=1;i<y.length();i++)
{
    x=x*10+(y[i]-'0');
}

    int res[3000]={0};
    res[0]=1;
    int sizeres=1,i;
    for(i=2;i<=x;i++)
    {
        bmul(res,sizeres,i);
    }
    for(i=sizeres-1;i>=0;i--)
        cout<<res[i];

}
//=============================
template <class T>
struct node{
T data;
node *next;
node *prev;
node(T val)
{
 data=val;
 next=NULL;
 prev=NULL;
}
};
template <class T>
class sta
{public:
node<T> *h= NULL,*t= NULL,*tem=NULL;
T c;
bool empty1(){if(!h)return true;
            return false;}

T top()
{
return t->data;}
void pop()
{if(t)
{
tem=t;
t=t->prev;
tem->prev=NULL;
if(t)
 {t->next = NULL;}
else h=NULL;}
}
void push(node<T>* n)
{if(!h)
h=t=n;
else{
t->next = n;
n->prev= t;
t= n;}
}
};
//===========
int priority(char o){
    if(o == '+'||o== '-')
        return 2;
    if(o== 'x')
        return 3;
    return 0;
}
string bexpeval(string a)
{
    sta<string> *oprand=new sta<string>();
    sta<char> *oprator=new sta<char>();
    node<string> *ni;
    node<char> *nc;
    string op1,op2,res;
for(int i=0; i<a.length(); i++)
{
if(isdigit(a[i]))
{  res ="";
while(i<a.length() && isdigit(a[i]))
{
res=res+(a[i]);
i++;
}
ni=new node<string>(res);
oprand->push(ni);
i--;}
else
{
while(!oprator->empty1()&&(priority(oprator->top())<= priority(a[i])))
{
op1=oprand->top();
oprand->pop();
op2 =oprand->top();
oprand->pop();
if(oprator->top()=='*')
{
ni=new node<string>(multi(op2,op1));
}
else if(oprator->top()== '+')
{
ni = new node<string>(add(op2,op1));}
else
{ni=new node<string>(diff(op2,op1));}
oprand->push(ni);
//cout<<oprator->top();
oprator->pop();
}
nc=new node<char>(a[i]);
// cout<<a[i];
oprator->push(nc);
}
}

    while(!oprator->empty1())
    {
    op1=oprand->top();
    oprand->pop();
    op2=oprand->top();
   oprand->pop();
   if(oprator->top()=='*')
    { ni=new node<string>(multi(op2,op1));}
    else if(oprator->top()== '+'){
    ni = new node<string>(add(op2,op1));}
    else
    {ni=new node<string>(diff(op2,op1));}
    oprand->push(ni);
    oprator->pop();
    }
    return oprand->top();
}

int main()
{
int x;
cin>>x;
switch(x)
{
    case 1:{string base;unsigned long long int expo;cin>>base;cin>>expo;string s=bexpo(base,expo);cout<<s;break;}
    case 2:{string a,b;cin>>a;cin>>b;string s=bgcd(a,b);cout<<s;break;}
    case 3:{string f;cin>>f; bfact(f);break;}
    case 4:{string exp;cin>>exp;string s=bexpeval(exp);cout<<s;break;}

}
return 0;
}
