typedef
struct node_key_value
{
  struct node_key_value *next;
  char *key;
  char *value;
} node_key_value_t;

node_key_value_t * initialize_linked_list ();

int add_key_value_node (node_key_value_t *head,
			char *key,
			char *value);
