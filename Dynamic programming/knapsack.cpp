//0-1��������
//��������������һ����Ʒ������w�Ͷ��õļ۸�p�����������ΪK�ı���ʹװ�µ���Ʒ���ܼ۸����
//ģ�ͣ�c[i,j]=max{c[i-1,j],c[i-1,j-wj]+pj}jΪ����,iΪ��Ʒ������;
#include"stdafx.h"
void knapsack::calculateTable()
{
	for (int i = 0; i < size; i++)
	{
		c[i*size] = 0;//c[i,0]=0;
	}
	for (int j = 0; j < capacity; j++)
	{
		c[j] = 0;//c[0,j]=0;
	}
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < capacity; j++)
		{
			if (w[i] > this->capacity)
			{
				c[i*size + j] = c[(i - 1)*size + j];
			}
			else
			{
				int temp = c[(i - 1)*size + j - w[i]] + p[i];
				temp > c[(i - 1)*size + j] ?c[i*size+j]=temp :c[i*size+j]=c[(i-1)*size+j] ;
			}
		}
	}
}
void knapsack::getSolution()
{
	int temp = capacity;
	for (int i = size; i >0; i--)
	{
		if (c[i*size + temp]!= c[(i - 1)*size + temp])
		{
			temp -= w[i];
			cout << i << " ";
		}
	}
}