// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//
#ifndef STDAFX
#define STDAFX
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include<limits.h>
#define MAX 5000
typedef struct point
{
	int data;
	int index;
	bool isIncluded;
	struct point * parent;
}* Mat;
void dijkstra(int*base, int size);
void printOut(Mat d, int size);
void floyd(int*base, int size);
#endif // !STDAFX
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
