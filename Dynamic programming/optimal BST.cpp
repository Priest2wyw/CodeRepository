//���Ŷ���������(optimal binary search tree)
//������������������K��ÿ����ĸ��ʣ�����һ�ŷ��ʽڵ����ٵ������������������������k��˳��һ��
//����˼·�������T��������������������������������������Ҳ��һ�������������������ӽṹ��
//ģ�ͣ�c[i,j]={min{c[i,k-1]+c[k+1,j]+w[i,j]} k��[i,j] i<=j,q[i-1] i=j+1};
#include"stdafx.h"
void OBST::calculateTable()
{
	for (int i = 1; i < this->size; i++)
	{
		c[i*size + i - 1] = this->q[i-1];
		w[i*size + i - 1] = this->q[i - 1];
	}
	for (int length = 1; length <size; length++)
	{
		for (int i = 1; i <size-length+1; i++)
		{
			int j = i + length - 1;
			if (j < size)
			{
				double min = MAX;
				w[i*size + j] = w[i*size + j - 1] + p[j] + q[j];
				for (int k = i; k <= j; k++)
				{
					double temp = c[i*size + k - 1] + c[(k + 1)*size + j] + w[i*size+j];
					if (temp < min)
					{
						min = temp;
						index[i*size + j] = k;
					}
				}
				c[i*size + j] = min;
			}
		}
	}
}
void OBST::getSolution(int from,int end)
{//���ǰ�����
	if (from <= end)
	{
		int temp = index[from*size + end];
		cout << temp<<" ";
		getSolution(from, temp - 1);
		getSolution(temp + 1, end);
	}
}