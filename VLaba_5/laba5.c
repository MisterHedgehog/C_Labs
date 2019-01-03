#define _CRT_SECURE_NO_WARNINGS // для возможности использования scanf
#include <stdio.h>
#include <math.h>
int main(){
	int i, j, n,m = 0,A[100], stroka = 0;
	
	printf("vvedite razmer stroki\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
			A[i] = -25 + rand() % 50;
	}
	printf("Ishodnay stroka\n");
	for (i = 0; i < n; i++) {
			printf("element[%d]:%d\n", i, A[i]);
	}
	for (i = 0; i < n; i++) {
		if (A[i] > m) {
			m = A[i];
			stroka = i;
		}
		}
	printf("nomer stroki s bolshim kolichestvom nulei: %d", stroka);
	getch();
	return 0;
}
