#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chooseform.h"
#include "drawingw.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_CF = new ChooseForm();
    ui_AN = new DrawingW();

    // Стандартные значения
    speed = 100;
    motion = true;

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


    SpeedLabel = new QLabel(this);
    SpeedLabel->setObjectName(QString::fromUtf8("SpeedLabel"));
    SpeedLabel->setGeometry(QRect(40, 70, 41, 21));


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
    QObject::connect(this,SIGNAL(AnimateSignal(const int &,const bool &)),ui_AN,SLOT(set_paramW(const int &,const bool &)));
    QObject::connect(this,SIGNAL(StopSignal()),ui_AN,SLOT(stop_objects()));
    QObject::connect(this,SIGNAL(ShowSlot()),ui_AN,SLOT());

}

void MainWindow::ExitSlot(){
    exit(0);
}

void MainWindow::ChooseSlot(){
    ui_CF->show();
    this->close();


}

void MainWindow::AnimateSlot(){
    emit AnimateSignal(speed,motion);


}


void MainWindow::ShowSlot(){
     ui_AN->show();

}

void MainWindow::StopSlot(){

    emit StopSignal();
}
void  MainWindow::Set_params(const int & _speed,const bool & _motion){

    SpeedLabel->setText(QString::number(_motion));
    speed = _speed;
    motion = _motion;
    this->show();

}


MainWindow::~MainWindow()
{
    delete ui;
}

