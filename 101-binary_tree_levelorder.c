#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	/* Create a queue for level order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	int front = 0, rear = 0;

	binary_tree_t *current = (binary_tree_t *)tree;

	while (current != NULL)
	{
		/* Print the value of the current node */
		func(current->n);

		/* Enqueue the left child */
		if (current->left != NULL)
		{
			queue[rear++] = current->left;
		}

		/* Enqueue the right child */
		if (current->right != NULL)
		{
			queue[rear++] = current->right;
		}

		/* Dequeue the next node to process */
		current = queue[front++];

		if (front == 1024)
		{
			front = 0;
		}
		if (rear == 1024)
		{
			rear = 0;
		}
	}
	free(queue);
}
