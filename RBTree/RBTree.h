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


		//已经有节点了，先插入再考虑旋转*********************************************
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

		//比他大则插在右边***********************************************************
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

		//平衡***********************************************************************
		while (parent && parent->_col == RED)  //父亲存在且为红，祖父一定存在
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					//第一种情况：变色
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//第三种情况：双旋->单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						std::swap(cur, parent);
					}

					//第二种情况：单旋+变色
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
					//第一种情况：变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//第三种情况：双旋->单旋
					if (cur == parent->_left)
					{
						RotateR(parent);
						std::swap(parent, cur);
					}

					//第二种情况：单旋+变色
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
		}

		_root->_col = BLACK;  //万一grandfather是根节点，保证根节点一定为黑色
		return true;
	}
private:
	Node* _root = nullptr;  //不是初始化，是缺省值
};


//有问题
//void TestRBTree()
//{
//	RBTree<int, int> t;
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	for (auto e : a)
//	{
//		t.Insert(std::make_pair(e, e));
//	}
//
//	t.Inorder();    //这句有问题
//	
//}

//删除（关注颜色）：先按照搜索树的规则 为黑色，孩子为红，先删除，再用孩子替代，把孩子变为黑；没有节点，先旋转，再考虑