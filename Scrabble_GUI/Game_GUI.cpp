#include "Game_GUI.h"
#include "ui_Game_GUI.h"
#include <random>
#include <string>

Game_GUI::Game_GUI(QWidget *parent)
	: QDialog(parent)
{
	gameMap gameMap1;
	if (gameMap1.getNumberOfPlayers() >= 1 ) {
		mufasa.randomCards(gameMap1.cybant);
		mufasa.setNick("mufasa");
	}
	if (gameMap1.getNumberOfPlayers() >= 2) {
		esteban.randomCards(gameMap1.cybant);
		esteban.setNick("esteban");
	}
	if (gameMap1.getNumberOfPlayers() >= 3) {
		zeromski.randomCards(gameMap1.cybant);
		zeromski.setNick("zeromski");
	}
	if (gameMap1.getNumberOfPlayers() == 4) {
		rokoko.randomCards(gameMap1.cybant);
		rokoko.setNick("rokoko");
	}
	ui.setupUi(this);
	// mufasa to zawsze domyslny player 1 czy z kompem czy nie i zawsze robi 1 ruch i zawsze jeg literki
	changeCurrentPlayer();
	playerLetterRefresh(mufasa);
}

Game_GUI::~Game_GUI()
{
}

void Game_GUI::on_pushButton_add_clicked()
{
	//zmiana na odpowedniego playera w zaleznosci od ilosci
	//bool computerMove = 
	if (gameMap1.getNumberOfPlayers() == 1) {
		playerMove(mufasa);
		gameMap1.computerAction();
	}
	else if (gameMap1.getNumberOfPlayers() == 2) {
		if (mufasa.getCurrentlyPlay() == true) {
			playerLetterRefresh(mufasa);
			playerMove(mufasa);
			mufasa.setCurrentlyPlay(false);
			esteban.setCurrentlyPlay(true);
			playerLetterRefresh(esteban);
		}else if (esteban.getCurrentlyPlay() == true) {
			playerLetterRefresh(esteban);
			playerMove(esteban);
			esteban.setCurrentlyPlay(false);
			mufasa.setCurrentlyPlay(true);
			playerLetterRefresh(mufasa);
		}
	}
	/*if (!computerMove) {
		gameMap1.board[0][0].setLetter('%');
	}*/
	refreshGameMap();
}

void Game_GUI::on_pushButton_change_clicked() {
	if (gameMap1.getNumberOfPlayers() == 1) {
		mufasa.changeEveryPlayerCard(gameMap1.cybant, gameMap1.getFirstMove());
		playerLetterRefresh(mufasa);
	}
	/*std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(65, 90);
	auto playerLetter = ui.tableWidget_letters->model();
	for (int i{ 0 }; i < 10; ++i)
	{
			QString tmp = char(distrib(rd));
			playerLetter->setData(playerLetter->index(0, i), tmp);
	}*/
}

void Game_GUI::on_pushButton_pass_clicked() {
	gameMap1.computerAction();
	refreshGameMap();
	//zmiana playera i zmian jego dymow
	
}

void Game_GUI::playerLetterRefresh(player player) {
	auto model = ui.tableWidget_letters->model();
	for (int i{ 0 }; i < 10; ++i) { // wpisuje w tabelke zawsze literki mufasy bo on jest graczem rozpoczynajcym rozgryke 
		QString tmp = char(player.getPlayerCardsName(i));
		model->setData(model->index(0, i), tmp);
	}
}

void Game_GUI::playerMove(player player) {
	auto model = ui.tableWidget_game->model();
	std::string word = ui.lineEdit_word->text().toStdString();
	bool check_word = true;
	if (word == "") {
		check_word = false;
	}
	if (check_word) { //trzeba dodac jakies rzeczy gdy slowo nie znajduje sie w slowniku dic
		int x = ui.comboBox_column->currentText().toInt();
		int y = ui.comboBox_row->currentText().toInt();
		int cnt = 0;
		int s = 0;
		for (auto lett : word) { //sprawdzenie czy na odpowiednich pozycjach jest to samo i czy litery istnieja odpowiednio
			if (ui.radioButton_horizontal->isChecked()) {
				if (this->gameMap1.board[y][x + cnt].isOccupied()) {
					if (this->gameMap1.board[y][x + cnt].getLetter() != lett) {
						check_word = false;
					}
				}
				else {
					check_word = false;
					for (int i{ 0 }; i < 10; ++i) {
						if (lett == char(player.getPlayerCardsName(i))) {
							this->gameMap1.board[y][x + cnt].setSession(1);
							this->gameMap1.board[y][x + cnt].setLetter(lett);
							check_word = true;
							break;
						}
					}
				}
				if (check_word == false)
					break;
			}
			else
			{
				if (this->gameMap1.board[y + cnt][x].isOccupied()) {
					if (this->gameMap1.board[y + cnt][x].getLetter() != lett) {
						check_word = false;
					}
				}
				else {
					check_word = false;
					for (int i{ 0 }; i < 10; ++i) {
						if (lett == char(player.getPlayerCardsName(i))) {
							this->gameMap1.board[y + cnt][x].setSession(1);
							this->gameMap1.board[y + cnt][x].setLetter(lett);
							check_word = true;
							break;
						}
					}
				}
				if (check_word == false)
					break;
			}
			++cnt;
		}
		if (check_word == true) {
			check_word = this->gameMap1.correctMove();
			if (check_word == true) {
				int x = ui.comboBox_column->currentText().toInt();
				int y = ui.comboBox_row->currentText().toInt();
				int cnt = 0;
				for (auto lett : word) {
					if (ui.radioButton_horizontal->isChecked()) {
						model->setData(model->index(y, x + cnt), QString(lett));
						this->gameMap1.board[y][x + cnt].setSession(2);
						this->gameMap1.board[y][x + cnt].setLetter(lett);
					}
					else {
						model->setData(model->index(y + cnt, x), QString(lett));
						this->gameMap1.board[y + cnt][x].setSession(2);
						this->gameMap1.board[y + cnt][x].setLetter(lett);
					}
					++cnt;
				}
				player.changeUsedCards(word, gameMap1.cybant);
				gameMap1.setFirstMove(false);
			}
			ui.lineEdit_word->setText(""); //zmiana tabelki
			playerLetterRefresh(player);
		}
		if (!check_word) {
			gameMap1.incorrextMoveOfPlayer();
			ui.lineEdit_word->setText(""); //zmiana tabelki
		}
	}

}

void Game_GUI::changeCurrentPlayer() {
	cout << "";
	mufasa.setCurrentlyPlay(true);
	cout << "";
};

void Game_GUI::refreshGameMap() {
	mufasa.setPossibilityToChangeCards(true);
	auto model = ui.tableWidget_game->model();
	for (int i = 0; i < 15; i++) { // refresh tablicy
		for (int j = 0; j < 15; j++) {
			if (gameMap1.board[i][j].getSession() == 1 || gameMap1.board[i][j].getSession() == 2)
				model->setData(model->index(i, j), QString(gameMap1.board[i][j].getLetter()));
		}
	}
}