
#include "stdafx.h"
#include<iostream>
#include<assert.h>
using namespace std;
//����p��size
int OSTree::getSize(NodePoint p)
{
	int left = 0, right = 0;
	if (p->leftchild != NULL)left = p->leftchild->size;
	if (p->rightchild != NULL)right = p->rightchild->size;
	return left + right + 1;
}
//����ת����pΪ���ĺ���ߵĸ��ڵ������ת
void OSTree::leftRatate(NodePoint p)
{
	assert(p->parent != NULL&&p->parent->rightchild==p);
	NodePoint parent = p->parent;
	Color temp_color = parent->color;
	parent->color = p->color;
	p->color = temp_color;
	parent->rightchild = p->leftchild;
	if (p->leftchild != NULL)p->leftchild->parent = parent;
	p->leftchild = parent;
	NodePoint grandparent = parent->parent;
	parent->parent = p;
	p->parent = grandparent;
	if (grandparent != NULL)
	{
		grandparent->leftchild == parent ? grandparent->leftchild=p:grandparent->rightchild=p ;
	}
	p->size = parent->size;
	parent->size= getSize(parent);
}
//����ת����pΪ�������ұߵĸ��ڵ������ת
void OSTree::rightRatate(NodePoint p)
{
	assert(p->parent != NULL&&p->parent->leftchild == p);
	NodePoint parent = p->parent;
	Color temp_color = parent->color;
	parent->color = p->color;
	p->color = temp_color;
	parent->leftchild=p->rightchild;
	if (p->rightchild != NULL)p->rightchild->parent = parent;
	p->rightchild = parent;
	NodePoint grandparent = parent->parent;
	parent->parent = p;
	p->parent = grandparent;
	if (grandparent != NULL)
	{
		grandparent->leftchild == parent ?grandparent->leftchild=p :grandparent->rightchild=p ;
	}
	p->size=parent->size;
	parent->size = getSize(parent);
}
//����ֵΪdata�Ľڵ�
//���û�иýڵ��ⷵ�ظ��ڵ㣬
//���Ϊ��Ϊ�գ�����null
NodePoint OSTree::searchNode(int data)
{
	NodePoint p = T;
	if (p = NULL)return NULL;
	while (p->data != data)
	{
		if (p->data > data)
		{
			if (p->leftchild != NULL)
			{
				p = p->leftchild;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (p->rightchild != NULL)
			{
				p = p->rightchild;
			}
			else
			{
				break;
			}
		}
	}
	return p;
}
//����ڵ�
void OSTree::insertNode(int data)
{
	NodePoint parent = searchNode(data);
	if(parent=NULL)
	{
		this->T = new Node(data,BLACK);
		return;
	}
	NodePoint p=parent;
	if (parent->data > data)
	{
		parent->leftchild = new Node(data);
		parent->leftchild->parent = parent;
		while (p != NULL)
		{
			p->size++;
			p = p->parent;
		}
		p = parent->leftchild;
	}
	else if (parent->data < data)
	{
		parent->rightchild = new Node(data);
		parent->rightchild->parent = parent;
		while (p != NULL)
		{
			p->size++;
			p = p->parent;
		}
		p = parent->rightchild;
	}
	else
	{
		return;
	}
	while (parent->color!=BLACK)
	{//parent->color==Rad
		NodePoint grandparent = parent->parent;
		NodePoint parentbrother=(grandparent->leftchild==parent?grandparent->rightchild:grandparent->leftchild);
		if (parentbrother != NULL)
		{
			if (parentbrother->color == Rad)
			{
				grandparent->color = Rad;
				parent->color = BLACK;
				parentbrother->color = BLACK;
				p = grandparent;
				if (p->parent != NULL)
				{
					parent = p->parent;
					continue;
				}
				else
				{
					break;
				}
			}
		}
		if (grandparent->leftchild == parent)
		{
			if (parent->rightchild == p)
			{
				leftRatate(p);
				rightRatate(p);
			}
			else
			{
				rightRatate(parent);
			}
			break;
		}
		else
		{//parent==grantparent->right
			if (parent->leftchild == p)
			{
				rightRatate(p);
				leftRatate(p);
			}
			else
			{
				leftRatate(parent);
			}
		}
	}
}
//ɾ���ڵ����
void OSTree::deleteNode(int data)
{
	NodePoint p = searchNode(data);
	if (p != NULL)
	{
		NodePoint repNode = p->rightchild;
		if(repNode!=NULL)
		{
			while (repNode->leftchild != NULL)repNode = repNode->leftchild;
			p->data=repNode->data;
			p = repNode;
		}
		else if (p->leftchild == NULL)
		{
			if (p->color == Rad)
			{//ɾ����ɫҶ�ӽڵ�
				p == p->parent->leftchild ?p->parent->leftchild=NULL :p->parent->rightchild=NULL;
				NodePoint temp = p->parent;
				delete p;
				p = temp;
			}
			else
			{//ɾ��˫�ڽڵ�
				adjustBlack(p);
			}
			while (p != NULL)
			{
				p->size--;
				p = p->parent;
			}
		}
		else
		{//��������ɾ�����ӽڵ�
			p->data=p->leftchild->data;
			delete p->leftchild;
			p->leftchild = NULL;
			while (p != NULL)
			{
				p->size--;
				p=p->parent;
			}
		}
	}
}
void OSTree::adjustBlack(NodePoint& p)
{
	NodePoint parent = p->parent;
	assert(parent != NULL);
	NodePoint brother;
	if (p == parent->leftchild)
	{
		brother = parent->rightchild;
		if (brother->color == Rad)
		{
			leftRatate(brother);
		}
		brother = parent->rightchild;
		if (brother->rightchild == NULL)
		{
			if (brother->leftchild != NULL)
			{
				rightRatate(brother->leftchild);
			}
			else
			{
				parent->color = BLACK;
				brother->color = Rad;
				parent->leftchild = NULL;
				delete p;
				p = parent;
				return;
			}
		}
		brother = parent->rightchild;
		leftRatate(brother);
		parent->leftchild = NULL;
		delete p;
		p = parent;
	}
	else
	{//parent->right==p;
		brother = parent->leftchild;
		if (brother->color == Rad)
		{
			rightRatate(brother);
		}
		brother = parent->leftchild;
		if (brother->leftchild== NULL)
		{
			if (brother->rightchild != NULL)
			{
				leftRatate(brother->rightchild);
			}
			else
			{
				parent->color = BLACK;
				brother->color = Rad;
				parent->rightchild = NULL;
				delete p;
				p=parent;
				return;
			}
		}
		brother = parent->leftchild;
		rightRatate(brother);
		parent->rightchild = NULL;
		delete p;
		p = parent;
	}
}