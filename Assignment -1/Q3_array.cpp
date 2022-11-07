#include<iostream>
using namespace std;
template<class T>
class sm{
public:
int row,col,len;
T **data;;

    sm<T>(int r,int c)
    {
        row=r;
        col=c;
        len=0;
        data = new T *[100];
        for (int i = 0; i < 100; i++)
			data[i] = new T[3];

    }
    /*void create()
    {
        int i;
        for(i=0;i<len;i++)
        {
            cout<<"enter the row";
            cin>>data[i][0];
            cout<<"enter the col";
            cin>>data[i][1];
            cout<<"enter the value";
            cin>>data[i][2];
        }

    }*/
    void insert1(T r,T c,T val)
    {
      data[len][0]=r;
      data[len][1]=c;
      data[len][2]=val;
      len++;
    }
    void display()
    {
        int i;
        for(i=0;i<len;i++)
        {
            cout<<data[i][0]<<"   "<<data[i][1]<<"   "<<data[i][2]<<endl;

        }
    }
    void addi(sm<T> b)
    {
        if(row!=b.row||col!=b.col)
            {cout<<"addition not possible";}
        else
        {
            sm<T> res(row,col);
            int i=0,j=0,k=0;
            while(i<len && j<b.len)
            {   //equal
                if(data[i][0]==b.data[j][0]&&data[i][1]==b.data[j][1])
                { int x=data[i][2]+b.data[j][2];
                   if(x!=0){
                   res.data[k][0]=data[i][0];
                   res.data[k][1]=data[i][1];
                   res.data[k][2]=data[i][2]+b.data[j][2]; k++;}
                   i++;j++;
                }
                    //b is greater
                else if(data[i][0]<b.data[j][0]||(data[i][0]==b.data[j][0]&&data[i][1]<b.data[j][1]))
                {
                   res.data[k][0]=data[i][0];
                   res.data[k][1]=data[i][1];
                   res.data[k][2]=data[i][2];
                   i++;k++;
                }
                //a is greater
                else if(data[i][0]>b.data[j][0]||(data[i][0]==b.data[j][0]&&data[i][1]>b.data[j][1]))
                {
                   res.data[k][0]=b.data[j][0];
                   res.data[k][1]=b.data[j][1];
                   res.data[k][2]=b.data[j][2];
                   j++;k++;
                }
            }
            //insert remaining in matrix
            while(i<len)
            {
               res.data[k][0]=data[i][0];
                   res.data[k][1]=data[i][1];
                   res.data[k][2]=data[i][2];
                   i++;k++;
            }
            while(j<b.len)
            {
                 res.data[k][0]=b.data[j][0];
                   res.data[k][1]=b.data[j][1];
                   res.data[k][2]=b.data[j][2];
                   j++;k++;
            }
            res.len=k;
            cout<<"RESULT OF ADDITION"<<endl;
            res.display();
        }
    }
    sm transp()
    {
      sm<T> res(col,row);
      res.len=len;
      int c[col]={0};
      int ind[col];
      for(int i=0;i<len;i++)
      {
          c[(int)data[i][1]]++;
      }
      ind[0]=0;
      for(int i=1;i<col;i++)
      {
          ind[i]=ind[i-1]+c[i-1];
      }
      for(int i=0;i<len;i++)
      {
          int x=ind[(int)data[i][1]]++;
          res.data[x][0]=data[i][1];
          res.data[x][1]=data[i][0];
          res.data[x][2]=data[i][2];
      }
      cout<<"RESULT OF TRANSPOSE"<<endl;
      res.display();
      return res;

    }
    void mul(sm<T> b)
    {
        if(col!=b.row)
            cout<<"Multiplication is not possible";
        else
        {
            b=b.transp();
            sm<T> res(row,b.row);
            int i,j,ta,tb,r,c;
            T sum;
            for(i=0;i<len;)
            {   r=data[i][0];
                for(j=0;j<b.len;)
                {
                  c=b.data[j][0];
                  ta=i;
                  tb=j;
                  sum=0;
                  while(ta<len && tb<b.len &&data[ta][0]==r &&b.data[tb][0]==c)
                  {
                      if(data[ta][1]<b.data[tb][1])ta++;
                      else if(data[ta][1]>b.data[tb][1])tb++;
                      else{sum=sum+data[ta++][2]*b.data[tb++][2];}
                  }
                  if(sum!=0)
                  {
                      res.insert1(r,c,sum);
                  }
                  while(b.len&&b.data[j][0]==c)j++;
                }
                while(i<len&&data[i][0]==r)i++;
            }
            cout<<"RESULT OF MATRIX MULTIPLICATION"<<endl;
            res.display();

        }
    }


};
int main()
{
    int r1,c1,r2,c2,l1,l2;
    cout<<"enter no of rows in first sparse matrix";
    cin>>r1;
    cout<<"enter no of columns in first sparse matrix";
    cin>>c1;
    //cout<<"enter no of entries in first sparse matrix";
    //cin>>l1;
    sm<double> a(r1,c1);

   // a.create();
    cout<<"enter no of rows in second sparse matrix";
    cin>>r2;
    cout<<"enter no of columns in second sparse matrix";
    cin>>c2;
    //cout<<"enter no of entries in first sparse matrix";
   // cin>>l2;
    sm<double> b(r2,c2);
   // b.create();

    a.insert1(0,1,10.9);
    a.insert1(0,3, 12.2);
    a.insert1(2, 2, 5.4);
    a.insert1(3, 0, 15.6);
    a.insert1(3, 1, 12);
    b.insert1(0, 2, 8);
    b.insert1(1, 3, 23.5);
    b.insert1(2, 2, 9);
    b.insert1(3, 0, 20.6);
    b.insert1(3, 1, 25);
    a.addi(b);
    a.transp();
    a.mul(b);
    return 0;
}
