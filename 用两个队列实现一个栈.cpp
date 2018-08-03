//用两个队列实现一个栈
//Push的时候往不为空的队列中压入数值；Pop是将不为空的队列中的size-1个数值压入到另一个为空的队列中
template<class T>
class Stack
{
public:
	void Push(const T& x)
	{
		if (!qu1.empty())
		{
			qu1.push(x);
		}
		else
		{
			qu2.push(x);
		}
	}

	void Pop()
	{
		if (qu1.empty())
		{
			size_t size1 = qu2.size();
			while (size1 != 1)
			{
				qu1.push(qu2.front());
				--size1;
				qu2.pop();
			}
			return qu2.pop();
		}
		else
		{
			size_t size2 = qu1.size();
			while (size2 != 1)
			{
				qu2.push(qu1.front());
				--size2;
				qu1.pop();
			}
			return qu1.pop();
		}
	}

	T& Top()
	{
		if (qu1.empty())
		{
			size_t size1 = qu2.size();
			while (size1 != 1)
			{
				qu1.push(qu2.front());
				--size1;
				qu2.pop();
			}
			return qu2.front();
		}
		else
		{
			size_t size2 = qu1.size();
			while (size2 != 1)
			{
				qu2.push(qu1.front());
				--size2;
				qu1.pop();
			}
			return qu1.front();
		}
	}

	size_t Size()
	{
		return qu1.size() + qu2.size();
	}

	bool Empty()
	{
		return qu1.empty() && qu2.empty();
	}
private:
	queue<T> qu1;
	queue<T> qu2;
};
int main()
{
	Stack<int> s;
	s.Push(3);
	s.Push(6);
	s.Push(4);
	s.Push(1);
	s.Push(9);

	s.Pop();
	s.Pop();

	cout << s.Size() << endl;

	cout << s.Top() << endl;

	cout << s.Empty() << endl;

	system("pause");

}