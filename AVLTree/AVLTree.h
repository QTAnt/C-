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

	AVLTreeNode(const std::pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}

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
				parent->_bf--;
			else
				parent->_bf++;

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
				//3.不平衡旋转(旋转的本质是在降高度)
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)
					{
						RotateLR(parent);
					}
				}

				break;
			} 
		}
		return true;
	}


	//3.不平衡旋转*********************************************************************
	//左单璇
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if(subRL)   //判断subRL是否为空
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppnode = parent->_parent;  ///先保存一下原来的parent
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
		}
		//subR->_parent = parent->_parent;
		subR->_parent = ppnode;

		subR->_bf = parent->_bf = 0;
	}

	//右单璇*****************************************************************************
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)      //subL与parent不可能为空，其他节点可能为空
			subLR->_parent = parent;

		subL->_right=parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subL;

		if (parent = _root)
		{
			_root = subL;
		}
		else
		{
			if (ppnode->_left = parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
		}

		subL->_parent = ppnode;
	}

	//左右双璇********************************************************************************
	//根据subR平衡因子更新之后考虑旋转
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;  //平衡因子

		subLR->_bf = 0;   //一定是
		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 0)
		{
			subL->_bf = parent->_bf = 0;
		}
	}


	//右左双璇********************************************************************************
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = subR->_bf = 0;
		}
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* root)    //中序
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}

	//判平衡
	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int letfHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		//分制
		return letfHeight > rightHeight ? letfHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int letfHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		////检查异常时
		if (rightHeight - letfHeight != root->_bf)
		{
			cout << "平衡因子异常" << endl;
			return false;
		}

		return abs(rightHeight - letfHeight) < 2   //仅判断了当前树
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);

	}

private:
	Node* _root;
};

void TestAVLTree()
{
	AVLTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
	}

	t.Inorder();
	cout << t.IsBalance() << endl;
}