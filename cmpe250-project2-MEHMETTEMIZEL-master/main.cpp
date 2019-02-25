#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<iterator>

#include "OptimizedAirport.h"


using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

int main(int argc, char* argv[]) {
    // below reads the input file

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
    split1(line,words);
    int NumberOfCustomers= stoi(words[0]);

    int LuggageCounters=stoi(words[1]);

    int SecurityCounters=stoi(words[2]);


    cout << "number of customers: " << NumberOfCustomers << endl;
    cout << "number of luggage counters: " << LuggageCounters << endl;
    cout << "number of security counters: " << SecurityCounters << endl;

    OptimizedAirport MyManager(NumberOfCustomers,LuggageCounters,SecurityCounters);


    for (int i=0; i<NumberOfCustomers; i++) {
        getline(infile, line);
        vector<string> words;
        split1(line,words);

        int arrival=stoi(words[0]);
        int flight=stoi(words[1]);
        int luggageService=stoi(words[2]);
        int securityService=stoi(words[3]);
        bool VIP=(words[4][0]=='V')? true:false;
        bool luggage=(words[5][0]=='L')? true:false;


        MyManager.people[i]=new Person(arrival,flight,luggageService,securityService,VIP,luggage);

        //  cout <<i<< "th customer :"<< MyManager.Customers[i]->arrivalTime <<" "<< MyManager.Customers[i]->flightTime<<" " << MyManager.Customers[i]->luggageServiceTime<<" " <<MyManager.Customers[i]->securityServiceTime<<" " <<MyManager.Customers[i]->VIP <<" "<<MyManager.Customers[i]->luggage<<" " <<endl;

    }
    cout << "input file has been read" << endl;



    MyManager.startSimulation(false,false,false);     // 1
    MyManager.avg1=MyManager.avgSpendTime;
    MyManager.late1=MyManager.latePeople;
    MyManager.resetStatistics();

    MyManager.startSimulation(true,false,false);        //2
    MyManager.avg2=MyManager.avgSpendTime;
    MyManager.late2=MyManager.latePeople;
    MyManager.resetStatistics();

    MyManager.startSimulation(false,true,false);        //3
    MyManager.avg3=MyManager.avgSpendTime;
    MyManager.late3=MyManager.latePeople;
    MyManager.resetStatistics();

    MyManager.startSimulation(true,true,false);         //4
    MyManager.avg4=MyManager.avgSpendTime;
    MyManager.late4=MyManager.latePeople;
    MyManager.resetStatistics();

    MyManager.startSimulation(false,false,true);        //5
    MyManager.avg5=MyManager.avgSpendTime;
    MyManager.late5=MyManager.latePeople;
    MyManager.resetStatistics();

    MyManager.startSimulation(true,false,true);       //6
    MyManager.avg6=MyManager.avgSpendTime;
    MyManager.late6=MyManager.latePeople;
    MyManager.resetStatistics();

    MyManager.startSimulation(false,true,true);       //7
    MyManager.avg7=MyManager.avgSpendTime;
    MyManager.late7=MyManager.latePeople;
    MyManager.resetStatistics();

    MyManager.startSimulation(true,true,true);       //8
    MyManager.avg8=MyManager.avgSpendTime;
    MyManager.late8=MyManager.latePeople;
    MyManager.resetStatistics();



    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>
    ofstream myfile;
    myfile.open (argv[2]);

    cout << MyManager.avg1 << " " << MyManager.late1 << endl;
    myfile << MyManager.avg1 << " " << MyManager.late1 << " "<<endl;

    cout << MyManager.avg2 << " " << MyManager.late2 << endl;
    myfile << MyManager.avg2 << " " << MyManager.late2 << " "<<endl;

    cout << MyManager.avg3 << " " << MyManager.late3 << endl;
    myfile << MyManager.avg3 << " " << MyManager.late3 << " "<<endl;

    cout << MyManager.avg4 << " " << MyManager.late4 << endl;
    myfile << MyManager.avg4 << " " << MyManager.late4 << " "<<endl;

    cout << MyManager.avg5 << " " << MyManager.late5 << endl;
    myfile << MyManager.avg5 << " " << MyManager.late5 << " "<<endl;

    cout << MyManager.avg6 << " " << MyManager.late6 << endl;
    myfile << MyManager.avg6 << " " << MyManager.late6 << " "<<endl;

    cout << MyManager.avg7 << " " << MyManager.late7 << endl;
    myfile << MyManager.avg7 << " " << MyManager.late7 << " "<<endl;

    cout << MyManager.avg8 << " " << MyManager.late8 << endl;
    myfile << MyManager.avg8 << " " << MyManager.late8 << " "<<endl;


    //cout << avg1 << " " << late1 << endl;
    //myfile << avg1 << " " << late1 << " "<<endl;




    /*
    cout << avg2 << " " << late2 << endl;
    myfile << avg2 << " " << late2 << " "<<endl;

    cout << avg3 << " " << late3 << endl;
    myfile << avg3 << " " << late3 << " "<<endl;

    cout << avg4 << " " << late4 << endl;
    myfile << avg4 << " " << late4 << " "<<endl;

    cout << avg5 << " " << late5 << endl;
    myfile << avg5 << " " << late5 << " "<<endl;

    cout << avg6 << " " << late6 << endl;
    myfile << avg6 << " " << late6 << " "<<endl;

    cout << avg7 << " " << late7 << endl;
    myfile << avg7 << " " << late7 << " "<<endl;

    cout << avg8 << " " << late8 << endl;
    myfile << avg8 << " " << late8 << " "<<endl;
    */

    myfile.close();

    cout << "output file has been written" << endl;


    return 0;
}