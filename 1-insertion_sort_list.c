
#include "sort.h"
/**
 *SortedInsert - inserts a new nnode in a sorted way
 *@newnode : node to be inserted
 *@list : pointer to the head of the double linked list
 *Return : void
 */

void InsertSortedNode(listint_t **list, listint_t *newnode)
{
  listint_t* current;
  /*if list is empty...*/
  if(*list == NULL)
    newnode = *list;

  /*if the new node is to be inserted at the begining of list..*/
  else if ((*list)->n >= newnode->n)
    {
      newnode->next = *list;
      newnode->next->prev = newnode;
      *list = newnode;
    }
  else
    {
      current = *list;

      /*locate the node after which the new node is to be inserted*/
      while (current->next != NULL && current->next->n < newnode->n)
	current = current->next;
      newnode->next = current->next;

      /*if the newnode is not inserted at the end of the list..*/
      if (current->next != NULL)
	newnode->next->prev = newnode;

      current->next = newnode;
      newnode->prev = current;
    }
}
/**
 *insertion_sort_list - sorts a double linked list with insertion method
 *@list: list to be sorted
 *Return: print sorted list
 */

void insertion_sort_list(listint_t **list)
{
  /*initialize 'sorted' - a sorted double linked list*/
  listint_t *sorted;
  listint_t *current;
  listint_t *tmp; /*temporarily holds a node in waiting*/

  /*review the list and insert every node to 'sorted'*/
  current = *list;
  while (current)
    {
      tmp = current->next;

      /*making current the newnode for insertion*/
      current->prev = current->next  = NULL;

      /*insert current in sorted using the InsertSortedNode function*/
      InsertSortedNode(&sorted, current);

      /*update current*/
      current = tmp;
    }

   /*update list to point to sorted list*/
      *list = sorted;
      print_list(sorted);

}
