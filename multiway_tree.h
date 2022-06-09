#include <stdio.h>
#include <stdlib.h>

typedef struct entry {
    void *data;
    struct node *right;
} ENTRY;

typedef struct node {
    struct node *first;
    int nEntries;
    ENTRY *entries;
} NODE;

typedef struct {

    int count;
    NODE *root;
    int (*compare)(void *, void *);

} MULTIWAY_TREE;

/******************************************************************************
 * Function: create_multiway_tree
 * Description: Creates a new multiway tree
 * Parameters: compare - function to compare two entries
 * Returns: A pointer to the new tree
/******************************************************************************/
MULTIWAY_TREE *createTree(int (*compare)(void *, void *));

/******************************************************************************
 * Function: search_multiway_tree
 * Description: Searches for an entry in the tree
 * Parameters: tree - the tree to search.
 *             process to search for the nodes within the tree.
 * Returns: A pointer to the entry if found, NULL otherwise
/******************************************************************************/
void *searchTree(MULTIWAY_TREE *tree, void *data);

/******************************************************************************
 * Function: recursive_search
 * Description: Recursively searches for an entry in the tree
 * Parameters:  tree - the tree to search.
 *              node - the node to search
 *              target - the target to search for
 * Returns: A pointer to the entry if found, NULL otherwise
/******************************************************************************/
void *recursiveSearch(MULTIWAY_TREE* tree, NODE *node, void *target);

void traversal(NODE *node, void (*process) (void *data));


    * Inserts data into the tree.                                                
    * @param node The root of the tree.
    * @param data The data to insert.
*/                                       
/******************************************************************************/
void insert(NODE *node, void *data);

/******************************************************************************/
/*
    * Identifies the leaf to insert the data. 
    * @param node The root of the tree.
    * @param data The data to insert.
    * @return The leaf to insert the data.
    * @return tree with the data inserted if the data is not in the tree.
*/
/******************************************************************************/
NODE *insertNode(NODE *node, void *data, ENTRY *upEntry);