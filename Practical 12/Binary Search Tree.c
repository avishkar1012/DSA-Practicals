
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
};

// Inorder: Left -> Root -> Right
void inorder(struct tnode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(struct tnode *root)
{
    if (root == NULL)
        return;

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(struct tnode *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

// Level-order: Visit nodes level by level
void levelorder(struct tnode *root)
{
    struct tnode *queue[MAX_NODES];
    int front = 0, rear = 0;

    if (root == NULL)
    {
        printf("Tree is empty.");
        return;
    }

    queue[rear++] = root;

    while (front < rear)
    {
        struct tnode *cur = queue[front++];
        printf("%d\t", cur->data);

        if (cur->left != NULL)
        {
            if (rear >= MAX_NODES)
            {
                printf("\nQueue capacity exceeded.");
                return;
            }
            queue[rear++] = cur->left;
        }

        if (cur->right != NULL)
        {
            if (rear >= MAX_NODES)
            {
                printf("\nQueue capacity exceeded.");
                return;
            }
            queue[rear++] = cur->right;
        }
    }
}

// Insert a node into the binary search tree
void insert(struct tnode **root, int data)
{
    struct tnode *temp, *cur;

    temp = malloc(sizeof(struct tnode));

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (*root == NULL)
    {
        *root = temp;
        printf("%d is the root node.\n", data);
        return;
    }

    cur = *root;

    while (1)
    {
        if (data == cur->data)
        {
            printf("%d already exists, not added.\n", data);
            free(temp);
            return;
        }

        if (data < cur->data)
        {
            if (cur->left == NULL)
            {
                cur->left = temp;
                printf("%d added to the LEFT of %d.\n",
                       data, cur->data);
                return;
            }

            cur = cur->left;
        }
        else
        {
            if (cur->right == NULL)
            {
                cur->right = temp;
                printf("%d added to the RIGHT of %d.\n",
                       data, cur->data);
                return;
            }

            cur = cur->right;
        }
    }
}

// Free all allocated nodes before exiting
void free_tree(struct tnode *root)
{
    if (root == NULL)
        return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void)
{
    struct tnode *root = NULL;
    int choice, data;

    printf("Binary Tree Implementation...\n");

    while (1)
    {
        printf("\n1. Insert one node");
        printf("\n2. Inorder");
        printf("\n3. Preorder");
        printf("\n4. Postorder");
        printf("\n5. Level-order");
        printf("\n6. Exit");
        printf("\n\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice)
        {
            case 1:
                printf("Enter the value: ");

                if (scanf("%d", &data) != 1)
                {
                    printf("Invalid input. Exiting.\n");
                    free_tree(root);
                    return 1;
                }

                insert(&root, data);
                break;

            case 2:
                printf("\nInorder traversal:\n");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("\nPreorder traversal:\n");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nPostorder traversal:\n");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("\nLevel-order traversal:\n");
                levelorder(root);
                printf("\n");
                break;

            case 6:
                free_tree(root);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Enter a valid choice.\n");
                break;
        }
    }

    free_tree(root);
    return 0;
}
