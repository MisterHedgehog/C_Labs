#define _CRT_SECURE_NO_WARNINGS // ��� ����������� ������������� scanf
#define SERVERS   13

#include <stdio.h>

//---------------------------------------------------------------------------//
/*
				������������ ������ � 19
������� ������ 61391
������� �.�.
���� ����������: 09.12.2018
���� ������: �����������, ������� � ��������� ���������� � �������� ���������� ������������ ������� � �����.
�������: ���������� ����������� ��� ������ ��������. ��������� ������������
����� �� s � t � ������� ����������� ������, ���������� s �� t .
����� ������� ������������� ������ ������ �� ������.
*/
//---------------------------------------------------------------------------//

// ��������� �������
typedef struct Server {
	struct Server* from;
	int number;
} Server;

// ������� ���������
int N[SERVERS][SERVERS] = {
	//     0   1   2   3   4   5   6   7   8   9  10  11  12
	/*0*/{ 0,  6, 42, 14,  0, 16,  0, 36,  0,  0,  5,  0,  0},
	/*1*/{ 0,  0,  0,  3, 27, 12,  0, 45,  0, 23,  2,  0,  0},
	/*2*/{ 0, 21,  0, 21, 25,  0,  0,  0, 29,  0, 13,  9,  0},
	/*3*/{ 0, 32, 31,  0,  0,  0, 30,  0, 31,  0, 27,  0,  0},
	/*4*/{ 0,  0,  0,  0,  0, 21,  0,  2, 22, 44, 44, 41, 33},
	/*5*/{35,  0,  0,  2,  8,  0,  0, 29,  5,  0, 42,  0,  0},
	/*6*/{ 0, 11,  0, 48,  0,  0,  0,  0, 42,  0,  0,  0, 45},
	/*7*/{ 0,  0, 29,  0,  0, 48,  1,  0,  0, 41,  0,  0, 34},
	/*8*/{24, 16,  7,  0,  0,  0,  0, 21,  0,  8,  0, 23, 47},
	/*9*/{ 0, 31, 44,  0,  0, 41,  0,  0, 24,  0,  0,  0,  0},
   /*10*/{12, 25,  0,  0,  7,  0,  0, 39,  0,  0,  0,  0,  0},
   /*11*/{ 0,  0, 25, 30,  0, 17,  0,  0,  0, 47,  4,  0,  0},
   /*12*/{38,  0,  0, 35,  6,  0,  3,  0,  0, 36, 14,  0,  0},
};
int threads = 0; // ���������� �������
int stream  = 0; // ������������ �����

// ������� ����������� ����������� ������
void findThread(int �������_������, int ��������_������, Server ����������_�������, int ���_������_��_�������);
// ������� ������ ������
printThread(Server �����_������, int ����������_�����������);

void main() {
	setlocale(0, "Russian");
	int from, to;
	// ���� �������� ��������, ����� �������� ����� ������������ ������ ������
	printf("������� ����� �����������:\n");
	scanf("%d", &from);
	printf("������� �������� �����:\n");
	scanf("%d", &to);
	// ����������� ����������� ����
	findThread(from, to, (Server) {NULL, from}, 1024);
	printf("\n������������ ���������� ����������� %d ���", stream);
	getch();
}
// ������� ����������� ����������� ������
void findThread(int from, int to, Server visited, int value) {
	for (int i = 0; i < SERVERS; i++) { // ����� ������
		Server * v = &visited; 
		_Bool was = 0;
		while (v != NULL && !was) {
			// ���� ������ ������� ������������ � ������, �� �������� ���� ����
			if (v->number == i) was = 1;
			v = v->from;
		}
		int bits = N[from][i];
		if (bits && !was) { // ���� ���� ����� ����� ��������� � ������� ��� �� ����������
							// �������� ���������� �������, ������� ��������� �� ������
			Server server = {&visited, i};
			// ���������� ������������ �������
			int minValue = value > bits ? bits : value; 
			if (i == to) { // ���� ������ �������� ������
				           // ����� ������ 
				printThread(server, minValue);
			} else // ���� �� ������ �������� ������
				   // ����� ��������� �������
			findThread(i, to, server, minValue);
		}
	}
}
// ������� ������ ������, ���������� �������� value (��������, ������� ����� ���������� �� ������������ ������)
printThread(Server town, int value) {
	Server bigin = town;				//  ��������� ����������
	int startEdge = town.number;		//  ��������� � �������� �������
	int finishEdge = town.from->number; //  ��������� ���� ������
	for (; bigin.from != NULL; bigin = *bigin.from) {
		if ((N[bigin.from->number][bigin.number] < value)) {
			// ���������� ���������� ����������� ������������ �������
			value = N[bigin.from->number][bigin.number];
		}
	}
	if (value) { // ���� ����� ����������
		printf("����� %d: (%d)", ++threads, town.number);
		for (; town.from != NULL; town = *town.from) {
			printf(" <<= %d ����� �������� <<= (%d)", N[town.from->number][town.number], town.from->number);
			if (!(N[town.from->number][town.number] -= value)) {
				// ���������� ������������ �������
				int startEdge = town.number;
				int finishEdge = town.from->number;
			}
		}
		printf("\n ������ ����� ��������� ����� (%d =>> %d) c ���������� ������������ ���� %d ���\n\n", finishEdge, startEdge, value);
		// ���������� ���������� ����������� ������ � ������������� ��� �������� ������
		stream += value;
	}
}