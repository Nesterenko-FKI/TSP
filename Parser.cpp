#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Parser {
    
private:
    string filename;
    ifstream fin;
    
public:
    vector <double> X, Y;
    int N;
    Parser(const string& path) {
        fin.open(path);
        if (!fin.is_open()) {
            cout << "error!" << endl;
        }
        else {
            string str;
            fin >> str;
            N = stoi(str);
            int i = 0;
            while (i < N) {
                str = "";
                fin >> str;
                X.push_back(stod(str));
                fin >> str;
                Y.push_back(stod(str));
                i++;
            }
        }
        fin.close();
    };
};
