#include<iostream>
#include<string>
using namespace std;
template <typename k,typename v>
class node
{
public:
k key;
v value;
node* link;
node(k key1,v value1)
{
key=key1;
value=value1;
link=NULL;
}
//~node(){delete link;}
};
template <typename k,typename v>
class umap
{
public:
int sizemap;
int nbcts;
node<k,v>** bcts;
/////initialisation////////////
umap()
{
sizemap=0;
nbcts=5;
bcts=new node<k,v>*[nbcts];
for(int i=0;i<nbcts;i++)
bcts[i]=NULL;
}
~umap()
{
for(int i=0;i<nbcts;i++)
delete bcts[i];
delete []bcts;
}
///////////////
int getsizemap()
{return sizemap;}

//////////////////
int getind(int key1){return getindcal(to_string(key1));}
int getind(float key1){return getindcal(to_string(key1));}
int getind(char key1){return getindcal(to_string(key1));}
int getind(double key1){return getindcal(to_string(key1));}
int getind(long int key1){return getindcal(to_string(key1));}
int getind(string key1){return getindcal(key1);}
int getindcal(string key1)
{
int hs=0,cf=1;
for(int j=key1.length()-1;j>=0;j--)
{
hs=hs+(cf*key1[j]);
cf=cf*53;
cf=cf%nbcts;
hs=hs%nbcts;
}
hs=hs%nbcts;
return hs;
}
/////////////////////
bool find1(k key1)
{
int ind=getind(key1);
node<k,v> *h=bcts[ind];
while(h!=NULL)
{
if(h->key==key1)
//return h->value;
return true;
h=h->link;
}
return false;
}

///////////////////

v del(k key1)
{
bool b=find1(key1);
if(b==true){
int ind=getind(key1);
node<k,v> *h=bcts[ind];
node<k,v> *curr=bcts[ind];
node<k,v> *prev1=NULL;
while(curr!=NULL)
{

if(curr->key==key1)
{
//cout<<curr->key;
if(prev1==NULL)
bcts[ind]=curr->link;
else
{prev1->link=curr->link;

}
//cout<<curr->key;
v val=curr->value;
sizemap=sizemap-1;
return val;
}
prev1=curr;
curr=curr->link;
}}
static v val1;
return val1;
}
//////////////////////////////
void redo()
{
node<k,v>** t1=bcts;
bcts=new node<k,v>*[2*nbcts];
for(int i=0;i<2*nbcts;i++)
bcts[i]=NULL;
int ob=nbcts;
nbcts=2*nbcts;
sizemap=0;
for(int i=0;i<ob;i++)
{
node<k,v> *h=t1[i];
//cout<<i<<"::";
while(h!=NULL)
{
//cout<<h->key<<" :"<<h->value<<"   ";
ins(h->key,h->value);
h=h->link;
}
}
for(int i=0;i<ob;i++)
{
node<k,v> *h1=t1[i];
//delete h1;
}
//delete []t1;
}

//////////////////////////////
void ins(k key1,v valu)
{
int ind=getind(key1);
node<k,v> *h=bcts[ind];
while(h!=NULL)
{
if(h->key==key1)
{h->value=valu;
return;
}
h=h->link;
}
node<k,v> *h1=bcts[ind];
node<k,v> *n=new node<k,v>(key1,valu);
n->link=h1;
bcts[ind]=n;
sizemap=sizemap+1;
double lf=(1.0*sizemap)/nbcts;
if(lf>0.7)
{
redo();
}
}
void display()
{
for(int i=0;i<nbcts;i++)
{
node<k,v> *h=bcts[i];
cout<<i<<"::";
while(h!=NULL)
{
cout<<h->key<<" :"<<h->value<<"   ";
h=h->link;
}
cout<<endl;
}
}
//////////////
v &operator[](k key1)
{
int ind=getind(key1);
node<k,v> *h=bcts[ind];
while(h!=NULL)
{
if(h->key==key1)
return h->value;
//return true;
h=h->link;
}
static v v1;
return v1;
}
};
int main()
{
/*umap<int,string> m;
m.ins(100,"shushma");
//m.display();
m.ins(10,"josh");
m.ins(3,"mom");
cout<<"size:"<<m.getsizemap()<<endl;
m.ins(2,"shushma");
m.ins(10,"josh");
m.ins(3,"mom");
cout<<"size:"<<m.getsizemap()<<endl;
m.display();
m.ins(6,"shushma");
m.ins(7,"josh");
m.ins(8,"mom");
m.ins(15,"mom");
m.ins(16,"shushma");
m.ins(97,"josh");
m.ins(68,"mom");
m.display();
cout<<"size:"<<m.getsizemap()<<endl;
//m.display();
cout<<m.find1(10)<<endl;
cout<<m.del(10)<<endl;
m.display();
cout<<m[68];
umap<int,string> m;
m.ins(100,"shushma");
m.ins(100,"sh");
m.display();
*/
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
int a1[]={ 1, 2, 1, 3, 4, 2, 3 };
int n1=sizeof(a1)/sizeof(a1[0]);
int k=4;
umap<int,int> m1;
int c=0;
for(int i=0;i<k;i++)
{
if(m1.find1(a1[i])==0){m1.ins(a1[i],1);}
else {int z=m1[a1[i]];m1.ins(a1[i],++z);}
}
cout<<m1.getsizemap()<<endl;
//m1.display();
for(int i=k;i<n1;i++)
{
//cout<<"I"<<i;
int x=m1[a1[i-k]];
if(x<=1){m1.del(a1[i-k]);}
else {x=x-1;m1.ins(a1[i-k],x);}
x=m1[a1[i]];
if(m1.find1(a1[i])==1){x++;m1.ins(a1[i],x);}
else {m1.ins(a1[i],1);}
cout<<m1.getsizemap()<<endl;
//m1.display();
}
return 0;
}
///////////////////final copy////
