#include <iostream>
#include <fstream>
#include "RBTree.h"
using namespace std;

const int dataset = 10;
const int N = 1e6;

ofstream fout;
ifstream fin;

int main(){
    ios::sync_with_stdio(0), cin.tie(nullptr);
    fout.open("output.txt");
    for (int i = 0; i < dataset; i++){
	    RBTree<int> bst;        
        fin.open("../Input/input"+std::to_string(i)+".txt");
        int x; 
        while(fin >> x) bst.insertValue(x);
        fout << "Testcase " << i << ": " << bst.maxDepth() << "\n";
        fin.close();
    }
    fout.close();
    return 0;
}