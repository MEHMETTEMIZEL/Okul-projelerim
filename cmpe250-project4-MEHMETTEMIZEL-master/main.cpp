#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<iterator>
#include <limits.h>
#include "Node.h"
#include <queue>

#define SIGABRT

using namespace std;

template<class Container>
void split1(const string &str, Container &cont) {
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

int shortestLadder;


int main(int argc, char *argv[]) {
    // below reads the input file
//
//
//    priority_queue<Node> test2;
//    Node no1(1,1,2,100);
//
//    Node no2(1,1,2,21);
//
//    Node no3(1,2,2,200);
//
//    Node no4(1,2,2,11);
//
//    test2.push(no1);
//    test2.push(no2);
//    test2.push(no3);
//    test2.push(no4);
//    cout<< test2.top().shortestPath<<endl;


    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;


    // here, perform the input operation. in other words,
    // read the file named <argv[1]>

    ifstream infile(argv[1]);
    string line;
    vector<string> input;
    // process first line
    /* getline(infile, line);
    int N = stoi(line);
    cout << "number of input lines: " << N << endl;     */

    getline(infile, line);
    vector<string> words;
    split1(line, words);
    int NodeX = stoi(words[0]);

    int NodeY = stoi(words[1]);

    Node **ArrForList = new Node *[NodeX + 1];
    bool **fixedOrNot = new bool *[NodeX + 1];

    /* cout<<"numOf X: " << NodeX<< endl;
     cout<<"numOf Y: " << NodeY<< endl;
     cout<< ArrForList<< endl;
 */
    for (int i = 1; i <= NodeX; i++) {

        ArrForList[i] = new Node[NodeY + 1];
        fixedOrNot[i] = new bool[NodeY + 1];

        getline(infile, line);
        vector<string> words;
        split1(line, words);

        for (int j = 1; j <= NodeY; j++) {
            ArrForList[i][j].height = stoi(words[j - 1]);
            // cout<<ArrForList[i][j].height<<' ';
            ArrForList[i][j].xCoor = i;
            ArrForList[i][j].yCoor = j;

            ArrForList[i][j].shortestPath = INT_MAX;
            fixedOrNot[i][j] = false;


            //  cout<<ArrForList[i][j].xCoor<< ' '<< ArrForList[i][j].yCoor;
        }

        //cout<< endl;
    }

    getline(infile, line);
    vector<string> words3;
    split1(line, words3);
    int howManyTarget = stoi(words3[0]);

    getline(infile, line);
    vector<string> words2;
    split1(line, words2);
    int srcCoorX = stoi(words2[0]);
    int srcCoorY = stoi(words2[1]);
    int targetCoorX = stoi(words2[2]);
    int targetCoorY = stoi(words2[3]);

//    cout << howManyTarget << ' ' << endl;
//    cout << srcCoorX << ' ';
//    cout << srcCoorY << ' ';
//    cout << targetCoorX << ' ';
//    cout << targetCoorY << ' ';
    //
    // cout<< shortestLadder<< ' ';



    priority_queue<Node> pqForDistance;


    ArrForList[srcCoorX][srcCoorY].shortestPath = 0;
    pqForDistance.push(ArrForList[srcCoorX][srcCoorY]);
    fixedOrNot[srcCoorX][srcCoorY] = true;

    while (!pqForDistance.empty()) {
        Node temp = pqForDistance.top();
        pqForDistance.pop();
        fixedOrNot[temp.xCoor][temp.yCoor]=true;

        // Node temp2=pqForDistance.top();
        //pqForDistance.pop();
        if (temp.xCoor == targetCoorX && temp.yCoor == targetCoorY) {
            shortestLadder = temp.shortestPath;
            break;
        } else {


            if (1 <= temp.xCoor + 1 && temp.xCoor + 1 <= NodeX) {
                if (max(temp.shortestPath, abs(ArrForList[temp.xCoor + 1][temp.yCoor].height - temp.height)) <
                    ArrForList[temp.xCoor + 1][temp.yCoor].shortestPath && !fixedOrNot[temp.xCoor + 1][temp.yCoor]) {
                    ArrForList[temp.xCoor + 1][temp.yCoor].shortestPath = max(
                            abs(ArrForList[temp.xCoor + 1][temp.yCoor].height - temp.height), temp.shortestPath);
                    //fixedOrNot[temp.xCoor + 1][temp.yCoor] = true;
                    pqForDistance.push(ArrForList[temp.xCoor + 1][temp.yCoor]);

                }

            }

            if (1 <= temp.xCoor - 1 && temp.xCoor - 1 <= NodeX) {
                if (max(temp.shortestPath, abs(ArrForList[temp.xCoor - 1][temp.yCoor].height - temp.height)) <
                    ArrForList[temp.xCoor - 1][temp.yCoor].shortestPath && !fixedOrNot[temp.xCoor - 1][temp.yCoor]) {
                    ArrForList[temp.xCoor - 1][temp.yCoor].shortestPath = max(
                            abs(ArrForList[temp.xCoor - 1][temp.yCoor].height - temp.height), temp.shortestPath);
                   // fixedOrNot[temp.xCoor - 1][temp.yCoor] = true;
                    pqForDistance.push(ArrForList[temp.xCoor - 1][temp.yCoor]);
                }

            }
            if (1 <= temp.yCoor + 1 && temp.yCoor + 1 <= NodeY) {
                if (max(temp.shortestPath, abs(ArrForList[temp.xCoor][temp.yCoor + 1].height - temp.height)) <
                    ArrForList[temp.xCoor][temp.yCoor + 1].shortestPath && !fixedOrNot[temp.xCoor][temp.yCoor + 1]) {
                    ArrForList[temp.xCoor][temp.yCoor + 1].shortestPath = max(
                            abs(ArrForList[temp.xCoor][temp.yCoor + 1].height - temp.height), temp.shortestPath);
                 //   fixedOrNot[temp.xCoor][temp.yCoor + 1] = true;
                    pqForDistance.push(ArrForList[temp.xCoor][temp.yCoor + 1]);
                }

            }
            if (1 <= temp.yCoor - 1 && temp.yCoor - 1 <= NodeY) {
                if (max(temp.shortestPath, abs(ArrForList[temp.xCoor][temp.yCoor - 1].height - temp.height)) <
                    ArrForList[temp.xCoor][temp.yCoor - 1].shortestPath && !fixedOrNot[temp.xCoor][temp.yCoor - 1]) {
                    ArrForList[temp.xCoor][temp.yCoor - 1].shortestPath = max(
                            abs(ArrForList[temp.xCoor][temp.yCoor - 1].height - temp.height), temp.shortestPath);
                   // fixedOrNot[temp.xCoor][temp.yCoor - 1] = true;
                    pqForDistance.push(ArrForList[temp.xCoor][temp.yCoor - 1]);
                }

            }


        }


    }


    ofstream myfile;
    myfile.open(argv[2]);

    cout << "input file has been read" << endl;
    myfile << shortestLadder << endl;

    myfile.close();

    cout << "output file has been written" << endl;


    return 0;
}