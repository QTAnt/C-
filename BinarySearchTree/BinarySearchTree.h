//����������ʵ��
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

//���������Ҵ���С
template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()  //����
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
			if (cur->_kv.first > kv.first)        //�ȵ�ǰС����
			{
				parent = cur;  //��֤����������
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)   //�ȵ�ǰ����
			{
				parent = cur;
				cur = cur->_right;
			}
			else    //�Ѿ�����
			{
				return false;
			}
		}
		//˵��Ϊ��
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
		return nullptr; //������������û���ҵ�
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
				//�ҵ��ˣ���ʼɾ��
				//1.��Ϊ�գ�����ָ��������
				//2.��Ϊ�գ�����ָ��������
				//3.���Ҿ���Ϊ�գ�������ڵ㣬ɾ������ڵ�
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
						else  //���׵���
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

				else    //���Ҿ���Ϊ�գ�������ڵ㣬ɾ������ڵ�(�����������ҽڵ㣬����������������ڵ�)
				{
					Node* preplace = cur;   //��������Ĺؼ���
					Node* replace = cur->_right;// replaceָ��7����7������ڵ㣬����β��nextΪ��
					while (replace->_left) //��Ϊ��
					{
						preplace = replace;
						replace = replace->_left;
					}

					//Ϊ���ˣ���������ڵ�(����ڵ�->��Ϊ�գ���һ����������)
					cur->_kv = replace->_kv;
					//ɾ�����������ڵ�
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
		//û���ҵ�,ɾ��ʧ��
		return false;
	}


	//void Inorder(Node* root)    //����
	//{
	//	if (root == nullptr)
	//		return;

	//	Inorder(root->_left);
	//	cout << root->kv.first << endl;
	//	Inorder(root->_right);
	//}

	void _Inorder(Node* root)    //����
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_kv.first << " ";
		_Inorder(root->_right);
	}

	void Inorder()    //����
	{
		_Inorder(_root);
	}
private:
	Node* _root;

};


void TestBSTree()
{
	//���룺����
	//BSTree<int, int> t;
	//t.Insert(std::make_pair(1, 1));
	//t.Insert(std::make_pair(5, 1));
	//t.Insert(std::make_pair(3, 1));
	//t.Insert(std::make_pair(2, 1));
	//t.Insert(std::make_pair(4, 1));


	//���룺����(�ظ���ֻ��һ��)	//UT :��Ԫ����
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9, 9};
	BSTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e)); 
	}

	t.Inorder();    //0 1 2 3 4 5 6 7 8 9


	//ɾ��
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
	t.Inorder();           //ɾ�꣺��һ������
}



