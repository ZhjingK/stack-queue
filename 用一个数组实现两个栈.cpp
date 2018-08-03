//用一个数组实现两个栈
//解决的方案是从两头开始向中间增长，因为是数组所以特别注意的是容量是否满了
template<class T>
class Stack
{
public:
	Stack()
		:_arr(new int [2])
		, size1(0)
		, size2(1)
		, _capacity(2)
	{}

	~Stack()
	{
		if (_arr != NULL)
		{
			delete[] _arr;
			_arr = NULL;
			size1 = 0;
			size2 = 0;
			_capacity = 0;
		}
	}

	void Push1(const T& x)
	{
		CheckCapacity();
		_arr[size1] = x;
		size1++;
	}

	void Push2(const T& x)
	{
		CheckCapacity();
		_arr[size2] = x;
		size2--;
	}

	void Pop1()
	{
		if (size1 > 0)
		{
			size1--;
		}
	}

	void Pop2()
	{
		if (size2 != _capacity - 1)
		{
			size2++;
		}
	}

	T& Top1()
	{
		if (size1 > 0)
		{
			return _arr[size1];
		}
	}

	T& Top2()
	{
		if (size2 > 0)
		{
			return _arr[size2];
		}
	}
private:
	void CheckCapacity()
	{
		if (size1 + size2 <= _capacity)
		{
			int newCapacity = _capacity + 10;

			T* tmp = new T[newCapacity];

			int k = newCapacity - 1;
			//将前后两个数据段进行拷贝
			for (int i = 0; i < size1; ++i)
			{
				tmp[i] = _arr[i];
			}
			for (int i = _capacity - 1; i>_capacity - size2; --i)
			{
				tmp[k] = _arr[i];
				k--;
			}

			delete[] _arr;
			size2 = newCapacity - (_capacity - size2);
			_capacity = newCapacity;
			_arr = tmp;
		}

	}

	T* _arr;
	int size1;
	int size2;
	int _capacity;
};
int main()
{
	Stack<int> s;
	s.Push1(4);
	s.Push1(7);
	s.Push1(1);
	s.Push1(9);


	s.Push2(6);
	s.Push2(8);
	s.Push2(2);
	s.Push2(0);

	
	s.Pop1();
	s.Pop2();

	cout << s.Top1() << endl;
	cout << s.Top2() << endl;

	system("pause");
}