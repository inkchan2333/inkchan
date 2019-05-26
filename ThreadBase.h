#pragma once
#include <thread>
#include <mutex>
#include <chrono>

class ThreadBase
{
public:
	ThreadBase();
	virtual ~ThreadBase();
	virtual void start();
	virtual void quit();

	static void mSleep(int64_t m);
	static void sleep(int64_t m);
protected:
	virtual void threadMain()=0;
private:
	std::thread * m_thread;
};

