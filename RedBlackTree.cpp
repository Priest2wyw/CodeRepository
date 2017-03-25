//ʵ�ֺ�����Ĳ�����ɾ��
#include"stdafx.h"
#include<assert.h>
#include<stdio.h>
//�ڵ��������ýڵ��Ǹ��ڵ���Һ��ӣ��Ըýڵ�Ϊ���ģ�
//���ڵ�����ʱ�뷭ת
//A-B ---> B-A
//����ֵ�ý��
NodePoint RBTree::leftRotate(NodePoint head)
{
	if (head == NULL||head->parent==NULL)return head;
	assert(head == head->parent->right);
	NodePoint parent = head->parent;
	Color temp = head->color;
	head->color = parent->color;
	parent->color = temp;
	parent->right = head->left;
	if (head->left != NULL)head->left->parent = parent;
	head->left = parent;
	head->parent=parent->parent;
	if (head->parent != NULL)
	{
		head->parent->left == parent ?head->parent->left=head :head->parent->right=head ;
	}
	parent->parent = head;
	return head; 
}
//�������ýڵ��Ǹ��ڵ������
NodePoint RBTree::rightRotate(NodePoint head)
{
	if (head == NULL || head->parent == NULL)return head;
	assert(head == head->parent->left);
	NodePoint parent = head->parent;
	Color temp = head->color;
	head->color=parent->color;
	parent->color = temp;
	parent->left = head->right;
	if (head->right != NULL)head->right->parent = parent;
	head->right = parent;
	head->parent = parent->parent;
	if (head->parent != NULL)
	{
		head->parent->left == parent ?head->parent->left=head :head->parent->right=head ;
	}
	parent->parent = head;
	return head;
}
//������Ĳ������
void RBTree::insertNode(NodePoint &head, int data)
{
	NodePoint p = searchByVal(head, data);
	if (p == NULL)
	{
		head = new Node{ data,NULL,NULL,NULL,0,BLACK };
		return;
	}
	if (p->parent == NULL)
	{
		p->color = BLACK;
		return;
	}
	while (p->parent->color!=BLACK)
	{
		NodePoint parent = p->parent;
		NodePoint grandFather = parent->parent;
		if (grandFather == NULL)
		{
			parent->color = BLACK;
		}
		if (grandFather->left == parent)
		{
			NodePoint parent_brother = grandFather->right;
			if (parent_brother != NULL)
			{
				if (parent_brother->color == RED)
				{
					grandFather->color = RED;
					parent->color = BLACK;
					parent_brother->color = BLACK;
					p = grandFather;
					if (p->parent == NULL)
					{
						p->color = BLACK;
						return;
					}
				}
				else
				{
					if (parent->left == p)
					{
						rightRotate(parent);
					}
					else
					{
						leftRotate(p);
						rightRotate(p);
						p = p->left;
					}
				}
			}
			else
			{
				if (parent->left == p)
				{
					rightRotate(parent);
				}
				else
				{
					leftRotate(p);
					rightRotate(p);
					p = p->left;
				}
			}
		}
		else if(grandFather->right==parent)
		{
			NodePoint parent_brother = grandFather->left;
			if (parent_brother != NULL)
			{
				if (parent_brother->color == RED)
				{
					parent->color = BLACK;
					parent_brother->color = BLACK;
					grandFather->color = RED;
					p = grandFather;
					if (p->parent == NULL)
					{
						p->color = BLACK;
						return;
					}
				}
				else
				{
					if (parent->left == p)
					{
						rightRotate(p);
						leftRotate(p);
						p = p->right;
					}
					else
					{
						leftRotate(parent);
					}
				}
			}
			else
			{
				if (parent->left == p)
				{
					rightRotate(p);
					leftRotate(p);
					p = p->right;
				}
				else
				{
					leftRotate(parent);
				}
			}
		}
	}
	while (head->parent != NULL)
	{
		head = head->parent;
	}
}
//�������ɾ������
void RBTree::deleteNode(NodePoint head, int data)
{

}
void RBTree::travers_RBTree(NodePoint head)
{
	using namespace std;
	if (head == NULL)return;
	travers_RBTree(head->right);
	printf("%5d", head->data);
	travers_RBTree(head->left);
}
//����ֵ�Ժ������������
//������ǿյģ�����NULL
//����ҵ����ظýڵ㣬����Ҳ��������ýڵ㣬�����ظýڵ�
NodePoint RBTree::searchByVal(NodePoint head, int data)
{
	if (head == NULL)return NULL;
	if (head->data == data)return head;
	else if (head->data > data)
	{
		if (head->left == NULL)
		{
			head->left = new Node{data,NULL,NULL,head,0,RED};
			return head->left;
		}
		searchByVal(head->left, data);
	}
	else
	{
		if (head->right == NULL)
		{
			head->right = new Node{ data,NULL,NULL,head,0,RED };
			return head->right;
		}
		searchByVal(head->right, data);
	}
}