#ifndef ROLE_H
#define ROLE_H

#include"DataStruct.h"

void IdentityShow(Role OneRole,vector<Task>tasks);	//��ʾ��ǰ��ɫ��Ϣ
void BuyStuff(vector<Stuff>Shop, Role &RoleNow);	//ȥ�̵�����
void EatStuff(Role &OneRole);						//��ҩ�ʳƷ
void SellStuff(Role &OneRole);						//��ҩ�ʳƷ
void LevelUp(Role &OneRole);						//����
void ShopShow(vector<Stuff>Shop);					//��ʾ�̵�
void BagShow(Role OneRole);							//��ʾ������Ϣ
bool TaskFin(int TaskNum, vector<Monster>mst,vector<Task>tsk);	//�жϸô�������ǲ���������
bool GameOver(vector<Task>task);					//�ж��Ƿ���������������
#endif // !ROLE_H
