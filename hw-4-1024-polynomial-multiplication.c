#include<stdlib.h>
#include<stdio.h>
typedef struct Node{
	int e,n;
	struct Node* next;
}Node;
int main(){
	Node *v1=NULL,*v2=NULL;
	v1=(Node*)malloc(sizeof(Node));
	v2=(Node*)malloc(sizeof(Node));
	Node *n1=v1,*n2=v2;
	int a,b;
	while(~scanf("%d %d", &a, &b)){
		if(a==0 && b==0){
			break;
		}
		n1->next=(Node*)malloc(sizeof(Node));
		n1=n1->next;
		n1->n=a;
		n1->e=b;
		n1->next=NULL;
	}
	while(~scanf("%d %d", &a, &b)){
		if(a==0 && b==0){
			break;
		}
		n2->next=(Node*)malloc(sizeof(Node));
		n2=n2->next;
		n2->n=a;
		n2->e=b;
		n2->next=NULL;
	}
	for(n1=v1->next; n1!=NULL; n1=n1->next) {
		printf("%dx^%d ", n1->n, n1->e);
	}
	printf("\n");
	printf("*\n");
	for(n1=v2->next; n1!=NULL; n1=n1->next) {
		printf("%dx^%d ", n1->n, n1->e);
	}
	printf("\n");
	printf("=\n");
	Node *v3=NULL;
	v3=(Node*)malloc(sizeof(Node));
	Node *n3=v3;
	for(n1=v1->next; n1!=NULL; n1=n1->next) {
		for(n2=v2->next; n2!=NULL; n2=n2->next) {
			n3->next = (Node*)malloc(sizeof(Node));
			n3 = n3->next;
			n3->n = n1->n*n2->n;
			n3->e = n1->e+n2->e;
			n3->next = NULL;
		}
	}
	n3->next = (Node*)malloc(sizeof(Node));
	n3 = n3->next;
	n3->n = 0;
	n3->e = -1;
	n3->next = NULL;
	int cnt = 0;
	for(n3=v3->next; n3!=NULL; n3=n3->next) {
		cnt++;
	}
	for(int c=0; c<cnt; c++) {
		for(n2=v3; n2->next->next!=NULL; n2=n2->next) {
			if(n2->next->e < n2->next->next->e) {
				Node *a = n2->next;
				Node *b = n2->next->next;
				Node *c = n2->next->next->next;
				n2->next = b;
				b->next = a;
				a->next = c;
			}
		}
	}
	int lastn = 0, laste = v3->next->e;
	for(n3=v3->next; n3!=NULL; n3=n3->next) {
		if (n3->e < laste) {
			printf("%dx^%d ", lastn, laste);
			laste = n3->e;
			lastn = 0;
		}
		lastn += n3->n;
	}
	printf("\n");
}
