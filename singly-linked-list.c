/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* �ʿ��� ������� �߰� */

typedef struct Node {
   int key;
   struct Node* link;
} listNode; // ��忡 ���� ����ü Ÿ��

typedef struct Head {
   struct Node* first;
} headNode; // ù��° ��带 ����Ű�� ���


/* �Լ� ����Ʈ */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
   char command;
   int key;
   headNode* headnode=NULL;

   do{
      printf("----------------------------------------------------------------\n");
      printf("                     Singly Linked List                         \n");
      printf("----------------------------------------------------------------\n");
      printf(" Initialize    = z           Print         = p \n");
      printf(" Insert Node   = i           Delete Node   = d \n");
      printf(" Insert Last   = n           Delete Last   = e\n");
      printf(" Insert First  = f           Delete First  = t\n");
      printf(" Invert List   = r           Quit          = q\n");
      printf("----------------------------------------------------------------\n");

      printf("Command = ");
      scanf(" %c", &command);

      switch(command) {
      case 'z': case 'Z':
         headnode = initialize(headnode);
         break;
      case 'p': case 'P':
         printList(headnode);
         break;
      case 'i': case 'I':
         printf("Your Key = ");
         scanf("%d", &key);
         insertNode(headnode, key);
         break;
      case 'd': case 'D':
         printf("Your Key = ");
         scanf("%d", &key);
         deleteNode(headnode, key);
         break;
      case 'n': case 'N':
         printf("Your Key = ");
         scanf("%d", &key);
         insertLast(headnode, key);
         break;
      case 'e': case 'E':
         deleteLast(headnode);
         break;
      case 'f': case 'F':
         printf("Your Key = ");
         scanf("%d", &key);
         insertFirst(headnode, key);
         break;
      case 't': case 'T':
         deleteFirst(headnode);
         break;
      case 'r': case 'R':
         invertList(headnode);
         break;
      case 'q': case 'Q':
         freeList(headnode);
         break;
      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');

   return 1;
}

headNode* initialize(headNode* h) {

   /* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
   if(h != NULL)
      freeList(h);

   /* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
   headNode* temp = (headNode*)malloc(sizeof(headNode));
   temp->first = NULL;
   return temp;
}

int freeList(headNode* h){
   /* h�� ����� listNode �޸� ����
    * headNode�� �����Ǿ�� ��.
    */
   listNode* p = h->first;

   listNode* prev = NULL;
   while(p != NULL) {
      prev = p;
      p = p->link;
      free(prev);
   }
   free(h);
   return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {

   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key = key;

   node->link = h->first;
   h->first = node;

   return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode)); // ���ο� ��� ����
   node->key = key;
   node->link = NULL;

   if(h->first == NULL){ // ����Ʈ�� ����ִٸ�
      h->first = node; // ����尡 ���� ������ ��带 ��Ű������ �Ѵ�.
      return 0;
   }
   else{
      listNode* p1 = NULL; // ����Ʈ �˻��� ��� p1 ����
      listNode* p2 = NULL; // ����Ʈ �˻��� ��� p2 ����

      p1 = h->first;
      p2 = h->first;

   while(p1 != NULL){
      {
         if(p1->key >= key){
            if(p1 == h->first){
               h->first = node;
               node->link - p1;
            }
            else{
               node->link = p1;
               p2->link = node;
            }
            return 0;
         }
         p2 = p1;
         p1 = p1->link;
      }
   }

   p2->link = node;

   return 0;
   }
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key = key;
   node->link = NULL;

   if(h->first == NULL){
      h->first = node;
      return 0;
   }
   
   else{
      listNode* p;
      p = NULL;
      p = h->first;
      h->first=p;

      while(p->link != NULL){
         p=p->link;
      }
      p->link=node;

      return 0;
   }
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {
   if(h->first == NULL){
      printf("����Ʈ�� ����ֽ��ϴ�.");
      return 0;
   }

   else{
      listNode* node = NULL;

      node = h->first;
      h->first = node->link;
      free(node);
      
      return 0;
   }
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {  
   if(h->first == NULL){
      printf("����Ʈ�� ����ֽ��ϴ�.");
      return 0;
   }
   else{
      listNode* p1 = NULL;
      listNode* p2 = NULL;
      p1=h->first;
      p2=h->first;

      while(p1->key != key){
         p2=p1;
         p1=p1->link;
      }
      p2->link=p1->link;
      free(p1);      
      return 0;
   }
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
   if(h->first == NULL){
      printf("����Ʈ�� ����ֽ��ϴ�.");
      return 0;
   }
   else{
      listNode* p1 = NULL;
      listNode* p2 = NULL;
      p1=h->first;
      p2-h->first;

      while(p1->link != NULL){
         p2=p1;
         p1=p1->link;
      }
      free(p1);
      p2->link = NULL;      
      return 0;
   }
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {
   if(h->first == NULL){
      printf("����Ʈ�� ����ֽ��ϴ�.");
      return 0;
   }
   else{
      listNode* p1 = h->first;
      listNode* p2 = h->first;
      listNode* p3 = h->first;

      while(p3 != NULL){
         p1 = p2;
         p2 = p3;
         p3 = p3->link;
         p2->link = p1;
      }

      h->first->link = NULL;
      h->first = p2;
      return 0;
   }
}


void printList(headNode* h) {
   int i = 0;
   listNode* p;

   printf("\n---PRINT\n");

   if(h == NULL) {
      printf("Nothing to print....\n");
      return;
   }

   p = h->first;

   while(p != NULL) {
      printf("[ [%d]=%d ] ", i, p->key);
      p = p->link;
      i++;
   }

   printf("  items = %d\n", i);
}
