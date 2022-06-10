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

// void *traversal(NODE *node, void (*process) (void *data)){
//     NODE* temp; // temp variable to track the nodes. 
//     int index; // index to track through the subtree. 

//     temp = node->first;

//     while (index < node->entries){
//         if (temp){
//             traversal(temp, process);
//         }

//         if (index < node->entries){
//             process(node->entries[index].data);
//             temp = temp->entries[index].right;
//         }

//         index++;
//     }

//     return;

// }

void insertTree(MULTIWAY_TREE *tree, void *data){
    if (tree == NULL){
        // create a new node when the tree is NULL.
        NODE* node = (NODE *)malloc(sizeof(NODE));
        node->first = NULL;
        node->entries = (ENTRY *)malloc(sizeof(ENTRY));
        // set the first entry to the data.
        node->entries[0].data = data;
        // set the right element as NULL.
        node->entries[0].right = NULL;
        // set the number of entries to 1.
        node->nEntries = 1;
        // set the root to the node.
        tree->root = node;
    }
}

bool insertNode(MULTIWAY_TREE* tree, NODE *node, void *data, ENTRY *upEntry){
    int entryNode; // variable to track the entry node.

    if (node == NULL){
        // if the root is null.
        (*upEntry).data = data;
        (*upEntry).right = NULL;
        return true;
    }

    entryNode = searchTree(tree, data);

    return true;
}

int compare(void *data1, void *data2){
    
    char *str1 = (char *)data1;
    char *str2 = (char *)data2;

    printf("Comparing %s and %s\n", str1, str2);

    return strcmp(str1, str2);

}

void testCompare(){
    // test 1 compare when string a is less than string b.
    char *a = "Labrador";
    char *b = "Penguin";

    printf("%d\n", compare(a, b));

    // test 2 compare when string a is greater than string b.
    a = "Penguin";
    b = "Labrador";

    printf("%d\n", compare(a, b));

    // test 3 compare when string a is equal to string b.

    a = "Labrador";
    b = "Labrador";

    printf("%d\n", compare(a, b));
}

int main(){

    MULTIWAY_TREE *tree = createTree(compare);

    testCompare();

}

