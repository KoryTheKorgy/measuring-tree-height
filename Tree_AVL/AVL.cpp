#include <iostream>
#include <algorithm>
#include <fstream>
#include "AVLTree.h"

using namespace std;

const int dataset = 10;
const int N = 10;
ifstream fin;
ofstream fout;

signed main() {
    for (int i = 0; i < dataset; i++){
	    AVLTree<int> bst;
        fout.open("Output/output"+std::to_string(i)+".txt");
        fin.open("../Input/input"+std::to_string(i)+".txt");
        for (int j = 0; j < 1e6; j++){
            int x; 
            fin >> x;
            bst.insert(x);
        }
        cout << bst.maxDepth();
        fin.close();
        fout.close();
    }
	return 0;
}