#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chooseform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_CF = new ChooseForm();

    //иницилизация кнопок
    ShowButton = new QPushButton(this);
    ShowButton->setObjectName(QString::fromUtf8("Show picture"));
    ShowButton->setGeometry(QRect(0, 0, 100, 32));
    ChooseButton = new QPushButton(this);
    ChooseButton->setObjectName(QString::fromUtf8("Choose"));
    ChooseButton->setGeometry(QRect(100, 0, 100, 32));
    AnimateButton = new QPushButton(this);
    AnimateButton->setObjectName(QString::fromUtf8("Animate"));
    AnimateButton->setGeometry(QRect(200, 0, 100, 32));
    StopButton = new QPushButton(this);
    StopButton->setObjectName(QString::fromUtf8("Stop"));
    StopButton->setGeometry(QRect(300, 0, 100, 32));
    ExitButton = new QPushButton(this);
    ExitButton->setObjectName(QString::fromUtf8("Quit"));
    ExitButton->setGeometry(QRect(400, 0, 100, 32));


    //ввод названий кнопкам
    ShowButton->setText(QCoreApplication::translate("Form", "Show picture", nullptr));
    ChooseButton->setText(QCoreApplication::translate("Form", "Choose", nullptr));
    StopButton->setText(QCoreApplication::translate("Form", "Stop", nullptr));
    AnimateButton->setText(QCoreApplication::translate("Form", "Animate", nullptr));
    ExitButton->setText(QCoreApplication::translate("Form", "Quit", nullptr));


    //коннект кнопок с функциями
    QObject::connect(ExitButton, SIGNAL(clicked()), this, SLOT(ExitSlot()));
    QObject::connect(ChooseButton,SIGNAL(clicked()),this,SLOT(ChooseSlot()));
    QObject::connect(StopButton,SIGNAL(clicked()),this,SLOT(StopSlot()));
    QObject::connect(AnimateButton,SIGNAL(clicked()),this,SLOT(AnimateSlot()));
    QObject::connect(ShowButton,SIGNAL(clicked()),this,SLOT(ShowSlot()));
    //Переход между окнами
    QObject::connect(ui_CF,SIGNAL(firstWindow(const int &,const bool &)),this,SLOT(Set_params(const int &,const bool &)));


}

void MainWindow::ExitSlot(){
    exit(0);
}

void MainWindow::ChooseSlot(){
    ui_CF->show();
    this->close();


}

void MainWindow::StopSlot(){

}

void MainWindow::AnimateSlot(){



}

void MainWindow::ShowSlot(){

}
void  MainWindow::Set_params(const int & _speed,const bool & _motion){
    this->show();
    speed = _speed;
    motion = _motion;
}


MainWindow::~MainWindow()
{
    delete ui;
}

