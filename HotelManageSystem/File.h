#ifndef FILE_H
#define FILE_H

#include"Header.h"

//���ļ���ȡ������Ϣ
void FileInOrder(string FileName, vector<Order>&OrderHead, vector<City>& CityList);

//��������Ϣ������ļ�
void FileOutOrder(string FileName, vector<Order>OrderHead);

//���ļ���ȡ�Ƶ���Ϣ
void FileInHotel(string FileName, Hotel *&Head);

//���Ƶ���Ϣ������ļ�
void FileOutHotel(string FileName, Hotel *HotelHead);

//���ļ���ȡ������Ϣ
void FileInComment(string FileName, vector<Comment>&CommentHead);

//������������ļ�
void FileOutComment(string FileName, vector<Comment>CommentHead);

#endif // !FILE_H