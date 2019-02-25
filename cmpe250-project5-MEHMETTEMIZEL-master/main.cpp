#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<iterator>

#define SIGABRT

using namespace std;

template<class Container>
void split1(const string &str, Container &cont) {
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

string *ArrForList;
string firstLine;
int numOfWordsInDic;
long long int **memoi;

bool isThisWord(string string1) {

    for (int i = 0; i < numOfWordsInDic; i++) {
        if (ArrForList[i] == string1) {
            return true;
        }
    }
    return false;
}

int findASntnce(int x, int y, int z) {
    string a = firstLine;
    while (y <= z) {
        string word = a.substr(x, y - x);
        if (isThisWord(word)) {
            return y;
        } else {
            y++;
        }
        // cout << y << endl;
    }

    return -1;
}

long long int findAllSentences(int x, int z) {
    if (memoi[x][z] != -1) {        // onceden bulunan aralik direkt array den
        return memoi[x][z];
    }


    long long int numOfSentences = 0;
    int fromWhere = x;
    while (true) {
        fromWhere = findASntnce(x, fromWhere + 1, z);
        if (fromWhere == z) {
            numOfSentences++;
            break;
        }
        if (fromWhere == -1) {
            // numOfSentences++;
            break;
        }
        numOfSentences += findAllSentences(fromWhere, z) % 1000000007;

    }
    memoi[x][z] = numOfSentences % 1000000007;
    return memoi[x][z];
}

int main(int argc, char *argv[]) {
    // below reads the input file
    int howMany;
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;

    // here, perform the input operation. in other words,
    // read the file named <argv[1]>

    ifstream infile(argv[1]);

    infile >> firstLine;
    //cout << firstLine << endl;

    infile >> numOfWordsInDic;
    //  cout << numOfWordsInDic << endl;

    ArrForList = new string[numOfWordsInDic];

    for (int i = 0; i < numOfWordsInDic; i++) {

        infile >> ArrForList[i];
        //  cout << ArrForList[i] << endl;

    }

    memoi = new long long int *[firstLine.length()];  // function values are stored

    for (int i = 0; i < firstLine.length(); i++) {        // functions arrayindeki tum degerler sifir atandi
        memoi[i] = new long long int[firstLine.length() + 1];
        fill_n(memoi[i], firstLine.length() + 1, -1); // default -1 values are assigned
    }

    //findAllSentences(0, firstLine.size());
    cout << findAllSentences(0, firstLine.size()) << endl;

    // long long int last = findAllSentences(0, firstLine.size());

    ofstream myfile;
    myfile.open(argv[2]);

    cout << "input file has been read" << endl;

    myfile << findAllSentences(0, firstLine.size()) << endl;

    myfile.close();

    cout << "output file has been written" << endl;


    return 0;
}
