#include <iostream>
#include <fstream>
#include "AVLTree.h"
using namespace std;

const int dataset = 10;
const int N = 1e6;

ifstream fin;
ofstream fout;

signed main(){
    ios::sync_with_stdio(0), cin.tie(nullptr);
    fout.open("output.txt");
    for (int i = 0; i < dataset; i++){
	    AVLTree<int> bst;
        fin.open("../Input/input"+std::to_string(i)+".txt");
        int x; 
        for (fin >> x){
        while(fin >> x) bst.insertValue(x);
        }
        fout << "Testcase " << i << ": " << bst.maxDepth() << "\n";
        fin.close();
    }
    fout.close();
	return 0;
}