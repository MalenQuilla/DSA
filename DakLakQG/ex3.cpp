#include<iostream>
#include <fstream>
#include<math.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* intitTreeNode(int data){
    TreeNode *Node = (TreeNode*) malloc(sizeof *Node);
    Node -> data = data;
    Node -> left = NULL;
    Node -> right = NULL;
    return Node;
}

int main(){
    // Read data from file--------------------------------------------------------
    int nor;
    string rooms, str;

    ifstream file("ex3.inp");
    getline(file, str);
    nor = stoi(str);
    
    string robots[nor];

    for (int i = 0; i < nor; i++){
        getline(file, str);
        robots[i] = str;
    }

    getline(file, rooms);

    file.close();

    // ---------------------------------------------------------------------------
    

}