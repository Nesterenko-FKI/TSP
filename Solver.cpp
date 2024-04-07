#include "Parser.cpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solver{
    Parser* parser;
    vector <int> way;
    
    double distance(Parser* parser, int v1, int v2) {
        double d = sqrt((parser->X[v1] - parser->X[v2])*(parser->X[v1] - parser->X[v2]) + (parser->Y[v1] - parser->Y[v2])*(parser->Y[v1] - parser->Y[v2]));
        return d;
    }
    
public:
    Solver (Parser* parser) {
        for (int i = 0; i < parser->N; i++) {
            way.push_back(i);
        }
        double d;
        double lenght = 0.0;
        for (int i = 0; i < parser->N - 1; i++) {
            for (int j = i + 2; j < parser->N; j++) {
                d = distance(parser, way[i], way[j]) + distance(parser, way[i + 1], way[(j + 1)%parser->N]) - distance(parser, way[i], way[i + 1]) - distance(parser, way[j], way[(j + 1)%parser->N]);
                if (d < 0) {
                    reverse(way.begin()+i+1, way.begin()+j+1);
                    j = i + 2;
                }
            }
        }
        for (int i = 0; i < parser->N - 1; i++) {
            lenght = lenght + distance(parser, way[i], way[i+1]);
        }
        lenght = lenght + distance(parser, 0, way[parser->N-1]);
        cout<<lenght<<endl;
        for (int i = 0; i < parser->N; i++) {
            cout<<way[i]<<" ";
        }
        cout<<endl;
    };
};