#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

#include<iostream>
using std::cout;
using std::endl;
namespace jjx
{
class Noncopyable
{
public:
	Noncopyable(){};
	~Noncopyable(){cout<<"~Noncopyable()"<<endl;};
private:
	Noncopyable(const Noncopyable &);
	Noncopyable & operator=(const Noncopyable &);
};
}//end of namespace jjx

#endif
