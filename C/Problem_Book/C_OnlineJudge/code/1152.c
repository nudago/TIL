#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 5
typedef struct date {
	char* place;
	int paid;
	int money;
}date;
date* stack[SZ];
int top = -1;
void push(char* _place, int _paid, int _money) {
	if (top == SZ - 1) {
		return;
	}
	top++;
	stack[top] = (date*)malloc(sizeof(date));
	stack[top]->place = (char*)malloc(sizeof(_place) + 1);
	strcpy(stack[top]->place, _place);
	stack[top]->paid = _paid;
	stack[top]->money = _money;
}
void pop() {
	if (top == -1) {
		return;
	}
	printf("%s\n", stack[top]->place);
	stack[top] = 0;
	top--;
}
int findMaxMoneyWhich() {
	int max = 0, which = 0;
	for (int i = 0; i <= top; i++) {
		if ((max < stack[i]->money) && (stack[i]->paid == 1) ) {
			max = stack[i]->money;
			which = i;
		}
	}
	return which;
}
int main() {
	int n, paid, money;
	char place[10];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", place ,&paid, &money);
		push(place, paid, money);
	}
	int num = findMaxMoneyWhich();
	if (num == top) {
		printf("%s", stack[top]->place);
		return 0;
	}
	for (int i = 0; i < n - num; i++) {
		pop();
	}
}