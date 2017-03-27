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
//��Ѱ�ҵ�һ��ֵΪ@param data�Ľڵ�
//Ȼ����Ѱ�Ҹýڵ�ĺ�̽ڵ�p��
//����p���ֵܽڵ���е��������������ɾ���ڵ�p��
void RBTree::deleteNode(NodePoint &head, int data)
{
	NodePoint p = searchByVal(head, data);
	if (p->data == data)
	{
		NodePoint parent = p->parent;
		if (p->color == RED)
		{
			if (p->left == NULL)   //���������ΪNULL����������ΪNULL
			{//ֱ��ɾ����ɫ��Ҷ�ӽڵ�
				parent->left == p ? parent->left=NULL:parent->right=NULL ;
				delete p;
			}
			else
			{//������������Ϊ�գ�����Ҫ�ҵ�p�ڵ�ĺ�̽ڵ�replacement;
				NodePoint repm = p->right;
				while (repm->left!=NULL)
				{
					repm = repm->left;
				}
				//����repm��p�ڵ��data���ݣ�Ȼ�����repm����ɫ���е���
				p->data = repm->data;
				if (repm->color == RED)
				{//�ú�ɫ�ڵ�һ����Ҷ�ӽڵ�
					repm->parent->left == repm ? repm->parent->left=NULL:repm->parent->right=NULL ;
					delete repm;
				}
				else
				{//�ýڵ��Ǻ�ɫ�Ľڵ㣬�ٸ��ݸýڵ��Ƿ��к�ɫ���Һ��ӽڵ���е���
					if (repm->right == NULL)
					{
						//ɾ����ɫҶ�ӽڵ�,���������ν��˫�ڵĴ���
						doubleBlackAdjust(repm);
						repm == NULL;
					}
					else
					{//�Һ���Ϊ��ɫ�ڵ�,�ú�ɫ�ڵ��ΪҶ�ӽڵ�
						NodePoint rc = repm->right;
						//�Ѻ�ɫ�ڵ�����ݣ��ŵ����ڵ��в���ɾ����ɫ�ڵ�
						repm->data = repm->right->data;
						delete repm->right;
						repm->right = NULL;
					}
				}
			}
		}
		else
		{//p->color==BLACK
			if (p->left == NULL)
			{//���p����ڵ���NULL�����ҽڵ�Ҫô��NULL��Ҫô�Ǻ�ɫ��Ҷ�ӽڵ�
				if (p->right == NULL)
				{
					//ɾ����ɫ��Ҷ�ӽڵ�ĵ���
					doubleBlackAdjust(p);
					p == NULL;
				}
				else
				{//p���ҽڵ��Ϊ��ɫ
					NodePoint rc = p->right;
					p->data=rc->data;
					p->right = NULL;
					delete rc;
				}
			}
			else
			{//���p����ڵ㲻��NULL
				if (p->right == NULL)
				{//p����ڵ�����Ǻ�ɫ��Ҷ�ӽڵ�
					NodePoint lc = p->left;
					p->data = lc->data;
					p->left == NULL;
					delete lc;
				}
				else
				{//���ҽڵ㶼����NULL����Ҫ�ҳ�p�ڵ�ĺ�̽ڵ㣬���ݺ�̽ڵ����ɫ���е���
					NodePoint repm = p->right;
					while (repm->left!=NULL)
					{
						repm=repm->left;
					}
					p->data=repm->data;
					//repm�ڵ�û�����ӽڵ㣬���repm�ڵ�Ϊ��ɫ����repm�ڵ�Ϊ��ɫ��Ҷ�ӽڵ�
					if (repm->color == RED)
					{
						repm->parent->left == repm ?repm->parent->left=NULL :repm->parent->left=NULL ;
						delete repm;
					}
					else
					{//repm�ڵ�Ϊ��ɫ�ڵ㣬����ݸýڵ��Ƿ����ҽڵ���е���
						if (repm->right == NULL)
						{
							//�������ɾ����ɫҶ�ӽڵ�ĵ���
							doubleBlackAdjust(repm);
							repm == NULL;
						}
						else
						{//���repm���ҽڵ㣬���ҽڵ����Ϊ��ɫ�Ľڵ�
							NodePoint rc = repm->right;
							repm->data = rc->data;
							repm->right = NULL;
							delete rc;
						}
					}
				}
			}
		}
	}
}
//ɾ����ɫ��Ҷ�ӽڵ�ĵ���
void RBTree::doubleBlackAdjust(NodePoint head)
{//head�ڵ�����и��ڵ�
	assert(head->parent != NULL);
	NodePoint parent = head->parent;
	if (parent->left == head)
	{//head�ڵ�Ϊparent�ڵ��������
		NodePoint brother = parent->right;
		assert(brother != NULL);
		if (brother->color == RED)
		{//���1
			leftRotate(brother);
		}
		//���»��head�ĸ��׺��ֵܽڵ�
		parent = head->parent;
		brother = parent->right;
		//�ֵܽڵ����ɫһ���Ǻ�ɫ
		assert(brother->color == BLACK);
		if (brother->left==NULL&&brother->right==NULL)
		{//�����
			parent->color = BLACK;
			brother->color = RED;
			parent->left = NULL;
			delete head;
			return;
		}
		else if(brother->left!=NULL && brother->right==NULL)
		{//�����
			rightRotate(brother->left);
		}
		//���»���ֵܽڵ�
		brother = parent->right;
		if (brother->right != NULL)
		{//�����
			leftRotate(brother);
			brother->right->color = BLACK;
			parent->left = NULL;
			delete head;
			return;
		}
	}
	else
	{//parent->right==head
		assert(parent != NULL);
		NodePoint brother = parent->left;
		if (brother->color == RED)
		{//���һ
			rightRotate(brother);
		}
		//���»�ø��׽ڵ���ֵܽڵ�
		parent = head->parent;
		brother = parent->left;
		if (brother->right == NULL&&brother->left == NULL)
		{
			parent->color = BLACK;
			brother->color = RED;
			parent->right = NULL;
			delete head;
		}
		else if(brother->right!=NULL&&brother->left==NULL)
		{
			leftRotate(brother->right);
		}
		//���»���ֵܽڵ�
		brother = parent->left;
		if (brother->left != NULL)
		{
			rightRotate(brother);
			brother->left->color = BLACK;
			parent->right = NULL;
			delete head;
			return;
		}
	}
}
void RBTree::travers_RBTree(NodePoint head)
{
	using namespace std;
	if (head == NULL)return;
	travers_RBTree(head->left);
	printf("%5d", head->data);
	travers_RBTree(head->right);
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