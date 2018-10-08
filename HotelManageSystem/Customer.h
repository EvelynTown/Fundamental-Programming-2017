#ifndef CUSTOMER_H
#define CUSTOMER_H

#include"Header.h"

//��ʾ������
void OrderShow(vector<Order>OrderHead);	

//ɾ�����Ϊnum�Ķ�����
void OrderCancel(vector<Order>&OrderHead, int OrderNum);	

//���ݳ��в��ҾƵ��
void SearchHotel(string CityName, vector<City> CityHead, string location);

//��ѯ��ʱ�η����Ƿ�Ϊ�ա�
bool RoomAvailable(string DayIn, string DayOut, string num, Hotel *RoomInHotel);

//ѡ����Ϊnum�ķ��䣬��������׷�ӵ����������
void RoomBook(vector<Order>&OrderTemp, string num, string DayIn, string DayOut, Hotel *RoomInHotel, vector<Order>OrderHead);

//���ڷ���������÷����¹������ڡ�
void RoomTag(string DayIn, string DayOut, string num, Hotel *&RoomInHotel);

//���Ƶ갴����λ�ý��з����
void CitySort(vector<City> &CityHead, Hotel *HotelHead);

//��ʱ��ת���ɱ�׼��xxxx/xx/xx ʱ���ʽ��
void DateStan(string &Date);

//����������
int DayBook(string DayIn, string DayOut);

//����1.1���м����
int DateToBegin(int year, int month, int day);

//�Ƿ������� ���� 1 ƽ�� 0��
bool LEAPYear(int year);

//�ҵ�һ�ҾƵ����ͱ�ۡ�
int LowestPrice(Hotel *hotel);

//����ʱ����׷�ӵ��ܶ�����
void OrderAdd(vector<Order>&Ordertot, vector<Order>Ordertemp);

//��ʾ������������
Hotel *RoomShow(string hotel, Hotel *HotelHead);

//�ж�b�Ƿ���a�Ӵ�
bool substring(string a, string b);

//�ж�ʱ��������д�
bool DateLegal(string date);

//��������
void CommentOn(string hotel, string buffer, vector<Comment>&CommentHead);

//�鿴����
void CommentShow(string hotel, vector<Comment>CommentHead);

//�жϾƵ��Ƿ����
bool HotelExist(Hotel *head, string hotel);
#endif // !CUSTOMER_H