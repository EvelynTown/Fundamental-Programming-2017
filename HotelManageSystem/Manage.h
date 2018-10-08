#ifndef MANAGE_H
#define MANAGE_H

#include"Header.h"

//添加酒店信息
void HotelAdd(string HotelInfo, Hotel *&HotelHead);	

//删除酒店信息
void HotelDelete(string HotelNum, Hotel *&HotelHead);	

//判断酒店是否有订单
bool HotelEmpty(string HotelNum, Hotel *HotelHead);	

//改变房间价格
void HotelPriceChange(string HotelNum,string RoomNum, int price, Hotel *&HotelHead);

//检查新添加的酒店是否已经有了
bool Exist(string buffer, Hotel*hotel);

//打印链表我检查一下...
void PrintHotel(Hotel *HotelHead);

//自定义排序函数
bool comp(const Order &a, const Order &b);

//密码输入不被看见
bool code();

//酒店排序
void HotelSort(Hotel *&head);

//增加房间
void RoomAdd(string HotelNum, string buffer, Hotel *&HotelHead);

//显示房间内容
void RoomAppear(string hotel, Hotel *HotelHead);
#endif // !MANAGE_H