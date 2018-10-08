#ifndef FILE_H
#define FILE_H

#include "DataStruct.h"
#include"Gamer.h"
#include<algorithm>

//�ļ���
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
	//���������ļ�,������npc����ͼ�����ɡ��̵�
	void FileInBackgroung(vector<City>&map, vector<School>&school, vector<Stuff>&shop, vector<NPC>&npc, vector<Monster>&monster,vector<Task>&tasks);																														//�����û���Ϣ
	//�����û���Ϣ
	void FileInGamer(vector<GamerClass>&Gamers, vector<School>school, vector<Stuff>shop);
	//�浵
	void FileOutGamer(vector<GamerClass>Gamers);
};

//stringת��int
int StrToInt(string str);

//stringת��double
double StrToDbl(string str);

//����ҿ�һ��
void Print(vector<City>map, vector<School>school, vector<Stuff>shop, vector<NPC>npc,vector<Monster>monster);

//�������ɽṹ
School Sch(int n, vector<School>school);

//����x,x,x��string��ת��int����
void StrToIntVec(string str, vector<int>&num);

//����һ�������ṹ
void BagStf(vector<int> num, Bag &bag, vector<Stuff>shop);

//������Ʒ�ṹ
Stuff StfNum(int n, vector<Stuff>shop);

//���ر�������
string BagIntVec(Bag bag);

#endif // !FILE_H
