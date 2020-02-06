#include <iostream>
#include "Tree.h"
#include "Node.h"

using namespace std;


int main() {
    srand (time(NULL));
    int n;
    cin >> n;
    float * a = new float[n];

    Node<float> * root = new Node<float> (rand() % 1000);

    Tree<float> * tree = new Tree<float>();

    for(int i = 1; i < n; i++) {
        a[i] = rand() % 1000 / 1007.f;
        tree->insert(root, a[i]);
    }
    tree->print(root);
    cout << tree->find_min(root) << " " << tree->find_max(root) << endl;
    return 0;
}