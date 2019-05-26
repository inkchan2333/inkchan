
#include "TransactionManagement.h"
#include "MsgSub.h"

TransactionManagement * TransactionManagement::getInstance()
{
	static TransactionManagement* t= new TransactionManagement();
	return t;
}

GroupMsgSub * TransactionManagement::getGroupMsgSubInstance()
{
	return m_groupMsgSub;
}

TransactionManagement::TransactionManagement()
{
	m_groupMsgSub = new GroupMsgSub();
}


TransactionManagement::~TransactionManagement()
{
}
