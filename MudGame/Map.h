#ifndef MAP_H
#define MAP_H

#include"DataStruct.h"

//��ͼ��
class MapClass
{
private:
	vector<City>Cities;	//�ܵĵ�ͼ��Ϣ
	vector<NPC>NPCs;
	vector<Monster>Msts;
	vector<Task>Tasks;
public:
	MapClass(vector<City>CityT, vector<NPC>NPCT,vector<Monster>MstT,vector<Task>tasks) {
		Cities = CityT;
		NPCs = NPCT;
		Msts = MstT;
		Tasks = tasks;
	}
	//void BattleShow(int MstNum);			//��ʾս������
	void SceneInfoShow(int CityNum);		//��ʾ��������
	void NPCInfoShow(int NPCNum);			//��ʾ��ǰNPC��������
	void MapShow();							//ѡ�����
	void MstShow(int MstNum);				//��ʾ������Ϣ
	void TaskShow(int NPCNum,int TaskNum, vector<Task>task);	//��ʾ������Ϣ
	bool WhetherTask(int TaskNum, int MstNum);	//�ж��ǲ���Ϊ�������ɱ��
};
#endif // !MAP_H
