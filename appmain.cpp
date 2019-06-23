#pragma once
/*
* CoolQ Demo for VC++ 
* Api Version 9
* Written by Coxxs & Thanks for the help of orzFly
*/

#include "stdafx.h"
#include "string.h"
#include <iostream>
#include "cqp.h"
#include "appmain.h" //应用AppID等信息，请正确填写，否则酷Q可能无法加载
#include "MsgSub.h"
#include "TransactionManagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define random(x) (rand()%x)
using namespace std;

int ac = -1; //AuthCode 调用酷Q的方法时需要用到
bool enabled = false;


GroupMsgSub * groupMsgSub = TransactionManagement::getInstance()->getGroupMsgSubInstance();

/*


*/
bool inkSE_seekXiaoTongMiao(const char *msg, int64_t fromQQ) {
	if (fromQQ != 3020019848) {
		return false;
	}
	for (int TIP = 0; TIP < strlen(msg); TIP++) {
		if ('D' == msg[TIP] && 'D' == msg[TIP + 1]) {
			return true;
		}
		else return false;
	}



}

//#递归暴力搜索算法
//#用于检测AC码是否为19198(10)，实现功能为切换MsgSub启用/关闭
//*const char *msg ——消息内容
//
bool inkSE_authCode_toggleMsgSub(const char *msg) {
	bool flag1 = false;
	bool flag2 = false;

	for (int TIP = 0; TIP < strlen(msg); TIP++) {

		if ('A' == msg[TIP])
			if ('C' == msg[TIP + 1])
				if ('=' == msg[TIP + 2]) {
					flag1 = true;
				}

		if ('1' == msg[TIP])
			if ('9' == msg[TIP + 1])
				if ('1' == msg[TIP + 2])
					if ('9' == msg[TIP + 3])
						if ('8' == msg[TIP + 4])
							if ('1' == msg[TIP + 5])
							{
								flag2 = true;
							}



	}

	if (flag1 == true && flag2 == true) {
		flag1 = false;
		flag2 = false;

		return true;
	}
	else
		return false;



}


bool inkSE_authCode_shutdownApp(const char *msg) {
	bool flag1 = false;
	bool flag2 = false;

	for (int TIP = 0; TIP < strlen(msg); TIP++) {

		if ('A' == msg[TIP])
			if ('C' == msg[TIP + 1])
				if ('=' == msg[TIP + 2]) {
					flag1 = true;
				}

		if ('s' == msg[TIP])
			if ('u' == msg[TIP + 1])
				if ('d' == msg[TIP + 2])
					if ('o' == msg[TIP + 3])
						if ('r' == msg[TIP + 5])
							if ('m' == msg[TIP + 6])
							{
								flag2 = true;
							}



	}

	if (flag1 == true && flag2 == true) {
		flag1 = false;
		flag2 = false;

		return true;
	}
	else
		return false;



}

bool inkSE_authCode_mon(const char *msg) {
	bool flag1 = false;
	bool flag2 = false;

	for (int TIP = 0; TIP < strlen(msg); TIP++) {

		if ('A' == msg[TIP])
			if ('C' == msg[TIP + 1])
				if ('=' == msg[TIP + 2]) {
					flag1 = true;
				}

		if ('1' == msg[TIP])
			if ('1' == msg[TIP + 1])
				if ('4' == msg[TIP + 2])
					if ('5' == msg[TIP + 3])
						if ('1' == msg[TIP + 4])
							if ('4' == msg[TIP + 5])
							{
								flag2 = true;
							}



	}

	if (flag1 == true && flag2 == true) {
		flag1 = false;
		flag2 = false;

		return true;
	}
	else
		return false;



}

bool inkSE_searchAT_bot(const char *msg) {
	bool flag1 = false;
	bool flag2 = false;

	for (int TIP = 0; TIP <= strlen(msg); TIP++) {

		//First Layer
		if ('C' == msg[TIP]) {
			if ('Q' == msg[TIP + 1]) {
				flag1 = true;
			}
		}


		//Second Layer
		if (flag1 == true) {
			if ('3' == msg[TIP]) {
				if ('2' == msg[TIP + 1]) {
					if ('0' == msg[TIP + 2]) {
						if ('6' == msg[TIP + 3]) {
							flag2 = true;
						}
					}
				}
			}

		}


	}

	if (flag1 == true && flag2 == true) {
		flag1 = false;
		flag2 = false;

		return true;
	}
	else
		return false;
}




/*



*/



/* 
* 返回应用的ApiVer、Appid，打包后将不会调用
*/
CQEVENT(const char*, AppInfo, 0)() {
	return CQAPPINFO;
}


/* 
* 接收应用AuthCode，酷Q读取应用信息后，如果接受该应用，将会调用这个函数并传递AuthCode。
* 不要在本函数处理其他任何代码，以免发生异常情况。如需执行初始化代码请在Startup事件中执行（Type=1001）。
*/
CQEVENT(int32_t, Initialize, 4)(int32_t AuthCode) {
	ac = AuthCode;
	return 0;
}


/*
* Type=1001 酷Q启动
* 无论本应用是否被启用，本函数都会在酷Q启动后执行一次，请在这里执行应用初始化代码。
* 如非必要，不建议在这里加载窗口。（可以添加菜单，让用户手动打开窗口）
*/
CQEVENT(int32_t, __eventStartup, 0)() {
	
	//启动消息处理线程
	groupMsgSub->start();
	return 0;
}


/*
* Type=1002 酷Q退出
* 无论本应用是否被启用，本函数都会在酷Q退出前执行一次，请在这里执行插件关闭代码。
* 本函数调用完毕后，酷Q将很快关闭，请不要再通过线程等方式执行其他代码。
*/
CQEVENT(int32_t, __eventExit, 0)() {
	//回收资源
	if (groupMsgSub!=nullptr)
	{
		groupMsgSub->quite();
	}
	return 0;
}

/*
* Type=1003 应用已被启用
* 当应用被启用后，将收到此事件。
* 如果酷Q载入时应用已被启用，则在_eventStartup(Type=1001,酷Q启动)被调用后，本函数也将被调用一次。
* 如非必要，不建议在这里加载窗口。（可以添加菜单，让用户手动打开窗口）
*/
CQEVENT(int32_t, __eventEnable, 0)() {
	enabled = true;
	return 0;
}


/*
* Type=1004 应用将被停用
* 当应用被停用前，将收到此事件。
* 如果酷Q载入时应用已被停用，则本函数*不会*被调用。
* 无论本应用是否被启用，酷Q关闭前本函数都*不会*被调用。
*/
CQEVENT(int32_t, __eventDisable, 0)() {
	enabled = false;
	return 0;
}


/*
* Type=21 私聊消息
* subType 子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
*/
CQEVENT(int32_t, __eventPrivateMsg, 24)(int32_t subType, int32_t msgId, int64_t fromQQ, const char *msg, int32_t font) {

	//如果要回复消息，请调用酷Q方法发送，并且这里 return EVENT_BLOCK - 截断本条消息，不再继续处理  注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
	//如果不回复消息，交由之后的应用/过滤器处理，这里 return EVENT_IGNORE - 忽略本条消息
	return EVENT_IGNORE;
}


/*
* Type=2 群消息
*/
CQEVENT(int32_t, __eventGroupMsg, 36)(int32_t subType, int32_t msgId, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font) {
	

	if (fromQQ == 3020019848) {
		int Pick2;
		srand(time(NULL));
		Pick2 = random(2);
		if (Pick2 == 1){
			if (msg == "摸头会长不高的喵！") {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848]没事，长不高才可爱，我来娶你。");
				return EVENT_BLOCK;
			}
			else if (msg == "别乱摸啦喵！……") {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848] 我也要摸摸你，");
				return EVENT_BLOCK;
			}
			else if (msg == "摸头会长不高的喵！") {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848] 别摸小桐喵！有事冲我来！");
				return EVENT_BLOCK;
			}
			else if (msg == "别乱摸喵，恶心喵！") {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848] 被老婆讨厌了，呜呜呜");
				return EVENT_BLOCK;
			}

			else return EVENT_IGNORE;
		}
	}
	if (inkSE_seekXiaoTongMiao(msg, fromQQ)) {
		CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848] 虽然你的主人是DD，你爱我吗？");
		return EVENT_BLOCK;
	}

	if (inkSE_searchAT_bot(msg) == true) {
		long long pickImage = 0;

		srand(time(0));
		pickImage = (rand()%7);
		
		switch (pickImage) {
			case 1:
			{
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:image,file=shiori_1.jpg]");
				break;

			}
			case 2:
			{
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:image,file=qua_1.jpg]");
				break;

			}
			case 3:
			{
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:image,file=serena_1.jpg]");
				break;

			}
			case 4:
			{
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:image,file=1.jpg]");
				break;

			}
			case 5: {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:image,file=shiori0.jpg]");
				break;
			}
			default:{
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:image,file=shiori7.jpg]");
			}

		}

		return EVENT_BLOCK;

	}

	//AC code from me;
	if (inkSE_searchAT_bot(msg) && fromQQ == 982957484) {

		if (inkSE_authCode_mon(msg) == true) {
			CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=982957484]AC代码已确认，请傻逼主人为自己写下的命令负责；正在备份服务器...(仅用于测试，不会真的执行)");
			/*


			*/
			CQ_sendGroupMsg(ac, fromGroup, "已强制关闭服务器。(仅用于测试，不会真的执行)");
			return EVENT_BLOCK;

		}
		else if (inkSE_authCode_shutdownApp(msg) == true) {
			 CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=982957484] 你他妈脑残吧，自己都没写完。还想关掉我？？");
			 return EVENT_BLOCK;
		}
	}
	

	groupMsgSub->pushMsg(msgId, fromGroup, fromQQ, msg);//抛入消息
	
	return EVENT_IGNORE; //关于返回值说明, 见“_eventPrivateMsg”函数
}


/*
* Type=301 请求-好友添加
* msg 附言
* responseFlag 反馈标识(处理请求用)
*/
CQEVENT(int32_t, __eventRequest_AddFriend, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, const char *responseFlag) {

	CQ_setFriendAddRequest(ac, responseFlag, REQUEST_ALLOW, "");

	return EVENT_IGNORE; //关于返回值说明, 见“_eventPrivateMsg”函数
}


/*
* Type=302 请求-群添加
* subType 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
* msg 附言
* responseFlag 反馈标识(处理请求用)
*/
CQEVENT(int32_t, __eventRequest_AddGroup, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, const char *responseFlag) {
	int LEN;
	LEN = strlen(msg);
	if (fromGroup == 789434274) {
		if (LEN <= 5) {
			CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPADD, REQUEST_DENY, "");
			LEN = -1;
			return EVENT_BLOCK;
		}
		else {
			return EVENT_IGNORE;
		}
	}

	if (fromGroup == 414752793) {
		CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPADD, REQUEST_ALLOW, "");
		return EVENT_BLOCK;
	}
	else return EVENT_IGNORE;
}


CQEVENT(int32_t, __eventSystem_GroupMemberIncrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	
	if (fromGroup == 982711563) {
		int pik;
		srand(time(0));
		pik = random(7);
		
		switch (pik) {
			case 1: {
				CQ_sendGroupMsg(ac, fromGroup, "欢迎进群， DD开始有丝分裂了。");
				break;
			}
			case 2: {
				CQ_sendGroupMsg(ac, fromGroup, "欢迎加入，玩音游请加414752793");
				break;
			}
			case 3: {
				CQ_sendGroupMsg(ac, fromGroup, "歡迎加入， 玩MC請加765455518");
				break;
			}
			case 4: {
				CQ_sendGroupMsg(ac, fromGroup, "人少的群在隔壁，群号764640926");
				break;
			}
			case 5: {
				CQ_sendGroupMsg(ac, fromGroup, "欢迎入群，想要建设cocomi王国(MC)加群765455518");
				break;
			}
			default: {
				CQ_sendGroupMsg(ac, fromGroup, "欢迎入群，想要参与烤肉请加入843096717");
			}
		}
		return EVENT_BLOCK;
		
	}
	if (fromGroup == 414752793)
	{
		CQ_sendGroupMsg(ac, 414752793, "欢迎来到inkCake的后宫（大雾）");
		//CQ_sendGroupMsg(ac, 414752793, "主人你个变态（超大声！）");
		return EVENT_BLOCK;
	}
	if (fromGroup == 789434274) {

		CQ_sendGroupMsg(ac, 789434274, "欢迎加入二刺螈（雾）百合控聚集交流地，在这里你甚至可以讨论各种百合作品（大雾）。进群后请看公告群规w");
		return EVENT_BLOCK;
	}
	
	
	return EVENT_IGNORE; //关于返回值说明, 见“_eventPrivateMsg”函数
}

CQEVENT(int32_t, __eventSystem_GroupMemberDecrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	CQ_sendGroupMsg(ac, fromGroup, "本群消失人口+1");


	return EVENT_BLOCK; //关于返回值说明, 见“_eventPrivateMsg”函数
}