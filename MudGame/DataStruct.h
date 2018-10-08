#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include"tinyxml2.h"

using namespace std;
using namespace tinyxml2;

//����
struct Task
{
	int TaskNum;		//������
	string TaskName;	//��������
	bool Complete;		//�Ƿ����
	string word;		//������NPC��Ҫ˵�Ļ�
	int ExperienceAdd;	//����ӳ�
	vector<int>MstToKill;	//Ҫ��ɱ�Ĺ���
};

//����
struct Skill
{
	string SkillName;
	int SkillNum;
	string Descript;
	double plus;	//����Ч��	
};

//����
struct Stuff
{
	string StuffName;	//��������
	int StuffNum;
	string Descript;	//����
	string Type;		//���������
	int Count;			//����������
	int Add;			//������ƷAddΪ0��ҩƷʳ��Ϊ������
	int Price;			//�����ļ�Ǯ	
};

//NPC
struct NPC
{
	string NPCName;		//NPC����
	int NPCNum;			//NPC���
	string Descript;	//NPC����
	vector<int>Tasks;	//NPC�е�����
};

//����
struct Monster
{
	string MonsterName;
	string Descript;	//����
	int MonsterNum;
	int HP;				//����
	int Atk;			//������
	int Def;			//��������
	int ExperienceAdd;	//����ӳ�
	bool Beat;			//�ǲ��Ǳ�������
};

//����
struct School
{
	string SchoolName;		//��������
	string Descript;
	int SchoolNum;			//���ɱ��
	vector<Skill>Skills;	//���ɼ���
	string Weapon;			//����
};

//�������еĵ�ͼ
struct City
{
	string CityName;
	int CityNum;
	string Descript;
	vector<int>NPC;		//�õص��NPC
	vector<int>Monster;	//�õص��С����
};

//����
struct Bag
{
	int Capacity;			//������С
	vector<Stuff>Things;	//����Ķ���
	int Coin;				//�����Ǯ
};

//�û�
struct Role			
{
	string RoleName;
	int HP;				//����
	int Atk;			//������
	int Def;			//��������
	int Grade;			//�ȼ�
	int Experience;		//����
	Bag bag;			//����
	vector<int>TaskCpl;	//����ɵ�����
	School SchoolIn;	//��������
	Stuff Wearing;		//�����·�
};

#endif // !DATASTRUCT_H

