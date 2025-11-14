#include "threads.h"
#include <iostream>
#include <format>


using namespace std;
int main() {
    vector<string> files11 = { "inputa1.txt" };
    vector<string> files12 = { "inputa1.txt", "inputa2.txt" };
    vector<string> files13 = { "inputa1.txt", "inputa2.txt", "inputa3.txt" };
    vector<string> files21 = { "inputb1.txt" };
    vector<string> files22 = { "inputb1.txt", "inputb2.txt" };
    vector<string> files23 = { "inputb1.txt", "inputb2.txt", "inputb3.txt" };
    vector<string> files31 = { "inputc1.txt" };
    vector<string> files32 = { "inputc1.txt", "inputc2.txt" };
    vector<string> files33 = { "inputc1.txt", "inputc2.txt", "inputc3.txt" };
    cout << "a)" << endl;
    funcForAllMethods(files11, files12, files13);
    cout << "b)" << endl;
    funcForAllMethods(files21, files22, files23);
    cout << "c)" << endl;
    funcForAllMethods(files31, files32, files33);

    return 0;
}