/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Single Linked List main file.
 *
 *        Version:  1.0
 *        Created:  10/28/2016 03:40:11 AM
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

int main(void)
{
  struct Node *head = NULL;

  insertNode(&head, 10); printList(head);
  insertNode(&head, 20); printList(head);
  insertNode(&head, 30); printList(head);
  insertNode(&head, 40); printList(head);
  insertNode(&head, 50); printList(head);

  reverseList(&head); printList(head);

  reversePrint(head);

  deleteNode(&head); printList(head);

  insertAtPos(&head, 60, 0);  printList(head);
  insertAtPos(&head, 70, 1); printList(head);
  insertAtPos(&head, 80, 4); printList(head);

  deleteAtPos(&head, 2); printList(head);

  rotateList(&head, 4); printList(head);

  return 0;
}
