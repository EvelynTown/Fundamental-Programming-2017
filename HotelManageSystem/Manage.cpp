#include"Manage.h"

//将新增加酒店信息节点插到头部
void HotelAdd(string HotelInfo, Hotel *&HotelHead)
{
	Hotel *HotelTemp = new Hotel;
	HotelTemp->next = 0;
	int CommaNum = 0, VerticalNum = 0, i = 0;
	for (i = 0; i < HotelInfo.size(); i++)
		if (HotelInfo[i] == '|')
			VerticalNum++;
	for (i = 0; HotelInfo[i] != '|'; i++) {
		if (HotelInfo[i] == ',')
			CommaNum++;
		else {
			if (CommaNum == 0)
				HotelTemp->num +=HotelInfo[i];
			else if (CommaNum == 1)
				HotelTemp->name += HotelInfo[i];
			else if (CommaNum == 2)
				HotelTemp->city += HotelInfo[i];
			else if (CommaNum == 3)
				HotelTemp->location += HotelInfo[i];
		}
	}
	//开始对房间数组进行操作
	for (int n = 0; n < VerticalNum - 1; n++) {
		Room RoomTemp;
		CommaNum = 0, RoomTemp.price = 0;
		i++;
		for (i; HotelInfo[i] != '|'; i++) {
			if (HotelInfo[i] == ',')
				CommaNum++; 
			else{
				if (CommaNum == 0)
					RoomTemp.num += HotelInfo[i];
				else if (CommaNum == 1)
					RoomTemp.price = RoomTemp.price * 10 + (int)(HotelInfo[i] - '0');
				else
					RoomTemp.type += HotelInfo[i];
			}
		}
		HotelTemp->RoomInHotel.push_back(RoomTemp);
	}
	Hotel *temp = HotelHead, *tail = HotelHead;
	while (tail->next)
		tail = tail->next;
	if (HotelTemp->num < HotelHead->num)
	{
		HotelTemp->next = HotelHead;
		HotelHead = HotelTemp;
	}
	else if (HotelTemp->num > tail->num)
	{
		tail->next = HotelTemp;
		tail = HotelTemp;
	}
	else {
		while (temp) {
			if (temp->num<HotelTemp->num && temp->next->num>HotelTemp->num) {
				Hotel *after = temp->next;
				temp->next = HotelTemp;
				HotelTemp->next = after;
				break;
			}
			temp = temp->next;
		}
	}
}

//删除酒店信息
void HotelDelete(string HotelNum, Hotel *&HotelHead)
{
	Hotel *tail = HotelHead, *temp = HotelHead;
	while (tail->next)
		tail = tail->next;
	if (HotelHead->num == HotelNum) {
		HotelHead = HotelHead->next;
		delete temp;
		cout << "删除成功" << endl;
	}
	else if (tail->num == HotelNum) {
		Hotel *prev = HotelHead;
		while (prev->next != tail)
			prev = prev->next;
		prev->next = 0;
		temp = tail;
		delete temp;
		tail = prev;
		cout << "删除成功" << endl;
	}
	else {
		while (temp->next->num != HotelNum && temp->next != 0)
			temp = temp->next;
		Hotel *prev = temp;
		temp = prev->next;
		prev->next = temp->next;
		delete temp;
		cout << "删除成功" << endl;
	}}

//判断酒店是否有订单
bool HotelEmpty(string HotelNum, Hotel *HotelHead)
{
	Hotel *temp = HotelHead;
	while (temp->num != HotelNum && temp!=0)
		temp = temp->next;
	if (!temp)//没有这个编号
		cout << "该酒店不存在" << endl;
	else {
		for (int i = 0; i < temp->RoomInHotel.size(); i++) {
		if (temp->RoomInHotel[i].DayIn.size() > 0)
			return 1;//有订单
		else
			return 0;//没订单
		}
	}
}

//改变房间价格
void HotelPriceChange(string HotelNum, string RoomNum, int price, Hotel *&HotelHead)
{
	bool flag = 0;
	Hotel *temp = HotelHead;
	while (temp->num != HotelNum && temp != 0)
		temp = temp->next;
	if (!temp)//没有这个编号
		cout << "该酒店不存在" << endl;
	else {
		for (int i = 0; i < temp->RoomInHotel.size(); i++){
			cout << temp->RoomInHotel[i].num<<' ';
			if (temp->RoomInHotel[i].num == RoomNum) {
				temp->RoomInHotel[i].price = price;
				flag = 1;
				cout << "修改成功" << endl;
				break;
			}
		}
		if (flag == 0)
			cout << "该房间不存在" << endl;
	}
}

//检查新添加的酒店是否已经有了
bool Exist(string buffer, Hotel*hotel)
{
	string temp;
	for (int i = 0; i < buffer.size(); i++) {
		if (buffer[i] == ',')
			break;
		else
			temp += buffer[i];
	}
	while (hotel) {
		if (temp == hotel->num)
			return 1;
		hotel = hotel->next;
	}
	if (hotel == 0)
		return 0;
}

//打印链表我检查一下...
void PrintHotel(Hotel *HotelHead)
{
	while (HotelHead) {
		cout << HotelHead->num << ' ' << HotelHead->name << ' ' << endl;
		for (int i = 0; i < HotelHead->RoomInHotel.size(); i++)
			cout << HotelHead->RoomInHotel[i].num << " " << HotelHead->RoomInHotel[i].price << endl;
		cout << endl;
		HotelHead = HotelHead->next;
	}
}

//自定义排序函数
bool comp(const Order &a, const Order &b)
{
	return a.OrderNum<b.OrderNum;
}

//密码输入不被看见
bool code() 
{
	char pw[50], ch;
	char *syspw = "tangsiyichaoshuai"; // 原始密码
	int i, m = 0;
	cout << "请输入密码:" << endl;
	while (m < 3) {
		i = 0;
		while ((ch = _getch()) != '\r') {
			if (ch == '\b' && i > 0) {
				cout << "\b \b";
				--i;
			}
			else if (ch != '\b') {
				pw[i++] = ch;
				cout <<"*";
			}
		}
		pw[i] = '\0';
		cout << endl;;
		if (strcmp(pw, syspw) != 0) {
			cout << "密码错误，请重新输入!" << endl;
			m++;
		}
		else {
			cout << "密码正确！" << endl;
			system("cls");
			return 1;
		}
	}
	cout << "连续3次输入错误，退出!" << endl;
	system("cls");
	return 0;
}

//酒店链表排序
void HotelSort(Hotel *&head)
{ 
	if (head == NULL || head->next == NULL) 
		return;
	for (Hotel *pi = head; pi->next != NULL; pi = pi->next) {
		Hotel *p_min = pi;
		for (Hotel *pj = pi->next; pj != NULL; pj = pj->next)
			if (p_min->num > pj->num)    
				p_min = pj;  
		if (p_min != pi) {
			Hotel *temp = pi;
			pi = p_min;
			p_min = temp;
		} 
	} 
}

//增加房间
void RoomAdd(string HotelNum, string buffer,Hotel *&HotelHead)
{
	Hotel *curr = HotelHead;
	while (curr->num != HotelNum)
		curr = curr->next;
	int i = 0, CommaNum = 0;
	Room RoomTemp;
	bool flag = 0;
	if (curr) {
		for (i = 0; i < buffer.size(); i++) {
			if (buffer[i] == ',')
				CommaNum++;
			else if (CommaNum == 0)
				RoomTemp.num += buffer[i];
			else if (CommaNum == 1)
				RoomTemp.price = RoomTemp.price * 10 + (int)(buffer[i] - '0');
			else if (CommaNum == 2)
				RoomTemp.type += buffer[i];
		}
		for (int j = 0; j < curr->RoomInHotel.size(); j++) {
			if (RoomTemp.num == curr->RoomInHotel[j].num) {
				cout << "该房间已存在" << endl;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			curr->RoomInHotel.push_back(RoomTemp);
			cout << "添加成功" << endl;
		}
	}
	else
		cout << "没有这个酒店" << endl;
}

//显示房间内容
void RoomAppear(string hotel, Hotel *HotelHead)
{
	Hotel *curr = HotelHead;
	while (curr->num != hotel)
		curr = curr->next;
	if (curr) {
		for (int i = 0; i < curr->RoomInHotel.size(); i++) {
			cout << curr->RoomInHotel[i].num << ',' << curr->RoomInHotel[i].price << ','
				<< curr->RoomInHotel[i].type << endl;
		}
	}
	else
		cout << "该酒店不存在" << endl;
}