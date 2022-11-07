#include<iostream>
#include<unordered_map>
using namespace std;
class lruc {
public:
class node {
public:
int key;
int val;
node* n;
node* p;
node(int k, int v)
{
val = v;
key =k;
}
};
int cap;
node* h= new node(-2,-2);
node* t= new node(-3,-3);
unordered_map<int, node*>m;
lruc(int capacity)
{
cap=capacity;
h->n=t;
t->p=h;
}
void addnode1(node* newnode1)
{
node* temp=h->n;
newnode1->n=temp;
newnode1->p=h;
h->n=newnode1;
temp->p=newnode1;
}
void deletenode1(node* t)
{
node* delprev=t->p;
node* delnext=t->n;
delprev->n=delnext;
delnext->p=delprev;
}
int get1(int k) {
if(m.find(k)!= m.end()) {
node* res=m[k];
int r=res->val;
m.erase(k);
deletenode1(res);
addnode1(res);
m[k]=h->n;
return r;
}
return -1;
}

void put1(int k, int v) {
if(m.find(k)!=m.end()) {
node* enode=m[k];
m.erase(k);
deletenode1(enode);
}
if(m.size()==cap) {
m.erase(t->p->key);
deletenode1(t->p);
}
addnode1(new node(k, v));
m[k]=h->n;
}
};
int main()
{
  lruc c(2);
  c.put1(1,10);
  c.put1(2,20);
  c.put1(3,30);
  c.put1(4,40);
  cout<<c.get1(4)<<endl;
  cout<<c.get1(5);
  return 0;

}
