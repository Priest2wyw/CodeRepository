// Dynamic programming.cpp : �������̨Ӧ�ó������ڵ㡣
//��̬�滮����:�ֹ��и��������ˣ�����������У���Ҫ�������������Ŷ�����������0-1��������
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
	lcs lcsClass;
	lcsClass.calculateTable();
	lcsClass.getSolution();
	return 0;
}

