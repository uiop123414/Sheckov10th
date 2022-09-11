#include "drawingw.h"
#include "ui_drawingw.h"
#include <iostream>

DrawingW::DrawingW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingW)
{
    ui->setupUi(this);
    dx = dxs=dxt=dxtp= 0;//velocity
    dy = dys=dyt=dytp= 0;
    circleBounds.setLeft(34);
    circleBounds.setTop(21);
    circleBounds.setWidth(50);
    circleBounds.setHeight(50);
    square.setLeft(0);
    square.setTop(20);
    square.setWidth(50);
    square.setHeight(50);


    //Присваиваем точки треугольнику через <<
    trig<<QPoint(10.0, 80.0)<<QPoint(20.0, 10.0)<<QPoint(80.0, 30.0);
    trapezoid<<QPoint(10.0,10.0)<<QPoint(10.0,100.0)<<QPoint(30.0,100.0)<<QPoint(40.0,10.0);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(100);
}

void DrawingW::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    painter.drawPolygon(trig);
    painter.drawPolygon(trapezoid);

    painter.setBrush(Qt::white);
    painter.drawRect(this->rect());

    //Движение круга
    if ( ( circleBounds.left() + dx ) < 0 || ( circleBounds.right() + dx ) > this->rect().width() )
        dx = -dx;
    if ( ( circleBounds.top() + dy ) < 0 || ( circleBounds.bottom() + dy ) > this->rect().height() )
        dy = -dy;
    circleBounds.setLeft(circleBounds.left() + dx);
    circleBounds.setTop(circleBounds.top() + dy);
    circleBounds.setWidth(50);
    circleBounds.setHeight(50);
    //Движение квадрата
    if ( ( square.left() + dxs) < 0 || ( square.right() + dxs ) > this->rect().width() )
        dxs = -dxs;
    if ( ( square.top() + dys ) < 0 || ( square.bottom() + dys ) > this->rect().height() )
        dys = -dys;
    square.setLeft(square.left() + dxs);
    square.setTop(square.top() + dys);
    square.setWidth(50);
    square.setHeight(50);


    for(int i=0;i<3;i++){// Движение треугольника

        if (( trig.at(i).x()+dxt )<0 || ( trig.at(i).x()+ dxt ) > this->rect().width() )
            dxt = -dxt;

        if ( ( trig.at(i).y() + dyt ) < 0 || ( trig.at(i).y() + dyt ) > this->rect().height() )
            dyt = -dyt;
    }
    for(int i=0;i<3;i++){
        trig.setPoint(i,trig.at(i).x()+dxt,trig.at(i).y()+dyt);
    }

    for(int i=0;i<4;i++){// Движение трапеции

        if (( trapezoid.at(i).x()+dxtp )<0 || ( trapezoid.at(i).x()+ dxtp ) > this->rect().width() )
            dxtp = -dxtp;

        if ( ( trapezoid.at(i).y() + dytp ) < 0 || ( trapezoid.at(i).y() + dytp ) > this->rect().height() )
            dytp = -dytp;
    }
    for(int i=0;i<4;i++){
        trapezoid.setPoint(i,trapezoid.at(i).x()+dxtp,trapezoid.at(i).y()+dytp);
    }

    painter.setBrush(Qt::red);
    painter.drawEllipse(circleBounds);
    painter.drawPolygon(square);
    painter.drawPolygon(trig);
    painter.drawPolygon(trapezoid);
}
void DrawingW::set_paramW(const int & speed,const bool & motion){//True - Up-Down; False - Left-Right

    this->setWindowTitle("Speed "+QString::number(speed)+" motion "+QString::number(motion));
    if(motion==1){
        dy=dys=dyt=dytp=speed;
        dx=dxs=dxt=dxtp=0;
    }
    else{
        dx=dxs=dxt=dxtp=speed;
        dy=dys=dyt=dytp=0;
    }

}

void DrawingW::stop_objects(){
    dx=dxt=dxs=dxtp=0;
    dy=dys=dyt=dytp=0;
}
DrawingW::~DrawingW()
{
    delete ui;
}
