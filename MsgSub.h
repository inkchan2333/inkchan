#pragma once
#include <string>
#include <queue>
#include "ThreadBase.h"
#include <map>

class TransactionManagement;

struct GroupMsg
{
	int32_t msgId;
	int64_t fromGroup;
	int64_t fromQQ;
	std::string msg;

	GroupMsg(int32_t msgId, int64_t fromGroup, int64_t fromQQ, std::string msg)
		:msgId(msgId), fromQQ(fromQQ), fromGroup(fromGroup), msg(msg) {}
};

class GroupMsgSub :
	public ThreadBase
{
public:
	void start();
	void quite();
	void pushMsg(int32_t msgId, int64_t fromGroup, int64_t fromQQ, std::string msg);
private:
	GroupMsgSub();
	~GroupMsgSub();
	virtual void threadMain();
private: 
	bool m_quit;   //ÊÇ·ñÍË³ö
	std::queue<GroupMsg> m_groupMsgBuffer;
	std::mutex m_mutex;

	friend TransactionManagement;
};



