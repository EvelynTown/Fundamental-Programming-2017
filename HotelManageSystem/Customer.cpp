#include"Customer.h"

//将酒店按城市位置进行分类
void CitySort(vector<City> &CityHead, Hotel *HotelHead)
{
	Hotel *temp = HotelHead;
	while (temp) {
		//比较是否出现了新的城市
		bool citySame = 0, locaSame = 0;
		int i = 0;
		for (i = 0; i < CityHead.size(); i++) {
			if (temp->city == CityHead[i].CityName) {
				citySame = 1;
				for (int j = 0; j < CityHead[i].LocaHead.size(); j++) {
					if (temp->location == CityHead[i].LocaHead[j].LocaName) {
						locaSame = 1;
						CityHead[i].LocaHead[j].HotelInLoca.push_back(temp);
						cout << CityHead[i].LocaHead[j].LocaName << endl;
						break;
					}
				}
				break;
			}
		}
		//没有这个城市
		if (citySame == 0) {
			City cityTemp;
			cityTemp.CityName = temp->city;
			Location locaTemp;
			locaTemp.LocaName = temp->location;
			//存入酒店的地址
			locaTemp.HotelInLoca.push_back(temp);
			//把地址结构存到地址数组中去
			cityTemp.LocaHead.push_back(locaTemp);
			CityHead.push_back(cityTemp);
		}
		//没有这个位置
		else if (locaSame == 0) {
			Location locaTemp;
			locaTemp.LocaName = temp->location;
			//存入酒店的地址
			locaTemp.HotelInLoca.push_back(temp);
			//把地址结构存到地址数组中去
			CityHead[i].LocaHead.push_back(locaTemp);
		}
		temp = temp->next;
	}
}

//将时间转化成标准的xxxx/xx/xx 时间格式
void DateStan(string &Date)
{
	int n = Date.size();
	if (n == 9) {
		if (Date[6] == '/')
			Date.insert(5, 1, '0');
		else
			Date.insert(8, 1, '0');
	}
	else if (n == 8) {
		Date.insert(5, 1, '0');
		Date.insert(8, 1, '0');
	}
}

//查询该时段房间是否为空
bool RoomAvailable(string DayIn, string DayOut, string num, Hotel *RoomInHotel)
{
	for (int i = 0; i < RoomInHotel->RoomInHotel.size(); i++) {
		if (num==RoomInHotel->RoomInHotel[i].num) {
			//标准化时间
			for (int j = 0; j < RoomInHotel->RoomInHotel[i].DayIn.size(); j++) {
				DateStan(RoomInHotel->RoomInHotel[i].DayIn[j]);
				DateStan(RoomInHotel->RoomInHotel[i].DayOut[j]);
			}
			//将居住日期按先后排序 上下对应
			sort(RoomInHotel->RoomInHotel[i].DayIn.begin(), RoomInHotel->RoomInHotel[i].DayIn.end());
			sort(RoomInHotel->RoomInHotel[i].DayOut.begin(), RoomInHotel->RoomInHotel[i].DayOut.end());
			//在所有时间之前
			if (RoomInHotel->RoomInHotel[i].DayIn.size() == 0)
				return 1;
			else if (DayIn < RoomInHotel->RoomInHotel[i].DayIn.front()
				&& DayOut < RoomInHotel->RoomInHotel[i].DayOut.front())
				return 1;
			else if (DayIn.compare(RoomInHotel->RoomInHotel[i].DayIn.back()) > 0
				&& DayOut.compare(RoomInHotel->RoomInHotel[i].DayOut.back()) > 0)
				return 1;
			else {
				for (int j = 0; j < RoomInHotel->RoomInHotel[i].DayIn.size() - 1; j++) {
					//在上一次退房之后 下一次订房之前
					if (DayIn.compare(RoomInHotel->RoomInHotel[i].DayOut[j]) > 0
						&& DayOut.compare(RoomInHotel->RoomInHotel[i].DayIn[j + 1]) < 0)
						return 1;
				}
				return 0;
			}
		}break;
	}
}

//选择编号为num的房间，并将订单追加到临时订单数组
void RoomBook(vector<Order>&OrderTemp, string num, string DayIn, string DayOut, Hotel *RoomInHotel, vector<Order>OrderHead)
{
	Order OTemp;
	//第一发订单
	if (OrderHead.empty() && OrderTemp.empty())
		OTemp.OrderNum = 10001;
	//临时的第一发订单
	else if (!OrderHead.empty() && OrderTemp.empty())
		OTemp.OrderNum = OrderHead.back().OrderNum + 1;
	else if(!OrderTemp.empty())
		OTemp.OrderNum = OrderTemp.back().OrderNum + 1;
	OTemp.HotelName = RoomInHotel->name;
	OTemp.City = RoomInHotel->city;
	OTemp.Location = RoomInHotel->location;
	OTemp.DayIn = DayIn;
	OTemp.DayOut = DayOut;
	OTemp.RoomNum = num;
	int time = DayBook(DayIn, DayOut);
	//遍历房间数组
	for (int i = 0; i < RoomInHotel->RoomInHotel.size(); i++) {
		if (num == RoomInHotel->RoomInHotel[i].num) {
			OTemp.RoomType = RoomInHotel->RoomInHotel[i].type;
			OTemp.Price = RoomInHotel->RoomInHotel[i].price*time;
			break;
		}
	}
	//有问题
	cout.setf(ios::left);
	cout << endl << "预订成功，订单为：" << endl;
	cout << setw(10) << "订单号"<<setw(20)<<"酒店名称"<<setw(25)<<"位置"<<setw(25)<<"预定时间"<<setw(30)<<"房间"<<setw(20)<<"总价格" << endl;
	cout << setw(10) << OTemp.OrderNum << setw(20) << OTemp.HotelName << OTemp.City << ','
		<< setw(20)<< OTemp.Location  << DayIn << '-' << setw(20)<< DayOut  << OTemp.RoomType << '-' << setw(20)<< OTemp.RoomNum  << OTemp.Price << endl;
	OrderTemp.push_back(OTemp);
}

//订房天数
int DayBook(string DayIn, string DayOut)
{
	DateStan(DayIn);
	DateStan(DayOut);
	int yearIn = 0, yearOut = 0, monthIn = 0, monthOut = 0, dayIn = 0, dayOut = 0, mark = 0;
	for (int i = 0; i < DayIn.size(); i++) {
		if (DayIn[i] == '/')
			mark++;
		else {
			if (mark == 0)
				yearIn = yearIn * 10 + (int)(DayIn[i] - '0');
			else if (mark == 1)
				monthIn = monthIn * 10 + (int)(DayIn[i] - '0');
			else if (mark == 2)
				dayIn = dayIn * 10 + (int)(DayIn[i] - '0');
		}	}
	mark = 0;
	for (int i = 0; i < DayOut.size(); i++) {
		if (DayOut[i] == '/')
			mark++;
		else {
			if (mark == 0)
				yearOut = yearOut * 10 + (int)(DayOut[i] - '0');
			else if (mark == 1)
				monthOut = monthOut * 10 + (int)(DayOut[i] - '0');
			else if (mark == 2)
				dayOut = dayOut * 10 + (int)(DayOut[i] - '0');
		}	}

	int total = 0, LeapYear = 0;//一共的天数 闰年的年数
	for (int i = yearIn; i < yearOut; i++)
		if (LEAPYear(i))
			LeapYear++;
	total = 365 * (yearOut - yearIn - LeapYear) + 366 * LeapYear 
		- DateToBegin(yearIn, monthIn, dayIn) + DateToBegin(yearOut, monthOut, dayOut);
	return total;
}

//是否是闰年
bool LEAPYear(int year)
{
	if (year % 1000 == 0 && year % 400 == 0)
		return 1;
	else if (year % 4 == 0)
		return 1;
	else
		return 0;
}

//距离1.1号有几天
int DateToBegin(int year, int month, int day)
{
	int Month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	if (LEAPYear(year))
		Month[1] = 29;
	for (int i = 0; i < month - 1; i++)
		days += Month[i];
	days += day;
	return days;
}

//讲道理 输出格式还有一点问题
//打印出临时订单（默认这次登陆的和上次登录的不是一个人）
void OrderShow(vector<Order>OrderHead)
{
	cout << "订单号\t\t" << "酒店名称\t\t" << "位置\t\t"
		<< "预定时间\t\t" << "房间\t\t" << "总价格\t\t" << endl;
	for (int i = 0; i < OrderHead.size(); i++) {
		cout << OrderHead[i].OrderNum << "\t\t" << OrderHead[i].HotelName << "\t\t"
			<< OrderHead[i].Location << "\t" << OrderHead[i].DayIn << '-' << OrderHead[i].DayOut
			<< "\t\t" << OrderHead[i].RoomType << '-' << OrderHead[i].RoomNum << "\t\t"
			<< OrderHead[i].Price << endl;
	}
}

//删除编号为num的订单 对临时订单操作
void OrderCancel(vector<Order>&OrderHead, int OrderNum)
{
	vector<Order>::iterator it;
	for (it = OrderHead.begin(); it != OrderHead.end();) {
		if (it->OrderNum== OrderNum)
			it = OrderHead.erase(it);
		else
			++it;
	}
}

//找到一家酒店的最低标价
int LowestPrice(Hotel *hotel)
{
	int price = 0;
	for (int i = 0; i < hotel->RoomInHotel.size(); i++) {
		if (price == 0)
			price = hotel->RoomInHotel[i].price;
		else if(price > hotel->RoomInHotel[i].price)
			price = hotel->RoomInHotel[i].price;
	}
	return price;
}

//根据城市查找酒店
void SearchHotel(string CityName, vector<City> CityHead, string location)
{
	cout << "酒店编号：\t" << "酒店名称：\t\t" << "位置：\t\t" << "价格：\t\t" << endl;
	int i = 0, j = 0, k = 0;
	bool flag = 0;
	for (i = 0; i < CityHead.size(); i++) {
		if (CityName == CityHead[i].CityName)
		{
			for (j = 0; j < CityHead[i].LocaHead.size(); j++) {
				if (location.size() == 0) {
					flag = 1;
					for (k = 0; k < CityHead[i].LocaHead[j].HotelInLoca.size(); k++) {
						cout << CityHead[i].LocaHead[j].HotelInLoca[k]->num << "\t\t"
							<< CityHead[i].LocaHead[j].HotelInLoca[k]->name << "\t\t"
							<< CityHead[i].LocaHead[j].HotelInLoca[k]->location << "\t"
							<< LowestPrice(CityHead[i].LocaHead[j].HotelInLoca[k]) << "起" << endl;
					}
				}
				else {
					if (substring(CityHead[i].LocaHead[j].LocaName, location)) {
						flag = 1;
						for (k = 0; k < CityHead[i].LocaHead[j].HotelInLoca.size(); k++) {
							cout << CityHead[i].LocaHead[j].HotelInLoca[k]->num << "\t\t"
								<< CityHead[i].LocaHead[j].HotelInLoca[k]->name << "\t\t"
								<< CityHead[i].LocaHead[j].HotelInLoca[k]->location << "\t"
								<< LowestPrice(CityHead[i].LocaHead[j].HotelInLoca[k]) << "起" << endl;
						}
					}				}			}		}
	}
	if (flag == 0)
		cout << "没有酒店" << endl;
}

//再在房间数组里该房间下挂上日期
void RoomTag(string DayIn, string DayOut, string num, Hotel *&RoomInHotel)
{
	for (int i = 0; i < RoomInHotel->RoomInHotel.size(); i++) {
		if (num == RoomInHotel->RoomInHotel[i].num) {
			RoomInHotel->RoomInHotel[i].DayIn.push_back(DayIn);
			RoomInHotel->RoomInHotel[i].DayOut.push_back(DayOut);
		}
	}
}

//将临时订单追加到总订单
void OrderAdd(vector<Order>&Ordertot, vector<Order>Ordertemp)
{
	for (int i = 0; i < Ordertemp.size(); i++) {
		Ordertot.push_back(Ordertemp[i]);
	}
}

//显示房间搜索内容 //////有点问题 南京的如家什么鬼
Hotel *RoomShow(string hotel, Hotel *HotelHead)
{
	cout << "编号：\t\t" << "房间类型\t" << "价格\t\t" << endl;
	Hotel *temp = HotelHead;
	bool flag = 0;
	while (temp) {
		if (temp->num == hotel) {
			for (int i = 0; i < temp->RoomInHotel.size(); i++) {
				cout << temp->RoomInHotel[i].num << "\t\t"
					<< temp->RoomInHotel[i].type << "\t\t"
					<< temp->RoomInHotel[i].price << endl;
			}
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if (flag == 0)
	{
		cout << "没有该房间" << endl;
		return 0;
	}
	else
		return temp;
}

//判断b是否是a子串
bool substring(string a, string b)
{
	int len1 = a.size(), len2 = b.size();
	for (int i = 0; i < len1 - len2; i++) {
		if (b == a.substr(i, len2))
			return 1;
	}
	return 0;
}

//判断时间输入否有错
bool DateLegal(string date)
{
	int year = 0, month = 0, day = 0, count = 0;
	for (int i = 0; i < date.size(); i++) {
		if (date[i] == '/')
			count++;
		else {
			if (count == 0)
				year = year * 10 + (int)(date[i] - '0');
			else if (count == 1)
				month = month * 10 + (int)(date[i] - '0');
			else
				day = day * 10 + (int)(date[i] - '0');
		}
	}
	int MonthDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (LEAPYear(year))
		MonthDay[1] = 29;
	if (month > 13 || month < 1)
		return 0;
	else if (day > MonthDay[month - 1])
		return 0;
	else
		return 1;
}

//输入评价
void CommentOn(string hotel, string buffer, vector<Comment>&CommentHead)
{
	bool flag = 0;
	for (int i = 0; i < CommentHead.size(); i++) {
		if (hotel == CommentHead[i].HotelNum)
		{
			CommentHead[i].Com.push_back(buffer);
			flag = 1;
		}
		break;
	}
	if (flag == 0)
	{
		Comment temp;
		temp.HotelNum = hotel;
		temp.Com.push_back(buffer);
		CommentHead.push_back(temp);
	}
}

//查看评价
void CommentShow(string hotel, vector<Comment>CommentHead)
{
	bool flag = 0;
	cout << "酒店评价：" << endl;
	for (int i = 0; i < CommentHead.size(); i++)	{
		if (hotel == CommentHead[i].HotelNum && !CommentHead[i].HotelNum.empty()) {
			for (int j = 0; j < CommentHead[i].Com.size(); j++)
				cout << CommentHead[i].Com[j] << endl;
			cout << endl;
		}
		else if (hotel == CommentHead[i].HotelNum && CommentHead[i].HotelNum.empty())
		{
			cout << "还没有评价" << endl;
			cout << endl;
		}
	}
	system("pause");
}

//判断酒店是否存在
bool HotelExist(Hotel *head,string hotel)
{
	Hotel *curr = head;
	while (curr)
	{
		if (hotel == curr->num)
			return 1;
		curr = curr->next;
	}
	return 0;
}