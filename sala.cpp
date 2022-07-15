#include "sala.h"
#include "ui_Sala.h"

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
