#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct footBallPlayerType
{
    string name;
    string position;
    int touchDowns;
    int catches;
    int passingYards;
    int receivingYards;
    int rushingYards;
};

const int MAX = 30;

int openFile(ifstream&);
int openOutFile(ofstream& out);
void showMenu();
void getData(ifstream& inf, footBallPlayerType list[], int& length);
void printPlayerData(footBallPlayerType list[], int length, int playerNum);
void printData(footBallPlayerType list[], int length);
void saveData(ofstream& outF, footBallPlayerType list[], int length);
int searchData(footBallPlayerType list[], int length, string n);
/// replace with function prototypes to:
void updateTouchdowns(footBallPlayerType list[], int length, int p, int td);
void updateCatches(int playerNum, footBallPlayerType list[], int numOfcatches, int num);
void updatePassingYards(footBallPlayerType list[], int passingYards, int length, int playerNum);
void UpdateReceivingYards(int playerNum, footBallPlayerType list[], int numOfReceivingYards, int num);
void RushYardUpdate(footBallPlayerType list[], int length, int rushYards, int playerNum);
