#include"Map.h"

//��ʾ������Ϣ
void MapClass::SceneInfoShow(int CityNum)
{
	cout << "��ǰ������" << Cities[CityNum].CityName << endl;

	cout << "��ǰ����NPC��";
	for (int i = 0; i < Cities[CityNum].NPC.size(); i++)
		cout << NPCs[Cities[CityNum].NPC[i]].NPCName << ' ';
	cout << endl;

	cout << "��ǰ�������";
	for (int i = 0; i < Cities[CityNum].Monster.size(); i++)
		cout << Msts[Cities[CityNum].Monster[i]].MonsterName << ' ';
	cout << endl;
}

//��ʾ��ǰNPC��������
void MapClass::NPCInfoShow(int NPCNum)
{
	if (NPCNum == -1)
		cout << "δѡ��NPC" << endl;
	else {
		cout << "NPC���֣�" << NPCs[NPCNum].NPCName << endl;
		cout << "NPC���ܣ�" << NPCs[NPCNum].Descript << endl;
		cout << "��ǰNPC��������" << endl;
		for (int i = 0; i < NPCs[NPCNum].Tasks.size(); i++)
			cout << Tasks[NPCs[NPCNum].Tasks[i]].TaskName<< ' ';
		cout << endl;
	}
}

//��ʾ����
void MapClass::MapShow()
{
	for (int i = 0; i < Cities.size(); i++)
		cout << Cities[i].CityName << ' ';
	cout << endl;
}

//��ʾ������Ϣ
void MapClass::MstShow(int MstNum)
{
	if (MstNum = -1)
		cout << "δѡ��ս������" << endl;
	else {
		cout << "�������֣�" << Msts[MstNum].MonsterName << endl;
		cout << "���ܣ�" << Msts[MstNum].Descript << endl;
		cout << "HP��" << Msts[MstNum].HP << endl;
		cout << "Atk��" << Msts[MstNum].Atk << endl;
		cout << "Def��" << Msts[MstNum].Def << endl;
		cout << "����ӳɣ�" << Msts[MstNum].ExperienceAdd << endl;
	}
	cout << endl;
}

//��ʾ������Ϣ
void MapClass::TaskShow(int NPCNum, int TaskNum, vector<Task>task)
{
	if (TaskNum < 0)
		cout << "��ѡ������" << endl;
	else {
		cout << "�������ƣ�" << task[TaskNum].TaskName << endl;
		cout << "����������" << NPCs[NPCNum].NPCName << ':' << task[TaskNum].word << endl;
		cout << "����ӳɣ�" << task[TaskNum].ExperienceAdd << endl;
		cout << "�Ƿ����:";
		if (task[TaskNum].Complete)
			cout << "�����" << endl;
		else
			cout << "δ���" << endl;
	}
	cout << endl;
}

//�ж��ǲ���Ϊ�������ɱ��
bool MapClass::WhetherTask(int TaskNum, int MstNum)
{
	if (TaskNum >= 0 && TaskNum < Tasks.size()) {
		for (int i = 0; i < Tasks[TaskNum].MstToKill.size(); i++)
			if (MstNum == Tasks[TaskNum].MstToKill[i])
				return 1;
		return 0;
	}
	return 0;
}