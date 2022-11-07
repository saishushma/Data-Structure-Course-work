#include<iostream>
using namespace std;
template<class T>
class node{
public:
int row;
int col;
T val;
node *link;

void display(node<T> *head)
{
    while(head!=NULL)
    {
        cout<<head->row<<"   "<<head->col<<"   "<<head->val<<endl;
        head=head->link;
    }
}
node<T> *insert1(node<T> *head,int r,int c,T v)
{
   node<T> *n=new node<T>();
   n->row=r;
   n->col=c;
   n->val=v;
   n->link=NULL;
   if(head==NULL)head=n;
   else{
        node<T> *temp=head;
    while(temp->link!=NULL){temp=temp->link;}
    temp->link=n;
   }
   return head;
}
void addi(node<T> *a,node<T> *b)
{
 node<T> *ta=a,*tb=b;
 node<T> *res=NULL;
 while(ta&&tb)
 {
     if(ta->row==tb->row&&ta->col==tb->col)
     {   if((ta->val+tb->val)!=0)
         {res=res->insert1(res,ta->row,ta->col,(ta->val+tb->val));}
         ta=ta->link;
         tb=tb->link;
     }
     //b is greater
     else if(ta->row<tb->row||(ta->row==tb->row&&ta->col<tb->col))
     {
        res=res->insert1(res,ta->row,ta->col,ta->val);
        ta=ta->link;
     }
     else
     {
       res=res->insert1(res,tb->row,tb->col,tb->val);
       tb=tb->link;
     }

 }
 while(ta)
 {
   res=res->insert1(res,ta->row,ta->col,ta->val);
        ta=ta->link;
 }
 while(tb)
 {
    res=res->insert1(res,tb->row,tb->col,tb->val);
       tb=tb->link;
 }
 cout<<"ADDITION RESULT"<<endl;
 res->display(res);
}
////////////////////
node<T> *sorti(node<T> *head)
{ node<T> *temp=head;
 node<T> *t=head,*p=head;
   temp=head;
  int r,c;
  T v;
  //selection sort
  while(temp->link!=NULL)
  {
     r=temp->row;
     c=temp->col;
    v=temp->val;
    p=temp;
    t=temp->link;
    while(t!=NULL)
    {
      if(r>t->row)
      {
       r=t->row;
       c=t->col;
       v=t->val;
       p=t;
      }
      else if(r==t->row&&c>t->col)
      {
        r=t->row;
       c=t->col;
       v=t->val;
       p=t;
      }
      t=t->link;
    }
    //swap
    p->row=temp->row;p->col=temp->col;p->val=temp->val;
    temp->row=r;temp->col=c;temp->val=v;
    temp=temp->link;

  }
  //head->display(head);
  return head;
}
///////////////////////////
node<T> *transp(node<T> *head)
{
    node<T> *temp=head;
    node<T> *tr=NULL;
  while(temp!=NULL)
  {
    tr=tr->insert1(tr,temp->col,temp->row,temp->val);
    temp=temp->link;

  }
  tr=tr->sorti(tr);
  cout<<"RESULT OF TRANSPOSE"<<endl;
  tr->display(tr);
  return tr;

}
node<T> *mul(node<T> *a,node<T> *b1)
{  node<T> *res=NULL;
    node<T> *b=b1->transp(b1);
   int r,c;
    T sum;
    node<T> *ta=a,*tb=b;
    while(ta!=NULL)
    {
      r=ta->row;
      tb=b;
      while(tb!=NULL)
      {
          c=tb->row;
          node<T> *tap=ta,*tbp=tb;
          sum=0;
          while(tap&&tbp&&tap->row==r&&tbp->row==c)
          {
              if(tap->col<tbp->col)tap=tap->link;
              else if(tap->col>tbp->col)tbp=tbp->link;
              else {sum=sum+tap->val*tbp->val;tap=tap->link;tbp=tbp->link;}
          }

          if(sum!=0){res=res->insert1(res,r,c,sum);}
          while(tb&&tb->row==c)tb=tb->link;
      }
      while(ta&&ta->row==r){ta=ta->link;}

    }
    cout<<"RESULT of multiplication "<<endl;
    res->display(res);

}
};
int main()
{   node<int> *a=NULL;
    a=a->insert1(a,0,1,10.3);
    a=a->insert1(a,0,3, 12);
    a=a->insert1(a,2, 2, 5);
    a=a->insert1(a,3, 0, 15);
    a=a->insert1(a,3, 1, 12);
    node<int> *b=NULL;
    b=b->insert1(b,0, 2, 8.7);
    b=b->insert1(b,1, 3, 23.9);
    b=b->insert1(b,2, 2, 9);
    b=b->insert1(b,3, 0, 20);
    b=b->insert1(b,3, 1, 25);
    a->display(a);
    cout<<"______________________"<<endl;
    b->display(b);
    a->addi(a,b);
    cout<<"______________________"<<endl;
   //b=b->transp(b);
   cout<<"______________________"<<endl;
   a->mul(a,b);
    return 0;
}
