#include "sala.h"
#include "ui_sala.h"

Sala::Sala(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sala)
{
    ui->setupUi(this);
}

Sala::~Sala()
{
    delete ui;
}
