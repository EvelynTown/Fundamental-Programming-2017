#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include"tinyxml2.h"

using namespace std;
using namespace tinyxml2;

//任务
struct Task
{
	int TaskNum;		//任务编号
	string TaskName;	//任务名字
	bool Complete;		//是否完成
	string word;		//任务中NPC需要说的话
	int ExperienceAdd;	//经验加成
	vector<int>MstToKill;	//要击杀的怪物
};

//技能
struct Skill
{
	string SkillName;
	int SkillNum;
	string Descript;
	double plus;	//增益效果	
};

//东西
struct Stuff
{
	string StuffName;	//东西名字
	int StuffNum;
	string Descript;	//描述
	string Type;		//东西的类别
	int Count;			//东西的数量
	int Add;			//任务物品Add为0，药品食物为正整数
	int Price;			//东西的价钱	
};

//NPC
struct NPC
{
	string NPCName;		//NPC名字
	int NPCNum;			//NPC编号
	string Descript;	//NPC描述
	vector<int>Tasks;	//NPC有的任务
};

//怪物
struct Monster
{
	string MonsterName;
	string Descript;	//描述
	int MonsterNum;
	int HP;				//体力
	int Atk;			//攻击力
	int Def;			//防御能力
	int ExperienceAdd;	//经验加成
	bool Beat;			//是不是被砍过了
};

//门派
struct School
{
	string SchoolName;		//门派名字
	string Descript;
	int SchoolNum;			//门派编号
	vector<Skill>Skills;	//门派技能
	string Weapon;			//武器
};

//单个城市的地图
struct City
{
	string CityName;
	int CityNum;
	string Descript;
	vector<int>NPC;		//该地点的NPC
	vector<int>Monster;	//该地点的小怪物
};

//背包
struct Bag
{
	int Capacity;			//容量大小
	vector<Stuff>Things;	//包里的东西
	int Coin;				//包里的钱
};

//用户
struct Role			
{
	string RoleName;
	int HP;				//体力
	int Atk;			//攻击力
	int Def;			//防御能力
	int Grade;			//等级
	int Experience;		//经验
	Bag bag;			//背包
	vector<int>TaskCpl;	//已完成的任务
	School SchoolIn;	//所属门派
	Stuff Wearing;		//穿的衣服
};

#endif // !DATASTRUCT_H

