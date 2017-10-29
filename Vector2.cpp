#include<iostream>
#include<memory>
using std::cout;
using std::endl;
template <typename T>
class Vector
{
public:
	Vector(int size=0, T elem=T())
	: _begin(NULL)
	, _first_free(NULL)
	, _end(NULL)
	{
		if(size>0)
		{
			_begin=_alloc.allocate(size);
			for(int i=0; i<size; ++i)
			{
				_alloc.construct(_begin+i, elem);
			}
			_first_free=_begin;
			_end=_begin+size;
		}
	}
	~Vector()
	{}
	void push_back(const T &elem);
	void pop_back();
	int size() const;
	int capacity() const;
	T & operator[](int idx)
	{
		return *(_begin+idx);
	}
private:
	void reallocate();
	T *_begin;
	T *_first_free;
	T *_end;
	std::allocator<T> _alloc;
};
template <typename T>
void Vector<T>::push_back(const T &elem)
{
	if(_begin==_end)
	{
		_begin=_alloc.allocate(1);
		_alloc.construct(_begin, elem);
		_first_free=_begin+1;
		_end=_begin+1;
	}else if(_first_free==_end){
		reallocate();
		_alloc.construct(_first_free++, elem);
	}else _alloc.construct(_first_free++, elem);
}
template <typename T>
void Vector<T>::pop_back()
{
	_alloc.destroy(--_first_free);
}
template <typename T>
int Vector<T>::size() const
{
	return _first_free-_begin;
}
template <typename T>
int Vector<T>::capacity() const
{
	return _end-_begin;
}
template <typename T>
void Vector<T>::reallocate()
{
	int oldsize=size();
	int oldcapacity=capacity();
	T *tmp=_alloc.allocate(oldsize*2);
	std::uninitialized_copy(_begin, _first_free, tmp);
	while(_begin!=_first_free)_alloc.destroy(--_first_free);
	_alloc.deallocate(_begin, oldsize);
	_begin=tmp;
	_first_free=_begin+oldsize;
	_end=_begin+oldcapacity*2;
}
int main()
{
	Vector<int> numbers;
	cout<<"size="<<numbers.size()<<" "<<"capacity="<<numbers.capacity()<<endl;
	for(int i=1; i<=15; ++i)
	{
		numbers.push_back(i);
		cout<<"size="<<numbers.size()<<" "<<"capacity="<<numbers.capacity()<<endl;
	}
	for(int i=0; i<numbers.size(); ++i)
	{
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
	return 0;
}
