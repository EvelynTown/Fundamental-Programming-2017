#ifndef MANAGE_H
#define MANAGE_H

#include"Header.h"

//��ӾƵ���Ϣ
void HotelAdd(string HotelInfo, Hotel *&HotelHead);	

//ɾ���Ƶ���Ϣ
void HotelDelete(string HotelNum, Hotel *&HotelHead);	

//�жϾƵ��Ƿ��ж���
bool HotelEmpty(string HotelNum, Hotel *HotelHead);	

//�ı䷿��۸�
void HotelPriceChange(string HotelNum,string RoomNum, int price, Hotel *&HotelHead);

//�������ӵľƵ��Ƿ��Ѿ�����
bool Exist(string buffer, Hotel*hotel);

//��ӡ�����Ҽ��һ��...
void PrintHotel(Hotel *HotelHead);

//�Զ���������
bool comp(const Order &a, const Order &b);

//�������벻������
bool code();

//�Ƶ�����
void HotelSort(Hotel *&head);

//���ӷ���
void RoomAdd(string HotelNum, string buffer, Hotel *&HotelHead);

//��ʾ��������
void RoomAppear(string hotel, Hotel *HotelHead);
#endif // !MANAGE_H