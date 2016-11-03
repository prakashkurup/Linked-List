/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  Header File for Single Linked List.
 *
 *        Version:  1.0
 *        Created:  10/28/2016 03:27:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (pk), prakashkurup7@gmail.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#ifndef LIST_H
#define LIST_H

struct Node {
  int data;
  struct Node *next;
};

/* Function to insert a node at end of list */
void insertNode(struct Node **head, int data);

/* Function to delete node from the head */
void deleteNode(struct Node **head);

/* Function to print the list */
void printList(struct Node *head);

/* Function to reverse the list */
void reverseList(struct Node **head);

/* Function to reverse print the list */
void reversePrint(struct Node *head);

/* Function to insert node at a given position */
void insertAtPos(struct Node **head, int data, int pos);

/* Function to delete a node at a position */
void deleteAtPos(struct Node **head, int pos);

/* Function to rotate list based on given num */
void rotateList(struct Node **head, int num);


#endif /* LIST_H */
