// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#ifndef STDAFX
#define STDAFX
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
enum Color
{
	BLACK = 0,
	RED=1
};
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int height;
	Color color ;

}* NodePoint;
enum DataType
{
	NUREPEAT = 1,
	REPEAT = 0
};

//������������
class BSTree
{
private:
	struct Node *head;

public:
	BSTree()
	{
		this->head = NULL;
	}
	NodePoint searchNode(NodePoint, int, DataType type=REPEAT);
	void addNode(NodePoint);
	void deleteNode(NodePoint, int );
	NodePoint getHead();
	void travers_BSTree(NodePoint);
};
//binary balance tree
class AVL
{
private:
	struct Node *head;
	int* getMaxHeight(NodePoint, NodePoint);
public:
	AVL()
	{
		this->head = NULL;
	}
	//����ת��֧������˳ʱ����ת
	NodePoint leftRotate(NodePoint& p);
	//����ת��֧����ұ���ʱ����ת
	NodePoint rightRotate(NodePoint& p);
	//��ӽڵ�
	NodePoint addNode(NodePoint &head,NodePoint p,int data);
	//ɾ���ڵ�
	NodePoint deleteNode(NodePoint &head,int data);
	NodePoint deleteNode(NodePoint p);
	//����
	void travers_AVL(NodePoint head);
	NodePoint getHead();
	void adjust(NodePoint & parent);
};
class RBTree
{
private:
	NodePoint head;
public:
	void insertNode(NodePoint &head, int data);
	void deleteNode(NodePoint &head, int data);
	NodePoint leftRotate(NodePoint head);
	NodePoint rightRotate(NodePoint head);
	void travers_RBTree(NodePoint head);
	NodePoint searchByVal(NodePoint head, int data);
	void doubleBlackAdjust(NodePoint head);
};
#endif
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
