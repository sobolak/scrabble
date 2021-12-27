//#include <iostream>
//#include <mysql.h>
//#include <fstream>
//#include <cstring>
//#include <iomanip>
//#include "accounts.h"
//#include "sha256.h"
//
//using std::cout;
//using std::endl;
//using std::setw;
//using std::left;
//using std::setfill;
//using std::ifstream;
//
//int main() {
    //string DBConfig[4];

    //std::ifstream DBconfigFile("db_config.txt");

    //if (DBconfigFile.is_open()) {     
    //    int i = 0;
    //    while (DBconfigFile.good() && i < 4) {
    //        DBconfigFile >> DBConfig[i++];
    //    }    
    //}
    //
    //UserManager* U = new UserManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
    //MatchManager* M = new MatchManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
    //MoveManager* MV = new MoveManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
//    
//
//    User* user1 = U->logIn("mufasa", "mufasa1");
//    User* user2 = U->createUser("nowy", "nowy1");
//
//    cout << setfill(' ') 
//    << setw(30) << left << "UID"                         << setw(5) << user2->getUid()                      << endl
//    << setw(30) << left << "getPlayedMatches"            << setw(5) << U->getPlayedMatches(user2)           << endl
//    << setw(30) << left << "getWonMatches"               << setw(5) << U->getWonMatches(user2)              << endl
//    << setw(30) << left << "getWonMatchesPercentage"     << setw(5) << U->getWonMatchesPercentage(user2)    << endl
//    << setw(30) << left << "getLostMatches"              << setw(5) << U->getLostMatches(user2)             << endl
//    << setw(30) << left << "getLostMatchesPercentage"    << setw(5) << U->getLostMatchesPercentage(user2)   << endl
//    << setw(30) << left << "getWonMatchesTrain"          << setw(5) << U->getWonMatchesTrain(user2)         << endl
//    << setw(30) << left << "getWonMatchesMax"            << setw(5) << U->getWonMatchesMax(user2)           << endl
//    << setw(30) << left << "getWordsCount"               << setw(5) << U->getWordsCount(user2)              << endl
//    << setw(30) << left << "getMeanLetterCount"          << setw(5) << U->getMeanLetterCount(user2)         << endl
//    << setw(30) << left << "getMeanWordScore"            << setw(5) << U->getMeanWordScore(user2)           << endl;
//
//    Match* mch1 = M->createMatch(user1, user2);
//    Move* mv1 = MV->createMove(mch1, user1, 2, 3, true, "slowo", 4);
//    Move* mv2 = MV->createMove(mch1, user2, 5, 6, false, "inneslowo", 9);
//    
//    vector<Match*>* matchesList = U->getAllMatchesList(user2);
//    if(!(*matchesList).empty()) {
//        Match* m1 = (*matchesList).back();
//        vector<Move*>* movesList = M->getAllMovesList(m1);
//        
//        for(Move* currMove : *movesList) {
//            cout << setfill(' ') 
//            << setw(9) << left << "mvid"    << setw(3) << currMove->getMvid()               << endl
//            << setw(9) << left << "mid"     << setw(3) << currMove->getMatch()->getMid()    << endl
//            << setw(9) << left << "seq"     << setw(3) << currMove->getSeq()                << endl
//            << setw(9) << left << "login"   << setw(3) << currMove->getUser()->getLogin()   << endl
//            << setw(9) << left << "r0w"     << setw(3) << currMove->getRow()                << endl
//            << setw(9) << left << "col"     << setw(3) << currMove->getCol()                << endl
//            << setw(9) << left << "isVert"  << setw(3) << currMove->getIsVert()             << endl
//            << setw(9) << left << "word"    << setw(3) << currMove->getWord()               << endl
//            << setw(9) << left << "score"   << setw(3) << currMove->getScore()              << endl
//            << setfill('-') << setw(20) << "-" << endl;
//        }
//        delete m1;
//        delete movesList;
//    }
//    delete matchesList;
//
//
//    // U->printAllUsers();
//    // M->printAllMatches();
//    // MV->printAllMoves();
//
//    U->deleteUser(user2);
//    M->deleteMatch(mch1);
//    MV->deleteMove(mv1);
//    MV->deleteMove(mv2);
//
//    delete U;
//    delete M;
//    delete MV;
//
//    return 0;
//}