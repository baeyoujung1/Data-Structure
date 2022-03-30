#define BUFFSIZE 1024
#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct polyTerm_ {
	int expon; 
	int coef; 
	struct polyTerm_* link; 
} polyTerm;

typedef struct poly_ {
	polyTerm* head;
} poly;

struct Node {
	struct Node* next;
};

void initPoly(poly* A) {
	A->head = NULL;
}

void clearPoly(poly* A) {
	polyTerm* a = A->head;
	polyTerm* b = NULL;
	while (a != NULL) {
		b = a;
		a = a->link;
		free(b);
	} A->head = NULL;
}

void printPoly_impl(poly A, char* buffer) {
	for (polyTerm* bf = A.head; bf; bf = bf->link) {
		if (!(bf->coef)) continue;
		if (bf->coef > 0 && bf != A.head) buffer += sprintf(buffer, "+");
		buffer += sprintf(buffer, "%dx^%d", bf->coef, bf->expon);
	}
}

void printPoly(poly A) {
	char buffer[BUFFSIZE] = "";
	printPoly_impl(A, buffer);
	printf(buffer);
}

void addTerm(poly* A, int expon, int coef) {
	polyTerm header;
	polyTerm* tmp = &header;
	tmp->link = A->head;

	for (; tmp->link && tmp->link->expon >= expon; tmp = tmp->link) {
		if (tmp->link->expon == expon) {
			tmp->link->coef += coef;
			return;
		}
	}

	polyTerm* newpoly = (polyTerm*)malloc(sizeof(polyTerm));
	newpoly->coef = coef;
	newpoly->expon = expon;
	newpoly->link = tmp->link;

	if (tmp == &header) {
		A->head = newpoly;
	}
	else {
		tmp->link = newpoly;
	}

}

poly multiPoly(poly A, poly B) {
	poly C;
	initPoly(&C);

	for (polyTerm* it = A.head; it; it = it->link) {
		for (polyTerm* it2 = B.head; it2; it2 = it2->link) {
			if (B.head->expon != 1) continue;
			addTerm(&C, (it->expon + it2->expon), (it->coef * it2->coef));
		}
	}
	return C;
}


int main() {

	poly A, B;
	initPoly(&A);
	initPoly(&B);

	addTerm(&A, 1, 1);
	addTerm(&A, 0, 1);
	printf("poly A: ");
	printPoly(A);
	printf("\n");

	addTerm(&B, 1, 1);
	addTerm(&B, 0, -1);
	printf("poly B: ");
	printPoly(B);
	printf("\n");

	printf("A*B: ");
	printPoly(multiPoly(A, B));

	return 0;
}
