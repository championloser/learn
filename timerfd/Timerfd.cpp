#include"Timerfd.h"
#include<unistd.h>
#include<sys/timerfd.h>

namespace jjx
{
Timerfd::Timerfd(int valTime, int inteTime)
: _tfd(timerfd_create(CLOCK_REALTIME, 0))
, _valTime(valTime)
, _inteTime(inteTime)
, _isStart(false)
{}
Timerfd::~Timerfd()
{
	::close(_tfd);
}
int Timerfd::setTime(int valTime, int inteTime)
{
	struct itimerspec new_time;
	new_time.it_value.tv_sec=valTime;
	new_time.it_value.tv_nsec=0;
	new_time.it_interval.tv_sec=inteTime;
	new_time.it_interval.tv_nsec=0;
	return timerfd_settime(_tfd, 0, &new_time, NULL);
}
int Timerfd::start()
{
	_isStart=true;
	return setTime(_valTime, _inteTime);
}
int Timerfd::stop()
{
	_isStart=false;
	return setTime(0, 0);
}
int Timerfd::getTfd()
{
	return _tfd;
}
bool Timerfd::isStart()
{
	return _isStart;
}
}//end of namespace jjx
