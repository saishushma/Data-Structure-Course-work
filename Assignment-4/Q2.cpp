#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include <sstream>
#include <string>
#include <climits>
#include <filesystem>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class minheap
{
public:
 //vector<pair(<int,long long int>)> a;
 vector< pair <int,long long int> > a;
 int cap;
 int sizeh;
  minheap(int c)
  {
    cap=c;
    //sizeh=0;
   // a= node[c];
  }
  ////
int par(int i)
{
return (i-1)/2;
}
int lft(int i)
{
return (2*i + 1);
}
int rit(int i)
{
return (2*i + 2);
}

void ins(long long int x,int f)
{
//cout<<"HAI";
a.push_back(make_pair(f,x));
int i=a.size()-1;
//cout<<a[i].first<<" "<<a[i].second<<endl;
while (i != 0 && a[par(i)].second > a[i].second)
{
//swap(&a[i], &a[parent(i)]);
int t1;
t1=a[i].first;
a[i].first=a[par(i)].first;
a[par(i)].first=t1;
long long int t2;
t2=a[i].second;
a[i].second=a[par(i)].second;
a[par(i)].second=t2;
i = par(i);
//cout<<a[i].first<<" "<<a[i].second<<endl;
}
}
/////////////////
pair<int,long long int> emin()
{
//pair <int, long long int> p1 ;
pair <int, long long int> p1 (a[0].first,a[0].second) ;
//swap
int t1;
int si=a.size()-1;
t1=a[0].first;
a[0].first=a[si].first;
a[si].first=t1;
long long int t2;
t2=a[0].second;
a[0].second=a[si].second;
a[si].second=t2;
a.erase(a.end());
hpy(0);
//make_pair<a[0].first,a[1].second> m1;
return p1;
}
///hpy
void hpy(int ind)
{
int l = lft(ind);
int r = rit(ind);
int sm = ind;
if(l<a.size()&&a[l].second<a[ind].second)
sm = l;
if(r<a.size()&&a[r].second<a[sm].second)
sm = r;
if(sm != ind)
{
//swap
int t1;
t1=a[ind].first;
a[ind].first=a[sm].first;
a[sm].first=t1;
long long int t2;
t2=a[ind].second;
a[ind].second=a[sm].second;
a[sm].second=t2;
hpy(sm);
}
}


};
int main()
{
//created temp files
ifstream fin;
fin.open("unsorted_file.txt");
string num;
string fname="temp";
int fno=0;
vector<long long int> v1;
while(!fin.eof())
{
int i=0;
while(i<100000&&getline(fin,num, ','))
{
long long int x1=stol(num);
 v1.push_back(x1);
 i++;
}
sort(v1.begin(),v1.end());
fstream f2;
string fn=fname+to_string(fno)+".txt";
f2.open(fn,ios::trunc | ios::out | ios::in);
for(int j=0;j<v1.size();j++)
{
    f2<<v1[j]<<",";
}
f2<<999999999;
f2.close();
v1.clear();
fno=fno+1;
i=0;
}
fin.close();
//insert into heap
fstream f3[fno];
minheap m1(fno);
for(int k=0;k<fno;k++)
{ string ff=fname+to_string(k)+".txt";
  f3[k].open(ff);
  getline(f3[k],num, ',');
  long long int x1=stol(num);
  m1.ins(x1,k);
}
int t=0;
for(int k=0;k<fno;k++)
{
 if(!f3[k].eof()){t=1;break;}
}
fstream fout;
int tx=1;
fout.open("output.txt",ios::trunc | ios::out | ios::in);
while(t==1){
  pair <int, long long int> p1 ;
  p1=m1.emin();
  //cout<<endl<<p1.first<<" "<<p1.second;
  if(tx==1)
  {fout<<p1.second;tx=2;}
  else
    fout<<","<<p1.second;
  if(!f3[p1.first].eof()){
  getline(f3[p1.first],num, ',');
  long long int x1=stol(num);
  m1.ins(x1,p1.first);

  }
  t=0;
for(int k=0;k<fno;k++)
{
 if(!f3[k].eof()){t=1;break;}
}
}
for(int k=0;k<fno;k++)
{
f3[k].close();
}
for(int k=0;k<fno;k++)
{
string fn=fname+to_string(k)+".txt";
char arr[100];
strcpy(arr,fn.c_str());
//cout<<string(arr);
int x=remove(arr);
if(x<0)cout<<"unsucessful"<<endl;
}
return 0;

}
