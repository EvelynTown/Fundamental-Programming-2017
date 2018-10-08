#ifndef FILE_H
#define FILE_H

#include "DataStruct.h"
#include"Gamer.h"
#include<algorithm>

//文件类
class FileClass
{
private:
	string BackgroundFile;
	string GamerFile;
public:
	FileClass() {
		BackgroundFile = "Background.xml";
		GamerFile = "Gamer.xml";
	}
	//读档背景文件,存入怪物、npc、地图、门派、商店
	void FileInBackgroung(vector<City>&map, vector<School>&school, vector<Stuff>&shop, vector<NPC>&npc, vector<Monster>&monster,vector<Task>&tasks);																														//读档用户信息
	//读档用户信息
	void FileInGamer(vector<GamerClass>&Gamers, vector<School>school, vector<Stuff>shop);
	//存档
	void FileOutGamer(vector<GamerClass>Gamers);
};

//string转成int
int StrToInt(string str);

//string转成double
double StrToDbl(string str);

//输出我看一下
void Print(vector<City>map, vector<School>school, vector<Stuff>shop, vector<NPC>npc,vector<Monster>monster);

//返回门派结构
School Sch(int n, vector<School>school);

//解析x,x,x的string类转成int数组
void StrToIntVec(string str, vector<int>&num);

//返回一个背包结构
void BagStf(vector<int> num, Bag &bag, vector<Stuff>shop);

//返回物品结构
Stuff StfNum(int n, vector<Stuff>shop);

//返回背包数组
string BagIntVec(Bag bag);

#endif // !FILE_H
