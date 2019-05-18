#pragma once

#include <iostream>

template<class T>
struct __ListNode
{
	T _data;
	__ListNode<T>* _prev;
	__ListNode<T>* _next;

	__ListNode(const T& x =T())
		:_data(x)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

//ģ�������     //Ref-&,Ptr-*
template<class T, class Ref, class Ptr>
struct __ListIterator
{
	typedef __ListNode<T> Node;
	typedef __ListIterator<T, Ref, Ptr> Self;
	Node* _node;    //�ýڵ��ָ��

	__ListIterator(Node* node)
		:_node(node)
	{}

	//����
	//*it=10;
	//T& operator*()          ///ȡ�������ڵ�ָ�������
	//{
	//	return _node->_data;
	//}

	//T* operator->()
	//{
	//	//return &_node->_data;
	//	return &(operator*());   //ʡ����this,return &(this->operator*());
	//}

	Ref operator*()          ///ȡ�������ڵ�ָ�������
	{
		return _node->_data;//ָ��ȡ����Ķ������ü�ͷ
	}

	Ptr operator->()
	{
		//return &_node->_data;
		return &(operator*());   //ʡ����this,return &(this->operator*());
	}

	//++it;(����++֮���)  ->it.operator++(&it)  (it����this��_node����thisָ���)
	Self& operator++()
	{
		_node=_node->_next;
		return *this;           //������++���ص�����һ������
	}

	//it++;(����++֮ǰ��)
	Self& operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;           //������++���ص�����һ������
	}

	//--it;(����--֮���)
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;           
	}
	//it--;(����--֮ǰ��)
	Self& operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;           
	}

	bool operator != (const Self& s)
	{
		return _node != s._node;
	}
	bool operator == (const Self& s)
	{
		return _node == s._node;
	}
};


template<class T>        //ģ�壺����-List ����-List<T> ��������������ͬ ��ģ����õ�ʱ��Ż�ʵ����
class List
{
	typedef __ListNode<T> Node;
public:
	//typedef __ListIterator<T> iterator;
	//typedef __ListIterator<T> const_iterator;
	typedef __ListIterator<T, T&, T*> iterator;
	typedef __ListIterator<T, const T&, const T*> const_iterator;

	iterator begin()   //���ص�һ��λ�õ�ָ��
	{
		return iterator(_head->_next);
	}
	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end() const
	{
		return const_iterator(_head);
	}

	List()        //����
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	//l2(l1)  //��� l2��this
	List(const List<T>& l)                    //��������
	{
		this->_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		List<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			this->PushBack(*it);
			++it;
		}
	}

	//l1=l2;
	List<T>& operator=(const List<T>& l)     //��ֵ
	{
		swap(_head, l._head);
		return *this;
	}


	~List()       //����
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	size_t Size()           //size���ݸ���
	{
		size_t size = 0;
		for (const auto& e : *this)
		{
			++size;
		}
	}

	bool Empty()
	{
		//return Size() == 0;
		//return _head->_next == _head;
		return begin() == end();
	}


	void Clear()     //����ֻʣ��ͷ�ڵ�
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			delete cur;

			cur = next;
		}

		_head->_next = _head;
		_head->_prev = _head;
	}

	//void PushBack(const T& x)
	//{
	//	Node* newnode = new Node(x);
	//	Node* tail = _head->_prev;

	//	tail->_next = newnode;
	//	newnode->_prev = tail;
	//	newnode->_next = _head;
	//	_head->_prev = newnode;
	//}
	void PushBack(const T& x)
	{
		Insert(end(), x);
	}

	void PopBack()
	{
		Erase(--end());
	}

	void PushFront(const T& x)
	{
		Insert(begin(), x);
	}

	void PopFront()
	{
		Erase(begin());       //begin()��ͷ�ڵ����һ����ͷɾ����ɾ������ڵ�
	}

	//ĳ��λ��֮ǰ����һ��x
	void Insert(iterator pos, const T& x)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* newnode = new Node(x);
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = cur;
		cur->_prev = newnode;
	}

	void Erase(iterator pos)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;
		delete cur;
	}

private:
	Node* _head;
};