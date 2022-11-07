// 210Program4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <string>

using namespace std;

class Node {
private:
    char letter;
    Node* next;
public:
    Node() = default;
    Node(char letter, Node* next) : letter(letter), next(next) {}
    void setLetter(char letter) {
        this->letter = toupper(letter);
    }
    void setNext(Node* next) {
        this->next = next;
    }
    int getLetter() {
        return this->letter;
    }
    Node* getNext() {
        return this->next;
    }
};

class HangmanNode : public Node {
private:
    bool isShow;
public:
    HangmanNode() = default;
    HangmanNode(char letter, bool isShow, Node* next) {
        setLetter(letter);
        setNext(next);
        this->isShow = isShow;
    }

    void setIsShow(bool isShow) {
        this->isShow = isShow;
    }
    bool getIsShow() {
        return this->isShow;
    }

};

class LinkedList {
private:
    Node* head;
    Node* rear;
    int sz;
public:
    LinkedList() {
        head = nullptr;
        rear = nullptr;
        sz = 0;
    }
    void add(Node* a) {
        if (head == nullptr) {
            head = a;
            rear = a;
        }
        else {
            rear->setNext(a);
            rear = a;
        }
        ++sz;
    }
    int getSize() {
        return this->sz;
    }
    Node* getHead() {
        return this->head;
    }
};

class Game {
private:
    enum State {
        START, // Added this to indicate first guess state
        PLATFORM,
        HEAD,
        BODY,
        LEFT_ARM,
        RIGHT_ARM,
        LEFT_LEG,
        RIGHT_LEG,
        HUNG
    };
    map<State, string> STATE_TEXT_MAP;

    State currentState;
    LinkedList hangList;
    LinkedList guessList;
public:
    Game() {

        //ASKING FOR INPUT WORD FROM PLAYER
        cout << "Enter a word:";
        string word;
        cin >> word;
        system("clear");
        usleep(1000000);

        //SETTING UP STATE TO TEXT MAPPING(FOR CONSOLE PRINTING PURPOSES)
        STATE_TEXT_MAP[START] = "START";
        STATE_TEXT_MAP[PLATFORM] = "PLATFORM";
        STATE_TEXT_MAP[HEAD] = "HEAD";
        STATE_TEXT_MAP[BODY] = "BODY";
        STATE_TEXT_MAP[LEFT_ARM] = "LEFT ARM";
        STATE_TEXT_MAP[RIGHT_ARM] = "RIGHT ARM";
        STATE_TEXT_MAP[LEFT_LEG] = "LEFT LEG";
        STATE_TEXT_MAP[RIGHT_LEG] = "RIGHT LEG";
        STATE_TEXT_MAP[HUNG] = "HUNG";

        //INITIALIZING VARIABLES
        this->currentState = START;
        guessList = LinkedList();
        hangList = LinkedList();

        for (int i = 0; i < word.size(); ++i) {
            if (!isalpha(word[i])) throw("Invalid State");
            Node* node = new HangmanNode(word[i], false, nullptr);
            hangList.add(node);
        }
    }

    //Printing the Menu
    void printConsole() {
        system("clear");
        usleep(1000000);
        cout << "CURRENT STATE: " << STATE_TEXT_MAP[currentState];
        cout << endl;
        HangmanNode* head = (HangmanNode*)hangList.getHead();
        while (head != nullptr) {
            //            cout<<"*";
            if (head->getIsShow()) {
                cout << (char)head->getLetter() << " ";
            }
            else {
                cout << "_ ";
            }
            head = (HangmanNode*)head->getNext();
        }
        cout << endl;
        cout << "(" << 8 - (int)currentState << " wrong attempts allowed)\n";
        cout << "Your response(type quit if you wish to exit):\n";
    }

    //Game Logic
    void play() {
        do {
            if (currentState == HUNG) {
                cout << "\n\nYOU LOST(since you have reached HUNG state)\n\n";
                break;
            }
            printConsole();
            string response;
            cin >> response;
            //Exit Route
            if (response == "quit") {
                cout << "Exiting...";
                break;
            }
            else {
                //Invalid Input by User
                if (response.size() > 1 || !isalpha(response[0])) {
                    cout << "Invalid response..Try again\n";
                    usleep(1000000);
                }
                //Valid Input
                else {
                    char ch = toupper(response[0]);
                    Node* guessHead = guessList.getHead();
                    bool exists = false;
                    //Checking if input entered already exists in Guess Linked List
                    while (guessHead != nullptr) {
                        if (guessHead->getLetter() == ch) {
                            exists = true;
                            break;
                        }
                        guessHead = guessHead->getNext();
                    }
                    if (!exists) {
                        //Does not exist in Guess Linked List
                        guessList.add(new Node(ch, nullptr));
                        HangmanNode* head = (HangmanNode*)hangList.getHead();
                        int shownCount = 0;
                        int match = 0;
                        //Setting up the word in response to input character
                        while (head != nullptr) {
                            if (head->getLetter() == ch) {
                                //Maintaining Match Count to check if any match has occurred
                                ++match;
                                head->setIsShow(true);
                            }
                            if (head->getIsShow()) {
                                // Maintaining show count to check if entire string has been shown
                                ++shownCount;
                            }
                            head = (HangmanNode*)head->getNext();
                        }
                        if (match == 0) {
                            //No Match - Thus update the game state
                            currentState = State(currentState + 1);
                        }
                        if (shownCount == hangList.getSize()) {
                            // Complete String shown - User wins
                            cout << "\n\nYOU WIN\n\n";
                            break;
                        }
                    }
                }
            }
        } while (true);
    }
};

int main() {
    while (true) {
        try {
            Game g = Game();
            g.play();
            break;
        }
        catch (const char* a) {
            printf("Initialization error: %s", a);
            cout << "\nTip:Only add a alphabetical string\n";
            continue;
        }
    }
}