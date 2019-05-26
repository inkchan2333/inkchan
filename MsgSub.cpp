#include "MsgSub.h"
#include "cqp.h"
#include <string.h>
//导入全局变量 ac   在appmain.h 中定义
extern int ac;


void GroupMsgSub::threadMain()
{
	while (!m_quit)
	{
		if (m_groupMsgBuffer.size() > 0)
		{
			m_mutex.lock();
			GroupMsg msg = m_groupMsgBuffer.front();
			m_groupMsgBuffer.pop();
			m_mutex.unlock();
			
			
			if (msg.msg=="test!!!")
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "响应测试成功，c++天下第一。");
			}
			else if (msg.msg == "摸摸小蛋糕") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "wwwwww");
			}
			else if (msg.msg == "小蛋糕" && msg.fromQQ == 982957484) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人好，今天也辛苦了");
			}
			else if (msg.msg == "!stats me" && msg.fromQQ == 982957484) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "唔...主人，咱找不到你的Stats呢 QAQ");
			}
			else if (msg.msg == "!stats me") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Stats不想写了，先给Mc让让路。");
			}


		/*
				#######################用于迫害黄老板的##############			
		
																					*/

			
			else if (msg.msg == "火 黄老板 火") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "火 黄老板 火");
				CQ_sendPrivateMsg(ac, 416575098, "酸 黄老板 酸");
			}
			else if (msg.msg == "酸 黄老板 酸") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "酸 黄老板 酸");
				CQ_sendPrivateMsg(ac, 416575098, "火 黄老板 火");
			}
			else if (msg.msg == "迫害黄老板") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "女装  黄老板  女装");
			}
			else if (msg.msg == "迫害") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "コウちゃん 女装！！");
			}
			else if (msg.msg == "女装") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Kou酱~~~~女装！！");
			}
			else if (msg.fromQQ == 416575098 && msg.msg == "艹") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "艹！黄老板 艹！");

			}
			else if (msg.fromQQ == 416575098 && msg.msg == "？") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "? Kou酱 ?");
			}
			else if (msg.fromQQ == 416575098 && msg.msg == "？？？") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "??? Kou酱 ???");
			}
			else if (msg.msg == "!sleep") {
				//CQ_setGroupBan(ac, msg.fromGroup, fromQQ, 12000);
				CQ_sendGroupMsg(ac, msg.fromGroup, "おやすみなさい、お主人様～");
			}

			/*
			
					#################### MC或者编程相关 ##############
			
																				*/


			else if (msg.msg == "!白名单申请") {
				//CQ_sendGroupMsg(ac, msg.fromGroup, "请私聊InkBot！发送你的ID");
				CQ_sendGroupMsg(ac, msg.fromGroup, "自动申请系统坏掉了(┬＿┬)！给我去填表，不写了，麻烦死了，https://docs.qq.com/form/fill/DUmVZekRqRGJUYVRp");
			}
			else if (msg.msg == "!github") { 
				CQ_sendGroupMsg(ac, msg.fromGroup, "主人写的代码太丑了，才不给你看呢。（傲娇）"); 
			}
			else if (msg.msg == "!简单整合包") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "喵(>^ω^<)？整合包下载地址： https://cola.sayobot.cn/inkcake/Minecraft%201.12.2%20IC2%20forge2768%20Shaders.zip");
				CQ_sendGroupMsg(ac, msg.fromGroup, "谢谢夜妈妈的云盘支持！");
			}



			/* 
			
								####  提醒  ###
			
																		*/
			else if (msg.msg == "糕姐" || msg.msg == "糕姐！") {
				CQ_sendPrivateMsg(ac, 982957484, "有人叫你！");
			}
		
		}
		else
		{
			ThreadBase::mSleep(10);
		}
	}
	return;
}

GroupMsgSub::GroupMsgSub()
{
	m_quit = false;
}

GroupMsgSub::~GroupMsgSub()
{
}

void GroupMsgSub::start()
{
	m_quit = false;
	ThreadBase::start();
}

void GroupMsgSub::quite()
{
	ThreadBase::quit();
	m_quit = true;
}


void GroupMsgSub::pushMsg(int32_t msgId, int64_t fromGroup, int64_t fromQQ, std::string msg)
{
	//如果缓存的消息大于100跳  则直接抛弃新到的消息
	if (m_groupMsgBuffer.size() < 100)
	{
		m_mutex.lock();
		m_groupMsgBuffer.push(GroupMsg(msgId, fromGroup, fromQQ, msg));
		m_mutex.unlock();
	}
}


