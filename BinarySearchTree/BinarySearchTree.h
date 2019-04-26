//搜索二叉树实现
#pragma once
using namespace std;

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	std::pair<K, V> _kv;

	BSTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
	{}
};

//搜索树，右大左小
template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()  //构造
		:_root(nullptr)
	{}

	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_kv.first > kv.first)        //比当前小，左
			{
				parent = cur;  //保证可以链起来
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)   //比当前大，右
			{
				parent = cur;
				cur = cur->_right;
			}
			else    //已经存在
			{
				return false;
			}
		}
		//说明为空
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	Node* Find(const K& k)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < k)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > k)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr; //跳出来，表明没有找到
	}

	bool Erase(const K& k)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < k)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > k)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到了，开始删除
				//1.左为空，父亲指向右子树
				//2.右为空，父亲指向左子树
				//3.左右均不为空，找替代节点，删除替代节点
				Node* del = cur;
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else  //父亲的右
						{
							parent->_right = cur->_right;
						}
					}
				}

				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				}

				else    //左右均不为空，找替代节点，删除替代节点(找左树的最右节点，或者是右树的最左节点)
				{
					Node* preplace = cur;   //特殊情况的关键点
					Node* replace = cur->_right;// replace指向7，找7的最左节点，链表尾的next为空
					while (replace->_left) //不为空
					{
						preplace = replace;
						replace = replace->_left;
					}

					//为空了，即是最左节点(最左节点->左为空，不一定是左子树)
					cur->_kv = replace->_kv;
					//删除替代的最左节点
					if (preplace->_left == replace)
					{
						preplace->_left = replace->_right;
					}
					else
					{
						preplace->_right = replace->_right;
					}
				}

				delete del;
				return true;
			}
		}
		//没有找到,删除失败
		return false;
	}


	//void Inorder(Node* root)    //中序
	//{
	//	if (root == nullptr)
	//		return;

	//	Inorder(root->_left);
	//	cout << root->kv.first << endl;
	//	Inorder(root->_right);
	//}

	void _Inorder(Node* root)    //中序
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}

	void Inorder()    //中序
	{
		_Inorder(_root);
	}
private:
	Node* _root;

};


void TestBSTree()
{
	//插入：有序
	//BSTree<int, int> t;
	//t.Insert(std::make_pair(1, 1));
	//t.Insert(std::make_pair(5, 1));
	//t.Insert(std::make_pair(3, 1));
	//t.Insert(std::make_pair(2, 1));
	//t.Insert(std::make_pair(4, 1));


	//插入：有序(重复的只计一次)	//UT :单元测试
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9, 9};
	BSTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e)); 
	}

	t.Inorder();    //0 1 2 3 4 5 6 7 8 9


	//删除
	t.Erase(2);
	t.Erase(8);
	t.Erase(2);
	t.Erase(1);
	t.Erase(5);
	t.Erase(7);

	t.Inorder();        //0 3 4 6 9

	for (auto e : a)   
	{
		t.Erase(e);
	}  
	t.Inorder();           //删完：是一个空行
}



