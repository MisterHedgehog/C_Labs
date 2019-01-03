#pragma once
#ifndef TIME_H
#define TIME_H
// ���������, ����������� ����
typedef struct Date {
	int year;
	int mounth;
	int day;
} Date;
// ���������, ����������� �����
typedef struct Time {
	int hour;
	int minute;
	int second;
} Time;
// ������� �������� ����
Date createDate(int ���, int �����, int ����);
// ������� �������� �����
Time createTime(int ���, int ������, int �������);
// ������� �������������� ������ � ������ ��.��.���� � ����
Date formatStringToDate(char* ������);
// ������� �������������� ������ � ������ ��.��.���� � ����
Time formatStringToTime(char* ������);
// ������� �������������� ������� � �����
int fromChar(char ������);
#endif