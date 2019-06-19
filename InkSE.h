#pragma once
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

//const long long AuthCode_InkCake = 114514;

bool inkSE_authCode_restartMsgSub(const char *msg) {
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

		if('1' == msg[TIP])
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