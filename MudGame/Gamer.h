#ifndef GAMER_H
#define GAMER_H

#include"DataStruct.h"
#include"Role.h"
#include<iomanip>
#include <stdio.h>
#include <conio.h>

//�û���
class GamerClass
{
private:
	string Account;	//��¼�˺�
	string Password;	//��¼����
	vector<Role>Roles;	//һ���˺�ӵ�еĶ����ɫ
public:
	GamerClass(string acc, string psw, vector<Role>roleTemp) {
		Account = acc;
		Password = psw;
		Roles = roleTemp;
	}
	GamerClass(string acc, string psw,Role role) {
		Account = acc;
		Password = psw;
		Roles.push_back(role);
	}
	GamerClass(){}

	void RoleCreate(vector<School>sch);	//����һ���µĽ�ɫ
	void RoleDelete(string NickName);	//ɾ��һ����ɫ
	bool Code();						//�������������ʾΪ*
	bool NameRep(string name);			//�жϸ��ǳ��Ƿ���� 1���� 0������
	void RoleShow();					//��ʾ��ǰ�˺�ӵ�еĽ�ɫ
	bool ReturnRole(Role &rolePre, string NickName, int &n);	//���ص�ǰ��ɫ
	string AccReturn() {		//�����˺�
		return Account;	}
	string PswReturn() {
		return Password;		//��������
	}
	//�浵ʱ������ɫ��Ϣ
	void RolesReturn(vector<Role>&roles) {
		roles = Roles;
	}
	void RoleModi(Role role,int n) {
		Roles[n] = role;
	}
};

void AccCreate(vector<GamerClass>&gamers, vector <School>sch);	//ע��

bool Correct(string psw, string psw1);	//���������Ƿ�һ��

string IntToStr(vector<int>n);

#endif // !GAMER_H