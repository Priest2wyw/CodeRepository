// Dynamic programming.cpp : �������̨Ӧ�ó������ڵ㡣
//��̬�滮����:�ֹ��и��������ˣ�����������У��������������Ŷ�����������0-1��������
//
#include "stdafx.h"
#include<iostream>
using namespace std;
int main()
{
	steelPipe sp(10);
	sp.calculateTable();
	sp.getSolution(10);
	matrixChain mc(6);
	mc.calculateTable();
	mc.getSolution(1, 6);
	return 0;
}
