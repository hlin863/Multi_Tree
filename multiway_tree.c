#include "multiway_tree.h"

MULTIWAY_TREE *createTree(int (*compare)(void *, void *)){
    MULTIWAY_TREE *tree = (MULTIWAY_TREE *)malloc(sizeof(MULTIWAY_TREE));
    tree->root = NULL;
    tree->compare = compare;
    tree->count = 0;
    return tree;
}

void *searchTree(MULTIWAY_TREE *tree, void *data){
    if (tree->root == NULL){
        return NULL;
    } else {
        recursiveSearch(tree, tree->root, data);
    }
}

/******************************************************************************/
/*
    * Recursively searches for an entry in the tree
    * Parameters:  tree - the tree to search.
    *              node - the node to search
    *              target - the target to search for 
    * Returns: A pointer to the entry if found, NULL otherwise
    *  compare the target with the first item in the tree.
*/
/******************************************************************************/
void *recursiveSearch(MULTIWAY_TREE* tree, NODE *node, void *target){

    /*
        initialise a found location to track the variables.  
    */
    int foundLocation = node->entries - 1;

    if (!node){
        return NULL;
    } else {

        // if target < first entry
        if (tree->compare(target, node->entries[0].data) < 0){
            return recursiveSearch(tree, node->first, target);
        } 

        // while the search key is less than the current data. 
        while (tree->compare(target, node->entries[foundLocation].data) < 0){
            foundLocation--;
        }

        if (tree->compare(target, node->entries[foundLocation].data) == 0){
            // if the target is found, return the data.
            return node->entries[foundLocation].data;
        } else {
            return recursiveSearch(tree, node->entries[foundLocation].right, target);
        }

    }
}

void *traversal(NODE *node, void (*process) (void *data)){
    NODE* temp; // temp variable to track the nodes. 
    int index; // index to track through the subtree. 

    temp = node->first;

    while (index < node->entries){
        if (temp){
            traversal(temp, process);
        }

        if (index < node->entries){
            process(node->entries[index].data);
            temp = temp->entries[index].right;
        }

        index++;
    }

    return;

}

void insert(NODE *node, void *data){
    /*
        if tree is empty, create new node 
    */
   if (node == NULL){
        node = (NODE*) malloc(sizeof(NODE));
    //    set the left subtree of the node to NULL.
        node->first = NULL;
    // move data to the first entry in the new node.
        node->entries[0].data = data;
    // set the subtree of the first entry to NULL.
        node->entries[0].right = NULL;
    // set the number of entries in the node to 1.
        node->nEntries = 1;
   } else {
       insertNode(node, data, NULL);
   }
}

NODE *insertNode(NODE *node, void *data, ENTRY *upEntry){

}