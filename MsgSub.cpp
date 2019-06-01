#include "MsgSub.h"
#include "cqp.h"
#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)
#include <string.h>
//导入全局变量 ac   在appmain.h 中定义
extern int ac;

/*struct Group {
	//bool SeTsuFunction_Active;
	//找不到色图！！色图功能没了！
	
	bool OsuGroup;
	bool AnimeGroup;

};*/

/*bool OsuGroups(msg.fromGroup) {

}
*/
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
		
			/*				通	用				*/


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
			
					###动漫之家漫画推荐###
			
													*/

			if (msg.msg == "漫画推荐") {
			//PICK
			int pick = 0;
			pick = random(10);
			switch (pick) {
				case 1:{
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《Girl Friends》\n 已完结");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(来自B漫)Address：https://manga.bilibili.com/m/detail/mc24791");
					break;
				}
				case 2: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《惊爆草莓》，作者：公野樱子");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(来自动漫之家)Address：https://manhua.dmzj.com/jbcm/");
					break;
				}
				case 3: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《圣母在上》，作者：长沢智");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(来自动漫之家)Address：https://manhua.dmzj.com/smzsmlydnw/");
					break;
				}
				case 4: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《甜蜜X密友》，作者：桐原いづみ");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(来自动漫之家)Address：https://manhua.dmzj.com/tianmixmiyou/");
					break;
				}
				case 5: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《初恋姐妹》\n 作者：东云水生");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(来自动漫之家)Address：https://manhua.dmzj.com/chulianjiemei/");
					break;
				}
				case 6: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《月夜的奶酪》\n 作者：てぃんくる");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(来自动漫之家)Address：https://manhua.dmzj.com/yueyedenailao/");
					break;
				}
				case 7: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《Happy Sugar Life》\N 作者：键空老贼NMSL");
					CQ_sendGroupMsg(ac, msg.fromGroup, "Address：没有！自己去百度贴吧找资源！！！");
					break;
				}
				case 8: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《轻声密语》\n 作者：池田学志");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(来自动漫之家)Address：https://manhua.dmzj.com/qingshengmiyu/");
					break;
				}
				case 9: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "给你推荐的：《为了让学姐鼓起干劲，我决定献出我自己》\n 作者：佐仓吉太");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(来自B漫)Address：https://manga.bilibili.com/m/detail/mc25905");
					break;
				}
				default:{
					CQ_sendGroupMsg(ac, msg.fromGroup, "本Bot不想给你推荐任何漫画!!!");
				
				}
			}


			}

		/*
				##############用于迫害##############			
		
																					*/

			//Dalou彩蛋
			if (msg.msg == "!hello" && msg.fromQQ == 1061566571) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "响应测试失败，嘤嘤嘤");
				 

			}

			if (msg.fromGroup == 982711563) {
				if (msg.msg == "火 黄老板 火") {
					CQ_sendGroupMsg(ac, msg.fromGroup, "火 黄老板 火");
					 
				}
				else if (msg.msg == "酸 黄老板 酸") {
					CQ_sendGroupMsg(ac, msg.fromGroup, "酸 黄老板 酸");
					 
				}
				else if (msg.msg == "迫害黄老板") {
					int PICKS;
					PICKS = random(4);

					switch (PICKS){
					 case 1: {
						CQ_sendGroupMsg(ac, msg.fromGroup, "女装  黄老板  女装");
						break;
					 }case 2: {
						CQ_sendGroupMsg(ac, msg.fromGroup, "コウちゃん 女装！！");
						break;
					 }case 3: {
						CQ_sendGroupMsg(ac, msg.fromGroup, "Kou酱~~~~女装！！");
						break;

					 }
					 default:
					 {
						CQ_sendGroupMsg(ac, msg.fromGroup, "黄老板快女装！"); 
					 }
					}      
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
			}

			/*else */ if (msg.msg == "!sleep") {
				//CQ_setGroupBan(ac, msg.fromGroup, fromQQ, 12000);
				CQ_sendGroupMsg(ac, msg.fromGroup, "おやすみなさい、お主人様～");
				 
			}

			else if (msg.msg == "!白名单申请") {
				//CQ_sendGroupMsg(ac, msg.fromGroup, "请私聊InkBot！发送你的ID");
				CQ_sendGroupMsg(ac, msg.fromGroup, "自动申请系统坏掉了(┬＿┬)！给我去填表，不写了，麻烦死了，https://docs.qq.com/form/fill/DUmVZekRqRGJUYVRp");
				 
			}
			else if (msg.msg == "!github") { 
				CQ_sendGroupMsg(ac, msg.fromGroup, "https://github.com/inkchan2333/inkchan"); 
				 
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


