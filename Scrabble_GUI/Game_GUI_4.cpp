#include "Game_GUI_4.h"

Game_GUI_4::Game_GUI_4(QWidget *parent)
	: QDialog(parent)
{	
	gameMap gameMap1;
	mufasa.setNick("mufasa");
	esteban.setNick("esteban");
	zeromski.setNick("zeromski");
	rokoko.setNick("rokoko");
	srand(time(NULL));
	mufasa.randomCards(gameMap1.cybant);
	esteban.randomCards(gameMap1.cybant);
	zeromski.randomCards(gameMap1.cybant);
	rokoko.randomCards(gameMap1.cybant);
	ui.setupUi(this);
	mufasa.setCurrentlyPlay(true);
	playerLetterRefresh('m');
	playerLetterRefresh('e');
	playerLetterRefresh('z');
	playerLetterRefresh('r');
	refreshGameMap();
	privacyBoard('e');
	privacyBoard('z');
	privacyBoard('r');

	ui.estebanHorizontal->setCheckable(false);
	ui.estebanVertical->setCheckable(false);
	ui.zeromskiHorizontal->setCheckable(false);
	ui.zeromskiVertical->setCheckable(false);
	ui.rokokoHorizontal->setCheckable(false);
	ui.rokokoVertical->setCheckable(false);
	ui.mufasaHorizontal->setCheckable(true);
	ui.mufasaVertical->setCheckable(true);
	ui.mufasaHorizontal->setChecked(true);
}

Game_GUI_4::Game_GUI_4(User* user, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
	ui.mufasaLabel->setText(QString::fromStdString(this->user->getLogin()));
	gameMap gameMap1;
	mufasa.setNick("mufasa");
	esteban.setNick("esteban");
	zeromski.setNick("zeromski");
	rokoko.setNick("rokoko");
	srand(time(NULL));
	mufasa.randomCards(gameMap1.cybant);
	esteban.randomCards(gameMap1.cybant);
	zeromski.randomCards(gameMap1.cybant);
	rokoko.randomCards(gameMap1.cybant);
	mufasa.setCurrentlyPlay(true);
	playerLetterRefresh('m');
	playerLetterRefresh('e');
	playerLetterRefresh('z');
	playerLetterRefresh('r');
	refreshGameMap();
	privacyBoard('e');
	privacyBoard('z');
	privacyBoard('r');

	ui.estebanHorizontal->setCheckable(false);
	ui.estebanVertical->setCheckable(false);
	ui.zeromskiHorizontal->setCheckable(false);
	ui.zeromskiVertical->setCheckable(false);
	ui.rokokoHorizontal->setCheckable(false);
	ui.rokokoVertical->setCheckable(false);
	ui.mufasaHorizontal->setCheckable(true);
	ui.mufasaVertical->setCheckable(true);
	ui.mufasaHorizontal->setChecked(true);

	ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
	ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
	ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
	ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");

}


Game_GUI_4::~Game_GUI_4()
{
}

void Game_GUI_4::on_mufasaAdd_clicked()
{
	if (mufasa.getCurrentlyPlay() == true && (ui.mufasaHorizontal->isChecked() || ui.mufasaVertical->isChecked())) {
		playerMove(mufasa, 'm');
		mufasa.setCurrentlyPlay(false);
		esteban.setCurrentlyPlay(true);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('e');
		playerLetterRefresh('z');
		playerLetterRefresh('m');
		playerLetterRefresh('r');
		privacyBoard('m');
		privacyBoard('z');
		privacyBoard('r');
		ui.mufasaHorizontal->setChecked(false);
		ui.mufasaVertical->setChecked(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.zeromskiVertical->setChecked(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.rokokoVertical->setChecked(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.estebanHorizontal->setCheckable(true);
		ui.estebanVertical->setCheckable(true);
		ui.estebanHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_estebanAdd_clicked()
{
	if (esteban.getCurrentlyPlay() == true && (ui.estebanHorizontal->isChecked() || ui.estebanVertical->isChecked() )) {
		playerMove(esteban, 'e');
		zeromski.setCurrentlyPlay(true);
		esteban.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white;}");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('m');
		privacyBoard('e');
		privacyBoard('r');
		ui.estebanHorizontal->setChecked(false);
		ui.estebanVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.rokokoVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(true);
		ui.zeromskiVertical->setCheckable(true);
		ui.zeromskiHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_zeromskiAdd_clicked() {
	if (zeromski.getCurrentlyPlay() == true && (ui.zeromskiHorizontal->isChecked() || ui.zeromskiVertical->isChecked())) {
		playerMove(zeromski, 'z');
		rokoko.setCurrentlyPlay(true);
		zeromski.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white;  }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan;  }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('z');
		privacyBoard('e');
		privacyBoard('m');
		ui.zeromskiHorizontal->setChecked(false);
		ui.zeromskiVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.zeromskiVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(true);
		ui.rokokoVertical->setCheckable(true);
		ui.rokokoHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_rokokoAdd_clicked() {
	if (rokoko.getCurrentlyPlay() == true && (ui.rokokoHorizontal->isChecked() || ui.rokokoVertical->isChecked())) {
		playerMove(rokoko, 'r');
		mufasa.setCurrentlyPlay(true);
		rokoko.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('z');
		privacyBoard('e');
		privacyBoard('r');
		ui.zeromskiHorizontal->setChecked(false);
		ui.zeromskiVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.zeromskiVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.rokokoVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(true);
		ui.mufasaVertical->setCheckable(true);
		ui.mufasaHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_mufasaChange_clicked() {
	if (mufasa.getCurrentlyPlay() == true) {
		gatherLetterToChange_1(mufasa, 'm');
		mufasa.setCurrentlyPlay(false);
		esteban.setCurrentlyPlay(true);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('e');
		playerLetterRefresh('z');
		playerLetterRefresh('m');
		playerLetterRefresh('r');
		privacyBoard('m');
		privacyBoard('z');
		privacyBoard('r');
		ui.mufasaHorizontal->setChecked(false);
		ui.mufasaVertical->setChecked(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.zeromskiVertical->setChecked(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.rokokoVertical->setChecked(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.estebanHorizontal->setCheckable(true);
		ui.estebanVertical->setCheckable(true);
		ui.estebanHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_estebanChange_clicked() {
	if (esteban.getCurrentlyPlay() == true) {
		gatherLetterToChange_1(esteban, 'e');
		zeromski.setCurrentlyPlay(true);
		esteban.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white;}");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan;  }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('m');
		privacyBoard('e');
		privacyBoard('r');
		ui.estebanHorizontal->setChecked(false);
		ui.estebanVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.rokokoVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(true);
		ui.zeromskiVertical->setCheckable(true);
		ui.zeromskiHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_zeromskiChange_clicked() {
	if (zeromski.getCurrentlyPlay() == true) {
		gatherLetterToChange_1(zeromski, 'z');
		rokoko.setCurrentlyPlay(true);
		zeromski.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('z');
		privacyBoard('e');
		privacyBoard('m');
		ui.zeromskiHorizontal->setChecked(false);
		ui.zeromskiVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.zeromskiVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(true);
		ui.rokokoVertical->setCheckable(true);
		ui.rokokoHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_rokokoChange_clicked() {
	if (rokoko.getCurrentlyPlay() == true) {
		gatherLetterToChange_1(rokoko, 'r');
		mufasa.setCurrentlyPlay(true);
		rokoko.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('z');
		privacyBoard('e');
		privacyBoard('r');
		ui.zeromskiHorizontal->setChecked(false);
		ui.zeromskiVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.zeromskiVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.rokokoVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(true);
		ui.mufasaVertical->setCheckable(true);
		ui.mufasaHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_mufasaPass_clicked() {
	if (mufasa.getCurrentlyPlay() == true) {
		mufasa.setCurrentlyPlay(false);
		esteban.setCurrentlyPlay(true);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white;  }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan;  }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('e');
		playerLetterRefresh('z');
		playerLetterRefresh('m');
		playerLetterRefresh('r');
		privacyBoard('m');
		privacyBoard('z');
		privacyBoard('r');
		ui.mufasaHorizontal->setChecked(false);
		ui.mufasaVertical->setChecked(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.zeromskiVertical->setChecked(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.rokokoVertical->setChecked(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.estebanHorizontal->setCheckable(true);
		ui.estebanVertical->setCheckable(true);
		ui.estebanHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_estebanPass_clicked() {
	if (esteban.getCurrentlyPlay() == true) {
		zeromski.setCurrentlyPlay(true);
		esteban.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white;  }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan;}");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('m');
		privacyBoard('e');
		privacyBoard('r');
		ui.estebanHorizontal->setChecked(false);
		ui.estebanVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.rokokoVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(true);
		ui.zeromskiVertical->setCheckable(true);
		ui.zeromskiHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_zeromskiPass_clicked() {
	if (zeromski.getCurrentlyPlay() == true) {
		rokoko.setCurrentlyPlay(true);
		zeromski.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('z');
		privacyBoard('e');
		privacyBoard('m');
		ui.zeromskiHorizontal->setChecked(false);
		ui.zeromskiVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.zeromskiVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(true);
		ui.rokokoVertical->setCheckable(true);
		ui.rokokoHorizontal->setChecked(true);
	}
}

void Game_GUI_4::on_rokokoPass_clicked() {
	if (rokoko.getCurrentlyPlay() == true) {
		mufasa.setCurrentlyPlay(true);
		rokoko.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.zeromskiLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		ui.rokokoLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('m');
		playerLetterRefresh('z');
		playerLetterRefresh('e');
		playerLetterRefresh('r');
		privacyBoard('z');
		privacyBoard('e');
		privacyBoard('r');
		ui.zeromskiHorizontal->setChecked(false);
		ui.zeromskiVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.zeromskiHorizontal->setCheckable(false);
		ui.zeromskiVertical->setCheckable(false);
		ui.rokokoHorizontal->setCheckable(false);
		ui.rokokoVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(true);
		ui.mufasaVertical->setCheckable(true);
		ui.mufasaHorizontal->setChecked(true);
	}
}

void Game_GUI_4::privacyBoard(char c) {
	QString tmp = '#';
	if (c == 'm') {
		auto model = ui.mufasaBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			model->setData(model->index(0, i), tmp);
		}
	}
	else if (c == 'e') {
		auto model = ui.estebanBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			model->setData(model->index(0, i), tmp);
		}
	}
	else if (c == 'z') {
		auto model = ui.zeromskiBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			model->setData(model->index(0, i), tmp);
		}
	}
	else if (c == 'r') {
		auto model = ui.rokokoBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			model->setData(model->index(0, i), tmp);
		}
	}
}

void Game_GUI_4::playerLetterRefresh(char c) {
	if (c == 'm') {
		auto model = ui.mufasaBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			QString tmp = char(mufasa.getPlayerCardsName(i));
			model->setData(model->index(0, i), tmp);
		}
	}
	else if (c == 'e') {
		auto model = ui.estebanBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			QString tmp = char(esteban.getPlayerCardsName(i));
			model->setData(model->index(0, i), tmp);
		}
	}
	else if (c == 'z') {
		auto model = ui.zeromskiBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			QString tmp = char(zeromski.getPlayerCardsName(i));
			model->setData(model->index(0, i), tmp);
		}
	}
	else if (c == 'r') {
		auto model = ui.rokokoBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			QString tmp = char(rokoko.getPlayerCardsName(i));
			model->setData(model->index(0, i), tmp);
		}
	}
}

void Game_GUI_4::playerMove(player& playerPlay, char c) {
	if (c == 'm') {
		auto model = ui.tableWidget_game->model();
		std::string word = ui.mufasaWord->text().toStdString();
		bool check_word = true;
		if (word == "") {
			check_word = false;
		}
		if (check_word) { //trzeba dodac jakies rzeczy gdy slowo nie znajduje sie w slowniku dic
			int x = ui.mufasaColumn->currentText().toInt();
			int y = ui.mufasaRow->currentText().toInt();
			int cnt = 0;
			int s = 0;
			for (auto lett : word) { //sprawdzenie czy na odpowiednich pozycjach jest to samo i czy litery istnieja odpowiednio
				if (ui.mufasaHorizontal->isChecked()) {
					if (this->gameMap1.board[y][x + cnt].isOccupied()) {
						if (this->gameMap1.board[y][x + cnt].getLetter() != lett) {
							check_word = false;
						}
					}
					else {
						check_word = false;
						for (int i{ 0 }; i < 10; ++i) {
							if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
								playerPlay.setPlayerCardsChoiceToWrite(i, true);
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
							if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
								playerPlay.setPlayerCardsChoiceToWrite(i, true);
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
			for (int i{ 0 }; i < 10; ++i) {
				playerPlay.setPlayerCardsChoiceToWrite(i, false);
			}
			if (check_word == true) {
				check_word = this->gameMap1.correctMove(mufasa);
				if (check_word == true) {
					int x = ui.mufasaColumn->currentText().toInt();
					int y = ui.mufasaRow->currentText().toInt();
					int cnt = 0;
					for (auto lett : word) {
						if (ui.mufasaHorizontal->isChecked()) {
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
					playerPlay.changeUsedCards(word, gameMap1.cybant);
					gameMap1.playerPointsCount(playerPlay, user, match);
					ui.mufasaWord->setText(""); //zmiana tabelki
					playerLetterRefresh('m');
				}
			}
			if (!check_word) {
				gameMap1.incorrextMoveOfPlayer();
				ui.mufasaWord->setText(""); //zmiana tabelki
			}
		}
	}
	else if (c == 'e') {
		auto model = ui.tableWidget_game->model();
		std::string word = ui.estebanWord->text().toStdString();
		bool check_word = true;
		if (word == "") {
			check_word = false;
		}
		if (check_word) { //trzeba dodac jakies rzeczy gdy slowo nie znajduje sie w slowniku dic
			int x = ui.estebanColumn->currentText().toInt();
			int y = ui.estebanRow->currentText().toInt();
			int cnt = 0;
			int s = 0;
			for (auto lett : word) { //sprawdzenie czy na odpowiednich pozycjach jest to samo i czy litery istnieja odpowiednio
				if (ui.estebanHorizontal->isChecked()) {
					if (this->gameMap1.board[y][x + cnt].isOccupied()) {
						if (this->gameMap1.board[y][x + cnt].getLetter() != lett) {
							check_word = false;
						}
					}
					else {
						check_word = false;
						for (int i{ 0 }; i < 10; ++i) {
							if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
								playerPlay.setPlayerCardsChoiceToWrite(i, true);
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
							if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
								playerPlay.setPlayerCardsChoiceToWrite(i, true);
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
			for (int i{ 0 }; i < 10; ++i) {
				playerPlay.setPlayerCardsChoiceToWrite(i, false);
			}
			if (check_word == true) {
				check_word = this->gameMap1.correctMove(mufasa);
				if (check_word == true) {
					int x = ui.estebanColumn->currentText().toInt();
					int y = ui.estebanRow->currentText().toInt();
					int cnt = 0;
					for (auto lett : word) {
						if (ui.estebanHorizontal->isChecked()) {
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
					playerPlay.changeUsedCards(word, gameMap1.cybant);
					gameMap1.playerPointsCount(playerPlay, user, match);
					ui.estebanWord->setText(""); //zmiana tabelki
					playerLetterRefresh('e');
				}
			}
			if (!check_word) {
				gameMap1.incorrextMoveOfPlayer();
				ui.estebanWord->setText(""); //zmiana tabelki
			}
		}
	}
	else if (c == 'z') {
	auto model = ui.tableWidget_game->model();
	std::string word = ui.zeromskiWord->text().toStdString();
	bool check_word = true;
	if (word == "") {
		check_word = false;
	}
	if (check_word) { //trzeba dodac jakies rzeczy gdy slowo nie znajduje sie w slowniku dic
		int x = ui.zeromskiColumn->currentText().toInt();
		int y = ui.zeromskiRow->currentText().toInt();
		int cnt = 0;
		int s = 0;
		for (auto lett : word) { //sprawdzenie czy na odpowiednich pozycjach jest to samo i czy litery istnieja odpowiednio
			if (ui.zeromskiHorizontal->isChecked()) {
				if (this->gameMap1.board[y][x + cnt].isOccupied()) {
					if (this->gameMap1.board[y][x + cnt].getLetter() != lett) {
						check_word = false;
					}
				}
				else {
					check_word = false;
					for (int i{ 0 }; i < 10; ++i) {
						if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
							playerPlay.setPlayerCardsChoiceToWrite(i, true);
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
						if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
							playerPlay.setPlayerCardsChoiceToWrite(i, true);
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
		for (int i{ 0 }; i < 10; ++i) {
			playerPlay.setPlayerCardsChoiceToWrite(i, false);
		}
		if (check_word == true) {
			check_word = this->gameMap1.correctMove(mufasa);
			if (check_word == true) {
				int x = ui.zeromskiColumn->currentText().toInt();
				int y = ui.zeromskiRow->currentText().toInt();
				int cnt = 0;
				for (auto lett : word) {
					if (ui.zeromskiHorizontal->isChecked()) {
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
				playerPlay.changeUsedCards(word, gameMap1.cybant);
				gameMap1.playerPointsCount(playerPlay, user, match);
				ui.zeromskiWord->setText(""); //zmiana tabelki
				playerLetterRefresh('z');
			}
		}
		if (!check_word) {
			gameMap1.incorrextMoveOfPlayer();
			ui.zeromskiWord->setText(""); //zmiana tabelki
		}
		}
	}
	else if (c == 'r') {
	auto model = ui.tableWidget_game->model();
	std::string word = ui.rokokoWord->text().toStdString();
	bool check_word = true;
	if (word == "") {
		check_word = false;
	}
	if (check_word) { //trzeba dodac jakies rzeczy gdy slowo nie znajduje sie w slowniku dic
		int x = ui.rokokoColumn->currentText().toInt();
		int y = ui.rokokoRow->currentText().toInt();
		int cnt = 0;
		int s = 0;
		for (auto lett : word) { //sprawdzenie czy na odpowiednich pozycjach jest to samo i czy litery istnieja odpowiednio
			if (ui.rokokoHorizontal->isChecked()) {
				if (this->gameMap1.board[y][x + cnt].isOccupied()) {
					if (this->gameMap1.board[y][x + cnt].getLetter() != lett) {
						check_word = false;
					}
				}
				else {
					check_word = false;
					for (int i{ 0 }; i < 10; ++i) {
						if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
							playerPlay.setPlayerCardsChoiceToWrite(i, true);
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
						if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
							playerPlay.setPlayerCardsChoiceToWrite(i, true);
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
		for (int i{ 0 }; i < 10; ++i) {
			playerPlay.setPlayerCardsChoiceToWrite(i, false);
		}
		if (check_word == true) {
			check_word = this->gameMap1.correctMove(mufasa);
			if (check_word == true) {
				int x = ui.rokokoColumn->currentText().toInt();
				int y = ui.rokokoRow->currentText().toInt();
				int cnt = 0;
				for (auto lett : word) {
					if (ui.rokokoHorizontal->isChecked()) {
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
				playerPlay.changeUsedCards(word, gameMap1.cybant);
				gameMap1.playerPointsCount(playerPlay, user, match);
				ui.rokokoWord->setText(""); //zmiana tabelki
				playerLetterRefresh('r');
			}
		}
		if (!check_word) {
			gameMap1.incorrextMoveOfPlayer();
			ui.rokokoWord->setText(""); //zmiana tabelki
		}
	}
	}
}

void Game_GUI_4::refreshGameMap() {
/*	if (esteban.getCurrentlyPlay() == true) {
		mufasa.setPossibilityToChangeCards(true);
		esteban.setPossibilityToChangeCards(false);
	}
	else {
		mufasa.setPossibilityToChangeCards(false);
		esteban.setPossibilityToChangeCards(true);
	}
	*/
	auto model = ui.tableWidget_game->model();
	for (int i = 0; i < 15; i++) { // refresh tablicy
		for (int j = 0; j < 15; j++) {
			if (gameMap1.board[i][j].getSession() == 1 || gameMap1.board[i][j].getSession() == 2)
				model->setData(model->index(i, j), QString(gameMap1.board[i][j].getLetter()));
		}
	}


	QString x = QString::number(mufasa.getPlayerPoints());
	auto bufforM = ui.mufasaPoint;
	bufforM->setText(x);

	QString y = QString::number(esteban.getPlayerPoints());
	auto bufforE = ui.estebanPoint;
	bufforE->setText(y);

	QString z = QString::number(zeromski.getPlayerPoints());
	auto bufforZ = ui.zeromskiPoint;
	bufforZ->setText(z);

	QString r = QString::number(rokoko.getPlayerPoints());
	auto bufforR = ui.rokokoPoint;
	bufforR->setText(r);
}

void Game_GUI_4::gatherLetterToChange_1(player& playerGane, char c) {
	if (c == 'm') {
		if (ui.checkBox_1->isChecked()) {
			playerGane.setPlayerCardsToChange(0, true);
		}
		if (ui.checkBox_2->isChecked()) {
			playerGane.setPlayerCardsToChange(1, true);
		}
		if (ui.checkBox_3->isChecked()) {
			playerGane.setPlayerCardsToChange(2, true);
		}
		if (ui.checkBox_4->isChecked()) {
			playerGane.setPlayerCardsToChange(3, true);
		}
		if (ui.checkBox_5->isChecked()) {
			playerGane.setPlayerCardsToChange(4, true);
		}
		if (ui.checkBox_6->isChecked()) {
			playerGane.setPlayerCardsToChange(5, true);
		}
		if (ui.checkBox_7->isChecked()) {
			playerGane.setPlayerCardsToChange(6, true);
		}
		if (ui.checkBox_8->isChecked()) {
			playerGane.setPlayerCardsToChange(7, true);
		}
		if (ui.checkBox_9->isChecked()) {
			playerGane.setPlayerCardsToChange(8, true);
		}
		if (ui.checkBox_10->isChecked()) {
			playerGane.setPlayerCardsToChange(9, true);
		}
		playerGane.changeChosenCards(gameMap1.cybant);
		playerLetterRefresh('m');

		playerGane.changeChosenCardsUnchecked();
		ui.checkBox_1->setCheckState(Qt::Unchecked);
		ui.checkBox_2->setCheckState(Qt::Unchecked);
		ui.checkBox_3->setCheckState(Qt::Unchecked);
		ui.checkBox_4->setCheckState(Qt::Unchecked);
		ui.checkBox_5->setCheckState(Qt::Unchecked);
		ui.checkBox_6->setCheckState(Qt::Unchecked);
		ui.checkBox_7->setCheckState(Qt::Unchecked);
		ui.checkBox_8->setCheckState(Qt::Unchecked);
		ui.checkBox_9->setCheckState(Qt::Unchecked);
		ui.checkBox_10->setCheckState(Qt::Unchecked);
	}
	else if (c == 'e') {
		if (ui.checkBox_11->isChecked()) {
			playerGane.setPlayerCardsToChange(0, true);
		}
		if (ui.checkBox_12->isChecked()) {
			playerGane.setPlayerCardsToChange(1, true);
		}
		if (ui.checkBox_13->isChecked()) {
			playerGane.setPlayerCardsToChange(2, true);
		}
		if (ui.checkBox_14->isChecked()) {
			playerGane.setPlayerCardsToChange(3, true);
		}
		if (ui.checkBox_15->isChecked()) {
			playerGane.setPlayerCardsToChange(4, true);
		}
		if (ui.checkBox_16->isChecked()) {
			playerGane.setPlayerCardsToChange(5, true);
		}
		if (ui.checkBox_17->isChecked()) {
			playerGane.setPlayerCardsToChange(6, true);
		}
		if (ui.checkBox_18->isChecked()) {
			playerGane.setPlayerCardsToChange(7, true);
		}
		if (ui.checkBox_19->isChecked()) {
			playerGane.setPlayerCardsToChange(8, true);
		}
		if (ui.checkBox_20->isChecked()) {
			playerGane.setPlayerCardsToChange(9, true);
		}
		playerGane.changeChosenCards(gameMap1.cybant);
		playerLetterRefresh('e');

		playerGane.changeChosenCardsUnchecked();
		ui.checkBox_11->setCheckState(Qt::Unchecked);
		ui.checkBox_12->setCheckState(Qt::Unchecked);
		ui.checkBox_13->setCheckState(Qt::Unchecked);
		ui.checkBox_14->setCheckState(Qt::Unchecked);
		ui.checkBox_15->setCheckState(Qt::Unchecked);
		ui.checkBox_16->setCheckState(Qt::Unchecked);
		ui.checkBox_17->setCheckState(Qt::Unchecked);
		ui.checkBox_18->setCheckState(Qt::Unchecked);
		ui.checkBox_19->setCheckState(Qt::Unchecked);
		ui.checkBox_20->setCheckState(Qt::Unchecked);
	}
	else if (c == 'z') {
		if (ui.checkBox_21->isChecked()) {
			playerGane.setPlayerCardsToChange(0, true);
		}
		if (ui.checkBox_22->isChecked()) {
			playerGane.setPlayerCardsToChange(1, true);
		}
		if (ui.checkBox_23->isChecked()) {
			playerGane.setPlayerCardsToChange(2, true);
		}
		if (ui.checkBox_24->isChecked()) {
			playerGane.setPlayerCardsToChange(3, true);
		}
		if (ui.checkBox_25->isChecked()) {
			playerGane.setPlayerCardsToChange(4, true);
		}
		if (ui.checkBox_26->isChecked()) {
			playerGane.setPlayerCardsToChange(5, true);
		}
		if (ui.checkBox_27->isChecked()) {
			playerGane.setPlayerCardsToChange(6, true);
		}
		if (ui.checkBox_28->isChecked()) {
			playerGane.setPlayerCardsToChange(7, true);
		}
		if (ui.checkBox_29->isChecked()) {
			playerGane.setPlayerCardsToChange(8, true);
		}
		if (ui.checkBox_30->isChecked()) {
			playerGane.setPlayerCardsToChange(9, true);
		}
		playerGane.changeChosenCards(gameMap1.cybant);
		playerLetterRefresh('z');

		playerGane.changeChosenCardsUnchecked();
		ui.checkBox_21->setCheckState(Qt::Unchecked);
		ui.checkBox_22->setCheckState(Qt::Unchecked);
		ui.checkBox_23->setCheckState(Qt::Unchecked);
		ui.checkBox_24->setCheckState(Qt::Unchecked);
		ui.checkBox_25->setCheckState(Qt::Unchecked);
		ui.checkBox_26->setCheckState(Qt::Unchecked);
		ui.checkBox_27->setCheckState(Qt::Unchecked);
		ui.checkBox_28->setCheckState(Qt::Unchecked);
		ui.checkBox_29->setCheckState(Qt::Unchecked);
		ui.checkBox_30->setCheckState(Qt::Unchecked);
	}
	else if (c == 'r') {
	if (ui.checkBox_31->isChecked()) {
		playerGane.setPlayerCardsToChange(0, true);
	}
	if (ui.checkBox_32->isChecked()) {
		playerGane.setPlayerCardsToChange(1, true);
	}
	if (ui.checkBox_33->isChecked()) {
		playerGane.setPlayerCardsToChange(2, true);
	}
	if (ui.checkBox_34->isChecked()) {
		playerGane.setPlayerCardsToChange(3, true);
	}
	if (ui.checkBox_35->isChecked()) {
		playerGane.setPlayerCardsToChange(4, true);
	}
	if (ui.checkBox_36->isChecked()) {
		playerGane.setPlayerCardsToChange(5, true);
	}
	if (ui.checkBox_37->isChecked()) {
		playerGane.setPlayerCardsToChange(6, true);
	}
	if (ui.checkBox_38->isChecked()) {
		playerGane.setPlayerCardsToChange(7, true);
	}
	if (ui.checkBox_39->isChecked()) {
		playerGane.setPlayerCardsToChange(8, true);
	}
	if (ui.checkBox_40->isChecked()) {
		playerGane.setPlayerCardsToChange(9, true);
	}
	playerGane.changeChosenCards(gameMap1.cybant);
	playerLetterRefresh('r');

	playerGane.changeChosenCardsUnchecked();
	ui.checkBox_31->setCheckState(Qt::Unchecked);
	ui.checkBox_32->setCheckState(Qt::Unchecked);
	ui.checkBox_33->setCheckState(Qt::Unchecked);
	ui.checkBox_34->setCheckState(Qt::Unchecked);
	ui.checkBox_35->setCheckState(Qt::Unchecked);
	ui.checkBox_36->setCheckState(Qt::Unchecked);
	ui.checkBox_37->setCheckState(Qt::Unchecked);
	ui.checkBox_38->setCheckState(Qt::Unchecked);
	ui.checkBox_39->setCheckState(Qt::Unchecked);
	ui.checkBox_40->setCheckState(Qt::Unchecked);
	}
	refreshGameMap();
}