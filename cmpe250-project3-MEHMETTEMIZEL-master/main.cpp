#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<iterator>

#include "tarjanSCC.h"
#include <unordered_set>

using namespace std;

template<class Container>
void split1(const string &str, Container &cont) {
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

int main(int argc, char *argv[]) {
    // below reads the input file
    ios_base::sync_with_stdio(false);

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


    getline(infile, line);
    vector<string> words;
    split1(line, words);
    int NumberOfNodes = stoi(words[0]);


    tarjanSCC MyPiggyBank(NumberOfNodes, argv[2]);



    /*
    int bankNumer;

    infile >> bankNumer;*/

    for (int i = 1; i < NumberOfNodes + 1; i++) {
        getline(infile, line);
        vector<string> words;
        split1(line, words);
        int numOfKey = stoi(words[0]);

        MyPiggyBank.graph[i] = new int[numOfKey];
        MyPiggyBank.numOfKeys[i] = numOfKey;


        for (int j = 0; j < numOfKey; j++) {
            int toWhich = stoi(words[j + 1]);
            (MyPiggyBank.graph[i])[j] = toWhich;

        }


    }
    cout << "input file has been read" << endl;

    MyPiggyBank.funcForFindSccs();

    /*   ofstream myfile;
       myfile.open(argv[2]);

       myfile << NumberOfNodes << endl;
       for (int j = 1; j < NumberOfNodes + 1; j++) {
           myfile << MyPiggyBank.numOfKeys[j] << " ";
           for (int k = 0; k < MyPiggyBank.numOfKeys[j]; k++)
               myfile << MyPiggyBank.graph[j][k] << " ";
           myfile<<endl;



       //    myfile << MyPiggyBank.low[j];
       }

   */

    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>

    //cout << avg1 << " " << late1 << endl;
    //myfile << avg1 << " " << late1 << " "<<endl;

    //  myfile.close();

    cout << "output file has been written" << endl;


    return 0;
}