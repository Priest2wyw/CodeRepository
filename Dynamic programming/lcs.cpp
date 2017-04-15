//����������У�longest-common-subsequence problem��
//����������A��B�������У��������������Z
//���˼·��
//���1�����A��B�����һԪ����ͬ����A��B���������Ԫ��һ����������������У����Ҵ�������λ��
//���2�����A��B������Ԫ�ز���ͬ�����Aȥ������Ԫ����B������������С�Bȥ������Ԫ����A���������������ѡ��Ĺ���������
//ģ�ͱ�ʾ��
//c[i,j]={c[i-1,j-1] A[i]=B[j];max{c[i,j-1],c[i-1,j]}A[i]!=B[j]};
#include"stdafx.h"
using namespace std;
void lcs::calculateTable()
{
	for (int j = 0; j < this->bsize; j++)
	{
		c[j] = 0;
	}
	for (int i = 0; i < this->asize; i++)
	{
		c[i*this->bsize] = 0;
	}
	for (int i = 1; i < this->asize; i++)
	{
		for (int j = 1; j < this->bsize; j++)
		{
			if (A[i] == B[j])
			{
				c[i*this->bsize + j] = c[(i - 1)*this->bsize + j - 1]+1;
			}
			else
			{
				if (c[i*this->bsize + j - 1] > c[(i - 1)*this->bsize + j])
				{
					c[i*this->bsize + j] = c[i*this->bsize + j - 1];
				}
				else
				{
					c[i*this->bsize + j] = c[(i - 1)*this->bsize + j];
				}
			}
		}
	}
}
void lcs::getSolution()
{
	for (int i = 0; i < 56; i++)
	{
		
		if (i % 7 == 0)
		{
			cout << endl;
		}
		cout << c[i] << " ";
	}
}