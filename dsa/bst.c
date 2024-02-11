#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *add(struct node *new, int data)
{
    struct node *newnode=(struct node *)(malloc(sizeof(struct node)));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(new==NULL)
    {
        return newnode;
    }
    else if(data > new->data)
    {
        new->right=add(new->right, data);
    }
    else
    {
        new->left=add(new->left, data);
    }
    return new;
}

void inorder(struct node *new)
{
    if(new != NULL)
    {
        inorder(new->left);
        printf("%d ", new->data);
        inorder(new->right);
    }
}

void preorder(struct node *new)
{
    if(new != NULL)
    {
        printf("%d ", new->data);
        preorder(new->left);
        preorder(new->right);
    }
}

void postorder(struct node *new)
{
    if(new != NULL)
    {
        postorder(new->left);
        postorder(new->right);
        printf("%d ", new->data);
    }
}

struct node *findmin(struct node *new)
{
    if(new==NULL)
    {
        return NULL;
    }
    else
    {
        while(new->left!=NULL)
        {
            new=new->left;
        }
        return new;
    }
}

struct node *findmax(struct node *new)
{
    while(new->right!=NULL)
    {
        new=new->right;
    }
    return new;
}

struct node *search(struct node *new, int data)
{
    if(new == NULL || new->data == data)
    {
        return new;
    }
    else if(data > new->data)
    {
        return search(new->right, data);
    }
    else
    {
        return search(new->left, data);
    }
}

struct node *delete(struct node *new, int data)
{
    if(new == NULL)
    {
        return new;
    }
    else if(data > new->data)
    {
        new->right = delete(new->right, data);
    }
    else if(data < new->data)
    {
        new->left = delete(new->left, data);
    }
    else 
    {
        if(new->left == NULL)
        {
            struct node *temp = new->right;
            free(new);
            return temp;
        }
        else if(new->right == NULL)
        {
            struct node *temp = new->left;
            free(new);
            return temp;
        }
        struct node *temp = findmin(new->right);
        new->data = temp->data;
        new->right = delete(new->right, temp->data);
    }
    return new;
} 

int depth(struct node *new)
{
    if(new==NULL)
        return 0;
    int l=depth(new->left);
    int r=depth(new->right);
    if(l>r)
    {
        return 1+l;
    }
    else
        return 1+r;
}

int count(struct node *new)
{
    if(new==NULL)
    {
        return 0;
    }
    else if(new->left==NULL && new->right==NULL)
    {
        return 1;
    }
    else 
        return count(new->left)+count(new->right);
}

int main()
{
    int ch, data;
    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Add\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n");
        printf("6. Find Min\n7. Find Max\n8. Search\n9. Depth\n10. Count Leaf Nodes\n11. Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                root = add(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Minimum value: %d\n", findmin(root)->data);
                break;
            case 7:
                printf("Maximum value: %d\n", findmax(root)->data);
                break;
            case 8:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if(search(root, data) != NULL)
                    printf("Data found\n");
                else
                    printf("Data not found\n");
                break;
            case 9:
                printf("Depth of the tree: %d\n", depth(root));
                break;
            case 10:
                printf("Count of leaf nodes: %d\n", count(root));
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *add(struct node *new, int data)
{
    struct node *newnode=(struct node *)(malloc(sizeof(struct node)));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(new==NULL)
    {
        return newnode;
    }
    else if(data > new->data)
    {
        new->right=add(new->right, data);
    }
    else
    {
        new->left=add(new->left, data);
    }
    return new;
}

void inorder(struct node *new)
{
    if(new != NULL)
    {
        inorder(new->left);
        printf("%d ", new->data);
        inorder(new->right);
    }
}

void preorder(struct node *new)
{
    if(new != NULL)
    {
        printf("%d ", new->data);
        preorder(new->left);
        preorder(new->right);
    }
}

void postorder(struct node *new)
{
    if(new != NULL)
    {
        postorder(new->left);
        postorder(new->right);
        printf("%d ", new->data);
    }
}

struct node *findmin(struct node *new)
{
    if(new==NULL)
    {
        return NULL;
    }
    else
    {
        while(new->left!=NULL)
        {
            new=new->left;
        }
        return new;
    }
}

struct node *findmax(struct node *new)
{
    while(new->right!=NULL)
    {
        new=new->right;
    }
    return new;
}

struct node *search(struct node *new, int data)
{
    if(new == NULL || new->data == data)
    {
        return new;
    }
    else if(data > new->data)
    {
        return search(new->right, data);
    }
    else
    {
        return search(new->left, data);
    }
}

struct node *delete(struct node *new, int data)
{
    if(new == NULL)
    {
        return new;
    }
    else if(data > new->data)
    {
        new->right = delete(new->right, data);
    }
    else if(data < new->data)
    {
        new->left = delete(new->left, data);
    }
    else 
    {
        if(new->left == NULL)
        {
            struct node *temp = new->right;
            free(new);
            return temp;
        }
        else if(new->right == NULL)
        {
            struct node *temp = new->left;
            free(new);
            return temp;
        }
        struct node *temp = findmin(new->right);
        new->data = temp->data;
        new->right = delete(new->right, temp->data);
    }
    return new;
} 

int depth(struct node *new)
{
    if(new==NULL)
        return 0;
    int l=depth(new->left);
    int r=depth(new->right);
    if(l>r)
    {
        return 1+l;
    }
    else
        return 1+r;
}

int count(struct node *new)
{
    if(new==NULL)
    {
        return 0;
    }
    else if(new->left==NULL && new->right==NULL)
    {
        return 1;
    }
    else 
        return count(new->left)+count(new->right);
}

int main()
{
    int ch, data;
    while(1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Add\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n");
        printf("6. Find Min\n7. Find Max\n8. Search\n9. Depth\n10. Count Leaf Nodes\n11. Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                root = add(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Minimum value: %d\n", findmin(root)->data);
                break;
            case 7:
                printf("Maximum value: %d\n", findmax(root)->data);
                break;
            case 8:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if(search(root, data) != NULL)
                    printf("Data found\n");
                else
                    printf("Data not found\n");
                break;
            case 9:
                printf("Depth of the tree: %d\n", depth(root));
                break;
            case 10:
                printf("Count of leaf nodes: %d\n", count(root));
                break;
            case 11:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
