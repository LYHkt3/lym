#include<iostream>
using namespace std;

class Matrix {
    public:
       Matrix(int c,int r):col(c),row(r){
           size = c*r;
           if(size>0){
               element = new int[size];
           }
           else element = NULL;
       }
       Matrix(int c,int r,int val):col(c),row(r){
           size = c*r;
           if(size>0){
               element = new int[size];
           }
           else element = NULL;
           for(int i=0;i<col;i++)
              for(int j=0;j<row;j++){
                  element[col*i+j]=val;
            }     
       }
       void IN(){
           int num;
           for(int i=0;i<col;i++)
              for(int j=0;j<row;j++){
                  std::cin>>num;
                  element[col*i+j]=num;
            }     
       }
       void PUT(){
           if(!size){
               cout<<"数据错误!"<<endl;
               return ;
           }
           cout<<"矩阵为："<<endl;
           for(int i=0;i<col;i++){
              for(int j=0;j<row;j++)
                std::cout<<element[col*i+j]<<" ";
              std::cout<<endl;
            }    
       }
       friend Matrix dot(const Matrix&,const Matrix&);
       friend Matrix mul(const Matrix&,const Matrix&);
       friend Matrix add(const Matrix&,const Matrix&);
       friend Matrix sub(const Matrix&,const Matrix&);
    private:
       int row;
       int col;
       int size;
       int *element;
};

Matrix dot(const Matrix& a,const Matrix& b){
    if(a.col!=b.col || a.row!=b.row){
        Matrix ret(0,0);
        cout<<"数据错误！"<<endl;
        return ret;
    }
    Matrix ret(a.col,a.row);
    for(int i=0;i<a.col;i++)
        for(int j=0;j<b.row;j++){
           ret.element[i*a.col+j]=a.element[i*a.col+j]*b.element[i*a.col+j];
    }     
    return ret;
}
Matrix mul(const Matrix& a,const Matrix& b){
    if(a.row!=b.col){
        Matrix ret(0,0);
        cout<<"数据错误！"<<endl;
        return ret;
    }
    Matrix ret(a.col,b.row,0);
    for(int i=0;i<a.col;i++)
        for(int j=0;j<b.row;j++)
           for(int k=0;k<a.row;k++){
           ret.element[i*a.col+j]+=a.element[i*a.col+k]*b.element[k*b.col+j];
    }     
    return ret;
}
Matrix add(const Matrix& a,const Matrix& b){
    if(a.col!=b.col || a.row!=b.row){
        Matrix ret(0,0);
        cout<<"数据错误！"<<endl;
        return ret;
    }
    Matrix ret(a.col,a.row);
    for(int i=0;i<a.col;i++)
        for(int j=0;j<b.row;j++){
           ret.element[i*a.col+j]=a.element[i*a.col+j]+b.element[i*a.col+j];
    }     
    return ret;
}
Matrix sub(const Matrix& a,const Matrix& b){
    if(a.col!=b.col || a.row!=b.row){
        Matrix ret(0,0);
        cout<<"数据错误！"<<endl;
        return ret;
    }
    Matrix ret(a.col,a.row);
    for(int i=0;i<a.col;i++)
        for(int j=0;j<b.row;j++){
           ret.element[i*a.col+j]=a.element[i*a.col+j]-b.element[i*a.col+j];
    }     
    return ret;
}
