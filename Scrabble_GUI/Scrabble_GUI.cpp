#include "Scrabble_GUI.h"
#include "Logging_GUI.h"

Scrabble_GUI::Scrabble_GUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void Scrabble_GUI::on_pushButton_clicked()
{
    Logging_GUI login;
    login.setModal(true);
    login.exec();
}
