#pragma once

class GroupMsgSub;

class TransactionManagement
{
public:
	static TransactionManagement * getInstance();
	//»ñÈ¡GroupMsgSubÊµÀý
	GroupMsgSub * getGroupMsgSubInstance();
private:
	TransactionManagement();
	~TransactionManagement();

	GroupMsgSub * m_groupMsgSub;
};

