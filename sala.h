#ifndef SALA_H
#define SALA_H

#include <QMainWindow>

namespace Ui {
class Sala;
}

class Sala : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sala(QWidget *parent = nullptr);
    ~Sala();

private:
    Ui::Sala *ui;
};

#endif // SALA_H
