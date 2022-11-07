#include<iostream>
#include<map>
using namespace std;
struct node
{
    int key,val,c;
    node* prev;
    node *next;
    node(int k,int v)
    {   val=v;
        c=1;
        key=k;

    }

};
struct dlist
{
    int s;
    node *head;
    node *tail;
    dlist()
    {
        s=0;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
        s++;
    }

    void deletenode(node* temp) {
        node* delprev = temp->prev;
        node* delnext = temp->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        s--;
    }
};
class lfucache
{public:
    map<int,node*> keynode;
    map<int,dlist*> flmap;
    int cap;
    int minfreq;
    int csize;
    lfucache(int capacity)
    {
        cap=capacity;
        minfreq=0;
        csize=0;
    }
     void updatefmap(node *n)
     {
         keynode.erase(n->key);
         flmap[n->c]->deletenode(n);
         if(n->c==minfreq&&flmap[n->c]->s==0)
         {
             minfreq++;
         }
         dlist *nlist=new dlist();
         if(flmap.find(n->c+1)!=flmap.end())
         {
             nlist=flmap[n->c+1];
         }
         n->c=n->c+1;
         nlist->addnode(n);
         flmap[n->c]=nlist;
         keynode[n->key]=n;
     }

    int get(int key)
    {
        if(keynode.find(key)!=keynode.end())
        {
            node *n=keynode[key];
            int value=n->val;
            updatefmap(n);
            return value;
        }
        return -1;
    }
    void put(int key,int value)
    {
        if(cap==0)return;
        if(keynode.find(key)!=keynode.end())
        {
            node *n=keynode[key];
            updatefmap(n);

        }
        else
        {
           if(csize==cap)
           {
               dlist *l=flmap[minfreq];
               keynode.erase(l->tail->prev->key);
               flmap[minfreq]->deletenode(l->tail->prev);
               csize--;
           }
           csize++;
           minfreq=1;
           dlist *listfreq=new dlist();
           if(flmap.find(minfreq)!=flmap.end())
           {
               listfreq=flmap[minfreq];
           }
           node *n1=new node(key,value);
           listfreq->addnode(n1);
           keynode[key]=n1;
           flmap[minfreq]=listfreq;
        }
    }

};

int main()
{lfucache c(2);
  c.put(1,10);
  c.put(2,20);
  c.put(3,30);
  c.put(4,40);
  cout<<c.get(4)<<endl;
  cout<<c.get(5);

return 0;
}
