#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if none found.
 */
binary_tree_t
*binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp_first = first;
	const binary_tree_t *temp_second = second;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	while (temp_first != NULL)
	{
		temp_second = second;
		while (temp_second != NULL)
		{
			if (temp_first == temp_second)
			{
				return ((binary_tree_t *)temp_first);
			}
			temp_second = temp_second->parent;
		}
		temp_first = temp_first->parent;
	}

	return (NULL);
}
