#include <iostream>
#include <string>
using namespace std;
int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		int i;
		int flag = 0;
		for (i = 0; str1[i] != '\0'; ++i) {
			if (str1[i] == '"') {
				flag = (flag ^ 1);
			}
			int j = 0;
			int t = i;
			while (str1[t] == str2[j]&&str2[j]!='\0'&&str1[t]!='\0') {
				++t;
				++j;
			}
			if (str2[j] == '\0') {
				if ((str1[t - 1] == '\"'&&str2[j - 1] == '\"') || (str1[t - 1] != '\"'&&str2[j - 1] != '\"'&&flag == 0)) {
					cout << "Ignore" << endl;
					break;
				}
				else {
					continue;
				}
			}
		}
		if (str1[i] == '\0') {
			cout << "Important!" << endl;
		}
	}
	return 0;
}