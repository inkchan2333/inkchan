#include "MsgSub.h"
#include "cqp.h"
#include <string.h>
//擬秘畠蕉延楚 ac   壓appmain.h 嶄協吶
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
				CQ_sendGroupMsg(ac, msg.fromGroup, "�贄Σ睚坡氷Γ�c++爺和及匯。");
			}
			else if (msg.msg == "寵寵弌軌呉") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "wwwwww");
			}
			else if (msg.msg == "弌軌呉" && msg.fromQQ == 982957484) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "麼繁挫��書爺匆仭逗阻");
			}
			else if (msg.msg == "!stats me" && msg.fromQQ == 982957484) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "熏...麼繁��壑孀音欺低議Stats椿 QAQ");
			}
			else if (msg.msg == "!stats me") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Stats音�誂漢烹�枠公Mc斑斑揃。");
			}


		/*
				#######################喘噐独墾仔析医議##############			
		
																					*/

			
			else if (msg.msg == "諮 仔析医 諮") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "諮 仔析医 諮");
				CQ_sendPrivateMsg(ac, 416575098, "磨 仔析医 磨");
			}
			else if (msg.msg == "磨 仔析医 磨") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "磨 仔析医 磨");
				CQ_sendPrivateMsg(ac, 416575098, "諮 仔析医 諮");
			}
			else if (msg.msg == "独墾仔析医") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "溺廾  仔析医  溺廾");
			}
			else if (msg.msg == "独墾") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "コウちゃん 溺廾�。�");
			}
			else if (msg.msg == "溺廾") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Kou輯~~~~溺廾�。�");
			}
			else if (msg.fromQQ == 416575098 && msg.msg == "楹") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "楹�〇得楼� 楹��");

			}
			else if (msg.fromQQ == 416575098 && msg.msg == "��") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "? Kou輯 ?");
			}
			else if (msg.fromQQ == 416575098 && msg.msg == "�殖殖�") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "??? Kou輯 ???");
			}
			else if (msg.msg == "!sleep") {
				//CQ_setGroupBan(ac, msg.fromGroup, fromQQ, 12000);
				CQ_sendGroupMsg(ac, msg.fromGroup, "おやすみなさい、お麼繁��゛");
			}

			/*
			
					#################### MC賜宀園殻�犢� ##############
			
																				*/


			else if (msg.msg == "!易兆汽賦萩") {
				//CQ_sendGroupMsg(ac, msg.fromGroup, "萩暴祖InkBot�〃∨幼禝�ID");
				CQ_sendGroupMsg(ac, msg.fromGroup, "徭強賦萩狼由撒渠阻(�丕潯�)�仝�厘肇野燕��音亟阻��醍軍棒阻��https://docs.qq.com/form/fill/DUmVZekRqRGJUYVRp");
			}
			else if (msg.msg == "!github") { 
				CQ_sendGroupMsg(ac, msg.fromGroup, "麼繁亟議旗鷹湊鞄阻��嘉音公低心椿。�┛曾殖�"); 
			}
			else if (msg.msg == "!酒汽屁栽淫") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "燉(>^ω^<)�腎�栽淫和墮仇峽�� https://cola.sayobot.cn/inkcake/Minecraft%201.12.2%20IC2%20forge2768%20Shaders.zip");
				CQ_sendGroupMsg(ac, msg.fromGroup, "仍仍匚第第議堝徒屶隔��");
			}



			/* 
			
								####  戻佰  ###
			
																		*/
			else if (msg.msg == "呉純" || msg.msg == "呉純��") {
				CQ_sendPrivateMsg(ac, 982957484, "嗤繁出低��");
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
	//泌惚産贋議��連寄噐100柳  夸岷俊砺虹仟欺議��連
	if (m_groupMsgBuffer.size() < 100)
	{
		m_mutex.lock();
		m_groupMsgBuffer.push(GroupMsg(msgId, fromGroup, fromQQ, msg));
		m_mutex.unlock();
	}
}


