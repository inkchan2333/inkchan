#include "MsgSub.h"
#include "cqp.h"
#include<stdio.h>
#include<stdlib.h>
#define random(x) (rand()%x)
#include <string.h>
//����ȫ�ֱ��� ac   ��appmain.h �ж���
extern int ac;

/*struct Group {
	//bool SeTsuFunction_Active;
	//�Ҳ���ɫͼ����ɫͼ����û�ˣ�
	
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
		
			/*				ͨ	��				*/


			if (msg.msg=="test!!!")
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��Ӧ���Գɹ���c++���µ�һ��");
				 
			}
			else if (msg.msg == "����С����") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "wwwwww");
				 
			}
			else if (msg.msg == "С����" && msg.fromQQ == 982957484) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "���˺ã�����Ҳ������");
				 
			}
			else if (msg.msg == "!stats me" && msg.fromQQ == 982957484) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��...���ˣ����Ҳ������Stats�� QAQ");
				 
			}
			else if (msg.msg == "!stats me") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Stats����д�ˣ��ȸ�Mc����·��");
				 
			}

			/* 
			
					###����֮�������Ƽ�###
			
													*/

			if (msg.msg == "�����Ƽ�") {
			//PICK
			int pick = 0;
			pick = random(10);
			switch (pick) {
				case 1:{
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ���Girl Friends��\n �����");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(����B��)Address��https://manga.bilibili.com/m/detail/mc24791");
					break;
				}
				case 2: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ���������ݮ�������ߣ���Ұӣ��");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(���Զ���֮��)Address��https://manhua.dmzj.com/jbcm/");
					break;
				}
				case 3: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ���ʥĸ���ϡ������ߣ����g��");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(���Զ���֮��)Address��https://manhua.dmzj.com/smzsmlydnw/");
					break;
				}
				case 4: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ�������X���ѡ������ߣ�ͩԭ���Ť�");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(���Զ���֮��)Address��https://manhua.dmzj.com/tianmixmiyou/");
					break;
				}
				case 5: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ����������á�\n ���ߣ�����ˮ��");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(���Զ���֮��)Address��https://manhua.dmzj.com/chulianjiemei/");
					break;
				}
				case 6: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ�����ҹ�����ҡ�\n ���ߣ��Ƥ��󤯤�");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(���Զ���֮��)Address��https://manhua.dmzj.com/yueyedenailao/");
					break;
				}
				case 7: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ���Happy Sugar Life��\N ���ߣ���������NMSL");
					CQ_sendGroupMsg(ac, msg.fromGroup, "Address��û�У��Լ�ȥ�ٶ���������Դ������");
					break;
				}
				case 8: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ����������\n ���ߣ�����ѧ־");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(���Զ���֮��)Address��https://manhua.dmzj.com/qingshengmiyu/");
					break;
				}
				case 9: {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�����Ƽ��ģ���Ϊ����ѧ�����ɾ����Ҿ����׳����Լ���\n ���ߣ����ּ�̫");
					CQ_sendGroupMsg(ac, msg.fromGroup, "(����B��)Address��https://manga.bilibili.com/m/detail/mc25905");
					break;
				}
				default:{
					CQ_sendGroupMsg(ac, msg.fromGroup, "��Bot��������Ƽ��κ�����!!!");
				
				}
			}


			}

		/*
				##############�����Ⱥ�##############			
		
																					*/

			//Dalou�ʵ�
			if (msg.msg == "!hello" && msg.fromQQ == 1061566571) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��Ӧ����ʧ�ܣ�������");
				 

			}

			if (msg.fromGroup == 982711563) {
				if (msg.msg == "�� ���ϰ� ��") {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�� ���ϰ� ��");
					 
				}
				else if (msg.msg == "�� ���ϰ� ��") {
					CQ_sendGroupMsg(ac, msg.fromGroup, "�� ���ϰ� ��");
					 
				}
				else if (msg.msg == "�Ⱥ����ϰ�") {
					int PICKS;
					PICKS = random(4);

					switch (PICKS){
					 case 1: {
						CQ_sendGroupMsg(ac, msg.fromGroup, "Ůװ  ���ϰ�  Ůװ");
						break;
					 }case 2: {
						CQ_sendGroupMsg(ac, msg.fromGroup, "��������� Ůװ����");
						break;
					 }case 3: {
						CQ_sendGroupMsg(ac, msg.fromGroup, "Kou��~~~~Ůװ����");
						break;

					 }
					 default:
					 {
						CQ_sendGroupMsg(ac, msg.fromGroup, "���ϰ��Ůװ��"); 
					 }
					}      
				}
				else if (msg.fromQQ == 416575098 && msg.msg == "ܳ") {
					CQ_sendGroupMsg(ac, msg.fromGroup, "ܳ�����ϰ� ܳ��");
					 
				}
				else if (msg.fromQQ == 416575098 && msg.msg == "��") {
					CQ_sendGroupMsg(ac, msg.fromGroup, "? Kou�� ?");
					 
				}
				else if (msg.fromQQ == 416575098 && msg.msg == "������") {
					CQ_sendGroupMsg(ac, msg.fromGroup, "??? Kou�� ???");
					 
				}
			}

			/*else */ if (msg.msg == "!sleep") {
				//CQ_setGroupBan(ac, msg.fromGroup, fromQQ, 12000);
				CQ_sendGroupMsg(ac, msg.fromGroup, "���䤹�ߤʤ����������˘���");
				 
			}

			else if (msg.msg == "!����������") {
				//CQ_sendGroupMsg(ac, msg.fromGroup, "��˽��InkBot���������ID");
				CQ_sendGroupMsg(ac, msg.fromGroup, "�Զ�����ϵͳ������(�Уߩ�)������ȥ�����д�ˣ��鷳���ˣ�https://docs.qq.com/form/fill/DUmVZekRqRGJUYVRp");
				 
			}
			else if (msg.msg == "!github") { 
				CQ_sendGroupMsg(ac, msg.fromGroup, "https://github.com/inkchan2333/inkchan"); 
				 
			}
			else if (msg.msg == "!�����ϰ�") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��(>^��^<)�����ϰ����ص�ַ�� https://cola.sayobot.cn/inkcake/Minecraft%201.12.2%20IC2%20forge2768%20Shaders.zip");
				CQ_sendGroupMsg(ac, msg.fromGroup, "ллҹ���������֧�֣�");
				 
			}



			/* 
			
								####  ����  ###
			
																		*/
			else if (msg.msg == "���" || msg.msg == "��㣡") {
				CQ_sendPrivateMsg(ac, 982957484, "���˽��㣡");
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


