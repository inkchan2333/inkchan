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
#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)
using namespace std;

int ac = -1; //AuthCode ���ÿ�Q�ķ���ʱ��Ҫ�õ�
bool enabled = false;


GroupMsgSub * groupMsgSub = TransactionManagement::getInstance()->getGroupMsgSubInstance();

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
	if (LEN <= 4 && fromGroup == 789434274) {
		CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPADD, REQUEST_DENY,"����������");
		CQ_sendGroupMsg(ac, 772753419, "�Ѿܾ����˼�Ⱥ�����ɣ��ַ���������������ֵΪfalse");
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
	
	if (fromGroup == 982711563 || fromGroup == 764640926) {
		int pik;
		pik = random(3);
		
		switch (pik) {
			case 1: {
				
				CQ_sendGroupMsg(ac, fromGroup, "��ӭ����cocomi������ DD��ʼ��˿�����ˡ�");
			}
				
			case 2: {
				CQ_sendGroupMsg(ac, fromGroup, "��ӭ����cocomi������ DDն�ס�");
			}

			default: {
				CQ_sendGroupMsg(ac, fromGroup, "��ӭ����cocomi������ ���ϰ����Ůװ����");
			}

		}
		return EVENT_BLOCK;
		
	}
	if (fromGroup == 495093070) {
		CQ_sendGroupMsg(ac, 495093070, "��Ҳ��֪�����Ⱥ�Ǹ���ģ���֮��ӭ��ļ��룬�����������414752793");
		return EVENT_BLOCK;
	}
	if (fromGroup == 414752793)
	{
		CQ_sendGroupMsg(ac, 414752793, "��ӭ����inkCake�ĺ󹬣�����");
		CQ_sendGroupMsg(ac, 414752793, "���������̬������������");
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