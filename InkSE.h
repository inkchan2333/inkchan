#pragma once
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdint.h>
using namespace std;


//#ʹ��String������
//#���ڼ��AC���Ƿ�Ϊ1919810��ʵ��Ϊ�л�MsgSub����/�ر�
//*string msg ���� ��Ϣ����
//

bool inkSE_seekXiaoTongMiao(const char *msg,int64_t fromQQ) {
	if (fromQQ != 3020019848) {
		return false;
	}
	for (int TIP = 0; TIP < strlen(msg); TIP++) {
		if ('D' == msg[TIP] && 'D' == msg[TIP+1]) {
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

		if('A' == msg[TIP])
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