#pragma once

enum Colour
{
	RED, 
	BLACK,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	std::pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root = nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}


		//�Ѿ��нڵ��ˣ��Ȳ����ٿ�����ת*********************************************
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first>kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}                                                                                                                                                                                                                                      
		}

		//������������ұ�***********************************************************
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//ƽ��***********************************************************************
		while (parent && parent->_col == RED)  //���״�����Ϊ�죬�游һ������
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					//��һ���������ɫ
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//�����������˫��->����
					if (cur == parent->_right)
					{
						RotateL(parent);
						std::swap(cur, parent);
					}

					//�ڶ������������+��ɫ
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
			else     //parent==grandfather->_right***********************************
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					//��һ���������ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//�����������˫��->����
					if (cur == parent->_left)
					{
						RotateR(parent);
						std::swap(parent, cur);
					}

					//�ڶ������������+��ɫ
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
		}

		_root->_col = BLACK;  //��һgrandfather�Ǹ��ڵ㣬��֤���ڵ�һ��Ϊ��ɫ
		return true;
	}
private:
	Node* _root = nullptr;  //���ǳ�ʼ������ȱʡֵ
};


//������
//void TestRBTree()
//{
//	RBTree<int, int> t;
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	for (auto e : a)
//	{
//		t.Insert(std::make_pair(e, e));
//	}
//
//	t.Inorder();    //���������
//	
//}

//ɾ������ע��ɫ�����Ȱ����������Ĺ��� Ϊ��ɫ������Ϊ�죬��ɾ�������ú���������Ѻ��ӱ�Ϊ�ڣ�û�нڵ㣬����ת���ٿ���