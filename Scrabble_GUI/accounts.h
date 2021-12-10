#include <string>
//#include <mysql/mysql.h>
using std::string;

class User {
public:
    static const int MAX_LOGIN_SIZE = 20;
    static const int PASSWORD_SIZE = 65;

    User(const string = "", const string = "");
    ~User();

    // ----- SETTERS -----
    void setUid(int);
    void setLogin(string);
    void setPassword(string);

    // ----- GETTERS -----
    int getUid() const;
    string getLogin() const;
    string getPassword() const;

private:
    int uid = 0;
    char login[MAX_LOGIN_SIZE + 1];
    char password[PASSWORD_SIZE + 1];
};

class Match {
public:
    Match(User*, User*);
    ~Match();
    int incrementSeq();

    // ----- SETTERS -----
    void setMid(int);
    void setFirstUser(User*);
    void setSecondUser(User*);
    void setSeq(int);

    // ----- GETTERS -----
    int getMid() const;
    User* getFirstUser() const;
    User* getSecondUser() const;
    int getSeq() const;

private:
    int mid = 0;
    User* firstUser;
    User* secondUser;

    int seq = 0;
};

class Move {
public:
    static const int MAX_WORD_SIZE = 10;
    Move(Match*, User*, const string, const int);
    ~Move();

    // ----- SETTERS -----
    void setMvid(int);
    void setMatch(Match*);
    void setSeq(int);
    void setUser(User*);
    void setWord(string);
    void setScore(int);

    // ----- GETTERS -----
    int getMvid() const;
    Match* getMatch() const;
    int getSeq() const;
    User* getUser() const;
    string getWord() const;
    int getScore() const;

private:
    int mvid = 0;
    Match* match;
    int seq;
    User* user;
    char word[MAX_WORD_SIZE + 1];
    int score;
};

class Manager { 
public:
    Manager(const string, const string, const string, const string);
    ~Manager();
    void message(string);
    string fetchSingleValue(string);

protected:
    MYSQL* DBconnection;
};

class UserManager: public Manager {
public:
    UserManager(const string s1, const string s2, const string s3, const string s4): Manager(s1, s2, s3, s4) {};

    bool userIsAvail(const string);
    User* createUser(const string, const string);
    void printAllUsers();
    void deleteUser(User*);
    User* logIn(const string, const string);

    int getPlayedMatches(User*);
    int getWonMatches(User*);
    float getWonMatchesPercentage(User*);
    int getLostMatches(User*);
    float getLostMatchesPercentage(User*);
    int getWonMatchesTrain(User*);
    int getWonMatchesMax(User*);
    int getWordsCount(User*);
    float getMeanLetterCount(User*);
    float getMeanWordScore(User*);
};

class MatchManager: public Manager {
public:
    MatchManager(const string s1, const string s2, const string s3, const string s4): Manager(s1, s2, s3, s4) {};

    Match* createMatch(User*, User*);
    void printAllMatches();
    void deleteMatch(Match*);
};

class MoveManager: public Manager {
public:
    MoveManager(const string s1, const string s2, const string s3, const string s4): Manager(s1, s2, s3, s4) {};

    Move* createMove(Match*, User*, const string, const int);
    void printAllMoves();
    void deleteMove(Move*);
};
