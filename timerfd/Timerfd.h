#ifndef __TIMERFD_H__
#define __TIMERFD_H__

namespace jjx
{
class Timerfd
{
public:
	Timerfd(int valTime, int inteTime);
	~Timerfd();
	int setTime(int valTime, int inteTime);
	int start();
	int stop();
	bool isStart();
	int getTfd();
private:
	int _tfd;
	int _valTime;
	int _inteTime;
	bool _isStart;
};
}//end of namespace jjx

#endif
