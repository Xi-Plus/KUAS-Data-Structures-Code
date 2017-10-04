#include<stdlib.h>
#include<stdio.h>
typedef struct{
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
		if(a==0 && b== 0){
			break;
		}
		n1->next=(Node*)malloc(sizeof(Node));
		n1=n1->next;
		n1->n=a;
		n1->e=b;
		n1->next=NULL;
	}
	while(~scanf("%d %d", &a, &b)){
		if(a==0 && b== 0){
			break;
		}
		n2->next=(Node*)malloc(sizeof(Node));
		n2=n2->next;
		n2->n=a;
		n2->e=b;
		n2->next=NULL;
	}
	n1=v1->next;
	n2=v2->next;
	while(n1!=NULL && n2!=NULL){
		if(n1->e==n2->e){
			printf("%dx^%d ", n1->n+n2->n, n1->e);
			n1=n1->next;
			n2=n2->next;
		} else if(n1->e>n2->e){
			printf("%dx^%d ", n1->n, n1->e);
			n1=n1->next;
		} else {
			printf("%dx^%d ", n2->n, n2->e);
			n2=n2->next;
		}
	}
	while(n1!=NULL){
		printf("%dx^%d ", n1->n, n1->e);
		n1=n1->next;
	}
	while(n2!=NULL){
		printf("%dx^%d ", n2->n, n2->e);
		n2=n2->next;
	}
}

