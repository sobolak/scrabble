#include <iostream>
#include <mysql/mysql.h>
#include <fstream>
#include <cstring>
#include "accounts.h"
#include "sha256.h"

using std::cout;
using std::endl;
using std::ifstream;

int main() {
    string DBConfig[4];

    std::ifstream DBconfigFile("db_config.txt");

    if (DBconfigFile.is_open()) {     
        int i = 0;
        while (DBconfigFile.good() && i < 4) {
            DBconfigFile >> DBConfig[i++];
        }    
    }
    
    UserManager* U = new UserManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
    MatchManager* M = new MatchManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
    MoveManager* MV = new MoveManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
    
    User* user1 = U->createUser("tuta", "tuta1");
    User* user2 = U->logIn("mufasa", "mufasa1");

    Match* match = M->createMatch(user1, user2);
    
    Move* mv1 = MV->createMove(match, user1, "slowo", 4);
    

    U->printAllUsers();
    M->printAllMatches();
    MV->printAllMoves();

    U->deleteUser(user1);
    M->deleteMatch(match);
    MV->deleteMove(mv1);

    delete U;
    delete M;
    delete MV;
    
    delete user2;

    return 0;
}