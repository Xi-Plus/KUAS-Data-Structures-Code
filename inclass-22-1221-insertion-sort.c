#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_N 20
#define MAX_V 100
typedef struct Node {
	int v;
	struct Node* next;
}Node;
int main() {
	srand(time(NULL));
	Node *head = (Node*)malloc(sizeof(Node)), *now = head;
	for(int q=0; q<MAX_N; q++) {
		now->next = (Node*)malloc(sizeof(Node));
		now = now->next;
		now->v = rand()%MAX_V+1;
		printf("%d ", now->v);
	}
	printf("\n");
	
	for(Node *now=head; now->next; now = now->next) {
		Node *idx = now;
		int val = now->next->v;
		for(Node *temp = now; temp->next; temp = temp->next) {
			if(temp->next->v < val) {
				val = temp->next->v;
				idx = temp;
			}
		}
		Node *temp = idx->next;
		idx->next = idx->next->next;
		
		temp->next = now->next;
		now->next = temp;
	}
	
	for(Node *temp=head->next; temp; temp = temp->next) {
		printf("%d ", temp->v);
	}
	printf("\n");
}
