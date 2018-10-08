#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

class calculator
{
private:
	string exp;	//ת���ɺ�׺���ʽ֮���
	int length;
	int Sin;
	int Cos;
	int Tan;
	vector<string>recent;
	bool Legal;
public:
	bool legal();	//�ж��Ƿ�Ϸ�������1��ʾ�Ϸ���0��ʾ���Ϸ�
	void calculate();
	void brace();
	void GetIn();
	void analyse();
	void nothing()	{
		Sin = 0; Cos = 0; Tan = 0; Legal = 0;
	};
	string convert(double s);
	void Additional();
};

void calculator::GetIn()
{
	cout << "��������ʽ:";
	getline(cin, exp);
	if(exp == "")
		getline(cin, exp);
	if (exp.compare("quit") == 0)
		exit(0);
	length = exp.size();
	nothing();
}

bool calculator::legal()
{
	int Rn = 0, Ln = 0;
	//��дȫ��ת����Сд
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] >= 'A' && exp[i] <= 'Z')
			exp[i] += 32;
		if (!((exp[i] <= '9' && exp[i] >= '0') || exp[i] == 't' || exp[i] == 'a' || exp[i] == 'n' || exp[i] == 's' || exp[i] == 'i' || exp[i] == 'c' || exp[i] == 'o' || exp[i] == '(' || exp[i] == ')' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '=' || exp[i] == 'p' || exp[i] == '.')) {
			cout << "�зǷ�������" << endl;
			return 0;
		}
		if (exp[i] == ')')
			Rn++;
		else if (exp[i] == '(')
			Ln++;
		if (Rn > Ln) {
			cout << "���ʽ�����Ų�ƥ��" << endl;
			return 0;
		}	}
	if (Rn != Ln) {
		cout << "���Ų�ƥ��" << endl;
		return 0;
	}
	//�ж������Ƿ�����
	else {
		if (!(exp.substr(0, 2) == "pi" || (exp[0] <= '9' && exp[0] >= '0') || exp.substr(0, 3) == "tan" || exp.substr(0, 3) == "sin" || exp.substr(0, 3) == "cos" || exp[0] == '(' || exp[0] == '-')) {
			cout << "���ʽ�������󣬲�����ʵ��/���Ǻ���/��������ͷ" << endl;
			return 0;
		}
		else if (!(exp.substr(length - 2, 2) == "pi" || (exp[length - 1] <= '9' && exp[length - 1] >= '0') || exp[length - 1] == ')')) {
			cout << "���ʽ�������󣬲�����ʵ��/��������β" << endl;
			return 0;
		}
		for (int i = 0; i < exp.size(); i++) {
			if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
				if (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == ')') {
					cout << "���ʽ�������󣬲���������ʹ������/������" << endl;
					return 0;
				}			}
			else if (exp[i] <= 'z' && exp[i] >= 'a') {
				if (exp[i] == 'p') {
					if (exp[i + 1] != 'i') {
						cout << "���ʽ�������󣬿�����pi��������" << endl;
						return 0;
					}
					else if (!(exp[i + 2] == '\0' || exp[i + 2] == '+' || exp[i + 2] == '-' || exp[i + 2] == '*' || exp[i + 2] == '/' || exp[i + 2] == ')')) {
						cout << "ʵ�����治�����������������Ǻ�������ʵ��" << endl;
						return 0;
					}
					else {
						exp.erase(i, 2);
						exp.insert(i, "3.1415926");
						i += 9;
					}				}
				else if (exp[i] == 't') {
					string temp = exp;
					if (temp[i + 1] != 'a' || temp[i + 2] != 'n') {
						cout << "���ʽ�������󣬿�����tan��������" << endl;
						return 0;
					}
					else {
						i += 2;
						if (!(exp[i + 1] == '(' || (exp[i + 1] <= '9' && exp[i + 1] >= '0') || exp[i + 1] == 'p' || exp[i + 1] == '-' || exp[i + 1] == 't' || exp[i + 1] == 's' || exp[i + 1] == 'c')) {
							cout << "���Ǻ������治�����������ͳ�����֮�������������" << endl;
							return 0;
						}					}				}
				else if (exp[i] == 'c') {
					if (exp[i + 1] != 'o' || exp[i + 2] != 's') {
						cout << "���ʽ�������󣬿�����cos��������" << endl;
						return 0;
					}
					else {
						i += 2;
						if (!(exp[i + 1] == '(' || (exp[i + 1] <= '9' && exp[i + 1] >= '0') || exp[i + 1] == 'p' || exp[i + 1] == '-' || exp[i + 1] == 't' || exp[i + 1] == 's' || exp[i + 1] == 'c')) {
							cout << "���Ǻ������治�����������ͳ�����֮�������������" << endl;
							return 0;
						}					}				}
				else if (exp[i] == 's') {
					if (exp[i + 1] != 'i' || exp[i + 2] != 'n') {
						cout << "���ʽ�������󣬿�����sin��������" << endl;
						return 0;
					}
					else {
						i += 2;
						if (!(exp[i + 1] == '(' || (exp[i + 1] <= '9' && exp[i + 1] >= '0') || exp[i + 1] == 'p' || exp[i + 1] == '-' || exp[i + 1] == 't' || exp[i + 1] == 's' || exp[i + 1] == 'c')) {
							cout << "���Ǻ������治�����������ͳ�����֮�������������" << endl;
							return 0;
						}					}				}			}
			else if ((exp[i] <= '9' && exp[i] >= '0') || exp[i] == '.') {
				int point = 0;
				for (i; !((exp[i] <= '9' && exp[i] >= '0') || exp[i] == '.'); i++) {
					if (exp[i] == '.')
						point++;
				}
				if (point > 1) {
					cout << "С�������д���" << endl;
					return 0;
				}
				else if (point <= 1) {
					if (!((exp[i + 1] >= '0' && exp[i + 1] <= '9') || exp[i + 1] == ')' || exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '\0' || exp[i + 1] == '.')) {
						cout << "ʵ�����治�����������������Ǻ�������ʵ��" << endl;
						return 0;
					}				}			}
			else if (exp[i] == '(') {
				if (!(exp[i + 1] == '(' || exp[i + 1] == 't' || exp[i + 1] == 'c' || exp[i + 1] == 's' || exp[i + 1] == 'p' || (exp[i + 1] <= '9' && exp[i + 1] >= '0') || exp[i + 1] == '-')) {
					cout << "���������治�������������߳���������Ĳ�����" << endl;
					return 0;
				}			}
			else if (exp[i] == ')') {
				if (!(exp[i + 1] == ')' || exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '\0')) {
					cout << "���������������������߲������������Ǻ���" << endl;
					return 0;
				}			}		}	}
	recent.push_back(exp);
	Legal = 1;
	return 1;
}

void calculator::brace()
{
	for (int i = 0; i < exp.size(); i++) {
		//����Ǹ���
		if ((i == 0 || exp[i - 1] == 't' || exp[i - 1] == 'c' || exp[i - 1] == 's' || exp[i - 1] == 'n' || exp[i - 1] == '(') && exp[i] == '-') {
			exp.insert(i, "(0");
			i += 2;
			if (exp[i + 1] == '(') {
				int brace = 0, j = 0;
				for (j = i + 1; j < exp.size(); j++) {
					if (exp[j] == '(')
						brace++;
					else if (exp[j] == ')')
						brace--;
					if (brace == 0) {
						exp.insert(j, ")");
						break;
					}				}			}
			else {
				int j = i + 1;
				for (j = i + 1; exp[j] != '\0'; j++) {
					if (!((exp[j] <= '9' && exp[j] >= '0') || exp[j] == '.')) {
						exp.insert(j, ")");
						break;
					}				}
				if (exp[j] == '\0')
					exp.insert(j, ")");
			}		}	}
	//�����Ǻ������в���
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == 't' || exp[i] == 'c' || exp[i] == 's') {

			exp.insert(i, "(");
			i++;
			if (exp[i + 3] == '(') {
				int j = i + 3;
				int brace = 0;
				for (j; j < exp.size(); j++) {
					if (exp[j] == '(')
						brace++;
					else if (exp[j] == ')')
						brace--;
					if (brace == 0) {
						exp.insert(j, ")");
						break;
					}				}			}
			//
			else {
				int j = i + 3;
				for (j; exp[j] != '\0'; j++) {
					if (exp[j] == '(') {
						j = exp.find(')', j);
					}
					else if (!((exp[j] <= 'z' && exp[j] >= 'a') || (exp[j] <= '9' && exp[j] >= '0') || exp[j] == '.')) {
						exp.insert(j, ")");
						break;
					}				}
				if (exp[j] == '\0')
					exp.insert(j, ")");
			}
			i += 2;
		}	}
	//�Գ˳������ж�
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '*' || exp[i] == '/') {
			if (exp[i - 1] == ')') {
				int brace = 0;
				for (int j = i - 1; j >= 0; j--) {
					if (exp[j] == ')')
						brace++;
					else if (exp[j] == '(')
						brace--;
					if (brace == 0) {
						exp.insert(j, "(");
						i++;
						break;
					}				}			}
			else {
				for (int j = i - 1; j >= 0; j--) {
					if (!((exp[j] <= '9' && exp[j] >= '0') || exp[j] == '.')) {
						exp.insert(j + 1, "(");
						i++;
						break;
					}
					else if (j == 0) {
						exp.insert(0, "(");
						i++;
						break;
					}				}			}
			if (exp[i + 1] == '(') {
				int brace = 0;
				for (int j = i + 1; j <= exp.size(); j++) {
					if (exp[j] == '(')
						++brace;
					else if (exp[j] == ')')
						--brace;
					if (brace == 0) {
						exp.insert(j, ")");
						i++;
						break;
					}				}			}
			else {
				for (int j = i + 1; j <= exp.size(); j++) {
					if (!((exp[j] <= '9' && exp[j] >= '0') || exp[j] == '.') || exp[j] == '\0') {
						exp.insert(j, ")");
						i++;
						break;
					}				}			}		}	}
	//�ԼӼ����в���
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] == '+' || exp[i] == '-') {
			if (exp[i - 1] == ')') {
				int brace = 0;
				for (int j = i - 1; j >= 0; j--) {
					if (exp[j] == ')')
						brace++;
					else if (exp[j] == '(')
						brace--;
					if (brace == 0) {
						exp.insert(j, "(");
						i++;
						break;
					}			}			}
			else {
				for (int j = i - 1; j >= 0; j--) {
					if (!((exp[j] <= '9' && exp[j] >= '0') || exp[j] == '.') || j == 0)
					{
						exp.insert(j, "(");
						i++;
						break;
					}				}			}
			if (exp[i + 1] == '(') {
				int brace = 0;
				for (int j = i + 1; j <= exp.size(); j++) {
					if (exp[j] == '(')
						++brace;
					else if (exp[j] == ')')
						--brace;
					if (brace == 0) {
						exp.insert(j, ")");
						i++;
						break;
					}				}			}
			else {
				for (int j = i + 1; j <= exp.size(); j++) {
					if (!((exp[j] <= '9' && exp[j] >= '0') || exp[j] == '.') || exp[j] == '\0') {
						exp.insert(j, ")");
						i++;
						break;
					}				}			}		}	}}

void calculator::analyse()
{
	int j = 0;
	string temp;
	double a = 0, b = 0, c = 0;
	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] == ')') {
			j = exp.rfind('(', i);
			temp = exp.substr(j + 1, i - j - 1);
			break;
		}	}
	int length = temp.size() - 1;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == 't') {
			a = atof(temp.substr(3).c_str());
			b = tan(a);
			exp.replace(j, length + 3, convert(b));
			Tan++;
			break;
		}
		else if (temp[i] == 'c') {
			a = atof(temp.substr(3).c_str());
			b = cos(a);
			exp.replace(j, length + 3, convert(b));
			Cos++;
			break;
		}
		else if (temp[i] == 's') {
			a = atof(temp.substr(3).c_str());
			b = sin(a);
			exp.replace(j, length + 3, convert(b));
			Sin++;
			break;
		}
		else if (temp[i] == '+') {
			a = atof(temp.substr(0, i).c_str());
			b = atof(temp.substr(i + 1, length - i).c_str());
			c = a + b;
			exp.replace(j, length + 3, convert(c));
			break;
		}
		else if (temp[i] == '-' && i != 0) {
			a = atof(temp.substr(0, i).c_str());
			b = atof(temp.substr(i + 1, length - i).c_str());
			c = a - b;
			exp.replace(j, length + 3, convert(c));
			break;
		}
		else if (temp[i] == '*') {
			a = atof(temp.substr(0, i).c_str());
			b = atof(temp.substr(i + 1, length - i).c_str());
			c = a * b;
			exp.replace(j, length + 3, convert(c));
			break;
		}
		else if (temp[i] == '/') {
			a = atof(temp.substr(0, i).c_str());
			b = atof(temp.substr(i + 1, length - i).c_str());
			if (b == 0) {
				cout << "����������Ϊ��" << endl;
				exit(0);
			}
			c = a / b;
			exp.replace(j, length + 3, convert(c));
			break;
		}
		else if (temp[i + 1] == '\0') {
			exp.replace(j, length + 3, temp);
			break;
		}	}}

string calculator::convert(double s) {
	std::ostringstream o;
	if (!(o << s))
		return "";
	return o.str();
}

void calculator::calculate()
{
	int count = 0;
	for (int i = 0; exp[i] != '\0'; i++) {
		if (exp[i] == '(')
			++count;
	}
	for (int i = 0; i < count; i++) {
		analyse();
	}
	double result = atof(exp.c_str());
	cout << fixed << setprecision(8) << result << endl;
}

void calculator::Additional()
{
	int instr;
	cout << "����������ָʾ(����1���������ʹ��Ƶ�ʣ�2������5�����ʽ��������������)" << endl;
	cin >> instr;
	
	if (Legal) {
		if (instr == 1) {
			cout << "������ʹ��Ƶ�ʣ�" << endl;
			cout << "sin:" << Sin << endl;
			cout << "cos:" << Cos << endl;
			cout << "tan:" << Tan << endl;
		}
		else if (instr == 2) {
			int total = recent.size();
			cout << "���5������ģ���ȷ�ģ����ʽ" << endl;
			if (total <= 5) {
				for (int i = 0; i < total; i++)
					cout << recent[i] << endl;
			}
			else {
				for (int i = total - 5; i < total; i++)
					cout << recent[i] << endl;
			}		}	}}