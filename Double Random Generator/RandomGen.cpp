#include <fstream>
#include <random>
#include <queue>
#include <vector>
#include <algorithm>

const int dataset = 10;
const int maxLength = 1e6;
const int maxN = 1e6;

bool cmp(int a, int b){
  return a > b;
}

void genTest(int dataset, int maxLength, float maxN){
    std::ofstream fout;
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_int_distribution<int> dist(maxN*(-1),maxN);
    std::vector<int> vec;
    std::priority_queue<int> maxq;
    
    for (int j = 0; j < maxLength; j++){
       vec.push_back(dist(e2));
    }
    for (int j = 0; j < maxLength; j++){
       maxq.push(vec[j]);
    }
    std::priority_queue minq(vec.begin(), vec.end(), std::greater<int>());

    fout.open("../Input/input0.txt");
    for (; !maxq.empty(); maxq.pop())
        fout << maxq.top() << "\n";
    fout.close();
    
    fout.open("../Input/input1.txt");
    for (; !minq.empty(); minq.pop())
        fout << minq.top() << "\n";
    fout.close();
    for (int i = 2; i < dataset; i++){

        fout.open("../Input/input"+std::to_string(i)+".txt");
        for (int j = 0; j < maxLength; j++){
            fout << std::scientific << dist(e2) << "\n";
        }
        fout.close();
    }
}

signed main(){
    genTest(dataset,maxLength,maxN);
    return 0;
}