#ifndef CUSTOMER_H
#define CUSTOMER_H

#include"Header.h"

//显示订单√
void OrderShow(vector<Order>OrderHead);	

//删除编号为num的订单√
void OrderCancel(vector<Order>&OrderHead, int OrderNum);	

//根据城市查找酒店√
void SearchHotel(string CityName, vector<City> CityHead, string location);

//查询该时段房间是否为空√
bool RoomAvailable(string DayIn, string DayOut, string num, Hotel *RoomInHotel);

//选择编号为num的房间，并将订单追加到订单数组√
void RoomBook(vector<Order>&OrderTemp, string num, string DayIn, string DayOut, Hotel *RoomInHotel, vector<Order>OrderHead);

//再在房间数组里该房间下挂上日期√
void RoomTag(string DayIn, string DayOut, string num, Hotel *&RoomInHotel);

//将酒店按城市位置进行分类√
void CitySort(vector<City> &CityHead, Hotel *HotelHead);

//将时间转化成标准的xxxx/xx/xx 时间格式√
void DateStan(string &Date);

//订房天数√
int DayBook(string DayIn, string DayOut);

//距离1.1号有几天√
int DateToBegin(int year, int month, int day);

//是否是闰年 闰年 1 平年 0√
bool LEAPYear(int year);

//找到一家酒店的最低标价√
int LowestPrice(Hotel *hotel);

//将临时订单追加到总订单√
void OrderAdd(vector<Order>&Ordertot, vector<Order>Ordertemp);

//显示房间搜索内容
Hotel *RoomShow(string hotel, Hotel *HotelHead);

//判断b是否是a子串
bool substring(string a, string b);

//判断时间输入否有错
bool DateLegal(string date);

//输入评价
void CommentOn(string hotel, string buffer, vector<Comment>&CommentHead);

//查看评价
void CommentShow(string hotel, vector<Comment>CommentHead);

//判断酒店是否存在
bool HotelExist(Hotel *head, string hotel);
#endif // !CUSTOMER_H