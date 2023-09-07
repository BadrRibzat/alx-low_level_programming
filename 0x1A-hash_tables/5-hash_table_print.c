#include "hash_tables.h"

/**
 * hash_table_print - function that prints a hash table
 * @ht: is the hash table
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *aux;
	char flag = 'a';

	if (ht != NULL)
	{
		printf("{");
		for (index = 0; index < ht->size; index++)
		{
			aux = ht->array[index];
			while (aux != NULL)
			{
				if (flag == 'a')
				{
					printf("'%s': '%s'", (char *)aux->key, (char *)aux->value);
					flag = 'b';
				}
				else
				{
					printf(", '%s': '%s'", (char *)aux->key, (char *)aux->value);
				}
				aux = aux->next;
			}
		}
		printf("}\n");
	}
}
