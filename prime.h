#include<iostream>
#include<vector>

using namespace std;

class Prime{
 public:
    Prime(int low , int high);//���캯��
    bool judgePrime(int);//�ж�һ�����Ƿ�Ϊ����
    virtual bool isPrime();
    void showPrime();//��ӡ����ѡ��Χ�ڵ������������ո�ָ�
    int getSize();//��ȡ��������
//	int *getPrime();//��vector�е���������һ�����鲢�����׵�ַ���Թ�superPrimeʹ��
 protected:
  vector<int> p;//�������������
};

class superPrime : public Prime {
 public:
    superPrime(int low , int high):Prime(low,high);//���캯��
    virtual bool isPrime();
	void showPrime();
 private:
    bool judgePrime(int);//�ж��Ƿ�Ϊ��������
    void findPrime(int , int);//������������vector
 protected:
  vector<int> sp;//�������������
};
