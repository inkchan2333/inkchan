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
#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)
using namespace std;

int ac = -1; //AuthCode 调用酷Q的方法时需要用到
bool enabled = false;


GroupMsgSub * groupMsgSub = TransactionManagement::getInstance()->getGroupMsgSubInstance();

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
	if (LEN <= 4 && fromGroup == 789434274) {
		CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPADD, REQUEST_DENY,"答案字数不够");
		CQ_sendGroupMsg(ac, 772753419, "已拒绝此人加群，理由：字符参数不够，返回值为false");
		LEN = -1;
		return EVENT_BLOCK;
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
		pik = random(4);
		
		switch (pik) {
			case 1: {
				CQ_sendGroupMsg(ac, fromGroup, "欢迎加入cocomi王国！ DD开始有丝分裂了。");
				break;
			}
				
			case 2: {
				CQ_sendGroupMsg(ac, fromGroup, "欢迎加入cocomi王国！ DD斩首。");
				break;
			}

			case 3: {
				CQ_sendGroupMsg(ac, fromGroup,"欢迎加入cocomi王国，想玩音游请进414752793");
				break;
			
			}
			default: {
				CQ_sendGroupMsg(ac, fromGroup, "欢迎加入cocomi王国！ 黄老板今天女装了吗");
			}

		}
		return EVENT_BLOCK;
		
	}
	if (fromGroup == 495093070) {
		CQ_sendGroupMsg(ac, 495093070, "我也不知道这个群是干嘛的，总之欢迎你的加入，想玩音游请进414752793");
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
