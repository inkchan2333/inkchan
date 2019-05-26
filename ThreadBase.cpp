#include "ThreadBase.h"

ThreadBase::ThreadBase()
{
	m_thread = NULL;
}

ThreadBase::~ThreadBase()
{
}

void ThreadBase::start()
{
	if (m_thread == NULL)
	{
		m_thread = new std::thread{ &ThreadBase::threadMain,this};
	}
}

void ThreadBase::quit()
{
	if (m_thread!=nullptr)
	{
		delete m_thread;
		m_thread = nullptr;
	}
}

void ThreadBase::mSleep(int64_t m)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(m));
}

void ThreadBase::sleep(int64_t m)
{
	std::this_thread::sleep_for(std::chrono::seconds(m));
}

