#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct Room {
	string num;//������
	int price;//�۸�Ԫ/�죩
	string type;//����
	vector<string> DayIn;//��Ԥ������סʱ��
	vector<string> DayOut;//��Ԥ�����˷�ʱ��
};
struct Hotel {
	string num;//�Ƶ���
	string name;//�Ƶ�����
	string city;//���ڳ���
	string location;//λ��
	vector<Room> RoomInHotel;//��������
	Hotel *next;
};
struct Order {
	int OrderNum;//�������
	string HotelName;//�Ƶ���Ϣ
	string City;
	string Location;
	string DayIn;//������ס����
	string DayOut;//�˷�����
	string RoomType;
	string RoomNum;
	int Price;//�ܼ۸�
};
struct Comment {
	string HotelNum;//�Ƶ���
	vector<string> Com;//����
};
struct Location {
	string LocaName;
	vector<Hotel*>HotelInLoca;
};
struct City {
	string CityName;
	vector<Location> LocaHead;
};

#endif // HEADER_H