//�ֹ��и�����
//��������:���Ȳ�ͬ�ĸֹܣ���Ӧ�ļ۸�Ҳ��ͬ�����ĸֹܿ���ͨ���и���С�ĸֹ�
//����и�ʹ�õ��ĸֹܼ۸����
//ģ�ͣ�c[j]=max{p[k]+c[j-k]};
#include"stdafx.h"
//����c[j]
void steelPipe::calculateTable()
{
	for (int i = 1; i <= this->size; i++)
	{
		int sum = 0;
		int id = 0;
		for (int k = 1; k <= i; k++)
		{
			if (sum < price[k] + c[i - k])
			{
				sum = price[k] + c[i - k];
				id = k;
			}
		}
		c[i] = sum;
		this->index[i] = id;
	}
	for (int i = 0; i <= size; i++)
	{
		using namespace std;
		cout << this->index[i] << "  ";
	}
}
//��ӡ���и��
void steelPipe::getSolution(int size)
{
	using namespace std;
	if (index[size] != size)
	{
		getSolution(index[size]);
		getSolution(size - index[size]);
	}
	else
	{
		cout << "e" << size<<"  ";
	}
}