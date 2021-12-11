#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <fstream>
constexpr auto sizeOfTheBoard = 15;
constexpr auto cardQuantity = 10;
using namespace std;

struct card{
    char name;
    int points;
};
class field{
    private:
        char letter = '_';
        int letterBonus = 1;
        int wordBonus = 1;
        int session = 0;
    public:
        void changeSessionToOccupied(){
            if (getSession() == 1){
                setSession(2);
            }
        }
        bool isOccupied() {
            if (getSession() == 2)
                return true;
            return false;
        }
        bool changeSessionToFree(){
            if (getSession() == 1){
                setSession(0);
                setLetter('_');
                return true;
             }
             return false;
        }
        void setLetter(char letter){
            this->letter = letter;
        }
        void setLetterBonnus(int letterBonus){
            this->letterBonus = letterBonus;
        }
        void setWordBonus(int wordBonus){
            this->wordBonus = wordBonus;
        }
        void setSession(int session){
            this->session = session;
        }
        char getLetter(){
            return letter;
        }
        int getLetterBonus(){
            return letterBonus;
        }
        int getWordBonus(){
            return wordBonus;
        }
        int getSession(){
            return session;
        }
};
class computerPossibilities{
    private:
        int up = 0;
        int down =0;
        int left = 0;
        int right = 0;
        int row;
        int column;
        bool ok=false;
        string word;
    public:
        computerPossibilities(int row, int column){
            this->row = row;
            this->column = column;
        }
        void setWord(string word){
            this->word = word;
        }
        string getWord(){
            return word;
        }

        void setRow(int row){
            this->row = row;
        }
        int getRow(){
            return row;
        }
        int getColumn(){
            return column;
        }
        void setColumn(int column){
            this->column = column;
        }
        void setUp(int up){
            this->up = up;
        }
        int getUp(){
            return up;
        }
        void setDown(int down){
            this->down = down;
        }
        int getDown(){
            return down;
        }
        void setLeft(int left){
            this->left = left;
        }
        int getLeft(){
            return left;
        }
        void setRight(int right){
            this->right = right;
        }
        int getRight(){
            return right;
        }
        bool getOk(){
            return ok;
        }
        void setOk(bool ok){
            this->ok = ok;
        }
};
class player {
private:
    bool firstMove = true;
    bool currentlyPlay = false;
    card playerCards[cardQuantity];
    bool playerCardsChoiceToWrite[cardQuantity] = { false };
    bool playerCardsToChange[cardQuantity] = { false };
    bool possibilityToChangeCards = true;
    string nick;
public:
    bool getPlayerCardsToChange(int i) {
        return playerCardsToChange[i];
    }
    void setPlayerCardsToChange(int i, bool state) {
        playerCardsToChange[i] = state;
    }
    char getPlayerCardsName(int i) {
        return playerCards[i].name;
    }
    int getPlayerCardsPoints(int i) {
        return playerCards[i].points;
    }
    bool getPlayerCardsChoiceToWrite(int i) {
        return playerCardsChoiceToWrite[i];
    }
    void setPlayerCardsChoiceToWrite(int i, bool state) {
        playerCardsChoiceToWrite[i] = state;
    }
    void setNick(string nick) {
        this->nick = nick;
    }
    string getNick() {
        return nick;
    }
    void setCurrentlyPlay(bool currentlyPlay) {
        this->currentlyPlay = currentlyPlay;
    }
    bool getCurrentlyPlay() {
        return currentlyPlay;
    }
    void setPossibilityToChangeCards(bool possibilityToChangeCards) {
        this->possibilityToChangeCards = possibilityToChangeCards;
    }
    bool getPossibilityToChangeCards() {
        return possibilityToChangeCards;
    }
    void randomCards(card cybant[79]) {
        srand(time(NULL));
        int j;
        for (int i = 0; i < cardQuantity; i++) {
            j = rand() % 79;
            playerCards[i].name = cybant[j].name;
            playerCards[i].points = cybant[j].points;
        }
    }
    void changeUsedCards(string word, card cybant[79]) {
        srand(time(NULL));
        int luck;
        for (int i{ 0 }; i < word.length(); i++) {
            for (int j{ 0 }; j < cardQuantity; j++) {
                if (word[i] == playerCards[j].name) {
                    luck = rand() % 79;
                    playerCards[j].name = cybant[luck].name;
                    playerCards[j].points = cybant[luck].points;
                    break;
                }
            }
        }
    }
    void changeChosenCards(card cybant[79]) {
        bool change = false;
        int luck;
        srand(time(NULL));
        for (int i{ 0 }; i < cardQuantity; i++) {
            if (playerCardsToChange[i] == true) {
                luck = rand() % 79;
                playerCards[i].name = cybant[luck].name;
                playerCards[i].points = cybant[luck].points;
                change = true;
            }
        }
        //w gameGUI booli jak false to funkcja pass a jaktrue to leci kaabarecik
    }
    void changeChosenCardsUnchecked() {
        for (int i{ 0 }; i < cardQuantity; i++) {
            playerCardsToChange[i] = false;
        }
    }
};
class gameMap{
private:
    bool firstMove = true;
    int computerPoints = 0;
    int numberOfPlayers = 1; // 1 2 3 4 // przekazanie od poprzedniej planszy
    int difficultyLevel = 3; //2 3; // wpierdalam do konstruktora potem
public:
    card* cybant = new card[79];
    field board[sizeOfTheBoard][sizeOfTheBoard];
    int getComputerPoints() {
        return computerPoints;
    }
    void setComputerPoints(int computerPoints) {
        this->computerPoints = computerPoints;
    }
    field getBoardElement(int i, int j) {
        return board[i][j];
    }
    void xxx(int i, int j) {
        getBoardElement(i, j).setSession(1);
    }
    void setBoardElement(int i, int j, field buffor) {
        this->board[i][j] = buffor;
    }
    gameMap() {
        cybant[0] = { 'A',1 };
        cybant[1] = { 'A',1 };
        cybant[2] = { 'A',1 };
        cybant[3] = { 'A',1 };
        cybant[4] = { 'A',1 };
        cybant[5] = { 'A',1 };
        cybant[6] = { 'B',3 };
        cybant[7] = { 'B',3 };
        cybant[8] = { 'B',3 };
        cybant[9] = { 'C',3 };
        cybant[10] = { 'C',3 };
        cybant[11] = { 'D',2 };
        cybant[12] = { 'D',2 };
        cybant[13] = { 'D',2 };
        cybant[14] = { 'E',1 };
        cybant[15] = { 'E',1 };
        cybant[16] = { 'E',1 };
        cybant[17] = { 'E',1 };
        cybant[18] = { 'E',1 };
        cybant[19] = { 'E',1 };
        cybant[20] = { 'F',4 };
        cybant[21] = { 'F',4 };
        cybant[22] = { 'G',2 };
        cybant[23] = { 'G',2 };
        cybant[24] = { 'G',2 };
        cybant[25] = { 'G',2 };
        cybant[26] = { 'G',2 };
        cybant[27] = { 'H',4 };
        cybant[28] = { 'H',4 };
        cybant[29] = { 'H',4 };
        cybant[30] = { 'I',1 };
        cybant[31] = { 'I',1 };
        cybant[32] = { 'I',1 };
        cybant[33] = { 'I',1 };
        cybant[34] = { 'I',1 };
        cybant[35] = { 'J',8 };
        cybant[36] = { 'J',8 };
        cybant[37] = { 'K',5 };
        cybant[38] = { 'K',5 };
        cybant[39] = { 'L',1 };
        cybant[40] = { 'L',1 };
        cybant[41] = { 'L',1 };
        cybant[42] = { 'M',3 };
        cybant[43] = { 'M',3 };
        cybant[44] = { 'N',1 };
        cybant[45] = { 'O',1 };
        cybant[46] = { 'N',1 };
        cybant[47] = { 'N',1 };
        cybant[48] = { 'O',1 };
        cybant[49] = { 'O',1 };
        cybant[50] = { 'O',1 };
        cybant[51] = { 'O',1 };
        cybant[52] = { 'P',3 };
        cybant[53] = { 'P',3 };
        cybant[54] = { 'P',3 };
        cybant[55] = { 'Q',10 };
        cybant[56] = { 'R',1 };
        cybant[57] = { 'S',1 };
        cybant[58] = { 'T',1 };
        cybant[59] = { 'U',1 };
        cybant[60] = { 'R',1 };
        cybant[61] = { 'S',1 };
        cybant[62] = { 'T',1 };
        cybant[63] = { 'U',1 };
        cybant[64] = { 'R',1 };
        cybant[65] = { 'S',1 };
        cybant[66] = { 'T',1 };
        cybant[67] = { 'U',1 };
        cybant[68] = { 'W',4 };
        cybant[69] = { 'V',4 };
        cybant[70] = { 'W',4 };
        cybant[71] = { 'V',4 };
        cybant[72] = { 'X',6 };
        cybant[73] = { 'X',6 };
        cybant[74] = { 'Y',8 };
        cybant[75] = { 'Y',8 };
        cybant[76] = { 'Z',10 };
        cybant[77] = { 'Z',10 };
        cybant[78] = { 'Z',10 };

        board[0][0].setWordBonus(3);
        board[0][7].setWordBonus(3);
        board[0][14].setWordBonus(3);
        board[7][0].setWordBonus(3);
        board[14][0].setWordBonus(3);
        board[14][7].setWordBonus(3);
        board[14][14].setWordBonus(3);
        board[7][14].setWordBonus(3);

        board[1][1].setWordBonus(2);
        board[2][2].setWordBonus(2);
        board[3][3].setWordBonus(2);
        board[4][4].setWordBonus(2);
        board[13][1].setWordBonus(2);
        board[12][2].setWordBonus(2);
        board[11][3].setWordBonus(2);
        board[10][4].setWordBonus(2);
        board[1][13].setWordBonus(2);
        board[2][12].setWordBonus(2);
        board[3][11].setWordBonus(2);
        board[4][10].setWordBonus(2);
        board[13][13].setWordBonus(2);
        board[12][12].setWordBonus(2);
        board[11][11].setWordBonus(2);
        board[10][10].setWordBonus(2);
        board[7][7].setWordBonus(2);

        board[1][5].setLetterBonnus(3);
        board[1][9].setLetterBonnus(3);
        board[5][1].setLetterBonnus(3);
        board[5][5].setLetterBonnus(3);
        board[5][9].setLetterBonnus(3);
        board[5][13].setLetterBonnus(3);
        board[9][1].setLetterBonnus(3);
        board[9][5].setLetterBonnus(3);
        board[9][9].setLetterBonnus(3);
        board[9][13].setLetterBonnus(3);
        board[13][5].setLetterBonnus(3);
        board[13][9].setLetterBonnus(3);

        board[0][3].setLetterBonnus(2);
        board[0][11].setLetterBonnus(2);
        board[2][6].setLetterBonnus(2);
        board[2][8].setLetterBonnus(2);
        board[3][0].setLetterBonnus(2);
        board[3][7].setLetterBonnus(2);
        board[3][14].setLetterBonnus(2);
        board[6][2].setLetterBonnus(2);
        board[6][6].setLetterBonnus(2);
        board[6][8].setLetterBonnus(2);
        board[6][12].setLetterBonnus(2);
        board[7][3].setLetterBonnus(2);
        board[7][11].setLetterBonnus(2);
        board[8][2].setLetterBonnus(2);
        board[8][6].setLetterBonnus(2);
        board[8][8].setLetterBonnus(2);
        board[8][12].setLetterBonnus(2);
        board[11][0].setLetterBonnus(2);
        board[11][7].setLetterBonnus(2);
        board[11][14].setLetterBonnus(2);
        board[12][6].setLetterBonnus(2);
        board[12][8].setLetterBonnus(2);
        board[14][3].setLetterBonnus(2);
        board[14][11].setLetterBonnus(2);
    }
    ~gameMap() {
        delete cybant;
    }
    void setFirstMove(bool firstMove) {
            this->firstMove = firstMove;
        }
    bool getFirstMove() {
            return firstMove;
        }
    bool isFieldEmpty(field bufforField){
            // dopisaæ warunek z sesja czyli jak juz jest cos wpisane wczesniej ze nie mozna juz zrobiłem
            if (bufforField.getLetter() == '_'){
                return true;
            }else{
                return false;
            }
        }
    bool correctMove(player playerGame) {
            int rowPointer, columnPointer;
            int i = 0;
            bool looping = true;
            bool correctness = true;
            do {
                for (int j = 0; j < sizeOfTheBoard; j++) {
                    if (board[i][j].getSession() == 1) {
                        rowPointer = i;
                        columnPointer = j;
                        looping = false;
                        break;
                    }
                }
                i++;
            } while (looping && i < sizeOfTheBoard);

            if (board[rowPointer + 1][columnPointer].getSession() == 1 || board[rowPointer + 1][columnPointer].getSession() == 2) {
                if (wordUnityCheck(rowPointer, columnPointer, "column") == false) {
                    cout << "WPISALES NIECIAGLY WYRAZ" << endl;
                    correctness = false;
                }
            }
            else if (board[rowPointer][columnPointer + 1].getSession() == 1 || board[rowPointer][columnPointer + 1].getSession() == 2) {
                if (wordUnityCheck(rowPointer, columnPointer, "row") == false) {
                    cout << "WPISALES NIEPOPRAAWNY WYRAZ" << endl;
                    correctness = false;
                }
            }
            else {
                if (letterUnityCheck(rowPointer, columnPointer) == false) {
                    cout << "WPISALES NIEPOPRAWNY WYRAZ" << endl;
                    correctness = false;
                }
            }
            if (correctness == true) {
                correctness = checkWordEnteredByPlayer(playerGame);
            }
            if (correctness == true) {
                ifstream wordsToCheck;
                wordsToCheck.open("wordsToCheck.txt");
                if (wordsToCheck.is_open()) {
                    string word;
                    while (getline(wordsToCheck, word)) {
                        //playerPointsCount(word);
                    }
                }
            }
            return correctness;
        }
    bool checkWordEnteredByPlayer(player &playerGame){
            bool ok = false;
            int pointsInRound = 0;
            ifstream dictonary;
            ifstream wordsToCheck;
            dictonary.open("dic.txt");
            wordsToCheck.open("wordsToCheck.txt");
            if (dictonary.is_open() && wordsToCheck.is_open()) {
                string line;
                string word;
                while (getline(wordsToCheck, word)) {
                    ok = false;
                    while (getline(dictonary, line)) {
                        if (strcmp(line.c_str(), word.c_str()) == 0) {
                            ok = true;
                            pointsInRound += pointsForWordCount(word);
                        }
                    }
                    if (ok == false) {
                        break;
                    }
                    // kminie ze moze byc problemik z baza danych i zapisywanie pkt zkazdego slowa - musimy pokminic z Zeromskim
                }

                wordsToCheck.close();
                dictonary.close();
            }
            return ok;
        }
    int pointsForWordCount(string word) {
            int points =0;
            for (auto letter : word) {
                for (int i{ 0 }; i < 79; i++) {
                    if (letter == cybant[i].name) {
                        points += cybant[i].points;
                        break;
                    }
                }
            }
            return points;
        }
    bool letterUnityCheck(int rowPointer, int columnPointer){
            int newWordStartPointer = columnPointer;
            int newWordEndPointer = columnPointer;
            bool ok = true;
            bool aloneLetter = false;
            for (int p = columnPointer + 1 ; p < sizeOfTheBoard; p ++){
                if(board[rowPointer][p].getSession() == 1){
                    ok = false;
                    break;
                }
            }
            if (ok == true){
                int q = rowPointer + 1;
                do{
                    for(int p=0 ; p < sizeOfTheBoard; p++){
                        if(board[q][p].getSession() == 1){
                            ok = false;
                            break;
                        }
                    }
                    q++;
                }while(q < sizeOfTheBoard && ok == true);
            }

            ofstream WRITE("wordsToCheck.txt");
            if (ok == true){
                newWordStartPointer = rowPointer;
                newWordEndPointer = rowPointer;
                for (int p = rowPointer - 1; p >= 0 ; p--){
                    if(board[p][columnPointer].getSession() == 0){
                        newWordStartPointer = p + 1;
                        break;
                    }else{
                        newWordStartPointer = p;
                    }
                }
                for (int p = rowPointer + 1 ; p < sizeOfTheBoard; p++){
                    if(board[p][columnPointer].getSession() == 0){
                        newWordEndPointer = p - 1;
                        break;
                    }else{
                        newWordEndPointer = p;
                    }
                }
                if (newWordStartPointer != newWordEndPointer){
                    for(int p = newWordStartPointer ; p <= newWordEndPointer ; p++){
                        WRITE << board[p][columnPointer].getLetter();
                    }
                    WRITE << endl;
                }else{
                    aloneLetter = true;
                }

                newWordStartPointer = columnPointer;
                newWordEndPointer = columnPointer;
                for (int p = columnPointer - 1; p >= 0 ; p--){
                    if(board[rowPointer][p].getSession() == 0){
                        newWordStartPointer = p + 1;
                        break;
                    }else{
                        newWordStartPointer = p;
                    }
                }
                for (int p = columnPointer + 1 ; p < sizeOfTheBoard; p++){
                    if(board[rowPointer][p].getSession() == 0){
                        newWordEndPointer = p - 1;
                        break;
                    }else{
                        newWordEndPointer = p;
                    }
                } if (newWordStartPointer != newWordEndPointer){
                    aloneLetter = false;
                    for(int p = newWordStartPointer ; p <= newWordEndPointer ; p++){
                        WRITE << board[rowPointer][p].getLetter();
                    }
                    WRITE << endl;
                }
            }
            if (aloneLetter == true){
                ok = false;
            }
            return ok;
        }
    bool  wordUnityCheck(int rowPointer, int columnPointer, string columnRow){
            int state = 1;
            bool ok = true;
            int endColumnPointer;
            int endRowPointer;
            if (columnRow == "column"){
                cout << rowPointer << "  " << columnPointer << endl;
                for(int q = rowPointer; q < sizeOfTheBoard; q++){
                    if(board[q][columnPointer].getSession() == 1 && state == 0){
                        ok = false;
                        cout << "1" <<endl;
                        break;
                    }else if (board[q][columnPointer].getSession() == 1 && state == 1){
                        endRowPointer = q;
                    }
                    state = board[q][columnPointer].getSession();
                }
            int q = rowPointer;
            do{
                for(int p=0 ; p < sizeOfTheBoard; p++){
                    if(board[q][p].getSession() == 1 && p != columnPointer){
                        ok = false;
                         cout << "2" <<endl;
                        break;
                    }
                }
                q++;
            }while(q < sizeOfTheBoard && ok == true);
            int newWordStartPointer = columnPointer;
            int newWordEndPointer = columnPointer;
            if (ok == true){
                ofstream WRITE("wordsToCheck.txt");
                ofstream LOCATION("wordsToCheckLocatio.txt");
                for( int p = rowPointer ; p <= endRowPointer ; p ++){
                    newWordStartPointer = columnPointer;
                    newWordEndPointer = columnPointer;
                    if (columnPointer != 0){
                        for (int q = columnPointer - 1 ; q >= 0 ; q --){
                            if (board[p][q].getSession() == 0){
                                newWordStartPointer = q + 1;
                                break;
                            }else{
                                newWordStartPointer = q;
                            }
                        }
                    }
                    if (columnPointer != sizeOfTheBoard){
                        for (int q = columnPointer + 1 ; q < sizeOfTheBoard; q ++){
                            if (board[p][q].getSession() == 0){
                                newWordEndPointer = q - 1;
                                break;
                            }else{
                                newWordEndPointer = q;
                            }
                        }
                    }
                    if (newWordEndPointer != newWordStartPointer){

                        for(q = newWordStartPointer ; q <= newWordEndPointer ; q++){
                            WRITE << board[p][q].getLetter();
                        }
                        WRITE << endl;
                    }
                }
                newWordStartPointer = rowPointer;
                newWordEndPointer = endRowPointer;
                for (int p = rowPointer - 1; p >= 0 ; p--){
                    if(board[p][columnPointer].getSession() == 0){
                        newWordStartPointer = p + 1;
                        break;
                    }else{
                        newWordStartPointer = p;
                    }
                }
                for (int p = endRowPointer + 1 ; p < sizeOfTheBoard; p++){
                    if(board[p][columnPointer].getSession() == 0){
                        newWordEndPointer = p - 1;
                        break;
                    }else{
                        newWordEndPointer = p;
                    }
                }
                for(int p = newWordStartPointer ; p <= newWordEndPointer ; p++){
                    WRITE << board[p][columnPointer].getLetter();
                }
                WRITE << endl;
            }
            // zebranie wszytkich slow do pliku

            }else if (columnRow == "row"){
                for(int q = columnPointer; q < sizeOfTheBoard; q++){
                    if(board[rowPointer][q].getSession() == 1 && state == 0){
                        ok = false;
                        break;
                    }else if (board[rowPointer][q].getSession() == 1 && state == 1){
                        endColumnPointer = q;
                    }
                    state = board[rowPointer][q].getSession();
                }
                //cout << columnPointer << endl;
                //cout << endColumnPointer << endl;
                int q = rowPointer + 1;
                do{
                    for(int p=0 ; p < sizeOfTheBoard; p++){
                        if(board[q][p].getSession() == 1){
                            ok = false;
                            break;
                        }
                    }
                q++;
                }while(q < sizeOfTheBoard && ok == true);

                // zebranie wszytkich slow do pliku
                // trzeba otworzyc plik tutaj
                // sprawdziæ chujki góra dó³ i okalaj¹ce dwójki
                int newWordStartPointer = rowPointer;
                int newWordEndPointer = rowPointer;
                if (ok == true){
                    ofstream WRITE("wordsToCheck.txt");
                    for( int p = columnPointer ; p <= endColumnPointer ; p ++){
                        newWordStartPointer = rowPointer;
                        newWordEndPointer = rowPointer;
                        if (rowPointer != 0){
                            for (int q = rowPointer - 1 ; q >= 0 ; q --){
                                if (board[q][p].getSession() == 0){
                                    newWordStartPointer = q + 1;
                                    break;
                                }else{
                                    newWordStartPointer = q;
                                }
                            }
                        }
                        if (rowPointer != sizeOfTheBoard){
                            for (int q = rowPointer + 1 ; q < sizeOfTheBoard; q ++){
                                if (board[q][p].getSession() == 0){
                                    newWordEndPointer = q - 1;
                                    break;
                                }else{
                                    newWordEndPointer = q;
                                }
                            }
                        }
                        if (newWordEndPointer != newWordStartPointer){
                            for(q = newWordStartPointer ; q <= newWordEndPointer ; q++){
                                WRITE << board[q][p].getLetter();
                            }
                            WRITE << endl;
                        }
                    }
                    newWordStartPointer = columnPointer;
                    newWordEndPointer = endColumnPointer;
                    for (int p = columnPointer - 1; p >= 0 ; p--){
                        if(board[rowPointer][p].getSession() == 0){
                            newWordStartPointer = p + 1;
                            break;
                        }else{
                            newWordStartPointer = p;
                        }
                    }
                    for (int p = endColumnPointer + 1 ; p < sizeOfTheBoard; p++){
                        if(board[rowPointer][p].getSession() == 0){
                            newWordEndPointer = p - 1;
                            break;
                        }else{
                            newWordEndPointer = p;
                        }
                    }
                    for(int p = newWordStartPointer ; p <= newWordEndPointer ; p++){
                        WRITE << board[rowPointer][p].getLetter();
                    }
                    WRITE << endl;
                }
            }
            return ok;
        }
    void letterWrite(card* playerCard,int pointer){
            while(true){
                int row,column;
                char chosenLetter;
                char returnGame;
                chosenLetter = playerCard[pointer].name;
                int i = 0;
                cout << "podaj row: ";
                cin >> row;
                cout << endl;
                cout << "podaj kolumne: ";
                cin >> column;
                if (this->isFieldEmpty(this->board[row][column])){
                    board[row][column].setLetter(chosenLetter);
                    board[row][column].setSession(1);
                    playerCard[pointer].name = '_';
                    break;
                }else if (board[row][column].getSession() == 1) {
                    char yesNo;
                    cout << "Czy koniecznie chcesz zamienic! [t/n]" << endl;
                    cin >> yesNo;
                    if (yesNo == 't'){
                        returnGame = board[row][column].getLetter();
                        while(true){
                            if (playerCard[i].name == '_'){
                                playerCard[i].name = returnGame;
                                break;
                            }
                            i++;
                        }
                        board[row][column].setLetter(chosenLetter);
                        if (chosenLetter == '_'){
                            board[row][column].setSession(0);
                        }
                        else{
                            board[row][column].setSession(1);
                            playerCard[pointer].name = '_';
                        }
                        break;
                    }
                }else if (board[row][column].getSession() == 2){
                    cout << "TO POLE JEST ZAJETE" << endl;
                    break;
                }
            }
        }
    bool computerAction() { // zmiana na bool i ingerencja w gui
            //int i = 10;
            if (!getFirstMove()) {
                bool corectness = false;
                computerPossibilities buffor(0, 0);
                buffor = computerPlaceSelection(buffor);
                corectness = computerWordSelection(buffor);
                return corectness;
            }
        }
    bool checkLettersAvability(string wordToCheck){
            return true;
        }
    void incorrextMoveOfPlayer() {
            for (int i = 0; i < sizeOfTheBoard; i++) {
                for (int j = 0; j < sizeOfTheBoard; j++) {
                    board[i][j].changeSessionToFree();
                }
            }
        }
    bool computerWordSelection(computerPossibilities computerFieldCandidate) {
            ifstream dictonary;
            bool corectness = false;
            dictonary.open("sortedDic.txt");

            srand(time(NULL));
            int difficultyLevel = 3; //2 3; // wpierdalam do konstruktora potem
            int startWordIterator = 0;
            if (difficultyLevel == 1) {
                startWordIterator = rand() % 6000; //TUTAJ ZMIENIAMY TRUDNOŚĆ!!!
            }
            else if (difficultyLevel == 2) {
                startWordIterator = rand() % 5000 + 10446;
            }
            else if (difficultyLevel == 3) {
                startWordIterator = rand() % 500 + 24000;
            }
            int spaceToWrite = 0;
            int counter = 0;
            int candidateLetterPointer = 0;
            int leftUpSpace = 0;
            int rightDownSpace = 0;
            bool upDownOrRightLeft = 0;
            bool looping = true;
            string wordToCheck;
            if ((computerFieldCandidate.getUp() + computerFieldCandidate.getDown()) > (computerFieldCandidate.getLeft() + computerFieldCandidate.getRight())) {
                spaceToWrite = computerFieldCandidate.getUp() + computerFieldCandidate.getDown();
                upDownOrRightLeft = true;
            }
            else {
                spaceToWrite = computerFieldCandidate.getLeft() + computerFieldCandidate.getRight();
                upDownOrRightLeft = false;
            }
            if (dictonary.is_open()) {
                getline(dictonary, wordToCheck);
                do {
                    startWordIterator--;
                    counter++;
                    if (getline(dictonary, wordToCheck) && startWordIterator < 0) {
                        //  cout << wordToCheck;
                        //CHUJ << wordToCheck << endl;
                        if (wordToCheck.length() <= spaceToWrite) {

                            for (int i = 0; i < wordToCheck.length(); i++) {
                                if (board[computerFieldCandidate.getRow()][computerFieldCandidate.getColumn()].getLetter() == wordToCheck[i]) {
                                    candidateLetterPointer = i;
                                    leftUpSpace = i;
                                    rightDownSpace = wordToCheck.length() - 1 - i;

                                    if (upDownOrRightLeft == true) {
                                        if (computerFieldCandidate.getUp() >= leftUpSpace && computerFieldCandidate.getDown() >= rightDownSpace) {
                                            //  if (wordToCheck.length() > 3 || counter <= 700 ){
                                            if (checkLettersAvability(wordToCheck) == true) { // ONE MORE ZEBY PRZYBLOKOWAĆ MAŁE CHUJKI

                                                cout << wordToCheck << endl;
                                                computerFieldCandidate.setWord(wordToCheck);
                                                computerFieldCandidate.setLeft(0);
                                                computerFieldCandidate.setRight(0);
                                                computerFieldCandidate.setDown(rightDownSpace);
                                                computerFieldCandidate.setUp(leftUpSpace);
                                                corectness = true;
                                                looping = false;
                                                break;
                                            }
                                            //  }
                                        }
                                    }
                                    else {
                                        if (computerFieldCandidate.getLeft() >= leftUpSpace && computerFieldCandidate.getRight() >= rightDownSpace) {
                                            //  if (wordToCheck.length() > 3 || counter >= 80000 ){
                                            if (checkLettersAvability(wordToCheck) == true) {

                                                cout << wordToCheck << endl;
                                                computerFieldCandidate.setWord(wordToCheck);
                                                computerFieldCandidate.setDown(0);
                                                computerFieldCandidate.setUp(0);
                                                computerFieldCandidate.setLeft(leftUpSpace);
                                                computerFieldCandidate.setRight(rightDownSpace);
                                                looping = false;
                                                corectness = true;

                                                break;
                                            }
                                            //  }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } while (looping == true && wordToCheck != "KONIEC!");
            }


            if (corectness == true) {
                computerWriteWordToMap(computerFieldCandidate);
            }
            return corectness;
        }
    bool checkTwoWordsDic(int up, int down, int left, int right, char letter) {
            bool ok = false;
            ifstream twoWords;
            twoWords.open("twoWordsDic.txt");
            if (twoWords.is_open()) {
                string word;
                while (getline(twoWords, word)) {
                    if (up == 1 || left == 1) {
                        if (word[1] == letter) {
                            ok = true;
                        }
                    }
                    else {
                        if (word[0] == letter) {
                            ok = true;
                        }
                    }
                }
            }
            return ok;
        }
    computerPossibilities computerPlaceSelection(computerPossibilities x){
            int i,j,iZnacznik,jZnacznik;
            bool choice = false;
            srand(time(NULL));
            int counter = 500;
            do{
            i = rand()%15;
            j = rand()%15;
            if (board[i][j].getSession() == 2){
                // znaczniI znacznik J i konstruktor kurwa
                computerPossibilities computerFieldCandidate(i,j);
                computerFieldCandidate = computerCheckSpaceAvability(computerFieldCandidate);
                if ((computerFieldCandidate.getDown()+computerFieldCandidate.getUp()) >= 2 || (computerFieldCandidate.getRight()+computerFieldCandidate.getLeft()) >= 2 ){
                    choice = true;
                }
                else if (((computerFieldCandidate.getDown() + computerFieldCandidate.getUp()) == 1 || (computerFieldCandidate.getRight() + computerFieldCandidate.getLeft()) == 1 ) && counter < 70) {
                    // DO  WYJEBANIA WIDZOWEI tu sprawdzanie dic z wyrazami dwuliterowymi mykmym
                    if (checkTwoWordsDic(computerFieldCandidate.getUp(), computerFieldCandidate.getDown(), computerFieldCandidate.getLeft(), computerFieldCandidate.getRight(), board[i][j].getLetter())) {
                        ofstream CHUJ("qqq.txt");
                        CHUJ << computerFieldCandidate.getDown() << " " << computerFieldCandidate.getUp() << " " << computerFieldCandidate.getRight() << " " << computerFieldCandidate.getLeft() << " " << endl;
                        choice = true;
                    }
                }
                x = computerFieldCandidate;
                counter--;
            }
            }while(choice == false && counter > 0);

            return x;
        }
    int getPointsOfLetter(char letter) {
            for (int i{ 0 }; i < 79; i++) {
                if (letter == cybant[i].name) {
                    return cybant[i].points;
                    break;
                }
            }
            
        }
    void computerWriteWordToMap(computerPossibilities wordToWrite){
            cout <<"ROW "<< wordToWrite.getRow() << " COLUMN " << wordToWrite.getColumn() << endl;
            int startUpLeft, startDownRight;
            string word = wordToWrite.getWord();
            //cout << word.length() << endl;
            int pointsFromWord = 0;
            int localWordBonus = 1;
            int i;
            if (wordToWrite.getUp() > 0 || wordToWrite.getDown() > 0){
                startUpLeft = wordToWrite.getRow() - wordToWrite.getUp();
                startDownRight = wordToWrite.getRow() + 1;
                for ( i = 0 ; i < wordToWrite.getUp(); i++){
                    pointsFromWord += board[startUpLeft][wordToWrite.getColumn()].getLetterBonus() * getPointsOfLetter(word[i]);
                    localWordBonus *= board[startUpLeft][wordToWrite.getColumn()].getWordBonus();
                    board[startUpLeft][wordToWrite.getColumn()].setLetterBonnus(1);
                    board[startUpLeft][wordToWrite.getColumn()].setWordBonus(1);
                    board[startUpLeft][wordToWrite.getColumn()].setLetter(word[i]);
                    board[startUpLeft][wordToWrite.getColumn()].setSession(2); 
                    startUpLeft++;
                }
                pointsFromWord += getPointsOfLetter(word[i]);
                i++;
                for ( i  ; i < word.length(); i++){
                    //cout << "tam gdzie wpisuje " << startDownRight<<endl;
                    //cout << "ktora litere " << i << endl;
                    pointsFromWord += board[startDownRight][wordToWrite.getColumn()].getLetterBonus() * getPointsOfLetter(word[i]);
                    localWordBonus *= board[startDownRight][wordToWrite.getColumn()].getWordBonus();
                    board[startDownRight][wordToWrite.getColumn()].setLetterBonnus(1);
                    board[startDownRight][wordToWrite.getColumn()].setWordBonus(1);
                    board[startDownRight][wordToWrite.getColumn()].setLetter(word[i]);
                    board[startDownRight][wordToWrite.getColumn()].setSession(2);
                    startDownRight++;
                }
                //cout << "UP " <<wordToWrite.getUp() <<" DOWN " << wordToWrite.getDown() << endl;
            }else if (wordToWrite.getLeft() > 0 || wordToWrite.getRight() > 0){
                startUpLeft = wordToWrite.getColumn() - wordToWrite.getLeft();
                startDownRight = wordToWrite.getColumn() + 1;
                for ( i = 0 ; i < wordToWrite.getLeft(); i++){
                    pointsFromWord += board[wordToWrite.getRow()][startUpLeft].getLetterBonus() * getPointsOfLetter(word[i]);
                    localWordBonus *= board[wordToWrite.getRow()][startUpLeft].getWordBonus();
                    board[wordToWrite.getRow()][startUpLeft].setLetter(word[i]);
                    board[wordToWrite.getRow()][startUpLeft].setSession(2);
                    startUpLeft++;
                }
                pointsFromWord += getPointsOfLetter(word[i]);
                i++;
                for ( i  ; i < word.length(); i++){
                    //cout << "tam gdzie wpisuje " << startDownRight<<endl;
                    //cout << "ktora litere " << i << endl;
                    pointsFromWord += board[wordToWrite.getRow()][startDownRight].getLetterBonus() * getPointsOfLetter(word[i]);
                    localWordBonus *= board[wordToWrite.getRow()][startDownRight].getWordBonus();
                    board[wordToWrite.getRow()][startDownRight].setLetter(word[i]);
                    board[wordToWrite.getRow()][startDownRight].setSession(2);
                    startDownRight++;
                }
                //cout << "LEFT " <<wordToWrite.getLeft() <<" Right " << wordToWrite.getRight() << endl;
            }
            setComputerPoints(getComputerPoints() + pointsFromWord * localWordBonus);
        }
    computerPossibilities computerCheckSpaceAvability(computerPossibilities computerFieldCandidate){
            bool correction = false;
            //UP
            for (int q = computerFieldCandidate.getRow()-1; q >= 0 ; q--){
                if (board[q][computerFieldCandidate.getColumn()].getSession() == 2){
                    break;
                }else if(board[q][computerFieldCandidate.getColumn()].getSession() == 0){
                    if (q > 0){
                        if(board[q-1][computerFieldCandidate.getColumn()].getSession() == 2){
                            break;
                        }
                    }
                    if (computerFieldCandidate.getColumn() > 0){
                        if(board[q][computerFieldCandidate.getColumn()-1].getSession() == 2){
                            break;
                        }
                    }
                    if(computerFieldCandidate.getColumn() < sizeOfTheBoard - 1){
                        if(board[q][computerFieldCandidate.getColumn()+1].getSession() == 2){
                            break;
                        }
                    }
                    computerFieldCandidate.setUp(computerFieldCandidate.getUp() + 1);
                }
            }
            //DOWN
            for (int q = computerFieldCandidate.getRow()+1; q < sizeOfTheBoard; q++){
                if (board[q][computerFieldCandidate.getColumn()].getSession() == 2){
                    break;
                }else if(board[q][computerFieldCandidate.getColumn()].getSession() == 0){
                    if (q < sizeOfTheBoard -1){
                        if(board[q+1][computerFieldCandidate.getColumn()].getSession() == 2){
                            break;
                        }
                    }
                    if (computerFieldCandidate.getColumn() > 0){
                        if(board[q][computerFieldCandidate.getColumn()-1].getSession() == 2){
                            break;
                        }
                    }
                    if(computerFieldCandidate.getColumn() < sizeOfTheBoard - 1){
                        if(board[q][computerFieldCandidate.getColumn()+1].getSession() == 2){
                            break;
                        }
                    }
                    computerFieldCandidate.setDown(computerFieldCandidate.getDown() + 1);
                }
            }

            //RIGHT
            for (int q = computerFieldCandidate.getColumn()+1; q < sizeOfTheBoard; q++){
                if (board[computerFieldCandidate.getRow()][q].getSession() == 2){
                    break;
                }else if(board[computerFieldCandidate.getRow()][q].getSession() == 0){
                    if (q < sizeOfTheBoard -1){
                        if(board[computerFieldCandidate.getRow()][q+1].getSession() == 2){
                            break;
                        }
                    }
                    if (computerFieldCandidate.getRow() > 0){
                        if(board[computerFieldCandidate.getRow()-1][q].getSession() == 2){
                            break;
                        }
                    }
                    if(computerFieldCandidate.getRow() < sizeOfTheBoard - 1){
                        if(board[computerFieldCandidate.getRow()+1][q].getSession() == 2){
                            break;
                        }
                    }
                    computerFieldCandidate.setRight(computerFieldCandidate.getRight() + 1);
                }
            }
            //LEFT
            for (int q = computerFieldCandidate.getColumn()-1; q >= 0 ; q--){
                if (board[computerFieldCandidate.getRow()][q].getSession() == 2){
                    break;
                }else if(board[computerFieldCandidate.getRow()][q].getSession() == 0){
                    if (q > 0){
                        if(board[computerFieldCandidate.getRow()][q-1].getSession() == 2){
                            break;
                        }
                    }
                    if (computerFieldCandidate.getRow() > 0){
                        if(board[computerFieldCandidate.getRow()-1][q].getSession() == 2){
                            break;
                        }
                    }
                    if(computerFieldCandidate.getRow() < sizeOfTheBoard - 1){
                        if(board[computerFieldCandidate.getRow()+1][q].getSession() == 2){
                            break;
                        }
                    }
                    computerFieldCandidate.setLeft(computerFieldCandidate.getLeft() + 1);
                }
            }
            if (board[computerFieldCandidate.getRow()+1][computerFieldCandidate.getColumn()].getSession() == 2){
                computerFieldCandidate.setUp(0);
            }
            if (board[computerFieldCandidate.getRow()-1][computerFieldCandidate.getColumn()].getSession() == 2){
                computerFieldCandidate.setDown(0);
            }
            if (board[computerFieldCandidate.getRow()][computerFieldCandidate.getColumn()-1].getSession() == 2){
                computerFieldCandidate.setRight(0);
            }
            if (board[computerFieldCandidate.getRow()][computerFieldCandidate.getColumn()+1].getSession() == 2){
                computerFieldCandidate.setLeft(0);
            }
            cout << "row " << computerFieldCandidate.getRow() << " column " << computerFieldCandidate.getColumn() << endl;
            cout << "up    - " << computerFieldCandidate.getUp() << endl;
            cout << "down  - " << computerFieldCandidate.getDown() << endl;
            cout << "right - " << computerFieldCandidate.getRight() << endl;
            cout << "left  - " << computerFieldCandidate.getLeft() << endl;

            return computerFieldCandidate;

    }
    void setNumberOfPlayers(int numberOfPlayers) {
            this->numberOfPlayers = numberOfPlayers;
        }
    int getNumberOfPlayers() {
            return numberOfPlayers;
        }
};
