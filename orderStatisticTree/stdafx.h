// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
enum Color
{
	Rad = 0,
	BLACK=1
};
typedef struct Node
{
	int data;
	int size;
	Node* rightchild;
	Node* leftchild;
	Node* parent;
	Color color;
	Node(int data,Color color=Rad,int size=1)
	{
		this->data = data;
		this->size = size;
		this->rightchild = NULL;
		this->leftchild = NULL;
		this->parent = NULL;
		this->color = color;
	}
}* NodePoint;
class OSTree
{
private:
	NodePoint T;
public:
	OSTree()
	{
		this->T = NULL;
	}
	void insertNode(int data);
	void deleteNode(int data);
	NodePoint searchNode(int date);
	void adjustBlack(NodePoint& p);
	void travel_OSTree(NodePoint head);
	int getRank(int data);
	void leftRatate(NodePoint p);
	void rightRatate(NodePoint p);
	int getSize(NodePoint p);
};

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
