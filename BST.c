#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node* root = NULL;
int count = 0;

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int data) {
    struct Node* newNode = getNode(data);
    if (root == NULL) {
        root = newNode;
        return;
    }
    struct Node* temp = root;
    struct Node* prev = NULL;
    while (temp != NULL) {
        prev = temp;
        if (temp->data > data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (prev->data > data)
        prev->left = newNode;
    else
        prev->right = newNode;
}

void inorder(struct Node* temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void preorder(struct Node* temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct Node* temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

struct Node* recInsert(struct Node* root, int value) {
    if (root == NULL) return getNode(value);
    if (root->data > value)
        root->left = recInsert(root->left, value);
    else
        root->right = recInsert(root->right, value);
    return root;
}

struct Node* findMax(struct Node* temp) {
    if (temp == NULL || temp->right == NULL) return temp;
    return findMax(temp->right);
}

struct Node* findMin(struct Node* temp) {
    if (temp == NULL || temp->left == NULL) return temp;
    return findMin(temp->left);
}

struct Node* delete(struct Node* temp, int value) {
    if (!temp) return NULL;

    if (temp->data > value)
        temp->left = delete(temp->left, value);
    else if (temp->data < value)
        temp->right = delete(temp->right, value);
    else {
        if (!temp->left) {
            struct Node* temp1 = temp->right;
            free(temp);
            return temp1;
        }
        if (!temp->right) {
            struct Node* temp1 = temp->left;
            free(temp);
            return temp1;
        }
        struct Node* min = findMin(temp->right);
        temp->data = min->data;
        temp->right = delete(temp->right, min->data);
    }
    return temp;
}

void search(int key) {
    struct Node* temp = root;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key found\n");
            return;
        } else if (temp->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Key not found\n");
}

void countNodes(struct Node* temp) {
    if (temp != NULL) {
        countNodes(temp->left);
        count++;
        countNodes(temp->right);
    }
}

void countLeafNodes(struct Node* temp) {
    if (temp != NULL) {
        countLeafNodes(temp->left);
        if (temp->left == NULL && temp->right == NULL)
            count++;
        countLeafNodes(temp->right);
    }
}

void countOneChildNodes(struct Node* temp) {
    if (temp != NULL) {
        countOneChildNodes(temp->left);
        if ((temp->left == NULL && temp->right != NULL) || (temp->left != NULL && temp->right == NULL))
            count++;
        countOneChildNodes(temp->right);
    }
}

void countTwoChildNodes(struct Node* temp) {
    if (temp != NULL) {
        countTwoChildNodes(temp->left);
        if (temp->left != NULL && temp->right != NULL)
            count++;
        countTwoChildNodes(temp->right);
    }
}

int main() {
    int choice, data;
    do {
        printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Recursive Insert\n6. Find Max\n7. Find Min\n8. Delete\n9. Search\n10. Count Nodes\n11. Count Leaf Nodes\n12. Count One Child Nodes\n13. Count Two Child Nodes\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                root = recInsert(root, data);
                break;
            case 6:
                printf("Max: %d\n", findMax(root)->data);
                break;
            case 7:
                printf("Min: %d\n", findMin(root)->data);
                break;
            case 8:
                printf("Enter data: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 9:
                printf("Enter key: ");
                scanf("%d", &data);
                search(data);
                break;
            case 10:
                count = 0;
                countNodes(root);
                printf("Number of nodes: %d\n", count);
                break;
            case 11:
                count = 0;
                countLeafNodes(root);
                printf("Number of leaf nodes: %d\n", count);
                break;
            case 12:
                count = 0;
                countOneChildNodes(root);
                printf("Number of nodes with one child: %d\n", count);
                break;
            case 13:
                count = 0;
                countTwoChildNodes(root);
                printf("Number of nodes with two children: %d\n", count);
                break;
            case 14:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 14);
    return 0;
}