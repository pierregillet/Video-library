#include "linked_list.h"

#include <stdlib.h>


node_key_value_t * initialize_linked_list ()
{
  node_key_value_t *head = NULL;
  head = malloc (sizeof (node_key_value_t));
  head -> next = NULL;
  return head;
}

int add_key_value_node (node_key_value_t *head,
			char *key,
			char *value)
{
  if (head == NULL)
    return 1;
  
  node_key_value_t *node = NULL;
  node = malloc (sizeof (node_key_value_t));

  node_key_value_t *tail = node;
  while (tail -> next != NULL)
    node -> next = tail -> next;
  tail -> next = node;

  return 0;
}
