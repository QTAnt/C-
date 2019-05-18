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

//模板迭代器     //Ref-&,Ptr-*
template<class T, class Ref, class Ptr>
struct __ListIterator
{
	typedef __ListNode<T> Node;
	typedef __ListIterator<T, Ref, Ptr> Self;
	Node* _node;    //该节点的指针

	__ListIterator(Node* node)
		:_node(node)
	{}

	//重载
	//*it=10;
	//T& operator*()          ///取迭代器节点指向的数据
	//{
	//	return _node->_data;
	//}

	//T* operator->()
	//{
	//	//return &_node->_data;
	//	return &(operator*());   //省略了this,return &(this->operator*());
	//}

	Ref operator*()          ///取迭代器节点指向的数据
	{
		return _node->_data;//指针取里面的东西就用箭头
	}

	Ptr operator->()
	{
		//return &_node->_data;
		return &(operator*());   //省略了this,return &(this->operator*());
	}

	//++it;(返回++之后的)  ->it.operator++(&it)  (it传给this，_node就是this指向的)
	Self& operator++()
	{
		_node=_node->_next;
		return *this;           //迭代器++返回的仍是一迭代器
	}

	//it++;(返回++之前的)
	Self& operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;           //迭代器++返回的仍是一迭代器
	}

	//--it;(返回--之后的)
	Self& operator--()
	{
		_node = _node->_prev;
		return *this;           
	}
	//it--;(返回--之前的)
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


template<class T>        //模板：类名-List 类型-List<T> 函数名和类名相同 ；模板调用的时候才会实例化
class List
{
	typedef __ListNode<T> Node;
public:
	//typedef __ListIterator<T> iterator;
	//typedef __ListIterator<T> const_iterator;
	typedef __ListIterator<T, T&, T*> iterator;
	typedef __ListIterator<T, const T&, const T*> const_iterator;

	iterator begin()   //返回第一个位置的指针
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

	List()        //构造
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	//l2(l1)  //深拷贝 l2是this
	List(const List<T>& l)                    //拷贝构造
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
	List<T>& operator=(const List<T>& l)     //赋值
	{
		swap(_head, l._head);
		return *this;
	}


	~List()       //析构
	{
		Clear();
		delete _head;
		_head = nullptr;
	}

	size_t Size()           //size数据个数
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


	void Clear()     //最终只剩下头节点
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
		Erase(begin());       //begin()是头节点的下一个，头删就是删除这个节点
	}

	//某个位置之前插入一个x
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