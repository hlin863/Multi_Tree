#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

/******************************************************************************
 * Function: insert_multiway_tree
 * Description: Inserts an entry into the tree
 * Parameters: tree - the tree to insert into.
 *             data - the data to insert
/******************************************************************************/
void insertTree(MULTIWAY_TREE *tree, void *data);

/******************************************************************************/
/*
    * Identifies the leaf to insert the data. 
    * @param node The root of the tree.
    * @param data The data to insert.
    * @return The leaf to insert the data.
    * @return tree with the data inserted if the data is not in the tree.
*/
/******************************************************************************/
bool insertNode(MULTIWAY_TREE* tree, NODE *node, void *data, ENTRY *upEntry);

/******************************************************************************
 * Function: compare
 * Description: Compares two entries
 * Parameters: data1 - the first entry
 *             data2 - the second entry
 * Returns: 0 if the entries are equal, -1 if data1 < data2, 1 if data1 > data2
/******************************************************************************/
int compare(void *data1, void *data2);

void testCompare();