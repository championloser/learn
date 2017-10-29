#include<iostream>
using std::cout;
using std::endl;
template <typename T>
class Vector
{
public:
	Vector(int size=0)
	: _begin(NULL)
	, _first_free(NULL)
	, _end(NULL)
	{
		if(size>0)
		{
			_begin=_alloc.allocate(size);
			_first_free=_begin;
			_end=_begin+size+1;
			_alloc.construct(_begin);
		}
	}
	~Vector()
	{
		while(_begin!=_end)_alloc.destroy(--_end);
		_alloc.destroy(_end);
		_alloc.deallocate(_begin, size());
	}
	void push_back(const T &elem);
	void pop_back();
	int size();
	int capacity();
	void reallocate();
	void display();
	T & operator[](int idx)
	{
		return *(_begin+idx);
	}
private:
	T *_begin;
	T *_first_free;
	T *_end;
	//static std::allocator<T> _alloc;
	std::allocator<T> _alloc;
};
//template <typename T>
//std::allocator<T> Vector<T>::_alloc;
template <typename T>
void Vector<T>::push_back(const T &elem)
{
	if(_begin==_end)
	{
		_begin=_alloc.allocate(1);
		_end=_begin+1;
		_first_free=_begin+1;
		_alloc.construct(_begin, elem);
	}else if(_first_free==_end){
		reallocate();
		*(_first_free)=elem;
		++_first_free;
	}else{
		*(_first_free)=elem;
		++_first_free;
	}
}
template <typename T>
void Vector<T>::pop_back()
{
	--_first_free;
}
template <typename T>
void Vector<T>::reallocate()
{
	int oldsize=size();
	T *tmp=_alloc.allocate(oldsize*2);
	_alloc.construct(tmp, 0);
	for(int i=0; (_begin+i)!=_end; ++i)
	{
		*(tmp+i)=*(_begin+i);
	}
	_alloc.deallocate(_begin, capacity());
	_begin=tmp;
	_first_free=_begin+oldsize;
	_end=_begin+2*oldsize;
}
template <typename T>
int Vector<T>::size()
{
	return _first_free-_begin;
}
template <typename T>
int Vector<T>::capacity()
{
	if(_begin==_end)return 0;
	else return _end-_begin;
}
//template <typename T>
//void Vector<T>::display()
//{
//	int i=0;
//	while((_begin+i)!=_first_free)
//	{
//		cout<<*(_begin+i)<<" ";
//		++i;
//	}
//	cout<<endl;
//}
int main()
{
	Vector<int> numbers;
	for(int i=1; i<=10; ++i)
	{
		numbers.push_back(i);
		cout<<"size="<<numbers.size()<<" "<<"capacity="<<numbers.capacity()<<endl;
	}
	numbers.pop_back();
	cout<<"size="<<numbers.size()<<" "<<"capacity="<<numbers.capacity()<<endl;
	for(int i=0; i<numbers.size(); ++i)
	{
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
	numbers[5]=100;
	for(int i=0; i<numbers.size(); ++i)
	{
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
	return 0;
}
