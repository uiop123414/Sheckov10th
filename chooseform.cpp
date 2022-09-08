#include "chooseform.h"
#include "ui_chooseform.h"

ChooseForm::ChooseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseForm)
{
    ui->setupUi(this);

    if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("MainWindow"));
    this->resize(800, 600);
    SpeedLabel = new QLabel(this);
    SpeedLabel->setObjectName(QString::fromUtf8("SpeedLabel"));
    SpeedLabel->setGeometry(QRect(40, 70, 41, 21));
    SetButton = new QPushButton(this);
    SetButton->setObjectName(QString::fromUtf8("SetButton"));
    SetButton->setGeometry(QRect(40, 150, 75, 24));
    UpDownRadio = new QRadioButton(this);
    UpDownRadio->setObjectName(QString::fromUtf8("UpDownRadio"));
    UpDownRadio->setGeometry(QRect(40, 110, 89, 20));
    LeftRightRadio = new QRadioButton(this);
    LeftRightRadio->setObjectName(QString::fromUtf8("LeftRightRadio"));
    LeftRightRadio->setGeometry(QRect(140, 110, 89, 20));
    SpeedLine = new QLineEdit(this);
    SpeedLine->setObjectName(QString::fromUtf8("SpeedLine"));
    SpeedLine->setGeometry(QRect(110, 70, 113, 22));

    this->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    SpeedLabel->setText(QCoreApplication::translate("MainWindow", "Speed", nullptr));
    SetButton->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
    UpDownRadio->setText(QCoreApplication::translate("MainWindow", "Up-Down", nullptr));
    LeftRightRadio->setText(QCoreApplication::translate("MainWindow", "Left-Right", nullptr));
}

ChooseForm::~ChooseForm()
{
    delete ui;
}
