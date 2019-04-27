#pragma once
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;   //可以倒着走，从子走向父

	std::pair<K, V> _kv;
	int _bf;  //平衡因子
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				cur = parent;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				cur = parent;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}


		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			//1.高度不变，更新结束
			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				//2.高度变了，继续更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//3.不平衡旋转
			}

		}

		return true;
	}
private:
	Node* _root;
};