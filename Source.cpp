#include <iostream>

using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template<class T>
class Print
{
public:
	void operator() (T value)
	{
		cout << value << endl;
	}
};

template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template<class T>
int max_element(T* begin, T* end, T* Arr)
{
	int max = 0;
	for (T* from = begin; from < end; from++)
	{
		if (*from > max) { max = *from; }
	}
	return max;
}

template<class T>
int max_element_if(T* begin, T* end, T* Arr, Negative<T>& predicate)
{
	int max = -4444444;
	for (T* from = begin; from < end; from++)
	{
		if (predicate(*begin))
		{
			if (*from > max) { max = *from; }
		}
	}
	return max;
}

int main()
{
	int a[6] = { 2,3, 5, -1, -4, -5 };
	int b[6] = { -2,-3, -5, -1, -4, -5 };

	for (int i = 0; i < 6; i++)
		cout << a[i] << ' ';
	cout << endl << "Modified array" << endl;

	cout << endl << "Max" << endl;
	cout << max_element(&a[0], &a[6], &a[0]) << endl;

	cout << endl << "Max(if)" << endl;
	Negative<int>* pop = new Negative<int>();
	cout << max_element_if(&b[0], &b[6], &b[0], *pop) << endl;

	system("pause");
	return 0;
}