#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>
//#define MaxPerson 300
 
typedef struct Person {
	char name[1024];
	char phone[1024];
	char sex[1024];
	char age[3];
	char address[1024];
}Person;
typedef struct AddressBook {
	Person* persons;
	int size;
	int capacity;
}AddressBook;

AddressBook g_address_book;
//初始化
void Init() {
	g_address_book.size = 0;
	g_address_book.persons = (Person*)malloc(100 * sizeof(Person));
	g_address_book.capacity = 100;
	for (int i = 0; i < g_address_book.capacity; ++i) {
		/*g_address_book.persons->name[i] = '\0';
		g_address_book.persons->phone[i] = '\0';
		g_address_book.persons->sex[i] = '\0';
		g_address_book.persons->age = 0;
		g_address_book.persons->address[i] = '\0';*/
		g_address_book.persons[i].name[0] = '\0';
		g_address_book.persons[i].phone[0] = '\0'; 
		g_address_book.persons[i].sex[0] = '\0';
		g_address_book.persons[i].age[0] = '\0';
		g_address_book.persons[i].address[0] = '\0';
	}
}
//增
void AddPerson() {
	printf("新增联系人\n");
	if (g_address_book.size >= g_address_book.capacity) {
		g_address_book.capacity += 100;
		g_address_book.persons= (Person*)realloc(g_address_book.persons,g_address_book.capacity*sizeof(Person));		
	}
	Person* person = &g_address_book.persons[g_address_book.size];
	printf("联系人姓名:\n");
	scanf("%s", person->name);
	printf("联系人电话号码:\n");
	scanf("%s", person->phone);
	printf("联系人性别:\n");
	scanf("%s", person->sex);
	printf("联系人年龄:\n");
	scanf("%s", &person->age);
	printf("联系人地址:\n");
	scanf("%s", person->address);
	printf("新增联系人成功\n");
	++g_address_book.size;
}
//删
void DeletePerson() {
	printf("删除联系人\n");
	int del = 0;
	printf("输入要删除的下标\n");
	scanf("%d", &del);
	if (del < 0 || del > g_address_book.size - 1) {
		printf("删除失败\n");
		return;
	}
	free(&g_address_book.persons[del]);
	for (int i = del; i < g_address_book.size; ++i) {
		g_address_book.persons[i] = g_address_book.persons[i + 1];
	}	
	--g_address_book.size;
	printf("删除成功\n");
}
//查
void FindPerson() {
	printf("查找联系人\n");
	char name[1024];
	printf("输入姓名:\n");
	scanf("%s", name);
	int flag = 0;
	for (int i = 0; i < g_address_book.size; ++i) {
		if (strcmp(g_address_book.persons[i].name, name) == 0) {
			flag = 1;
			printf("[%d]姓名:%s\n", i, g_address_book.persons[i].name);
			printf("电话号码:%s\n", g_address_book.persons[i].phone);
			printf("性别:%s\n", g_address_book.persons[i].sex);
			printf("年龄:%s\n", g_address_book.persons[i].age);
			printf("地址:%s\n", g_address_book.persons[i].address);

		}
	}
	if (flag == 0) {
		printf("没有此联系人\n");
	}
	else {
		printf("查找联系人成功\n");
	}
}
//改
void UpdatePerson() {
	int update;
	char name[1024];
	char phone[1024];
	char sex[1024];
	char age[3];
	char address[1024];
	printf("输入要更改的下标\n");
	scanf("%d", &update);
	if (update<0 || update>g_address_book.size - 1) {
		printf("修改联系人失败\n");
		return;
	}
	printf("输入姓名:\n");
	scanf("%s", &name);
	strcpy(g_address_book.persons[update].name, name);
	printf("输入电话号码:\n");
	scanf("%s", &phone);
	strcpy(g_address_book.persons[update].phone, phone);
	printf("输入性别:\n");
	scanf("%s", &sex);
	strcpy(g_address_book.persons[update].sex, sex);
	printf("输入年龄:\n");
	scanf("%s", &age);
	strcpy(g_address_book.persons[update].age,age);
	printf("输入地址:\n");
	scanf("%s", &address);
	strcpy(g_address_book.persons[update].address, address);
	printf("修改联系人成功\n");
}
//打印
void PrintPerson() {
	if (g_address_book.size == 0) {
		printf("通讯录为空\n");
		return;
	}
	printf("打印通讯录\n");
	for (int i = 0; i < g_address_book.size; ++i) {
		printf("[%d]姓名:%s\n", i, g_address_book.persons[i].name);
		printf("电话号码:%s\n", g_address_book.persons[i].phone);
		printf("性别:%s\n", g_address_book.persons[i].sex);
		printf("年龄:%s\n", g_address_book.persons[i].age);
		printf("地址:%s\n", g_address_book.persons[i].address);
	}
	printf("打印通讯录成功\n");
}
//清空
void ClearPerson() {
	if (g_address_book.size == 0) {
		printf("通讯录为空\n");
		return;
	}
	printf("是否要清空联系人!  1.确定  0.取消 \n");
	int choice = 0;
	scanf("%d", &choice);
	if (choice == 1) {
		g_address_book.size = 0;
		printf("清空联系人成功\n");
	}
	else {
		printf("清空联系人失败\n");
	}
}
//排序联系人
void SortPerson() {
	if (g_address_book.size == 0) {
		printf("通讯录为空\n");
		return;
	}

	for (int i = 0; i < g_address_book.size - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < g_address_book.size; ++j) {
			if (strcmp(g_address_book.persons[min].name,
				g_address_book.persons[j].name)>0) {
				min = j;
			}
		}
		Person temp = g_address_book.persons[i];
		g_address_book.persons[i] = g_address_book.persons[min];
		g_address_book.persons[min] = temp;
	}
	printf("联系人排序成功\n");
}
void SavePerson() {
	FILE* fp=fopen("./text.txt","a+");
	//perror("fopen");
	for (int i = 0; i < g_address_book.size; ++i) {
		fwrite("姓名:", strlen("姓名:"), 1, fp);
		fwrite(&(g_address_book.persons[i].name),strlen(g_address_book.persons[i].name), 1, fp);
		fwrite("\t", strlen("\t"), 1, fp);
		fwrite("电话号码:", strlen("电话号码:"), 1, fp);
		fwrite(&(g_address_book.persons[i].phone), strlen(g_address_book.persons[i].phone), 1, fp);
		fwrite("\t", strlen("\t"), 1, fp);
		fwrite("性别:", strlen("性别:"), 1, fp);
		fwrite(&(g_address_book.persons[i].sex), strlen(g_address_book.persons[i].sex), 1, fp);
		fwrite("\t", strlen("\t"), 1, fp);
		fwrite("年龄:", strlen("年龄:"), 1, fp);
		fwrite(&(g_address_book.persons[i].age), strlen(g_address_book.persons[i].age), 1, fp);
		fwrite("\t", strlen("\t"), 1, fp);
		fwrite("地址:", strlen("地址:"), 1, fp);
		fwrite(&(g_address_book.persons[i].address), strlen(g_address_book.persons[i].address), 1, fp);
		fwrite("\n", strlen("\n"), 1, fp);
	}
	fclose(fp);
	printf("写入成功\n");
}
void LoadPerson() {
	char person[1024] = {'\0'};
	FILE* fp = fopen("./text.txt", "r");
	while (fgets(person,sizeof(person),fp)) {
		printf("%s\n", person);
	}
	/*fread(person, sizeof(Person), size, fp);*/
	
	fclose(fp);
}
int Menu() {
	printf("-----------------------\n");
	printf("0.退出\n");
	printf("1.添加联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.显示联系人\n");
	printf("6.清空所有联系人\n");
	printf("7.以名字排序联系人\n");
	printf("8.保存联系人到文件\n");
	printf("9.加载联系人\n");
	printf("-----------------------\n");
	printf("请输入您的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Empty() {
	//转移表凑数
}
typedef void(*Func)();
int main() {
	Func arr[] = {
		Empty,
		AddPerson,
		DeletePerson,
		FindPerson,
		UpdatePerson,
		PrintPerson,
		ClearPerson,
		SortPerson,
		SavePerson,
		LoadPerson
	};
	while (1) {
		int  choice = Menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
			printf("您的输入有误\n");
			continue;
		}
		if (choice == 0) {
			printf("退出\n");
			break;
		}
		else {
			arr[choice]();
		}
	}
	system("pause");
	return 0;
}
