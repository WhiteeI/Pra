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
//��ʼ��
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
//��
void AddPerson() {
	printf("������ϵ��\n");
	if (g_address_book.size >= g_address_book.capacity) {
		g_address_book.capacity += 100;
		g_address_book.persons= (Person*)realloc(g_address_book.persons,g_address_book.capacity*sizeof(Person));		
	}
	Person* person = &g_address_book.persons[g_address_book.size];
	printf("��ϵ������:\n");
	scanf("%s", person->name);
	printf("��ϵ�˵绰����:\n");
	scanf("%s", person->phone);
	printf("��ϵ���Ա�:\n");
	scanf("%s", person->sex);
	printf("��ϵ������:\n");
	scanf("%s", &person->age);
	printf("��ϵ�˵�ַ:\n");
	scanf("%s", person->address);
	printf("������ϵ�˳ɹ�\n");
	++g_address_book.size;
}
//ɾ
void DeletePerson() {
	printf("ɾ����ϵ��\n");
	int del = 0;
	printf("����Ҫɾ�����±�\n");
	scanf("%d", &del);
	if (del < 0 || del > g_address_book.size - 1) {
		printf("ɾ��ʧ��\n");
		return;
	}
	free(&g_address_book.persons[del]);
	for (int i = del; i < g_address_book.size; ++i) {
		g_address_book.persons[i] = g_address_book.persons[i + 1];
	}	
	--g_address_book.size;
	printf("ɾ���ɹ�\n");
}
//��
void FindPerson() {
	printf("������ϵ��\n");
	char name[1024];
	printf("��������:\n");
	scanf("%s", name);
	int flag = 0;
	for (int i = 0; i < g_address_book.size; ++i) {
		if (strcmp(g_address_book.persons[i].name, name) == 0) {
			flag = 1;
			printf("[%d]����:%s\n", i, g_address_book.persons[i].name);
			printf("�绰����:%s\n", g_address_book.persons[i].phone);
			printf("�Ա�:%s\n", g_address_book.persons[i].sex);
			printf("����:%s\n", g_address_book.persons[i].age);
			printf("��ַ:%s\n", g_address_book.persons[i].address);

		}
	}
	if (flag == 0) {
		printf("û�д���ϵ��\n");
	}
	else {
		printf("������ϵ�˳ɹ�\n");
	}
}
//��
void UpdatePerson() {
	int update;
	char name[1024];
	char phone[1024];
	char sex[1024];
	char age[3];
	char address[1024];
	printf("����Ҫ���ĵ��±�\n");
	scanf("%d", &update);
	if (update<0 || update>g_address_book.size - 1) {
		printf("�޸���ϵ��ʧ��\n");
		return;
	}
	printf("��������:\n");
	scanf("%s", &name);
	strcpy(g_address_book.persons[update].name, name);
	printf("����绰����:\n");
	scanf("%s", &phone);
	strcpy(g_address_book.persons[update].phone, phone);
	printf("�����Ա�:\n");
	scanf("%s", &sex);
	strcpy(g_address_book.persons[update].sex, sex);
	printf("��������:\n");
	scanf("%s", &age);
	strcpy(g_address_book.persons[update].age,age);
	printf("�����ַ:\n");
	scanf("%s", &address);
	strcpy(g_address_book.persons[update].address, address);
	printf("�޸���ϵ�˳ɹ�\n");
}
//��ӡ
void PrintPerson() {
	if (g_address_book.size == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("��ӡͨѶ¼\n");
	for (int i = 0; i < g_address_book.size; ++i) {
		printf("[%d]����:%s\n", i, g_address_book.persons[i].name);
		printf("�绰����:%s\n", g_address_book.persons[i].phone);
		printf("�Ա�:%s\n", g_address_book.persons[i].sex);
		printf("����:%s\n", g_address_book.persons[i].age);
		printf("��ַ:%s\n", g_address_book.persons[i].address);
	}
	printf("��ӡͨѶ¼�ɹ�\n");
}
//���
void ClearPerson() {
	if (g_address_book.size == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("�Ƿ�Ҫ�����ϵ��!  1.ȷ��  0.ȡ�� \n");
	int choice = 0;
	scanf("%d", &choice);
	if (choice == 1) {
		g_address_book.size = 0;
		printf("�����ϵ�˳ɹ�\n");
	}
	else {
		printf("�����ϵ��ʧ��\n");
	}
}
//������ϵ��
void SortPerson() {
	if (g_address_book.size == 0) {
		printf("ͨѶ¼Ϊ��\n");
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
	printf("��ϵ������ɹ�\n");
}
void SavePerson() {
	FILE* fp=fopen("./text.txt","a+");
	//perror("fopen");
	for (int i = 0; i < g_address_book.size; ++i) {
		fwrite("����:", strlen("����:"), 1, fp);
		fwrite(&(g_address_book.persons[i].name),strlen(g_address_book.persons[i].name), 1, fp);
		fwrite("\t", strlen("\t"), 1, fp);
		fwrite("�绰����:", strlen("�绰����:"), 1, fp);
		fwrite(&(g_address_book.persons[i].phone), strlen(g_address_book.persons[i].phone), 1, fp);
		fwrite("\t", strlen("\t"), 1, fp);
		fwrite("�Ա�:", strlen("�Ա�:"), 1, fp);
		fwrite(&(g_address_book.persons[i].sex), strlen(g_address_book.persons[i].sex), 1, fp);
		fwrite("\t", strlen("\t"), 1, fp);
		fwrite("����:", strlen("����:"), 1, fp);
		fwrite(&(g_address_book.persons[i].age), strlen(g_address_book.persons[i].age), 1, fp);
		fwrite("\t", strlen("\t"), 1, fp);
		fwrite("��ַ:", strlen("��ַ:"), 1, fp);
		fwrite(&(g_address_book.persons[i].address), strlen(g_address_book.persons[i].address), 1, fp);
		fwrite("\n", strlen("\n"), 1, fp);
	}
	fclose(fp);
	printf("д��ɹ�\n");
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
	printf("0.�˳�\n");
	printf("1.�����ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.��ʾ��ϵ��\n");
	printf("6.���������ϵ��\n");
	printf("7.������������ϵ��\n");
	printf("8.������ϵ�˵��ļ�\n");
	printf("9.������ϵ��\n");
	printf("-----------------------\n");
	printf("����������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Empty() {
	//ת�Ʊ����
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
			printf("������������\n");
			continue;
		}
		if (choice == 0) {
			printf("�˳�\n");
			break;
		}
		else {
			arr[choice]();
		}
	}
	system("pause");
	return 0;
}
