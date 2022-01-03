#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <mysql.h>
#include "accounts.h"
#include "sha256.h"

using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::vector;
using std::stringstream;

// ----- User -----

User::User(const string login, const string password) {
    setLogin(login);
    setPassword(password);
}

User::User(const string login, const int uid) {
    setLogin(login);
    setPassword("");
    setUid(uid);
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
    return this->uid;
}

string User::getLogin() const {
    return this->login;
}

string User::getPassword() const {
    return this->password;
}

// ----- Match -----

Match::Match(const int mid) {
    setMid(mid);
}

Match::~Match() {
    // nothing yet
}

int Match::incrementSeq() {
    setSeq(getSeq() + 1);
    return getSeq();
}

void Match::appendOpponent(string login) {
    this->opponents->push_back(login);
}

void Match::setMid(int mid) {
    this->mid = mid;
}

void Match::setSeq(int seq) {
    this->seq = seq;
}

void Match::setWinner(string winner) {
    this->winner = winner;
}

int Match::getMid() const {
    return this->mid;
}

int Match::getSeq() const {
    return this->seq;
}

string Match::getWinner() const {
    return this->winner;
}

vector<string>* Match::getOpponents() const {
    return this->opponents;
}

// ----- Move -----

Move::Move(Match* match, const int seq, User* user, const int row, const int col, const bool isVert, const string word, const int score, const int mvid) {
    setMatch(match);
    setSeq(seq);
    setUser(user);
    setRow(row);
    setCol(col);
    setIsVert(isVert);
    setWord(word);
    setScore(score);
    setMvid(mvid);
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
    return this->mvid;
}

Match* Move::getMatch() const {
    return this->match;
}

int Move::getSeq() const {
    return this->seq;
}

User* Move::getUser() const {
    return this->user;
}

int Move::getCol() const {
    return this->col;    
}

int Move::getRow() const {
    return this->row;    
}

bool Move::getIsVert() const {
    return this->isVert;    
}

string Move::getWord() const {
    return this->word;
}

int Move::getScore() const {
    return this->score;
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
    query << "SELECT COUNT(DISTINCT(mid)) FROM moves WHERE "
        << "uid = " << user->getUid();
    return stoi(fetchSingleValue(query.str()));
}

int UserManager::getWonMatches(User* user) {
    stringstream query;
    query << "SELECT COALESCE(COUNT(l1.mid), 0) AS cnt FROM users LEFT JOIN (SELECT DISTINCT m.mid, (SELECT uid FROM moves JOIN users USING(uid) WHERE mid=m.mid GROUP BY uid ORDER BY SUM(score) DESC LIMIT 1) AS uid FROM moves m JOIN users USING(uid)) AS l1 USING(uid) "
        << "WHERE uid = " << user->getUid()
        << " GROUP BY uid";

    return stoi(fetchSingleValue(query.str()));
}

float UserManager::getWonMatchesPercentage(User* user) {
    stringstream query;
    query << "SELECT COALESCE(l2.cnt/l3.cnt, 0) FROM (SELECT uid, COUNT(*) AS cnt FROM users JOIN (SELECT DISTINCT m.mid, (SELECT uid FROM moves JOIN users USING(uid) WHERE mid = m.mid GROUP BY uid ORDER BY SUM(score) DESC LIMIT 1) AS uid FROM moves m JOIN users USING(uid)) AS l1 USING(uid) GROUP BY uid) AS l2 RIGHT JOIN (SELECT COUNT(DISTINCT mid) AS cnt, uid FROM moves GROUP BY uid) AS l3 USING(uid) RIGHT JOIN users u USING(uid) "
        << "WHERE u.uid = " << user->getUid();

    return stof(fetchSingleValue(query.str()));
}

int UserManager::getLostMatches(User* user) {
    stringstream query;
    query << "SELECT COALESCE(COUNT(l1.mid), 0) AS cnt FROM users LEFT JOIN (SELECT DISTINCT m.mid, (SELECT uid FROM moves JOIN users USING(uid) WHERE mid = m.mid GROUP BY uid ORDER BY SUM(score) LIMIT 1) AS uid FROM moves m JOIN users USING(uid)) AS l1 USING(uid) "
        << "WHERE uid = " << user->getUid()
        << " GROUP BY uid";

    return stoi(fetchSingleValue(query.str()));
}

float UserManager::getLostMatchesPercentage(User* user) {
    stringstream query;
    query << "SELECT COALESCE(l2.cnt/l3.cnt, 0) FROM (SELECT uid, COUNT(*) AS cnt FROM users JOIN (SELECT DISTINCT m.mid, (SELECT uid FROM moves JOIN users USING(uid) WHERE mid = m.mid GROUP BY uid ORDER BY SUM(score) LIMIT 1) AS uid FROM moves m JOIN users USING(uid)) AS l1 USING(uid) GROUP BY uid) AS l2 RIGHT JOIN (SELECT COUNT(DISTINCT mid) AS cnt, uid FROM moves GROUP BY uid) AS l3 USING(uid) RIGHT JOIN users u USING(uid) "
        << "WHERE u.uid = " << user->getUid();

    return stof(fetchSingleValue(query.str()));
}

int UserManager::getWonMatchesTrain(User* user) {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    stringstream query;

    query << "SELECT DISTINCT m.mid, (SELECT SUM(score) FROM moves WHERE mid = m.mid AND uid = m.uid)-(SELECT MAX(score) FROM moves WHERE mid = m.mid) AS diff FROM moves m "
        << "WHERE uid = " << user->getUid();

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Error fetching matches for uid=" + user->getUid());
        return 0;
    }

    res = mysql_use_result(DBconnection);
    int train = 0;
    while(mysql_row = mysql_fetch_row(res)) {
        if(atoi(mysql_row[1]) > 0) 
            ++train;
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

    query << "SELECT DISTINCT m.mid, (SELECT SUM(score) FROM moves WHERE mid = m.mid AND uid = m.uid)-(SELECT MAX(score) FROM moves WHERE mid = m.mid) AS diff FROM moves m "
        << "WHERE uid = " << user->getUid();

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Error fetching matches for uid=" + user->getUid());
        return 0;
    }

    res = mysql_use_result(DBconnection);
    int train = 0;
    int maxTrain = 0;
    while(mysql_row = mysql_fetch_row(res)) {
        if(atoi(mysql_row[1]) > 0) {
            ++train;
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
    return count;
}

float UserManager::getMeanLetterCount(User* user) {
    stringstream query;
    query << "SELECT COALESCE(l2.sum/l3.total, 0) FROM "
        << "(SELECT l1.uid, SUM(l1.len) AS sum FROM "
        << "(SELECT uid, LENGTH(word) AS len FROM moves) AS l1 "
        << "GROUP BY l1.uid) AS l2 "
        << "JOIN "
        << "(SELECT uid, COUNT(*) AS total FROM moves GROUP BY uid) AS l3 "
        << "USING(uid) WHERE uid = " << user->getUid() << " GROUP BY uid";

    return stof(fetchSingleValue(query.str()));
}

float UserManager::getMeanWordScore(User* user) {
    stringstream query;
    query << "SELECT COALESCE(l1.sum/l2.total, 0) FROM "
        << "(SELECT uid, SUM(score) AS sum FROM moves GROUP BY uid) AS l1 "
        << "JOIN "
        << "(SELECT uid, COUNT(*) AS total FROM moves GROUP BY uid) AS l2 "
        << "USING(uid) WHERE uid = " << user->getUid() << " GROUP BY uid";

   return stof(fetchSingleValue(query.str()));
}

vector<string>* UserManager::getRemainingLogins(User* user) {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    stringstream query;

    query << "SELECT login FROM users "
        << "WHERE login <> '" << user->getLogin() << "' AND login <> 'easy' AND login <> 'medium' AND login <> 'hard'";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Error fetching remaining logins list for uid=" + user->getUid());
        return NULL;
    }

    vector<string>* loginsList = new vector<string>;
    res = mysql_use_result(DBconnection);
    while(mysql_row = mysql_fetch_row(res)) {
        loginsList->push_back(mysql_row[0]);
    }

    mysql_free_result(res);
    return loginsList;
}

vector<Match*>* UserManager::getAllMatchesList(User* user) {
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    stringstream query;

    query << "SELECT DISTINCT (SELECT login FROM users WHERE uid = m.uid) AS opp, m.mid, (select login from moves join users using(uid) where mid=m.mid group by uid order by sum(score) desc limit 1) as winner"
        << "FROM "
        << "moves m JOIN (SELECT mid, uid FROM moves) AS l1 USING(mid) JOIN "
        << "users u ON(l1.uid = u.uid AND m.uid <> u.uid) "
        << "WHERE u.uid = " << user->getUid() << " ORDER BY m.mid";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Error fetching matches list for uid=" + user->getUid());
        return NULL;
    }

    vector<Match*>* matchesList = new vector<Match*>;
    res = mysql_use_result(DBconnection);
    int lastMid = 0;
    int currMid = -1;
    Match* currMatch = NULL;
    while(mysql_row = mysql_fetch_row(res)) {
        currMid = atoi(mysql_row[1]);
        if (currMid != lastMid) {
            currMatch = new Match(currMid);
            currMatch->setWinner(mysql_row[2]);
            matchesList->push_back(currMatch);
        }
        currMatch->appendOpponent(mysql_row[0]);
        lastMid = currMid;
    }

    mysql_free_result(res);
    return matchesList;
}

// ----- MatchManager -----

Match* MatchManager::createMatch() {
    MYSQL_RES* res;
    stringstream query;
    query << "INSERT INTO matches() VALUES ()";

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Failed to create match! ");
        return NULL;
    }
    Match* match = new Match();
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
        << '+' << endl;

    cout << setfill(' ') << '|' << left << setw(9)
        << "mid"
        << '|' << endl;

    cout << setw(10) << setfill('-') << left << '+'
        << '+' << endl;

    if(res) {
        while(mysql_row = mysql_fetch_row(res)) {
            cout << setfill(' ') << '|' << left << setw(9) << mysql_row[0]
                << '|' << endl;
        }
        cout << setw(10) << setfill('-') << left << '+'
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

vector<Move*>* MatchManager::getAllMovesList(Match* match) {
    // returns first user's moves
    MYSQL_RES* res;
    MYSQL_ROW mysql_row;
    stringstream query;

    query << "SELECT mvid, mid, seq, uid, login, r0w, col, is_vert, word, score FROM moves JOIN users USING(uid) "
    << "WHERE mid = " << match->getMid();

    if(mysql_query(DBconnection, query.str().c_str())) {
        message("Error fetching moves list for mid=" + match->getMid());
        return NULL;
    }

    vector<Move*>* movesList = new vector<Move*>;
    res = mysql_use_result(DBconnection);
    while(mysql_row = mysql_fetch_row(res)) {
        User* user = new User(mysql_row[4], atoi(mysql_row[3]));
        Move* move = new Move(match, atoi(mysql_row[2]), user, atoi(mysql_row[5]), atoi(mysql_row[6]), atoi(mysql_row[7]), mysql_row[8], atoi(mysql_row[9]), atoi(mysql_row[0]));
        movesList->push_back(move);
    }

    mysql_free_result(res);
    return movesList;
}

int MatchManager::getScoreInMatch(User* user, Match* match) {
    stringstream query;
    query << "SELECT SUM(score) FROM moves WHERE "
    << "uid = " << user->getUid() << " AND mid = " << match->getMid() << " GROUP BY uid";

    return stoi(fetchSingleValue(query.str()));
}

// ----- MoveManager -----

Move* MoveManager::createMove(Match* match, User* user, const int row, const int col, const bool isVert, const string word, const int score) {
    MYSQL_RES* res;
    stringstream query;

    Move* move = new Move(match, match->incrementSeq(), user, row, col, isVert, word, score);

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
        while(mysql_row = mysql_fetch_row(res)) {
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
