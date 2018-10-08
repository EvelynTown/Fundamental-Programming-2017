#include"File.h"

ifstream fin;
ofstream fout;

//���ļ���ȡ������Ϣ
void FileInOrder(string FileName, vector<Order>&OrderHead, vector<City>&City)
{
	fin.open(FileName);
	if (!fin.is_open()) {
		fout.open(FileName);
		fout.close();
	}
	else {
		while (!fin.eof()) {
			Order OrderSingle;
			string buffer;
			fin >> buffer;
			if (buffer.size() != 0) {
				OrderSingle.OrderNum = 0, OrderSingle.Price = 0;
				int length = buffer.size(), LineNum = 0, VerticalNum = 0, CommaNum = 0;//'-','|'�Լ�','������
				for (int i = 0; i < length; i++) {
					if (buffer[i] == '-')
						LineNum++;
					else if (buffer[i] == '|')
						VerticalNum++;
					else if (buffer[i] == ',')
						CommaNum++;
					else {
						if (VerticalNum == 0)//���������
							OrderSingle.OrderNum = OrderSingle.OrderNum * 10 + (int)(buffer[i] - '0');
						else if (VerticalNum == 1)//����Ƶ�����
							OrderSingle.HotelName += buffer[i];
						else if (VerticalNum == 2 && CommaNum == 0)//�������
							OrderSingle.City += buffer[i];
						else if (VerticalNum == 2 && CommaNum == 1)//����λ����Ϣ
							OrderSingle.Location += buffer[i];
						else if (VerticalNum == 3 && LineNum == 0)
							OrderSingle.DayIn += buffer[i];//������סʱ��
						else if (VerticalNum == 3 && LineNum == 1)
							OrderSingle.DayOut += buffer[i];//��ȡ�˷�ʱ��
						else if (VerticalNum == 4 && LineNum == 1)
							OrderSingle.RoomType += buffer[i];//��������
						else if (VerticalNum == 4 && LineNum == 2)
							OrderSingle.RoomNum += buffer[i];//������
						else if (VerticalNum == 5)
							OrderSingle.Price = OrderSingle.Price * 10 + (int)(buffer[i] - '0');//����۸�
					}
				}
				OrderHead.push_back(OrderSingle);
				for (int i = 0; i < City.size(); i++) {
					if (City[i].CityName == OrderSingle.City) {
						for (int j = 0; j < City[i].LocaHead.size(); j++) {
							if (City[i].LocaHead[j].LocaName == OrderSingle.Location) {
								for (int k = 0; k < City[i].LocaHead[j].HotelInLoca.size(); k++) {
									if (City[i].LocaHead[j].HotelInLoca[k]->name == OrderSingle.HotelName) {
										for (int m = 0; m < City[i].LocaHead[j].HotelInLoca[k]->RoomInHotel.size(); m++) {
											if (City[i].LocaHead[j].HotelInLoca[k]->RoomInHotel[m].num == OrderSingle.RoomNum) {
												City[i].LocaHead[j].HotelInLoca[k]->RoomInHotel[m].DayIn.push_back(OrderSingle.DayIn);
												City[i].LocaHead[j].HotelInLoca[k]->RoomInHotel[m].DayOut.push_back(OrderSingle.DayOut);
											}										}									}								}							}						}					}				}		
			}
			fin.close();
		}
	}
}

//��������Ϣ������ļ�	
void FileOutOrder(string FileName, vector<Order>OrderHead)
{
	fout.open(FileName);
	if (!fout.is_open()) {
		cout << "FAIL TO OPEN THE FILE!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < OrderHead.size(); i++) {
		//
		fout << OrderHead[i].OrderNum << '|' << OrderHead[i].HotelName << '|'
			<< OrderHead[i].City << ',' << OrderHead[i].Location << '|'
			<< OrderHead[i].DayIn << '-' << OrderHead[i].DayOut << '|' << OrderHead[i].RoomType
			<< '-' << OrderHead[i].RoomNum << '|' << OrderHead[i].Price << '|';
		if (i < OrderHead.size() - 1)
			fout << endl;
	}
	fout.close();
}

//���ļ���ȡ�Ƶ���Ϣ
void FileInHotel(string FileName, Hotel *&Head)
{
	fin.open(FileName);
	if (!fin.is_open()) {
		cout << "FAIL TO OPEN THE FILE!" << endl;
		exit(EXIT_FAILURE);
	}
	Hotel *tail = Head;
	while (!fin.eof()) {
		string buffer;
		fin >> buffer;
		Hotel *HotelTemp = new Hotel;
		HotelTemp->next = 0;
		int CommaNum = 0, VerticalNum = 0, i = 0;
		for (i = 0; i < buffer.size(); i++)
			if (buffer[i] == '|')
				VerticalNum++;
		for (i = 0; buffer[i] != '|'; i++) {
			if (buffer[i] == ',')
				CommaNum++;
			else {
				if (CommaNum == 0)
					HotelTemp->num += buffer[i];
				else if (CommaNum == 1)
					HotelTemp->name += buffer[i];
				else if (CommaNum == 2)
					HotelTemp->city += buffer[i];
				else if (CommaNum == 3)
					HotelTemp->location += buffer[i];
			}
		}
		//��ʼ�Է���������в���
		for (int n = 0; n < VerticalNum - 1; n++) {
			Room RoomTemp;
			CommaNum = 0, RoomTemp.price = 0;
			i++;
			for (i; buffer[i] != '|'; i++) {
				if (buffer[i] == ',')
					CommaNum++;
				else if (CommaNum == 0)
					RoomTemp.num += buffer[i];
				else if (CommaNum == 1)
					RoomTemp.price = RoomTemp.price * 10 + (int)(buffer[i] - '0');
				else if(CommaNum == 2)
					RoomTemp.type += buffer[i];
			}
			HotelTemp->RoomInHotel.push_back(RoomTemp);
		}
		if (!Head)
			Head = HotelTemp;
		else
			tail->next = HotelTemp;
		tail = HotelTemp;
	}
	fin.close();
}

//���Ƶ���Ϣ������ļ�
void FileOutHotel(string FileName, Hotel *HotelHead)
{
	fout.open(FileName);
	if (!fout.is_open()) {
		cout << "FAIL TO OPEN THE FILE!" << endl;
		exit(EXIT_FAILURE);
	}
	Hotel *temp = HotelHead;
	while (temp) {
		fout << temp->num << ',' << temp->name << ',' << temp->city <<','<< temp->location << '|';
		for (int i = 0; i < temp->RoomInHotel.size(); i++)
			fout << temp->RoomInHotel[i].num << ',' << temp->RoomInHotel[i].price << ','
			<< temp->RoomInHotel[i].type << '|';
		if(temp->next!=0)
			fout << endl;
		temp = temp->next;
	}
	fout.close();
}

//���ļ���ȡ������Ϣ
void FileInComment(string FileName, vector<Comment>&CommentHead)
{
	fin.open(FileName);
	if (!fin.is_open()) {
		fout.open(FileName);
		fout.close();
	}
	else {
		while (!fin.eof()) {
			Comment CommentTemp;
			string buffer;
			fin>>buffer;
			CommentTemp.HotelNum = buffer;
			fin >> buffer;
			if (buffer.size() != 0) {
				string comment;
				bool flag = 0;
				for (int i = 0; i < buffer.size(); i++) {
					/*if (buffer[i] == ' ')
						flag = 1;
					else if (flag == 0)
						CommentTemp.HotelNum += buffer[i];*/
					if (buffer[i] == '|') {
						CommentTemp.Com.push_back(comment);
						comment = "";
					}
					else
						comment += buffer[i];
				}
			}
			CommentHead.push_back(CommentTemp);
		}
		fin.close();
	}
}

//������������ļ�
void FileOutComment(string FileName, vector<Comment>CommentHead)
{
	fout.open(FileName);
	if (!fout.is_open()) {
		cout << "FAIL TO OPEN THE FILE!" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		for (int i = 0; i < CommentHead.size(); i++){
			fout << CommentHead[i].HotelNum << ' ';
			for (int j = 0; j < CommentHead[i].Com.size(); j++) 
				fout << CommentHead[i].Com[j] << '|';
			if (i < CommentHead.size() - 1)
				fout << endl;
		}
	}
	fout.close();
}