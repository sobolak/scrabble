#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <mysql/mysql.h>
#include "accounts.h"
#include "sha256.h"

using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::stringstream;

// ----- User -----

User::User(const string login, const string password) {
    setLogin(login);
    setPassword(password);
}

User::~User() {
    // nothing yet
}

void User::setUid(int uid) {
    this->uid = uid;
}

void User::setLogin(string login) {
    int size = login.size() < MAX_LOGIN_SIZE ? login.size() : MAX_LOGIN_SIZE;
    strncpy(this->login, login.c_str(), size);
    this->login[size] = '\0';
}

void User::setPassword(string password) {
    string hashedPassword = sha256(password);
    strncpy(this->password, hashedPassword.c_str(), PASSWORD_SIZE);
    this->password[64] = '\0';
}

int User::getUid() const {
    return uid;
}

string User::getLogin() const {
    return login;
}

string User::getPassword() const {
    return password;
}

// ----- Match -----

Match::Match(User* firstUser, User* secondUser) {
    setFirstUser(firstUser);
    setSecondUser(secondUser);
}

Match::~Match() {
    // nothing yet
}

int Match::incrementSeq() {
    setSeq(getSeq() + 1);
    return getSeq();
}

void Match::setMid(int mid) {
    this->mid = mid;
}

void Match::setFirstUser(User* firstUser) {
    this->firstUser = firstUser;
}

void Match::setSecondUser(User* secondUser) {
    this->secondUser = secondUser;
}

void Match::setSeq(int seq) {
    this->seq = seq;
}

int Match::getMid() const {
    return mid;
}

User* Match::getFirstUser() const {
    return firstUser;
}

User* Match::getSecondUser() const {
    return secondUser;
}

int Match::getSeq() const {
    return seq;
}

// ----- Move -----

Move::Move(Match* match, User* user, const int row, const int col, const bool isVert, const string word, const int score) {
    setMatch(match);
    setSeq(match->incrementSeq());
    setUser(user);
    setRow(row);
    setCol(col);
    setIsVert(isVert);
    setWord(word);
    setScore(score);
}

Move::~Move() {
    // nothing yet
}

void Move::setMvid(int mvid) {
    this->mvid = mvid;
}

void Move::setMatch(Match* match) {
    this->match = match;
}

void Move::setSeq(int seq) {
    this->seq = seq;
}

void Move::setUser(User* user) {
    this->user = user;
}

void Move::setRow(int row) {
    this->row = row;
}

void Move::setCol(int col) {
    this->col = col;
}

void Move::setIsVert(bool isVert) {
    this->isVert = isVert;
}

void Move::setWord(string word) {
    int size = word.size() < MAX_WORD_SIZE ? word.size() : MAX_WORD_SIZE;
    strncpy(this->word, word.c_str(), size);
    this->word[size] = '\0';
}

void Move::setScore(int score) {
    this->score = score;
}

int Move::getMvid() const {
    return mvid;
}

Match* Move::getMatch() const {
    return match;
}

int Move::getSeq() const {
    return seq;
}

User* Move::getUser() const {
    return user;
}

int Move::getCol() const {
    return col;    
}

int Move::getRow() const {
    return row;    
}

bool Move::getIsVert() const {
    return isVert;    
}

string Move::getWord() const {
    return word;
}

int Move::getScore() const {
    return score;
}

// ----- Manager -----

Manager::Manager(const string HOST, const string USER, const string PASSWORD, const string DATABASE) {
    DBconnection = mysql_init(NULL);
    if(!DBconnection)
        message("MySQL initialization failed! ");
    DBconnection = mysql_real_connect(DBconnection, HOST.c_str(), USER.c_str(), PASSWORD.c_str(), DATABASE.c_str(), 0, NULL, 0);
    if(!DBconnection)
        message("Connection Error! ");
}

Manager::~Manager() {
    mysql_close(DBconnection);
}

void Manager::message(string message) {
    cout << message << endl;
}

string Manager::fetchSingleValue(string query) {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;

    if(mysql_query(DBconnection, query.c_str())) {
        message("Failed to fetch value! ");
        return "0";
    }
    res = mysql_use_result(DBconnection);
    if (res) {
        if(mysql_row = mysql_fetch_row(res)) {
            string result = mysql_row[0];
            mysql_free_result(res);
            return result;

        }
    }
    mysql_free_result(res);
    return "0";
}

// ----- UserManager -----


bool UserManager::userIsAvail(const string login) {
    MYSQL_RES* res;
    stringstream query;
    query << "SELECT uid FROM users WHERE "
        << "login = '" << login << "'";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Failed to check user! ");
        return false;
    }

    res = mysql_use_result(DBconnection);
    bool userAvail = true;
    if (res) {
        if(mysql_fetch_row(res)) {
            userAvail = false;
        }
    }
    mysql_free_result(res);
    return userAvail;
}

User* UserManager::createUser(const string login, const string password) {

    if (!userIsAvail(login)) {
        message("User already exists! ");
        return NULL;
    }

    User* user = new User(login, password);

    MYSQL_RES* res;
    stringstream query;
    query << "INSERT INTO users(login, password) VALUES ('"
        << user->getLogin() << "', '"
        << user->getPassword() << "')";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Failed to create user! ");
        return NULL;
    }

    user->setUid(mysql_insert_id(DBconnection));
    message("User creation successful. ");
    return user;
}

void UserManager::printAllUsers() {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    string query = "SELECT * FROM users";
    if(mysql_query(DBconnection, query.c_str())) {
        message("Error printing all users! ");
        return;
    }

    res = mysql_use_result(DBconnection);

    cout << setw(10) << setfill('-') << left << '+'
        << setw(20) << left << '+'
        << setw(65) << left << '+'
        << '+' << endl;

    cout << setfill(' ') << '|' << left << setw(9)
        << "uid"
        << setfill(' ') << '|' << setw(19) << "login"
        << setfill(' ') << '|' << setw(64) << "password"
        << '|' << endl;

    cout << setw(10) << setfill('-') << left << '+'
        << setw(20) << left << '+'
        << setw(65) << left << '+'
        << '+' << endl;

    if(res) {
        while((mysql_row = mysql_fetch_row(res))) {
            cout << setfill(' ') << '|' << left << setw(9) << mysql_row[0]
                << '|' << setw(19) << mysql_row[1]
                << '|' << setw(64) << mysql_row[2]
                << '|' << endl;
        }
        cout << setw(10) << setfill('-') << left << '+'
            << setw(20) << left << '+'
            << setw(65) << left << '+'
            << '+' << endl;
    }
    mysql_free_result(res);
}

void UserManager::deleteUser(User* user) {
    stringstream query;
    query << "DELETE FROM users WHERE "
        <<"login = '" << user->getLogin() << "' AND "
        <<"password = '" << user->getPassword() << "'";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Failed to delete user! ");
        return;
    }

    delete user;
    message("User delete successful. ");
    return;

}

User* UserManager::logIn(const string login, const string password) {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    stringstream query;

    User* user = new User(login, password);

    query << "SELECT uid FROM users WHERE "
        << "login = '" << user->getLogin() << "' AND "
        << "password = '" << user->getPassword() << "'";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Error logging! ");
        return NULL;
    }

    res = mysql_use_result(DBconnection);
    if(mysql_row = mysql_fetch_row(res)) {
        user->setUid(atoi(mysql_row[0]));
        mysql_free_result(res);
        return user;
    }

    mysql_free_result(res);
    return NULL;
}

int UserManager::getPlayedMatches(User* user) {
    stringstream query;
    query << "SELECT COUNT(*) FROM matches WHERE "
        << "fid = " << user->getUid() << " OR "
        << "sid = " << user->getUid() << "";
   return stoi(fetchSingleValue(query.str()));
}

int UserManager::getWonMatches(User* user) {
    stringstream query;
    query << "SELECT COUNT(*) FROM "
        << "(SELECT mid, SUM(score) as userscore FROM moves WHERE "
        << "uid = " << user->getUid() << " GROUP BY mid) as l1 "
        << "JOIN "
        << "(SELECT mid, SUM(score) as allscore FROM moves GROUP BY mid) as l2 "
        << "USING(mid) WHERE 2*l1.userscore-l2.allscore > 0";

    return stoi(fetchSingleValue(query.str()));
}

float UserManager::getWonMatchesPercentage(User* user) {
    stringstream query;
    query << "SELECT COALESCE(l3.won/l4.total, 0) FROM "
        << "(SELECT uid, COUNT(*) as won FROM "
        << "(SELECT uid, mid, SUM(score) as userscore FROM moves GROUP BY uid, mid) as l1 "
        << "JOIN "
        << "(SELECT mid, SUM(score) as allscore FROM moves GROUP BY mid) as l2 "
        << "USING(mid) WHERE 2*l1.userscore-l2.allscore > 0 GROUP BY uid) as l3 "
        << "RIGHT JOIN (SELECT l1.uid, COUNT(*) as total FROM "
        << "(SELECT uid, mid FROM moves GROUP BY uid, mid) as l1 GROUP BY l1.uid) as l4 "
        << "ON(l3.uid = l4.uid) WHERE l4.uid = " << user->getUid();

    return stof(fetchSingleValue(query.str()));
}

int UserManager::getLostMatches(User* user) {
    stringstream query;
    query << "SELECT COUNT(*) FROM "
        << "(SELECT mid, SUM(score) as userscore FROM moves WHERE "
        << "uid = " << user->getUid() << " GROUP BY mid) as l1 "
        << "JOIN "
        << "(SELECT mid, SUM(score) as allscore FROM moves GROUP BY mid) as l2 "
        << "USING(mid) WHERE 2*l1.userscore-l2.allscore < 0";

    return stoi(fetchSingleValue(query.str()));
}

float UserManager::getLostMatchesPercentage(User* user) {
    stringstream query;
    query << "SELECT COALESCE(l3.lost/l4.total, 0) FROM "
        << "(SELECT uid, COUNT(*) as lost FROM "
        << "(SELECT uid, mid, SUM(score) as userscore FROM moves GROUP BY uid, mid) as l1 "
        << "JOIN "
        << "(SELECT mid, SUM(score) as allscore FROM moves GROUP BY mid) as l2 "
        << "USING(mid) WHERE 2*l1.userscore-l2.allscore < 0 GROUP BY uid) as l3 "
        << "RIGHT JOIN (SELECT l1.uid, COUNT(*) as total FROM "
        << "(SELECT uid, mid FROM moves GROUP BY uid, mid) as l1 GROUP BY l1.uid) as l4 "
        << "ON(l3.uid = l4.uid) WHERE l4.uid = " << user->getUid();

    return stof(fetchSingleValue(query.str()));
}

int UserManager::getWonMatchesTrain(User* user) {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    stringstream query;

    query << "SELECT 2*l1.userscore-l2.allscore FROM "
        << "(SELECT mid, SUM(score) as userscore FROM moves WHERE "
        << "uid = " << user->getUid() << " GROUP BY mid) as l1 "
        << "JOIN "
        << "(SELECT mid, SUM(score) as allscore FROM moves GROUP BY mid) as l2 "
        << "USING(mid) ORDER BY l1.mid DESC";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Error fetching matches for uid=" + user->getUid());
        return 0;
    }

    res = mysql_use_result(DBconnection);
    int train = 0;
    while(mysql_row = mysql_fetch_row(res)) {
        if(atoi(mysql_row[0]) > 0) 
            train++;
        else
            break;
    }

    mysql_free_result(res);
    return train;    
}

int UserManager::getWonMatchesMax(User* user) {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    stringstream query;

    query << "SELECT 2*l1.userscore-l2.allscore FROM "
        << "(SELECT mid, SUM(score) as userscore FROM moves WHERE "
        << "uid = " << user->getUid() << " GROUP BY mid) as l1 "
        << "JOIN "
        << "(SELECT mid, SUM(score) as allscore FROM moves GROUP BY mid) as l2 "
        << "USING(mid) ORDER BY l1.mid";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Error fetching matches for uid=" + user->getUid());
        return 0;
    }

    res = mysql_use_result(DBconnection);
    int train = 0;
    int maxTrain = 0;
    while(mysql_row = mysql_fetch_row(res)) {
        if(atoi(mysql_row[0]) > 0) {
            train++;
        } else {
            train = 0;
        }
        maxTrain = train > maxTrain ? train : maxTrain;
    }

    mysql_free_result(res);
    return maxTrain;    
}

int UserManager::getWordsCount(User* user) {
    stringstream query;
    query << "SELECT COUNT(*) FROM moves "
        << "WHERE uid = " << user->getUid();

    int count = stoi(fetchSingleValue(query.str()));
    if(count == 0) {
        message("Cannot fetch words count for uid=" + user->getUid());
        return 0;
    } 
    return count;
}

float UserManager::getMeanLetterCount(User* user) {
    stringstream query;
    query << "SELECT uid, l2.sum/l3.total FROM "
        << "(SELECT l1.uid, SUM(l1.len) as sum FROM "
        << "(SELECT uid, LENGTH(word) as len FROM moves) as l1 "
        << "GROUP BY l1.uid) as l2 "
        << "JOIN "
        << "(SELECT uid, COUNT(*) as total FROM moves GROUP BY uid) as l3 "
        << "USING(uid) WHERE uid = " << user->getUid() << " GROUP BY uid";

    return stof(fetchSingleValue(query.str()));
}

float UserManager::getMeanWordScore(User* user) {
    stringstream query;
    query << "SELECT uid, l1.sum/l2.total FROM "
        << "(SELECT uid, SUM(score) as sum FROM moves GROUP BY uid) as l1 "
        << "JOIN "
        << "(SELECT uid, COUNT(*) as total FROM moves GROUP BY uid) as l2 "
        << "USING(uid) WHERE uid = " << user->getUid() << " GROUP BY uid";

   return stof(fetchSingleValue(query.str()));
}

// ----- MatchManager -----

Match* MatchManager::createMatch(User* firstUser, User* secondUser) {
    MYSQL_RES* res;
    stringstream query;
    query << "INSERT INTO matches(fid, sid) VALUES ("
        << firstUser->getUid() << ", "
        << secondUser->getUid() << ")";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Failed to create match! ");
        return NULL;
    }
    Match* match = new Match(firstUser, secondUser);
    match->setMid(mysql_insert_id(DBconnection));
    return match;
}

void MatchManager::printAllMatches() {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    string query = "SELECT * FROM matches";
    if(mysql_query(DBconnection, query.c_str())) {
        message("Error printing all matchs! ");
        return;
    }

    res = mysql_use_result(DBconnection);

    cout << setw(10) << setfill('-') << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << '+' << endl;

    cout << setfill(' ') << '|' << left << setw(9)
        << "mid"
        << '|' << setw(9) << "fid"
        << '|' << setw(9) << "sid"
        << '|' << endl;

    cout << setw(10) << setfill('-') << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << '+' << endl;


    if(res) {
        while((mysql_row = mysql_fetch_row(res))) {
            cout << setfill(' ') << '|' << left << setw(9) << mysql_row[0]
                << '|' << setw(9) << mysql_row[1]
                << '|' << setw(9) << mysql_row[2]
                << '|' << endl;
        }
        cout << setw(10) << setfill('-') << left << '+'
            << setw(10) << left << '+'
            << setw(10) << left << '+'
            << '+' << endl;
    }
    mysql_free_result(res);
}

void MatchManager::deleteMatch(Match* match) {
    stringstream query;
    query << "DELETE FROM matches WHERE mid = "
        << match->getMid();
    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Failed to delete match! ");
        return;
    }
    delete match;
    message("Match delete successful. ");
    return;
}

// ----- MoveManager -----

Move* MoveManager::createMove(Match* match, User* user, const int row, const int col, const bool isVert, const string word, const int score) {
    MYSQL_RES* res;
    stringstream query;

    Move* move = new Move(match, user, row, col, isVert, word, score);

    query << "INSERT INTO moves(mid, uid, r0w, col, is_vert, word, score) VALUES ("
        << move->getMatch()->getMid() << ", "
        << move->getUser()->getUid() << ", "
        << move->getRow() << ", "
        << move->getCol() << ", "
        << move->getIsVert() << ", '"
        << move->getWord() << "', "
        << move->getScore() << ")";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Failed to create move! ");
        return NULL;
    }
    move->setMvid(mysql_insert_id(DBconnection));
    message("Move creation successful. ");
    return move;
}

void MoveManager::printAllMoves() {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    string query = "SELECT * FROM moves";
    if(mysql_query(DBconnection, query.c_str())) {
        message("Error printing all moves! ");
        return;
    }

    res = mysql_use_result(DBconnection);

    cout << setw(10) << setfill('-') << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(14) << left << '+'
        << setw(10) << left << '+'
        << '+' << endl;

    cout << setfill(' ') << '|' << left << setw(9)
        << "mvid"
        << '|' << setw(9) << "mid"
        << '|' << setw(9) << "seq"
        << '|' << setw(9) << "uid"
        << '|' << setw(9) << "r0w"
        << '|' << setw(9) << "col"
        << '|' << setw(9) << "is_vert"
        << '|' << setw(13) << "word"
        << '|' << setw(9) << "score"
        << '|' << endl;

    cout << setw(10) << setfill('-') << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(10) << left << '+'
        << setw(14) << left << '+'
        << setw(10) << left << '+'
        << '+' << endl;

    if(res) {
        while((mysql_row = mysql_fetch_row(res))) {
            cout << setfill(' ') << '|' << left << setw(9) << mysql_row[0]
                << '|' << setw(9) << mysql_row[1]
                << '|' << setw(9) << mysql_row[2]
                << '|' << setw(9) << mysql_row[3]
                << '|' << setw(9) << mysql_row[4]
                << '|' << setw(9) << mysql_row[5]
                << '|' << setw(9) << mysql_row[6]
                << '|' << setw(13) << mysql_row[7]
                << '|' << setw(9) << mysql_row[8]
                << '|' << endl;
        }
        cout << setw(10) << setfill('-') << left << '+'
            << setw(10) << left << '+'
            << setw(10) << left << '+'
            << setw(10) << left << '+'
            << setw(10) << left << '+'
            << setw(10) << left << '+'
            << setw(10) << left << '+'
            << setw(14) << left << '+'
            << setw(10) << left << '+'
            << '+' << endl;
    }
    mysql_free_result(res);
}

void MoveManager::deleteMove(Move* move) {
    stringstream query;
    query << "DELETE FROM moves WHERE mvid = "
        << move->getMvid();
    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Failed to delete move! ");
        return;
    }
    delete move;
    message("Move delete successful. ");
    return;
}
