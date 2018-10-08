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
	string num;//房间编号
	int price;//价格（元/天）
	string type;//类型
	vector<string> DayIn;//被预定的入住时间
	vector<string> DayOut;//被预定的退房时间
};
struct Hotel {
	string num;//酒店编号
	string name;//酒店名字
	string city;//所在城市
	string location;//位置
	vector<Room> RoomInHotel;//房间数组
	Hotel *next;
};
struct Order {
	int OrderNum;//订单编号
	string HotelName;//酒店信息
	string City;
	string Location;
	string DayIn;//订单入住日期
	string DayOut;//退房日期
	string RoomType;
	string RoomNum;
	int Price;//总价格
};
struct Comment {
	string HotelNum;//酒店编号
	vector<string> Com;//评价
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