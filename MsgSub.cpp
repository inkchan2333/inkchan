#include "MsgSub.h"
#include "cqp.h"
#include<stdio.h>
#include<stdlib.h>
#include <ctime>
#include <Windows.h>
#include <windows.data.json.h>
#include <windows.web.h>
#include <cstring>


#define random(x) (rand()%x)

#include <string.h>
//����ȫ�ֱ��� ac   ��appmain.h �ж���


unsigned long long delay_omikuji;
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
			if (msg.msg == "!help mc") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Ŀǰ�������е��ǻ���sponge��1.12.2ԭ�������1.15.1����spigot�Ĵ������ip��ַ�ֱ�Ϊinkcake.sayobot.cn:25565��inkcake.sayobot.cn:23333");
			}
			else if (msg.msg == "С��������ɫͼ") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "�����裬��֪�����Ӳ��ܷ�ͼ��");
			}
			else if (msg.msg == "!faq Ѫè" || msg.msg == "Ѫè" || msg.msg == "site:Ѫè") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��ʲôѪè����Сҹѽ��https://osu.sayobot.cn");
			}
			else if (msg.msg == "mc:prism" || msg.msg == "mc:��ѯ") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "���⾵����ѯ�����https://www.mcbbs.net/thread-847818-1-1.html?tdsourcetag=s_pcqq_aiomsg ��Ӣ�ģ�https://forums.spongepowered.org/t/prism-official-thread-v3-0-beta/1137");
			}
			else if (msg.msg == "mc:latch" || msg.msg == "mc:����") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��latch���� https://www.mcbbs.net/thread-786357-1-1.html");
			}
			else if (msg.msg == "mc:forge" || msg.msg == "mc:api") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Forge��mc��һ��ģ��api���������е�mod��Ҫͨ��forge�Ž���ʹ�á�����С��ͼ�����岹����Optifine�������� http://files.minecraftforge.net/");
			}
			else if (msg.msg == "mc:optifine" || msg.msg == "mc:���岹��") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��OptifineHD���ֳ�Ϊ���岹�������ڼ����˹�Ӱ��shaders��mod��ǰ��API��forge https://optifine.net/downloads");
			}
			else if (msg.msg == "mc:register" || msg.msg == "mc:ע��") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "/register ��������룩 ���ظ�������룩�����μ����룬���Ǹ�㲻���ȡ���ݿ⡣");
			}
			else if (msg.msg == "mc:gf" || msg.msg == "mc:���") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "����MCbbs: https://www.mcbbs.net/thread-711313-1-1.html ԭ��ַ��https://forums.spongepowered.org/t/griefprevention-official-thread-1-8-9-1-10-2-1-11/1123");
			}
			else if (msg.msg == "mc:sponge") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "https://docs.spongepowered.org/stable/zh-CN/server/spongineer/commands.html");
			}
			else if (msg.msg == "site:���ɫͼ") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "����д���Լ��� https://api.lolicon.app/setu/view.php");
			}
			else if (msg.msg == "site:pp+") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "https://syrin.me/ ����osu chan��һ����վ����pp plus, �ϲ�ȥ��Ҹ��ݣ�");
			}
			else if (msg.msg == "site:pp") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��������ȫ��ppͼ��ַ https://grumd.github.io/osu-pps/#/osu/maps");
			}
			else if (msg.msg == "site:newpp") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "���㷨�ļ����ַ��https://newpp.stanr.info/");
			}
			else if (msg.msg == ".jrsc") {
				if (msg.fromQQ == 2047192802) {
					CQ_sendGroupMsg(ac, msg.fromGroup, "��Ҳ�����ʣ���Ҳ���ҽ�");
				}
				else {
					if (time(0) % 2 == 0) {
						CQ_sendGroupMsg(ac, msg.fromGroup, "����");
					}
					else {
						CQ_sendGroupMsg(ac, msg.fromGroup, "��");
					}
				}


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
	//����������Ϣ����100��  ��ֱ�������µ�����Ϣ
	if (m_groupMsgBuffer.size() < 100)
	{
		m_mutex.lock();
		m_groupMsgBuffer.push(GroupMsg(msgId, fromGroup, fromQQ, msg));
		m_mutex.unlock();
	}
}


