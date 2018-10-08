#include"Calculate.h"  

int main() {
	calculator cal;
	while (1) {
		cal.GetIn();
		if (cal.legal()) {
			cal.brace();
			cal.calculate();
			cal.Additional();
			cout << endl;
		}
		else
			continue;
	}
	return 0;
}