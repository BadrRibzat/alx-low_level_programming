#include "hash_tables.h"

/**
 * hash_table_delete - function that deletes a hash table
 * @ht: is the hash table
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *aux, *head;

	if (ht != NULL)
	{
		for (index = 0; index < ht->size; index++)
		{
			head = ht->array[index];
			while (head != NULL)
			{
				aux = head->next;
				free(head->value);
				free(head->key);
				free(head);
				head = aux;
			}
		}
		free(ht->array);
		free(ht);
	}
}
