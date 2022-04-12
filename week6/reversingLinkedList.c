#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* nextNode;
}Node;

typedef struct LinkedList {
    int curCount;
    Node headNode;
}LinkedList;

void showNode(LinkedList* pList)
{
    int i = 0;
    Node* pNode = NULL;

    if (pList == NULL)
    {
        printf("showNode() error\n");
        return;
    }

    printf("현재 Node 개수 : %d \n", pList->curCount);
    pNode = pList->headNode.nextNode;

    while (pNode != NULL)
    {
        printf("[%d]\n", pNode->data);
        pNode = pNode->nextNode;
    }
    printf("---------------------------------\n");
}

int isEmpty(LinkedList* pList)
{
    if (pList == NULL)
    {
        printf("isEmpty() error\n");
        return -1;
    }

    if (pList->headNode.nextNode == NULL)
        return 1;
    else
        return -1;
}

int addNode(LinkedList* pList, int pos, int data)
{
    int i = 0;
    Node* pNewNode = NULL, * pTmpNode = NULL;
    if (pList == NULL)
    {
        printf("addNode() error1 \n");
        return -1;
    }
    if (pos < 0 || pos > pList->curCount)
    {
        printf("addNode() error2: 추가 범위 초과 \n");
        return -1;
    }

    pNewNode = (Node*)malloc(sizeof(Node));
    if (!pNewNode)
    {
        printf("addNode() error3 \n");
        return -1;
    }

    pNewNode->data = data;
    pNewNode->nextNode = NULL;

    pTmpNode = &(pList->headNode);
    for (i = 0; i < pos; i++)
        pTmpNode = pTmpNode->nextNode;

    pNewNode->nextNode = pTmpNode->nextNode;
    pTmpNode->nextNode = pNewNode;
    pList->curCount++;
    return 1;
}

int removeNode(LinkedList* pList, int pos)
{
    int i = 0;
    Node* pDelNode = NULL, * pTmpNode = NULL;

    if (pList == NULL)
    {
        printf("removeNode() error1\n");
        return -1;
    }

    if (pos < 0 || pos > pList->curCount)
    {
        printf("removeNode() error2: 삭제 범위 초과\n");
        return -1;
    }

    pTmpNode = &(pList->headNode);
    for (i = 0; i < pos; i++)
        pTmpNode = pTmpNode->nextNode;

    pDelNode = pTmpNode->nextNode;
    pTmpNode->nextNode = pDelNode->nextNode;

    free(pDelNode);
    pList->curCount--;
    return 1;
}

int findPos(LinkedList* pList, int data)
{
    int pos = 0;
    Node* pNode = NULL;

    if (pList == NULL)
    {
        printf("findPos() error\n");
        return -1;
    }

    pNode = pList->headNode.nextNode;

    while (pNode != NULL)
    {
        if (pNode->data == data)
            return pos;

        pos++;
        pNode = pNode->nextNode;
    }
    return -1;
}

void makeEmpty(LinkedList* pList)
{
    Node* pDummyNode = NULL, * pTmpNode = NULL;
    if (pList != NULL)
    {
        pTmpNode = pList->headNode.nextNode;

        while (pTmpNode != NULL)
        {
            pDummyNode = pTmpNode;
            pTmpNode = pTmpNode->nextNode;
            free(pDummyNode);
            pList->curCount--;
        }
        pList->headNode.nextNode = NULL;
    }
}

typedef struct StackNode {
    int data;
    struct StackNode* next;
}StackNode;

int isEmpty(StackNode* top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

void showLinkedStack(StackNode* top)
{
    StackNode* pNode = NULL;
    if (isEmpty(top))
    {
        printf("the Stack is empty\n");
        return;
    }

    pNode = top;
    printf("==========Show Stack==========\n");
    while (pNode != NULL)
    {
        printf("[%d]\n", pNode->data);
        pNode = pNode->next;
    }
    printf("==============================\n");
}

void pushLinkedStack(StackNode** top, int data)
{
    StackNode* pNode = NULL;

    pNode = (StackNode*)malloc(sizeof(StackNode));
    pNode->data = data;
    pNode->next = NULL;

    if (isEmpty(*top))
        *top = pNode;
    else
    {
        pNode->next = *top;
        *top = pNode;
    }
}

StackNode* popLinkedStack(StackNode** top)
{
    StackNode* pNode = NULL;

    if (isEmpty(*top))
    {
        printf("the Stack is empty\n");
        return NULL;
    }

    pNode = *top;
    *top = pNode->next;

    return pNode;
}

StackNode* topLinkedStack(StackNode* top)
{
    StackNode* pNode = NULL;

    if (!isEmpty(top))
        pNode = top;
    return pNode;
}

void deleteLinkedStack(StackNode** top)
{
    StackNode* pNode = NULL, * pDelNode = NULL;
    pNode = *top;

    while (pNode != NULL)
    {
        pDelNode = pNode;
        pNode = pNode->next;
        free(pDelNode);
    }
    *top = NULL;
}

void reverseList(LinkedList* pList, StackNode** top)
{
    Node* pNode = NULL;
    StackNode* sNode = NULL;
    pNode = pList->headNode.nextNode;
    while (pNode != NULL)
    {
        sNode = (StackNode*)malloc(sizeof(StackNode));
        sNode->data = pNode->data;
        sNode->next = NULL;
        if (*top == NULL) {
            *top = sNode;
        }
        else
        {
            sNode->next = *top;
            *top = sNode;
        }
        pNode = pNode->nextNode;
    }

    pNode = pList->headNode.nextNode;
    while ((*top) != NULL)
    {
        pNode->data = sNode->data;
        sNode = *top;
        *top = sNode->next;
        pNode->data = sNode->data;
        pNode = pNode->nextNode;
    }
    printf("Reverse Linked List!\n");
}

int main()
{
    int pos;
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->curCount = 0;
    linkedList->headNode.nextNode = NULL;

    StackNode* top = NULL;
    StackNode* pNode;

    //showNode(linkedList);
    addNode(linkedList, 0, 10);
    addNode(linkedList, 5, 100);
    addNode(linkedList, 1, 20);
    addNode(linkedList, 2, 30);
    addNode(linkedList, 1, 50);
    addNode(linkedList, 1, 70);
    addNode(linkedList, 1, 40);

    showNode(linkedList);

    reverseList(linkedList, &top);

    showNode(linkedList);

    //removeNode(linkedList, 1);
    //showNode(linkedList);

    //pos = findPos(linkedList, 30);
    //printf("the location of node with data '30': %d\n", pos);

    makeEmpty(linkedList);
    showNode(linkedList);
    return 0;
}