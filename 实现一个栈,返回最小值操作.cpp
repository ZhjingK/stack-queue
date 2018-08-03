//实现一个栈，要求实现Push(入栈)，Pop(出栈)，Min(返回最小值的操作)的时间复杂度为O(1)
//用两个原生栈实现一个特殊功能的栈；一个栈用来存储原数据，一个栈用来存储每次压入数值时的目前较小值
template<class T>
class Stack
{
public:

	void Push(T key)
	{
		if (_min.empty() || key < _min.top())
		{
			_min.push(key);
		}
		_num.push(key);
	}

	void Pop()
	{
		if (_min.top() == _num.top())
		{
			_min.pop();
		}
		_num.pop();
	}

	T Min()
	{
		return _min.top();
	}

	void Print()
	{
		while (!_num.empty())
		{
			cout << _num.top() << " ";
			_num.pop();
		}
		while (!_min.empty())
		{
			cout << _min.top() << " ";
			_min.pop();
		}
	}

	size_t Size()
	{
		return _num.size();
	}
private:
	stack<T> _num;
	stack<T> _min;
	T _x;
};
int main()
{
	Stack<int> s;
	s.Push(4);
	s.Push(5);
	s.Push(7);
	s.Push(0);
	s.Push(2);

	s.Pop();
	s.Pop();

	cout << s.Min() << endl;

	system("pause");

}
