/*
* File: tree.c
* Author: Minh Phat
* Date: 5/4/2024
* Description: This file contains all the functions/methods for search
*/
#include "tree.h"
/*
* Description: Build a binary search tree from the given member list.
* Input: A pointer to the head of the member list, and the start and end indices for the current subtree.
* Output: A pointer to the root of the built binary search tree.
*/
CenterPoint *buildTree(MemberNode* head , int start, int end) {
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    MemberNode *node = head;
    int i;
    for (i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *) malloc(sizeof(CenterPoint));
    strcpy(root->value.uid, node->data.uid);
	strcpy(root->value.roomNumber, node->data.roomNumber);
	strcpy(root->value.name, node->data.name);
	strcpy(root->value.licensePlate, node->data.licensePlate); 
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}
/*
* Description: Construct a binary search tree from the given member list.
* Input: A pointer to the head of the member list.
* Output: A pointer to the root of the constructed binary search tree.
*/
CenterPoint *centerPoint(MemberNode *head) {
    int length = 0;
    MemberNode *node = head;
    while (node != NULL) {
        node = node->next;
        length++;
    }

    return buildTree(head, 0, length - 1);
}

/*
* Description: Perform a binary search in the binary search tree for a member with the given UID.
* Input: A pointer to the root of the binary search tree and the UID to search for.
* Output: A pointer to the CenterPoint containing the member data if found, otherwise NULL.
*/

CenterPoint *binarySearch(CenterPoint *root,const char* value) {
    if (root == NULL) {
        return NULL;
    }

    int comparisonResult = strcmp(root->value.uid, value);
    if (comparisonResult == 0) {
        return root;
    } else if (comparisonResult > 0) {
        return binarySearch(root->left, value);
    } else {
        return binarySearch(root->right, value);
    }
}

/*
* Description: Recursively search for members with the given UID in the binary search tree and print their information.
* Input: A pointer to the root of the binary search tree and the UID to search for.
* Output: None.
*/
void searchByUIDtree(CenterPoint* root, const char* uid) {
    if (root == NULL) {
        return;
    }
    searchByUIDtree(root->left, uid);
    if (strcmp(root->value.uid, uid) == 0) {
        printf("%-20s%-10s%-50s%-20s\n", root->value.uid, root->value.roomNumber, root->value.name, root->value.licensePlate);
    }

    searchByUIDtree(root->right, uid);
}