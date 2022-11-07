#include<iostream>
using namespace std;
class stu
{
public:
int no;
string name;
string branch;
stu(){}
stu(int n,string nm,string b)
{
no=n;
name=nm;
branch=b;
}
inline bool operator !=(const stu& x) const {return (this->no!=x.no);}
inline bool operator ==(const stu& x) const {return (this->no==x.no);}
inline bool operator <(const stu& x) const {return (this->no<x.no);}
inline bool operator >(const stu& x) const {return (this->no>x.no);}
inline bool operator >=(const stu& x) const {return (this->no>=x.no);}
inline bool operator <=(const stu& x) const {return (this->no<=x.no);}
//inline bool operator >=(const stu& x) const {return (this->no<=x.no);}
inline bool operator +(const stu& x) const {return (this->no+x.no);}
inline bool operator -(const stu& x) const {return (this->no-x.no);}
friend ostream & operator <<(ostream& os, const stu &x)
{
os << x.no << ":" << x.name << ":" << x.branch;
return os;
}
};
template <class t>
struct node
{
public:
t data;
int c;
node<t> *l;
node<t> *r;
node<t> *p;
int height;
node(){l=NULL;r=NULL;p=NULL;}
};
template <class t>
class avl1
{public:
//template <class t>
node<t> *root=NULL;
//template <class t>
node<t>* create(t key)
{  // cout<<"created node"<<endl;
//node<int> *n=new node<int>();
node<t> *n=new node<t>();
n->l=NULL;
n->r=NULL;
n->p=NULL;
n->data=key;
n->c=1;
n->height=1;
return n;
}
///////////////////////print///////////////////
//template <class t>
void preorder(node<t> *n)
{  //cout<<"hai";
if(n!=NULL)
{   for(int i=0;i<n->c;i++){
    cout<<n->data<</*" h:"<<n->height<<*/" ";
}
    preorder(n->l);
    preorder(n->r);
}

}
//template <class t>
int h(node<t>* n)
{
if(n==NULL)return 0;
else
{
    return n->height;
}
}

int maximum(int a,int b)
{
if(a>b)return a;
else return b;
}
//////////////////left rotate/////////
//template <class t>
void lrotate(node<t> *x)
{
node<t>* y=x->l;
node<t>* z=x->r;
x->r=z->l;
z->p=x->p;
if(z->l!=NULL)z->l->p=x;
if(x->p==NULL)
    root=z;
else if(x->p!=NULL)
{
    //z->p=x->p;
    if(x==x->p->l)x->p->l=z;
    else if(x==x->p->r)x->p->r=z;
}
z->l=x;
x->p=z;
x->height=1+maximum(h(x->l),h(x->r));
z->height=1+maximum(h(z->l),h(z->r));
}
/////////////////////right rotate////////////////////
//template <class t>
void rrotate(node<t> *x)
{
node<t> *y=x->l;
node<t> *z=x->r;
x->l=y->r;
y->p=x->p;
if(y->r!=NULL)y->r->p=x;
if(x->p==NULL)root=y;
else if(x->p!=NULL)
{
    if(x==x->p->l)x->p->l=y;
    else if(x==x->p->r)x->p->r=y;
}
y->r=x;
x->p=y;
x->height=1+maximum(h(x->l),h(x->r));
y->height=1+maximum(h(y->l),h(y->r));

}
///////////////////////////insertion///////////////////////////
//template <class t>
node<t> *insertion(t key)
{
if(root==NULL)
{
  root=create(key);
  return root;
}
else
{
node<t>* temp=root;
node<t> *par;
//cout<<"not root";
while(temp!=NULL)
{   par=temp;
   if(temp->data==key)
    break;
   else if(temp->data>key)
   {   par=temp;
       temp=temp->l;
   }
   else if(temp->data<key)
   {   par=temp;
       temp=temp->r;
   }
}
//cout<<"break";
if(par->data==key)
{
   temp->c=(temp->c)+1;
}
else
{
   //cout<<"hai";
   node<t> *n=create(key);
   n->p=par;
   if(key>par->data)
   {
       par->r=n;
   }
   else if(key<par->data)
   {
       par->l=n;
   }

   //////update height////
   node<t> *x=n;
   while(x!=NULL)
   {
       x->height=1+maximum(h(x->l),h(x->r));
       x=x->p;
   }
  // preorder(root);
   //cout<<endl;
   ///node inserted balancing
   node<t> *pn=n->p;
   node<t> *ppn=pn->p;
   while(ppn!=NULL)
   {
       //pn->height=1+maximum(h(par->l),h(par->r));
       //ppn=pn->p;
       int dif=h(ppn->l)-h(ppn->r);
       if(dif>=2||dif<=-2)
       {  //cout<<"rotations"<<ppn->data<<endl;
           if(pn==ppn->l)    //left
           {
             if(n==pn->l)     //left
             {
                 rrotate(ppn);
                 //cout<<"ll"<<endl;
             }
             else if(n==pn->r)  //right
             {
                 lrotate(pn);
                 rrotate(ppn);
                 //cout<<"lr"<<endl;
             }
           }
           else if(pn==ppn->r)
           {
               if(n==pn->r)
               {
                   lrotate(ppn);
                   //cout<<"rr"<<endl;
               }
               else if(n==pn->l)
               {
                   rrotate(pn);
                   lrotate(ppn);
                   //cout<<"rl"<<endl;
               }
           }
           break;
       }
       pn=pn->p;
       n=n->p;
       ppn=pn->p;

   }


}

}

}
///////////////////////deletion/////////////////////

///////////////////////////////////////search///////////
//template <class t>
void searching(t key)
{  //cout<<"searcj";
node<t> *temp=root;
while(temp!=NULL)
{
    if(temp->data==key)
        break;
    else if(temp->data>key)
        temp=temp->l;
    else if(temp->data<key)
        temp=temp->r;
}
//cout<<"end";
if(temp==NULL)
    cout<<"key not found"<<endl;
else if(temp->data==key)
    cout<<"key found"<<endl;
}

///////////////////////count occurance//////////
//template <class t>
void countoccurance(t key)
{  //cout<<"searcj";
node<t> *temp=root;
while(temp!=NULL)
{
    if(temp->data==key)
        break;
    else if(temp->data>key)
        temp=temp->l;
    else if(temp->data<key)
        temp=temp->r;
}
//cout<<"end";
if(temp==NULL)
    cout<<"key not found"<<endl;
else if(temp->data==key)
    cout<<"no of occurances:"<<temp->c<<endl;
}
////////////////////////////lower bound /////////////
//template <class t>
node<t>* getmin(node<t> *temp)
{
while(temp->l!=NULL)
    temp=temp->l;
return temp;
}
//template <class t>
node<t>* getmax(node<t> *temp)
{
while(temp->r!=NULL)
    temp=temp->r;
return temp;
}
//template <class t>
void lowerbound(t key)
{   node<t> *temp=root;
t mini=getmin(temp)->data;
t maxi=getmax(temp)->data;
t res;
if(key>=mini&&key<=maxi)
{
while(temp!=NULL)
{
if(temp->data==key){res=temp->data;break;}
else if(temp->data>key){res=temp->data;temp=temp->l;}
else temp=temp->r;
}
cout<<"Lower bound for the value "<<key<<": "<<res<<endl;
}
else
cout<<"lower bound does not exist";

}
////////////////////upper bound///////////
//template <class t>
void upperbound(t key)
{   node<t> *temp=root;
t mini=getmin(temp)->data;
t maxi=getmax(temp)->data;
t res=maxi;
if(key>=mini&&key<=maxi)
{
while(temp!=NULL)
{
if(temp->data>key){res=temp->data;temp=temp->l;}
else temp=temp->r;
}
cout<<"Upper bound for the value "<<key<<": "<<res<<endl;
}
else
cout<<"upper bound does not exist";

}
//////////////////closest value////////////////
//template <class t>
void closestvalue(t key)
{
node<t> *temp=root;
t mini=getmin(temp)->data;
t maxi=getmax(temp)->data;
t res,tempmax=maxi,tempmin=mini;
if(key<mini)res=mini;
else if(key>maxi)res=maxi;
else{
while(temp!=NULL)
{
if(key<temp->data){tempmax=temp->data;temp=temp->l;}
else if(key>temp->data){tempmin=temp->data;temp=temp->r;}
else{res=temp->data;break;}
}
if((key-tempmin)>(tempmax-key))res=tempmax;
else if((key-tempmin)<(tempmax-key))res=tempmin;
}
cout<<"closest value for the "<<key<<" : "<<res<<endl;
}
/////////////////////////////////k th largest element/////////
//template <class t>
void klargest(node<t>* temp,int k,int &count1,int &f)
{
if(temp==NULL||count1>=k||f==1)return;
klargest(temp->r,k,count1,f);
count1=count1+temp->c;
if(count1>=k&&f==0)
{
cout<<k<<" th largest element"<<temp->data<<endl;
f=1;
return;
}
klargest(temp->l,k,count1,f);
}
void klargest1(int k)
{
int count1=0;
int f=0;
klargest(root,k,count1,f);
}
//////////////////////////////////count range//////////////////////
//template <class t>
int countrange(t k1,t k2)
{
int count1=0;
count1=countrange1(root,k1,k2,count1);
cout<<"no of elements in the range "<<k1<<" and "<<k2<<" is :"<<count1<<endl;
return count1;
}
//template <class t>
int countrange1(node<t>* temp,t &k1,t &k2,int &count1)
{
if(temp==NULL)return 0;
if(temp->data==k1&&temp->data==k2){return temp->c;}
if(temp->data>=k1&&temp->data<=k2)
count1=temp->c+countrange1(temp->l,k1,k2,count1)+countrange1(temp->r,k1,k2,count1);
else if(temp->data<k1)count1=countrange1(temp->r,k1,k2,count1);
else count1=countrange1(temp->l,k1,k2,count1);
return count1;
}
//////////////////////////////////deletion
//template <class t>
void deletion(t key)
{
node<t> *temp=root;
while(temp!=NULL)
{
    if(temp->data>key)
        temp=temp->l;
    else if(temp->data<key)
        temp=temp->r;
    else
        break;
}
node<t> *par=NULL;
if(temp!=NULL&&temp->data==key)
{
if(temp->c>1)
temp->c=(temp->c)-1;
else if(temp->l==NULL)
{//cout<<"gm";
exc(temp,temp->r);
//cout<<"hai";
if(temp->r!=NULL)delbal(temp->r);
}
else if(temp->r==NULL)
{
exc(temp,temp->l);
if(temp->l!=NULL)delbal(temp->l);
}
else{
node<t> *m=getmin(temp->r);
node<t> *x1=m->p;
//cout<<"min"<<m->data<<endl;
if(m->p!=temp)
{
exc(m,m->r);
//cout<<m->data<<endl;
m->r=temp->r;
m->r->p=m;
}
exc(temp,m);
//cout<<root->data<<endl;
m->l=temp->l;
m->l->p=m;
//preorder(root);
node<t> *x=x1;
while(x!=NULL)
{

//cout<<x->data;
x->height=1+maximum(h(x->l),h(x->r));
//cout<<x->data<<":height:"<<x->height<<endl;
x=x->p;
}
if(m!=NULL)delbal(m);}}
else cout<<"not found"<<endl;
}
//template <class t>
void exc(node<t>* x,node<t>* y)
{
if(x->p==NULL)root=y;//root
else if(x->p->l==x){x->p->l=y;}//left
else if(x->p->r==x)x->p->r=y;//right
if(y!=NULL)y->p=x->p;
}
//template <class t>
void delbal(node<t> *n)
{
node<t> *temp=n;
node<t> *x=n;
while(x!=NULL)
{

//cout<<x->data;
x->height=1+maximum(h(x->l),h(x->r));
//cout<<x->data<<":height:"<<x->height<<endl;
x=x->p;
}
while(temp!=NULL)
{
//temp->height=1+maximum(h(temp->l),h(temp->r));
//cout<<temp->data;
//cout<<"height"<<temp->height<<endl;
int dif=h(temp->l)-h(temp->r);
if(dif<=-2||dif>=2)
{
//cout<<"disorder"<<temp->data<<"height"<<temp->height<<endl;
node<t> *x;
node<t> *y;
node<t> *z;
x=temp;
/*if(x->l->height>x->r->height)y=x->l;
else y=x->r;
if(y->l->height>y->r->height){z=y->l;}
else if(y->l->height<y->r->height)z=y->r;
else {
if(y==x->l)z=y->r;
else z=y->r;
}
//bal
if(x->l==y)
{
if(x->l->l==z)rrotate(x);
else if(x->l->r){lrotate(y);rrotate(x);}
}
else if(x->r==y)
{
if(x->r->r==z)lrotate(x);
else if(x->r->l==z){rrotate(y);lrotate(x);}
}
}*/
if(dif>1)
{
y=temp->l;
int dif2=h(y->l)-h(y->r);
if(dif2>=0)
rrotate(x);
else if(dif2<0){lrotate(y);rrotate(x);}
}
else if(dif<-1)
{
y=temp->r;
int dif2=h(y->l)-h(y->r);
if(dif2<=0)
lrotate(x);
else if(dif2>0){rrotate(y);lrotate(x);}
}
}
temp=temp->p;
}
}
};
int main()
{
/*insertion(10);
insertion(20);
insertion(30);
insertion(40);
insertion(50);
//preorder(root);
insertion(25);
insertion(35);
insertion(10);
insertion(10);
insertion(33);
insertion(31);
insertion(30);
preorder(root);
searching(10);
searching(80);
deletion(35);
cout<<endl;
preorder(root);
cout<<endl;
deletion(40);
/*deletion(25);
deletion(20);
deletion(30);
deletion(30);
cout<<endl;
preorder(root);
countoccurance(10);
countoccurance(30);
lowerbound(32);
upperbound(10);
closestvalue(14);
closestvalue(16);
closestvalue(60);
closestvalue(1);
klargest1(3);
countrange(10,40);*/
//cout<"_____________________________________________";
avl1<char> a;
a.insertion('a');
a.insertion('g');
a.insertion('h');
a.insertion('s');
a.insertion('m');
a.insertion('k');
a.insertion('n');
a.insertion('i');
a.insertion('l');
a.insertion('a');
a.insertion('a');
a.preorder(a.root);
cout<<endl;
a.deletion('m');
a.deletion('n');
a.preorder(a.root);
cout<<endl;
a.countoccurance('a');
a.countoccurance('m');
a.lowerbound('a');
a.upperbound('k');
a.closestvalue('m');
a.closestvalue('a');
a.closestvalue('z');
a.closestvalue('g');
a.klargest1(3);
a.countrange('a','h');

/////////////////////////////////////////////////
cout<<" &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
avl1<stu> a1;
stu s1(1,"shushma","cse");
stu s2(2,"josh","cse");
stu s3(3,"shushma","cse");
stu s4(6,"shushma","cse");
stu s5(4,"shushma","cse");
stu s6(8,"shushma","cse");
stu s7(7,"shushma","cse");
a1.insertion(s1);
a1.insertion(s2);
a1.insertion(s3);
a1.insertion(s4);
a1.insertion(s5);
a1.insertion(s6);
a1.insertion(s7);
a1.insertion(s7);
a1.preorder(a1.root);
cout<<endl;
a1.deletion(s4);
a1.deletion(s5);
a1.preorder(a1.root);
cout<<endl;
a1.countoccurance(s1);
a1.countoccurance(s7);
a1.lowerbound(s5);
a1.upperbound(s5);
//a1.closestvalue('m');
//a1.closestvalue('a');
//a1.closestvalue('z');
a1.closestvalue(s3);
a1.klargest1(3);
a1.countrange(s1,s7);

return 0;

}
