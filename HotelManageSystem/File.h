#ifndef FILE_H
#define FILE_H

#include"Header.h"

//从文件读取订单信息
void FileInOrder(string FileName, vector<Order>&OrderHead, vector<City>& CityList);

//将订单信息输出到文件
void FileOutOrder(string FileName, vector<Order>OrderHead);

//从文件读取酒店信息
void FileInHotel(string FileName, Hotel *&Head);

//将酒店信息输出到文件
void FileOutHotel(string FileName, Hotel *HotelHead);

//从文件读取评价信息
void FileInComment(string FileName, vector<Comment>&CommentHead);

//将评价输出到文件
void FileOutComment(string FileName, vector<Comment>CommentHead);

#endif // !FILE_H