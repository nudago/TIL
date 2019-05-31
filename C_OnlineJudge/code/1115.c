#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node* next;
};
struct node* head;

void addToSLL(int _data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = _data;
	new_node->next = 0;

	if (head == 0) {
		head = new_node;
	}
	else { 
		struct node* cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = new_node;
	}
}
	
void showSLL() {
	struct node* cur = head;
	while (cur != 0) {
		printf("%d ", cur->i);
		cur = cur->next;
	}
}
struct node* findFromSLL(int __x) {
	struct node* cur = head;
	while (cur->next != 0) {
		if (cur->i == __x) {
			return cur;
		}
		cur = cur->next;
	}
	return 0;
}
void insertIntoSLL(int _x, int _y) {
	struct node* cur = findFromSLL(_x);

	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = _y;
	if (cur == 0) {
		new_node->next = head;
		head = new_node;
	}
	else {
		new_node->next = cur->next;
		cur->next = new_node;
	}
}

int main() {
	int n, data, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		addToSLL(data);
	}
	scanf("%d %d", &x, &y);
	insertIntoSLL(x, y);
	showSLL();
}