//ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(������Сֵ�Ĳ���)��ʱ�临�Ӷ�ΪO(1)
//������ԭ��ջʵ��һ�����⹦�ܵ�ջ��һ��ջ�����洢ԭ���ݣ�һ��ջ�����洢ÿ��ѹ����ֵʱ��Ŀǰ��Сֵ
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
