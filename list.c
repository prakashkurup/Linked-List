/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  Single Linked List implementation source .c
 *
 *        Version:  1.0
 *        Created:  10/28/2016 03:31:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (pk), prakashkurup7@gmail.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/* Function to dynamically allocate new node */
struct Node *newNode(int data)
{
  struct Node *nNode = (struct Node *)malloc(sizeof(struct Node));
  nNode->next = NULL;
  nNode->data = data;

  return nNode;
}

/* Function to insert new node at end of list */
void insertNode(struct Node **head, int data)
{
  struct Node *tmp = newNode(data);
  /* If list is empty */
  if (*head == NULL) {
    *head = tmp;
    return;
  }

  /* Have pointer move till end of list */
  struct Node *ptr = *head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }

  /* New node will be the end node of list */
  tmp->next = ptr->next; // NULL

  /* The previous end node point to the new node */
  ptr->next = tmp;
}

/* Function to print list */
void printList(struct Node *head)
{
  if (head == NULL) {
    puts("List is empty!");
    return;
  }

  struct Node *ptr = head;
  printf("List: ");
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

/* Function to delete node from the head node */
void deleteNode(struct Node **head)
{
  puts("\nDeleting node from the head");

  if (*head == NULL) {
    puts("List is empty!");
    return;
  }

  /* Delete node at head */
  struct Node *ptr = *head;

  /* New head will the node after ptr */
  *head = ptr->next;
  free(ptr);
  ptr = NULL;
}

/* Function to reverse linked list */
void reverseList (struct Node **head)
{
  if (*head == NULL) {
    puts("List is empty");
    return;
  }

  struct Node *prev, *current, *forward;
  prev = NULL;
  current = *head;

  /* Self explanatory */
  while (current != NULL) {
    forward = current->next;
    current->next = prev;
    prev = current;
    current = forward;
  }

  /* New head node will be prev */
  *head = prev;
}

/* Function to reverse print linked list */
void reversePrint(struct Node *head)
{
  if (head == NULL)
    return;

  /* Recursive call */
  reversePrint(head->next);

  printf("%d ", head->data);
}

/* Function to insert node at given position */
void insertAtPos(struct Node **head, int data, int pos)
{
  printf("\nInserting node '%d' at position %d\n", data, pos);

  struct Node *tmp = newNode(data);

  if (pos == 0) {
    tmp->next = *head;
    *head = tmp;
    return;
  }

  struct Node *ptr = *head;
  /* Position greater than 0 */
  while (pos != 1) {
    /* ptr moves to the node before the specified position */
    ptr = ptr->next;
    pos--;
  }

  /* New node takes the place of the specified position */
  tmp->next = ptr->next;
  ptr->next = tmp;
}

/* Function to delete node at given position */
void deleteAtPos(struct Node **head, int pos)
{
  printf("\nDelete node at position %d\n", pos);
  if (*head == NULL) {
    puts("List is empty!");
    return;
  }

  if (pos == 0) {
    deleteNode(head);
    return;
  }

  struct Node *ptr = *head;
  struct Node *tmp = NULL;

  while (pos != 1) {
    ptr = ptr->next;
    pos--;
  }

  tmp = ptr->next;
  ptr->next = tmp->next;
  free(tmp);
  tmp = NULL;
}

/* Function to rotate a list based on given number */
void rotateList(struct Node **head, int num)
{
  printf("Rotating list at %d\n", num);

  if (num == 0)
    return;
  
  struct Node *headRef = *head;
  struct Node *current = *head;
  struct Node *newCurrent = NULL;

  int i;
  /* current points to the node based on num */
  for (i = 0; i < num - 1; i++) {
    current = current->next;
  }
  
  /* newCurrent is now at next node after current */
  newCurrent = current->next;

  /* Have current node as the end of the list */
  current->next = NULL;

  /* Have newCurrent as the new head node */
  *head = newCurrent;

  /* Move newCurrent to the end of the remaining portion of list */
  while (newCurrent->next != NULL)
    newCurrent = newCurrent->next;

  /* Have the newCurrent->next to the previous head node */
  newCurrent->next = headRef;
}
