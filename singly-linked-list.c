/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
   int key;
   struct Node* link;
} listNode; // 노드에 대한 구조체 타입

typedef struct Head {
   struct Node* first;
} headNode; // 첫번째 노드를 가리키는 노드


/* 함수 리스트 */
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

   /* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
   if(h != NULL)
      freeList(h);

   /* headNode에 대한 메모리를 할당하여 리턴 */
   headNode* temp = (headNode*)malloc(sizeof(headNode));
   temp->first = NULL;
   return temp;
}

int freeList(headNode* h){
   /* h와 연결된 listNode 메모리 해제
    * headNode도 해제되어야 함.
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
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

   listNode* node = (listNode*)malloc(sizeof(listNode));
   node->key = key;

   node->link = h->first;
   h->first = node;

   return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
   listNode* node = (listNode*)malloc(sizeof(listNode)); // 새로운 노드 생성
   node->key = key;
   node->link = NULL;

   if(h->first == NULL){ // 리스트가 비어있다면
      h->first = node; // 헤드노드가 새로 생성된 노드를 가키리도록 한다.
      return 0;
   }
   else{
      listNode* p1 = NULL; // 리스트 검색용 노드 p1 생성
      listNode* p2 = NULL; // 리스트 검색용 노드 p2 생성

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
 * list에 key에 대한 노드하나를 추가
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
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
   if(h->first == NULL){
      printf("리스트가 비어있습니다.");
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
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {  
   if(h->first == NULL){
      printf("리스트가 비어있습니다.");
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
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
   if(h->first == NULL){
      printf("리스트가 비어있습니다.");
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
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {
   if(h->first == NULL){
      printf("리스트가 비어있습니다.");
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
