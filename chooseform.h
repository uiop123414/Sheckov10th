#ifndef CHOOSEFORM_H
#define CHOOSEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QButtonGroup>
#include <QWidget>

namespace Ui {
class ChooseForm;
}

class ChooseForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseForm(QWidget *parent = nullptr);
    ~ChooseForm();

private:
    Ui::ChooseForm *ui;
    QLabel *SpeedLabel;
    QPushButton *SetButton;
    QRadioButton *UpDownRadio;
    QRadioButton *LeftRightRadio;
    QLineEdit *SpeedLine;

    int speed;
    bool motion;
private slots:
    void pressSet();
signals:
    void firstWindow(const int &,const bool &);

};

#endif // CHOOSEFORM_H
