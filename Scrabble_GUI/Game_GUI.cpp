#include "Game_GUI.h"
#include "ui_Game_GUI.h"
#include <random>
#include <string>

Game_GUI::Game_GUI(QWidget *parent)
	: QDialog(parent)
{
	gameMap gameMap1;
	//player mufasa;
	mufasa.randomCards(gameMap1.cybant);
	ui.setupUi(this);
	//card buffor[10];
	std::random_device rd;
	std::mt19937 gen(rd());
	//std::uniform_int_distribution<> distrib(65, 90);
	auto model = ui.tableWidget_letters->model();
	for (int i{ 0 }; i < 10; ++i){
		QString tmp = char(mufasa.playerCards[i].name);
		//QString tmp = char(distrib(rd));
		model->setData(model->index(0, i), tmp);
	}
	cout << " " << endl;
}

Game_GUI::~Game_GUI()
{
}

void Game_GUI::on_pushButton_add_clicked()
{
	playerMove(mufasa);
	//bool computerMove = 
	gameMap1.computerAction();
	/*if (!computerMove) {
		gameMap1.board[0][0].setLetter('%');
	}*/
	refreshGameMap();
}

void Game_GUI::on_pushButton_change_clicked() {
	mufasa.changeEveryPlayerCard(gameMap1.cybant);
	auto model = ui.tableWidget_letters->model();
	for (int i{ 0 }; i < 10; ++i) {
		QString tmp = char(mufasa.playerCards[i].name);
		//QString tmp = char(distrib(rd));
		model->setData(model->index(0, i), tmp);
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
}

void Game_GUI::playerMove(player player) {
	cout << " " << endl;
	auto model = ui.tableWidget_game->model();
	auto model_letters = ui.tableWidget_letters->model();
	auto playerLetter = ui.tableWidget_letters->model();
	std::string word = ui.lineEdit_word->text().toStdString();
	bool check_word = true;
	if (word == "") {
		check_word = false;
	}
	if (check_word) { //trzeba dodac jakies rzeczy gdy slowo nie znajduje sie w slowniku dic
		int x = ui.comboBox_column->currentText().toInt();
		int y = ui.comboBox_row->currentText().toInt();
		int cnt = 0;
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
						if (lett == char(player.playerCards[i].name)) {
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
						if (lett == char(player.playerCards[i].name)) {
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
			//ofstream XXX("C:\\Users\\48508\\Desktop\\cosiedzieje.txt");
			//XXX << check_word << endl;
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
						this->gameMap1.board[y][x + cnt].setLetter(lett);
					}
					++cnt;
				}
				player.changeUsedCards(word, gameMap1.cybant);
				gameMap1.setFirstMove(false);
			}
			ui.lineEdit_word->setText(""); //zmiana tabelki
			for (int i{ 0 }; i < 10; ++i) {
				QString tmp = char(player.playerCards[i].name);
				playerLetter->setData(playerLetter->index(0, i), tmp);
			}
		}
		if (!check_word) {
			gameMap1.incorrextMoveOfPlayer();
			ui.lineEdit_word->setText(""); //zmiana tabelki
		}
	}

}

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