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
#include "appmain.h" //Ӧ��AppID����Ϣ������ȷ��д�������Q�����޷�����
#include "MsgSub.h"
#include "TransactionManagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define random(x) (rand()%x)
using namespace std;

int ac = -1; //AuthCode ���ÿ�Q�ķ���ʱ��Ҫ�õ�
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

//#�ݹ鱩�������㷨
//#���ڼ��AC���Ƿ�Ϊ19198(10)��ʵ�ֹ���Ϊ�л�MsgSub����/�ر�
//*const char *msg ������Ϣ����
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
* ����Ӧ�õ�ApiVer��Appid������󽫲������
*/
CQEVENT(const char*, AppInfo, 0)() {
	return CQAPPINFO;
}


/* 
* ����Ӧ��AuthCode����Q��ȡӦ����Ϣ��������ܸ�Ӧ�ã���������������������AuthCode��
* ��Ҫ�ڱ��������������κδ��룬���ⷢ���쳣���������ִ�г�ʼ����������Startup�¼���ִ�У�Type=1001����
*/
CQEVENT(int32_t, Initialize, 4)(int32_t AuthCode) {
	ac = AuthCode;
	return 0;
}


/*
* Type=1001 ��Q����
* ���۱�Ӧ���Ƿ����ã������������ڿ�Q������ִ��һ�Σ���������ִ��Ӧ�ó�ʼ�����롣
* ��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�
*/
CQEVENT(int32_t, __eventStartup, 0)() {
	
	//������Ϣ�����߳�
	groupMsgSub->start();
	return 0;
}


/*
* Type=1002 ��Q�˳�
* ���۱�Ӧ���Ƿ����ã������������ڿ�Q�˳�ǰִ��һ�Σ���������ִ�в���رմ��롣
* ������������Ϻ󣬿�Q���ܿ�رգ��벻Ҫ��ͨ���̵߳ȷ�ʽִ���������롣
*/
CQEVENT(int32_t, __eventExit, 0)() {
	//������Դ
	if (groupMsgSub!=nullptr)
	{
		groupMsgSub->quite();
	}
	return 0;
}

/*
* Type=1003 Ӧ���ѱ�����
* ��Ӧ�ñ����ú󣬽��յ����¼���
* �����Q����ʱӦ���ѱ����ã�����_eventStartup(Type=1001,��Q����)�����ú󣬱�����Ҳ��������һ�Ρ�
* ��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�
*/
CQEVENT(int32_t, __eventEnable, 0)() {
	enabled = true;
	return 0;
}


/*
* Type=1004 Ӧ�ý���ͣ��
* ��Ӧ�ñ�ͣ��ǰ�����յ����¼���
* �����Q����ʱӦ���ѱ�ͣ�ã��򱾺���*����*�����á�
* ���۱�Ӧ���Ƿ����ã���Q�ر�ǰ��������*����*�����á�
*/
CQEVENT(int32_t, __eventDisable, 0)() {
	enabled = false;
	return 0;
}


/*
* Type=21 ˽����Ϣ
* subType �����ͣ�11/���Ժ��� 1/��������״̬ 2/����Ⱥ 3/����������
*/
CQEVENT(int32_t, __eventPrivateMsg, 24)(int32_t subType, int32_t msgId, int64_t fromQQ, const char *msg, int32_t font) {

	//���Ҫ�ظ���Ϣ������ÿ�Q�������ͣ��������� return EVENT_BLOCK - �ضϱ�����Ϣ�����ټ�������  ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
	//������ظ���Ϣ������֮���Ӧ��/�������������� return EVENT_IGNORE - ���Ա�����Ϣ
	return EVENT_IGNORE;
}


/*
* Type=2 Ⱥ��Ϣ
*/
CQEVENT(int32_t, __eventGroupMsg, 36)(int32_t subType, int32_t msgId, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font) {
	

	if (fromQQ == 3020019848) {
		int Pick2;
		srand(time(NULL));
		Pick2 = random(2);
		if (Pick2 == 1){
			if (msg == "��ͷ�᳤���ߵ�����") {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848]û�£������߲ſɰ�������Ȣ�㡣");
				return EVENT_BLOCK;
			}
			else if (msg == "����������������") {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848] ��ҲҪ�����㣬");
				return EVENT_BLOCK;
			}
			else if (msg == "��ͷ�᳤���ߵ�����") {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848] ����Сͩ�������³�������");
				return EVENT_BLOCK;
			}
			else if (msg == "������������������") {
				CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848] �����������ˣ�������");
				return EVENT_BLOCK;
			}

			else return EVENT_IGNORE;
		}
	}
	if (inkSE_seekXiaoTongMiao(msg, fromQQ)) {
		CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=3020019848] ��Ȼ���������DD���㰮����");
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
			CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=982957484]AC������ȷ�ϣ���ɵ������Ϊ�Լ�д�µ���������ڱ��ݷ�����...(�����ڲ��ԣ��������ִ��)");
			/*


			*/
			CQ_sendGroupMsg(ac, fromGroup, "��ǿ�ƹرշ�������(�����ڲ��ԣ��������ִ��)");
			return EVENT_BLOCK;

		}
		else if (inkSE_authCode_shutdownApp(msg) == true) {
			 CQ_sendGroupMsg(ac, fromGroup, "[CQ:at,qq=982957484] �������Բаɣ��Լ���ûд�ꡣ����ص��ң���");
			 return EVENT_BLOCK;
		}
	}
	

	groupMsgSub->pushMsg(msgId, fromGroup, fromQQ, msg);//������Ϣ
	
	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=301 ����-�������
* msg ����
* responseFlag ������ʶ(����������)
*/
CQEVENT(int32_t, __eventRequest_AddFriend, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, const char *responseFlag) {

	CQ_setFriendAddRequest(ac, responseFlag, REQUEST_ALLOW, "");

	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}


/*
* Type=302 ����-Ⱥ���
* subType �����ͣ�1/����������Ⱥ 2/�Լ�(����¼��)������Ⱥ
* msg ����
* responseFlag ������ʶ(����������)
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
				CQ_sendGroupMsg(ac, fromGroup, "��ӭ��Ⱥ�� DD��ʼ��˿�����ˡ�");
				break;
			}
			case 2: {
				CQ_sendGroupMsg(ac, fromGroup, "��ӭ���룬���������414752793");
				break;
			}
			case 3: {
				CQ_sendGroupMsg(ac, fromGroup, "�gӭ���룬 ��MCՈ��765455518");
				break;
			}
			case 4: {
				CQ_sendGroupMsg(ac, fromGroup, "���ٵ�Ⱥ�ڸ��ڣ�Ⱥ��764640926");
				break;
			}
			case 5: {
				CQ_sendGroupMsg(ac, fromGroup, "��ӭ��Ⱥ����Ҫ����cocomi����(MC)��Ⱥ765455518");
				break;
			}
			default: {
				CQ_sendGroupMsg(ac, fromGroup, "��ӭ��Ⱥ����Ҫ���뿾�������843096717");
			}
		}
		return EVENT_BLOCK;
		
	}
	if (fromGroup == 414752793)
	{
		CQ_sendGroupMsg(ac, 414752793, "��ӭ����inkCake�ĺ󹬣�����");
		//CQ_sendGroupMsg(ac, 414752793, "���������̬������������");
		return EVENT_BLOCK;
	}
	if (fromGroup == 789434274) {

		CQ_sendGroupMsg(ac, 789434274, "��ӭ�������󢣨���ٺϿؾۼ������أ��������������������۸��ְٺ���Ʒ����������Ⱥ���뿴����Ⱥ��w");
		return EVENT_BLOCK;
	}
	
	
	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}

CQEVENT(int32_t, __eventSystem_GroupMemberDecrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {
	CQ_sendGroupMsg(ac, fromGroup, "��Ⱥ��ʧ�˿�+1");


	return EVENT_BLOCK; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}