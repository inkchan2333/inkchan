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
//导入全局变量 ac   在appmain.h 中定义


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
				CQ_sendGroupMsg(ac, msg.fromGroup, "目前正在运行的是基于sponge的1.12.2原版生存和1.15.1基于spigot的创造服。ip地址分别为inkcake.sayobot.cn:25565和inkcake.sayobot.cn:23333");
			}
			else if (msg.msg == "小蛋糕来点色图") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "吵你妈，不知道老子不能发图。");
			}
			else if (msg.msg == "!faq 血猫" || msg.msg == "血猫" || msg.msg == "site:血猫") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "用什么血猫，用小夜呀！https://osu.sayobot.cn");
			}
			else if (msg.msg == "mc:prism" || msg.msg == "mc:查询") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "【棱镜】查询插件：https://www.mcbbs.net/thread-847818-1-1.html?tdsourcetag=s_pcqq_aiomsg （英文）https://forums.spongepowered.org/t/prism-official-thread-v3-0-beta/1137");
			}
			else if (msg.msg == "mc:latch" || msg.msg == "mc:保护") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "【latch】： https://www.mcbbs.net/thread-786357-1-1.html");
			}
			else if (msg.msg == "mc:forge" || msg.msg == "mc:api") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Forge是mc的一个模组api，几乎所有的mod都要通过forge桥接来使用。例如小地图，高清补丁（Optifine），官网 http://files.minecraftforge.net/");
			}
			else if (msg.msg == "mc:optifine" || msg.msg == "mc:高清补丁") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "【OptifineHD】又称为高清补丁，现在集成了光影（shaders）mod，前置API是forge https://optifine.net/downloads");
			}
			else if (msg.msg == "mc:register" || msg.msg == "mc:注册") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "/register （你的密码） （重复你的密码），请牢记密码，弱智糕姐不会读取数据库。");
			}
			else if (msg.msg == "mc:gf" || msg.msg == "mc:领地") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "中文MCbbs: https://www.mcbbs.net/thread-711313-1-1.html 原地址：https://forums.spongepowered.org/t/griefprevention-official-thread-1-8-9-1-10-2-1-11/1123");
			}
			else if (msg.msg == "mc:sponge") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "https://docs.spongepowered.org/stable/zh-CN/server/spongineer/commands.html");
			}
			else if (msg.msg == "site:随机色图") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "懒得写，自己上 https://api.lolicon.app/setu/view.php");
			}
			else if (msg.msg == "site:pp+") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "https://syrin.me/ 除了osu chan另一个网站就是pp plus, 上不去请挂个梯！");
			}
			else if (msg.msg == "site:pp") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "世界上最全的pp图网址 https://grumd.github.io/osu-pps/#/osu/maps");
			}
			else if (msg.msg == "site:newpp") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "新算法的计算地址：https://newpp.stanr.info/");
			}
			else if (msg.msg == ".jrsc") {
				if (msg.fromQQ == 2047192802) {
					CQ_sendGroupMsg(ac, msg.fromGroup, "咱也不敢问，咱也不敢讲");
				}
				else {
					if (time(0) % 2 == 0) {
						CQ_sendGroupMsg(ac, msg.fromGroup, "不冲");
					}
					else {
						CQ_sendGroupMsg(ac, msg.fromGroup, "冲");
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
	//如果缓存的消息大于100跳  则直接抛弃新到的消息
	if (m_groupMsgBuffer.size() < 100)
	{
		m_mutex.lock();
		m_groupMsgBuffer.push(GroupMsg(msgId, fromGroup, fromQQ, msg));
		m_mutex.unlock();
	}
}


