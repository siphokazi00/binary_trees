#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	binary_tree_t *queue[1024], *current;
	int front = 0, rear = 0, non_full_node = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front != rear)
	{
		current = queue[front++];
		if (current->left)
		{
			if (non_full_node)
				return (0);
			queue[rear++] = current->left;
		}
		else
			non_full_node = 1;

		if (current->right)
		{
			if (non_full_node)
				return (0);
			queue[rear++] = current->right;
		}
		else
			non_full_node = 1;

		front = front == 1024 ? 0 : front;
		rear = rear == 1024 ? 0 : rear;
	}
	return (1);
}
