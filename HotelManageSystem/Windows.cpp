#include "Windows.h"
#include"Customer.h"
#include"File.h"
#include"Header.h"
#include"Manage.h"

string OrderFile = "order.txt";
string HotelFile = "hotel.txt";
string CommentFile = "comment.txt";

Hotel *HotelList;
vector<Order> OrderTotalList;//存储总的订单
vector<City> CityList;
vector<Order> OrderTempList;//存储该次登录下的订单
vector<Comment>CommentList;//评价文件

//欢迎界面
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
				cout << "欢迎使用本系统";
				for (int j = 0; j < 9; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "1.管理员";
				for (int j = 0; j < 13; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "2.用户";
				for (int j = 0; j < 15; j++) cout << ' ';
			}
			else {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "3.退出系统";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//管理员界面
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
				cout << "管理员界面";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "1.导入信息";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "2.增加酒店";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 6) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "3.删除酒店";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 7) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "4.修改酒店";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 8) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "5.添加房间";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 9) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "6.保存信息";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 10) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "7.酒店信息";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 11) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "8.房间信息";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "9.返回上一级";
				for (int j = 0; j < 9; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//用户界面
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
				cout << "用户界面";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "1.查询酒店";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "2.查看订单";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 6) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "3.评价酒店";
				for (int j = 0; j < 11; j++) cout << ' ';
			}
			else if (i == 7) {
				for (int j = 0; j < 11; j++) cout << ' ';
				cout << "4.返回上一级";
				for (int j = 0; j < 9; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//查询界面
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
				cout << "查询界面";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "1.输入位置";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "2.输入预定时间";
				for (int j = 0; j < 8; j++) cout << ' ';
			}
			else if (i == 6) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "3.输入关键字";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			else if (i == 7) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "4.搜索";
				for (int j = 0; j < 16; j++) cout << ' ';
			}
			else {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "5.返回上一级";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//选择界面（选择酒店）
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
				cout << "选择界面";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "1.选择酒店";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "2.查看评价";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 6) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "3.返回上一级";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//预定界面(房间)
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
				cout << "预订界面";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "1.选择房间";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "2.返回上一级";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << endl << endl;
}

//查看订单界面(房间)
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
				cout << "查看订单界面";
				for (int j = 0; j < 10; j++) cout << ' ';
			}
			else if (i == 4) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "1.取消订单";
				for (int j = 0; j < 12; j++) cout << ' ';
			}
			else if (i == 5) {
				for (int j = 0; j < 10; j++) cout << ' ';
				cout << "2.返回上一级";
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
		cout << "选择所需的功能：";
		cin >> FunctionNum0;
		system("cls");
		//选择管理界面
		if (FunctionNum0 == 1 && code()) {
			ScreenManage();
			string FileName;
			int FunctionNum1 = 0;
			while (1) {
				cout << "选择所需的功能：";
				cin >> FunctionNum1;
				//选择功能1导入文件
				if (FunctionNum1 == 1) {
					string buffer;
					cout << "输入文件名：";
					cin >> buffer;
					//FileInOrder(OrderFile, OrderTotalList,CityList);
					//FileInHotel(HotelFile, HotelList);
					cout << "导入成功" << endl;
				}

				//增加酒店
				else if (FunctionNum1 == 2) {
					string buffer;
					cout << "输入酒店信息：";
					cin >> buffer;
					if (Exist(buffer, HotelList))
						cout << "该酒店已存在" << endl;
					else {
						HotelAdd(buffer, HotelList);
						cout << "添加成功" << endl;
					}
				}

				//删除酒店
				else if (FunctionNum1 == 3) {
					cout << "输入酒店编号：";
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
						cout << "没有该酒店" << endl;
					else if (HotelEmpty(number, HotelList))
						cout << "该酒店已有订单" << endl;
					else if (flag == 1)
						HotelDelete(number, HotelList);
				}

				//修改房间价格
				else if (FunctionNum1 == 4) {
					string hotel, room;
					int price = 0;
					cout << "输入酒店编号：";
					cin >> hotel;
					cout << "输入房间编号：";
					cin >> room;
					cout << "请输入改变后的价格（元/天）:";
					cin >> price;
					HotelPriceChange(hotel, room, price, HotelList);
				}

				//增加房间
				else if (FunctionNum1 == 5) {
					string hotel, buffer;
					cout << "请输入酒店编号：";
					cin >> hotel;
					cout << "请输入房间信息：";
					cin >> buffer;
					RoomAdd(hotel, buffer, HotelList);
				}

				//保存订单信息
				else if (FunctionNum1 == 6) {
					OrderAdd(OrderTotalList, OrderTempList);
					//不知道还有没有问题
					sort(OrderTotalList.begin(), OrderTotalList.end(), comp);
					FileOutOrder(OrderFile, OrderTotalList);
					FileOutHotel(OrderFile, HotelList);
					cout << "保存成功" << endl;
				}

				//选择酒店信息
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

				//选择房间信息
				else if (FunctionNum1 == 8) {
					string hotel;
					cout << "请输入酒店编号：";
					cin >> hotel;
					RoomAppear(hotel, HotelList);					
				}

				//选择返回上一级
				else if (FunctionNum1 == 9) {
					system("cls");
					break;
				}

				else
					cout << "没有这个功能" << endl;
			}
		}

		//选择用户界面
		else if (FunctionNum0 == 2) {
			int FunctionNum1 = 0;
			while (1) {
				system("cls");
				ScreenUser();
				cout << "选择所需的功能：";
				cin >> FunctionNum1;

				//选择查询酒店
				if (FunctionNum1 == 1) {				
					system("cls");
					ScreenReference();
					int FunctionNum2 = 0;
					string  city, timetemp, timein, timeout, keyword, room;
					
					while (1) {				
						cout << "选择所需的功能：";
						cin >> FunctionNum2;

						//输入位置
						if (FunctionNum2 == 1) {
							keyword = "";
							timetemp = "";
							room = "";
							city = "";
							cout << "输入位置信息：";
							cin >> city;
						}

						//输入预定时间
						else if (FunctionNum2 == 2) {
							cout << "输入预定时间：";
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
								cout << "输入时间有误" << endl;
							else {
								DateStan(timein);
								DateStan(timeout);
								if(timein>timeout)
									cout << "输入时间有误" << endl;
							}
						}

						//输入关键字
						else if (FunctionNum2 == 3) {
							cout << "输入关键字：";
							cin >> keyword;
						}

						//搜索
						else if (FunctionNum2 == 4) {
							int FunctionNum3 = 0;
							while (1) {
								system("cls");
								ScreenSelect();
								SearchHotel(city, CityList,keyword);
								cout << "选择所需的功能：";
								cin >> FunctionNum3;

								//选择酒店
								if (FunctionNum3 == 1) {
									string hotel;
									cout << "输入酒店编号：";
									cin >> hotel;
									int FunctionNum4 = 0;
									system("cls");
									ScreenBook();

									cout << endl << endl;
									Hotel *HotelTolive = RoomShow(hotel, HotelList);
									while (1) {
										cout << "选择所需的功能：";
										cin >> FunctionNum4;
										//选择房间
										if (FunctionNum4 == 1) {
											cout << "选择房间：";
											cin >> room;
											bool empty = RoomAvailable(timein, timeout, room, HotelTolive);
											if (empty && timein.size() != 0) {
												RoomBook(OrderTempList, room, timein, timeout, HotelTolive, OrderTotalList);
												RoomTag(timein, timeout, room, HotelTolive);
											}
											else if (!empty)
												cout << "预订失败，时间冲突" << endl;
											else if (timein.size() == 0)
												cout << "请输入订房时间" << endl;
										}
										//返回上一级(返回选择界面)
										else if (FunctionNum4 == 2) {
											system("cls");
											break;
										}
										else
											cout << "没有该功能。" << endl;
									}
								}

								//查看评价
								else if (FunctionNum3 == 2) {
									string hotel;
									cout << "请输入酒店编号：";
									cin >> hotel;
									if (!HotelExist(HotelList, hotel)) {
										cout << "该酒店不存在" << endl;
										system("pause");
									}
									else {
										CommentShow(hotel, CommentList);
									}
								}

								//返回上一级（返回用户界面）
								else if (FunctionNum3 == 3) {
									system("cls");
									break;
								}

								else
									cout << "没有该功能。" << endl;
							}
							ScreenReference();
						}

						//返回上一级（返回用户界面）
						else if (FunctionNum2 == 5) {
							system("cls");
							break;
						}

						else
							cout << "没有该功能。" << endl;
					}
				}

				//选择查看订单
				else if (FunctionNum1 == 2) {
					int FunctionNum2 = 0;
					system("cls");
					ScreenOrderCheck();
					cout << endl << endl;
					//显示订单
					OrderShow(OrderTempList);
					while (1) {
						cout << "选择所需的功能：";
						cin >> FunctionNum2;
						//取消订单
						if (FunctionNum2 == 1) {
							cout << "输入订单号：";
							int Order;
							cin >> Order;
							OrderCancel(OrderTempList, Order);
							cout << "订单取消成功!" << endl;
						}

						//返回上一级
						else if (FunctionNum2 == 2) {
							system("cls");
							break;
						}
						else
							cout << "没有此功能。" << endl;
					}
				}

				//评价酒店
				else if (FunctionNum1 == 3) {
					string buffer, hotel;
					cout << "请输入酒店编号：";
					cin >> hotel;
					if (!HotelExist(HotelList, hotel)) {
						cout << "该酒店不存在" << endl;
						system("pause");
					}
					else {
						cout << "请输入评价：";
						cin >> buffer;
						CommentOn(hotel, buffer, CommentList);
						cout << "评价成功" << endl;
						system("pause");
					}
				}

				//选择返回上一级(返回主菜单屏幕)
				else if (FunctionNum1 == 4) {
					system("cls");
					break;
				}

				else
				{
					cout << "没有该功能。" << endl;
					system("pause");
				}
			}
		}

		//选择退出系统
		else if (FunctionNum0 == 3) {
			OrderAdd(OrderTotalList, OrderTempList);
			FileOutHotel(HotelFile, HotelList);
			FileOutOrder(OrderFile, OrderTotalList);
			FileOutComment(CommentFile, CommentList);
			exit(0);
		}

		//随便乱选的？？
		else {
			cout << "没有这个选项。" << endl;
			system("pause");
			system("cls");
		}
	}
}