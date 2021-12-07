#include "Game_GUI.h"
#include "ui_Game_GUI.h"
#include <random>
#include <string>

Game_GUI::Game_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(65, 90);
	auto model = ui.tableWidget_letters->model();
	gameMap gameMap1;
	for (int i{ 0 }; i < 10; ++i)
	{
		QString tmp = char(gameMap1.mufasa.playerCards[i].name);
		//QString tmp = char(distrib(rd));
		model->setData(model->index(0, i), tmp);
	}
}

Game_GUI::~Game_GUI()
{
}

void Game_GUI::on_pushButton_add_clicked()
{
	auto model = ui.tableWidget_game->model();
	auto model_letters = ui.tableWidget_letters->model();
	std::string word = ui.lineEdit_word->text().toStdString();

	bool check_word = true;
	std::string letters{ "" };

	for (int i{ 0 }; i < 10; ++i)
	{
		letters.append(ui.tableWidget_letters->item(0, i)->text().toStdString());
	}

	for (auto lett: word)
	{
		int position = letters.find_first_of(lett);
		if (position != -1)
			letters.erase(position, 1);
		else
		{
			ui.lineEdit_word->setText("niepoprawne litery");
			check_word = false;
		}
	}

	if (check_word)
	{
		int x = ui.comboBox_column->currentText().toInt();
		int y = ui.comboBox_row->currentText().toInt();
		int cnt = 0;
		for (auto lett : word)
		{
			if (ui.radioButton_horizontal->isChecked())
			{
				if (!this->gameMap1.board[y][x + cnt].isOccupied()) {
					if (this->gameMap1.board[y][x + cnt].getLetter() != lett) {
						check_word = false;
						break;
					}
				}
				else {
					this->gameMap1.board[y][x + cnt].setSession(1);
					this->gameMap1.board[y][x + cnt].setLetter(lett);
				}

			}
			else
			{
				if (!this->gameMap1.board[y + cnt][x].isOccupied()) {
					if (this->gameMap1.board[y + cnt][x].getLetter() != lett) {
						check_word = false;
						break;
					}
				}
				else {
					this->gameMap1.board[y + cnt][x].setSession(1);
					this->gameMap1.board[y + cnt][x].setLetter(lett);
				}
			}
			++cnt;
		}
	}

	if (check_word) {
		check_word = this->gameMap1.correctMove();
	}

	if (check_word)
	{
		int x = ui.comboBox_column->currentText().toInt();
		int y = ui.comboBox_row->currentText().toInt();
		int cnt = 0;
		for (auto lett : word)
		{
			if (ui.radioButton_horizontal->isChecked())
			{
				model->setData(model->index(y, x + cnt), QString(lett));
				this->gameMap1.board[y][x + cnt].setSession(2);
			}
			else
			{
				model->setData(model->index(y + cnt, x), QString(lett));
				this->gameMap1.board[y + cnt][x].setSession(2);
			}
			++cnt;
		}
		gameMap1.mufasa.changeUsedCards(word,gameMap1.cybant);
	}

	for (int i{ 0 }; i < 10; ++i)
	{
		QString tmp = char(gameMap1.mufasa.playerCards[i].name);
		model_letters->setData(model->index(0, i), tmp);
	}

	if (!gameMap1.computerAction()) { 
		model->setData(model->index(0, 0), QString('&'));
	}


	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (gameMap1.board[i][j].getSession() == 1 || gameMap1.board[i][j].getSession() == 2)
				model->setData(model->index(i, j), QString(gameMap1.board[i][j].getLetter()));
		}
	}
}


void Game_GUI::refreshGameMap(){
	auto model = ui.tableWidget_game->model();
	auto model_letters = ui.tableWidget_letters->model();
	for (int i = 0; i < 15; i++){
		for (int j = 0; i < 15; j++) {
			if (gameMap1.board[i][j].getSession() == 1 && gameMap1.board[i][j].getSession() == 2)
				model->setData(model->index(j, i), QString(gameMap1.board[i][j].getLetter()));
		}
	}
}

void Game_GUI::on_pushButton_change_clicked()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(65, 90);
	auto model = ui.tableWidget_letters->model();
	for (int i{ 0 }; i < 10; ++i)
	{
			QString tmp = char(distrib(rd));
			model->setData(model->index(0, i), tmp);
	}
}
