//ʹ������ջʵ��һ������
//st1����ѹ������ݣ�st2����������ݣ�ֻ�е�st2Ϊ�յ�ʱ����ܴ�st1��st2��ѹ������
template<class T>
class Queue
{
public:
	void Push(const T& x)
	{
		st1.push(x);
	}

	void Pop()
	{
		if (st2.empty())
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
		st2.pop();
	}

	T& Front()
	{
		if (st2.empty())
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
		return st2.top();
	}

	size_t Size()
	{
		return st1.size() + st2.size();
	}

	bool Empty()
	{
		return st1.empty() && st2.empty();
	}
private:
	stack<T> st1;
	stack<T> st2;
};
int main()
{
	Queue<int> q;
	q.Push(5);
	q.Push(3);
	q.Push(6);
	q.Push(2);
	q.Push(1);

	q.Pop();
	q.Pop();

	cout << q.Front() << endl;

	cout << q.Empty() << endl;

	cout << q.Size() << endl;

	system("pause");

}