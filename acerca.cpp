#include "acerca.h"
#include "ui_acerca.h"

Acerca::Acerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca)
{
    ui->setupUi(this);
    setWindowTitle(tr("Informacion"));
}

Acerca::~Acerca()
{
    delete ui;
}
