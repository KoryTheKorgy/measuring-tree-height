#include <bits/stdc++.h>
#include "RBTree.h"
using namespace std;

const int dataset = 10;

ofstream fout;
ifstream fin;

int main() {
    for (int i = 0; i < dataset; i++){
	    RBTree<int> bst;
        fout.open("Output/output"+std::to_string(i)+".txt");
        fin.open("../Input/input"+std::to_string(i)+".txt");
        for (int j = 0; j < 1e6; j++){
            int x; 
            fin >> x;
            bst.insertValue(x);
        }
        cout << bst.maxDepth() << "\n";
        fin.close();
        fout.close();
    }
    return 0;
}