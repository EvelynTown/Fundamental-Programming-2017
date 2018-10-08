#include "Windows.h"
#include"Customer.h"
#include"File.h"
#include"Header.h"
#include"Manage.h"

string OrderFile = "order.txt";
string HotelFile = "hotel.txt";
string CommentFile = "comment.txt";

Hotel *HotelList;
vector<Order> OrderTotalList;//�洢�ܵĶ���
vector<City> CityList;
vector<Order> OrderTempList;//�洢�ôε�¼�µĶ���
vector<Comment>CommentList;//�����ļ�

//��ӭ����
void ScreenWelcome()
{
	cout << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 1; j++)
			cout << '\t';
		if (i == 0 || i == 8) {
			cout << ' ';
			for (int j = 0; j < 32; j++) cout << '-';
		}
		else {
			cout << '|';
			if (i == 1 || i == 3 || i == 7)
				for (int j = 0; j < 32; j++) cout << ' ';
			else if (i == 2) {
				for (int j = 0; j < 9; j++) cout << ' ';
				cout << "��ӭʹ�ñ�ϵͳ";
				for (int j = 0; j < 9; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "1.����Ա";
				for (int j = 0; j < 13; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "2.�û�";
				for (int j = 0; j < 15; j++) cout << ' ';
			}
			else {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "3.�˳�ϵͳ";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//����Ա����
void ScreenManage()
{
	cout << endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 1; j++)
			cout << '\t';
		if (i == 0 || i == 14) {
			cout << ' ';
			for (int j = 0; j < 32; j++) cout << '-';
		}
		else {
			cout << '|';
			if (i == 1 || i == 3 || i == 13)
				for (int j = 0; j < 32; j++) cout << ' ';
			else if (i == 2) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "����Ա����";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "1.������Ϣ";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "2.���ӾƵ�";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 6) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "3.ɾ���Ƶ�";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 7) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "4.�޸ľƵ�";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 8) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "5.��ӷ���";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 9) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "6.������Ϣ";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 10) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "7.�Ƶ���Ϣ";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 11) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "8.������Ϣ";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "9.������һ��";
				for (int j = 0; j < 9; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//�û�����
void ScreenUser()
{
	cout << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 1; j++)
			cout << '\t';
		if (i == 0 || i == 9) {
			cout << ' ';
			for (int j = 0; j < 32; j++) cout << '-';
		}
		else {
			cout << '|';
			if (i == 1 || i == 3 || i == 8)
				for (int j = 0; j < 32; j++) cout << ' ';
			else if (i == 2) {
				for (int j = 0; j < 12; j++) cout << ' ';
				cout << "�û�����";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "1.��ѯ�Ƶ�";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "2.�鿴����";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 6) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "3.���۾Ƶ�";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 7) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "4.������һ��";
				for (int j = 0; j < 9; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//��ѯ����
void ScreenReference()
{
	cout << endl;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 1; j++)
			cout << '\t';
		if (i == 0 || i == 10) {
			cout << ' ';
			for (int j = 0; j < 32; j++) cout << '-';
		}
		else {
			cout << '|';
			if (i == 1 || i == 3 || i == 9)
				for (int j = 0; j < 32; j++) cout << ' ';
			else if (i == 2) {
				for (int j = 0; j < 12; j++) cout << ' ';
				cout << "��ѯ����";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "1.����λ��";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "2.����Ԥ��ʱ��";
				for (int j = 0; j < 8; j++) cout << ' ';
			}
			else if (i == 6) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "3.����ؼ���";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			else if (i == 7) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "4.����";
				for (int j = 0; j < 16; j++) cout << ' ';
			}
			else {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "5.������һ��";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//ѡ����棨ѡ��Ƶ꣩
void ScreenSelect()
{
	cout << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 1; j++)
			cout << '\t';
		if (i == 0 || i == 8) {
			cout << ' ';
			for (int j = 0; j < 32; j++) cout << '-';
		}
		else {
			cout << '|';
			if (i == 1 || i == 3 || i == 7)
				for (int j = 0; j < 32; j++) cout << ' ';
			else if (i == 2) {
				for (int j = 0; j < 12; j++) cout << ' ';
				cout << "ѡ�����";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "1.ѡ��Ƶ�";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "2.�鿴����";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 6) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "3.������һ��";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//Ԥ������(����)
void ScreenBook()
{
	cout << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 1; j++)
			cout << '\t';
		if (i == 0 || i == 7) {
			cout << ' ';
			for (int j = 0; j < 32; j++) cout << '-';
		}
		else {
			cout << '|';
			if (i == 1 || i == 3 || i == 6)
				for (int j = 0; j < 32; j++) cout << ' ';
			else if (i == 2) {
				for (int j = 0; j < 12; j++) cout << ' ';
				cout << "Ԥ������";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "1.ѡ�񷿼�";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "2.������һ��";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//�鿴��������(����)
void ScreenOrderCheck()
{

	cout << endl;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 1; j++)
			cout << '\t';
		if (i == 0 || i == 7) {
			cout << ' ';
			for (int j = 0; j < 32; j++) cout << '-';
		}
		else {
			cout << '|';
			if (i == 1 || i == 3 || i == 6)
				for (int j = 0; j < 32; j++) cout << ' ';
			else if (i == 2) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "�鿴��������";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "1.ȡ������";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "2.������һ��";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Windows()
{
	FileInHotel(HotelFile, HotelList);
	CitySort(CityList, HotelList);
	FileInOrder(OrderFile, OrderTotalList,CityList);
	FileInComment(CommentFile, CommentList);
	int FunctionNum0 = 0;
	while (1) {
		ScreenWelcome();
		cout << "ѡ������Ĺ��ܣ�";
		cin >> FunctionNum0;
		system("cls");
		//ѡ��������
		if (FunctionNum0 == 1 && code()) {
			ScreenManage();
			string FileName;
			int FunctionNum1 = 0;
			while (1) {
				cout << "ѡ������Ĺ��ܣ�";
				cin >> FunctionNum1;
				//ѡ����1�����ļ�
				if (FunctionNum1 == 1) {
					string buffer;
					cout << "�����ļ�����";
					cin >> buffer;
					//FileInOrder(OrderFile, OrderTotalList,CityList);
					//FileInHotel(HotelFile, HotelList);
					cout << "����ɹ�" << endl;
				}

				//���ӾƵ�
				else if (FunctionNum1 == 2) {
					string buffer;
					cout << "����Ƶ���Ϣ��";
					cin >> buffer;
					if (Exist(buffer, HotelList))
						cout << "�þƵ��Ѵ���" << endl;
					else {
						HotelAdd(buffer, HotelList);
						cout << "��ӳɹ�" << endl;
					}
				}

				//ɾ���Ƶ�
				else if (FunctionNum1 == 3) {
					cout << "����Ƶ��ţ�";
					string number;
					cin >> number;
					Hotel *temp = HotelList;
					bool flag = 0;
					while (temp) {
						if (temp->num == number) {
							flag = 1;
							break;
						}
						temp = temp->next;
					}
					if (flag == 0)
						cout << "û�иþƵ�" << endl;
					else if (HotelEmpty(number, HotelList))
						cout << "�þƵ����ж���" << endl;
					else if (flag == 1)
						HotelDelete(number, HotelList);
				}

				//�޸ķ���۸�
				else if (FunctionNum1 == 4) {
					string hotel, room;
					int price = 0;
					cout << "����Ƶ��ţ�";
					cin >> hotel;
					cout << "���뷿���ţ�";
					cin >> room;
					cout << "������ı��ļ۸�Ԫ/�죩:";
					cin >> price;
					HotelPriceChange(hotel, room, price, HotelList);
				}

				//���ӷ���
				else if (FunctionNum1 == 5) {
					string hotel, buffer;
					cout << "������Ƶ��ţ�";
					cin >> hotel;
					cout << "�����뷿����Ϣ��";
					cin >> buffer;
					RoomAdd(hotel, buffer, HotelList);
				}

				//���涩����Ϣ
				else if (FunctionNum1 == 6) {
					OrderAdd(OrderTotalList, OrderTempList);
					//��֪������û������
					sort(OrderTotalList.begin(), OrderTotalList.end(), comp);
					FileOutOrder(OrderFile, OrderTotalList);
					FileOutHotel(OrderFile, HotelList);
					cout << "����ɹ�" << endl;
				}

				//ѡ��Ƶ���Ϣ
				else if (FunctionNum1 == 7) {
					HotelSort(HotelList);
					Hotel *temp = HotelList;
					while (temp) {
						cout << temp->num << ',' << temp->name << ',' << temp->city << ',' << temp->location << '|';
						for (int i = 0; i < temp->RoomInHotel.size(); i++)
							cout << temp->RoomInHotel[i].num << ',' << temp->RoomInHotel[i].price << ','
							<< temp->RoomInHotel[i].type << '|';
						cout << endl;
						temp = temp->next;
					}
				}

				//ѡ�񷿼���Ϣ
				else if (FunctionNum1 == 8) {
					string hotel;
					cout << "������Ƶ��ţ�";
					cin >> hotel;
					RoomAppear(hotel, HotelList);					
				}

				//ѡ�񷵻���һ��
				else if (FunctionNum1 == 9) {
					system("cls");
					break;
				}

				else
					cout << "û���������" << endl;
			}
		}

		//ѡ���û�����
		else if (FunctionNum0 == 2) {
			int FunctionNum1 = 0;
			while (1) {
				system("cls");
				ScreenUser();
				cout << "ѡ������Ĺ��ܣ�";
				cin >> FunctionNum1;

				//ѡ���ѯ�Ƶ�
				if (FunctionNum1 == 1) {				
					system("cls");
					ScreenReference();
					int FunctionNum2 = 0;
					string  city, timetemp, timein, timeout, keyword, room;
					
					while (1) {				
						cout << "ѡ������Ĺ��ܣ�";
						cin >> FunctionNum2;

						//����λ��
						if (FunctionNum2 == 1) {
							keyword = "";
							timetemp = "";
							room = "";
							city = "";
							cout << "����λ����Ϣ��";
							cin >> city;
						}

						//����Ԥ��ʱ��
						else if (FunctionNum2 == 2) {
							cout << "����Ԥ��ʱ�䣺";
							cin >> timetemp;
							bool flag = 0;	
							timein = "";
							timeout = "";
							for (int i = 0; i < timetemp.size(); i++) {
								if (timetemp[i] == '-')
									flag = 1;
								else {
									if (flag == 0)
										timein += timetemp[i];
									else
										timeout += timetemp[i];
								}
							}
							if (!DateLegal(timein) || !(DateLegal(timeout)))
								cout << "����ʱ������" << endl;
							else {
								DateStan(timein);
								DateStan(timeout);
								if(timein>timeout)
									cout << "����ʱ������" << endl;
							}
						}

						//����ؼ���
						else if (FunctionNum2 == 3) {
							cout << "����ؼ��֣�";
							cin >> keyword;
						}

						//����
						else if (FunctionNum2 == 4) {
							int FunctionNum3 = 0;
							while (1) {
								system("cls");
								ScreenSelect();
								SearchHotel(city, CityList,keyword);
								cout << "ѡ������Ĺ��ܣ�";
								cin >> FunctionNum3;

								//ѡ��Ƶ�
								if (FunctionNum3 == 1) {
									string hotel;
									cout << "����Ƶ��ţ�";
									cin >> hotel;
									int FunctionNum4 = 0;
									system("cls");
									ScreenBook();

									cout << endl << endl;
									Hotel *HotelTolive = RoomShow(hotel, HotelList);
									while (1) {
										cout << "ѡ������Ĺ��ܣ�";
										cin >> FunctionNum4;
										//ѡ�񷿼�
										if (FunctionNum4 == 1) {
											cout << "ѡ�񷿼䣺";
											cin >> room;
											bool empty = RoomAvailable(timein, timeout, room, HotelTolive);
											if (empty && timein.size() != 0) {
												RoomBook(OrderTempList, room, timein, timeout, HotelTolive, OrderTotalList);
												RoomTag(timein, timeout, room, HotelTolive);
											}
											else if (!empty)
												cout << "Ԥ��ʧ�ܣ�ʱ���ͻ" << endl;
											else if (timein.size() == 0)
												cout << "�����붩��ʱ��" << endl;
										}
										//������һ��(����ѡ�����)
										else if (FunctionNum4 == 2) {
											system("cls");
											break;
										}
										else
											cout << "û�иù��ܡ�" << endl;
									}
								}

								//�鿴����
								else if (FunctionNum3 == 2) {
									string hotel;
									cout << "������Ƶ��ţ�";
									cin >> hotel;
									if (!HotelExist(HotelList, hotel)) {
										cout << "�þƵ겻����" << endl;
										system("pause");
									}
									else {
										CommentShow(hotel, CommentList);
									}
								}

								//������һ���������û����棩
								else if (FunctionNum3 == 3) {
									system("cls");
									break;
								}

								else
									cout << "û�иù��ܡ�" << endl;
							}
							ScreenReference();
						}

						//������һ���������û����棩
						else if (FunctionNum2 == 5) {
							system("cls");
							break;
						}

						else
							cout << "û�иù��ܡ�" << endl;
					}
				}

				//ѡ��鿴����
				else if (FunctionNum1 == 2) {
					int FunctionNum2 = 0;
					system("cls");
					ScreenOrderCheck();
					cout << endl << endl;
					//��ʾ����
					OrderShow(OrderTempList);
					while (1) {
						cout << "ѡ������Ĺ��ܣ�";
						cin >> FunctionNum2;
						//ȡ������
						if (FunctionNum2 == 1) {
							cout << "���붩���ţ�";
							int Order;
							cin >> Order;
							OrderCancel(OrderTempList, Order);
							cout << "����ȡ���ɹ�!" << endl;
						}

						//������һ��
						else if (FunctionNum2 == 2) {
							system("cls");
							break;
						}
						else
							cout << "û�д˹��ܡ�" << endl;
					}
				}

				//���۾Ƶ�
				else if (FunctionNum1 == 3) {
					string buffer, hotel;
					cout << "������Ƶ��ţ�";
					cin >> hotel;
					if (!HotelExist(HotelList, hotel)) {
						cout << "�þƵ겻����" << endl;
						system("pause");
					}
					else {
						cout << "���������ۣ�";
						cin >> buffer;
						CommentOn(hotel, buffer, CommentList);
						cout << "���۳ɹ�" << endl;
						system("pause");
					}
				}

				//ѡ�񷵻���һ��(�������˵���Ļ)
				else if (FunctionNum1 == 4) {
					system("cls");
					break;
				}

				else
				{
					cout << "û�иù��ܡ�" << endl;
					system("pause");
				}
			}
		}

		//ѡ���˳�ϵͳ
		else if (FunctionNum0 == 3) {
			OrderAdd(OrderTotalList, OrderTempList);
			FileOutHotel(HotelFile, HotelList);
			FileOutOrder(OrderFile, OrderTotalList);
			FileOutComment(CommentFile, CommentList);
			exit(0);
		}

		//�����ѡ�ģ���
		else {
			cout << "û�����ѡ�" << endl;
			system("pause");
			system("cls");
		}
	}
}