#ifndef DRAWINGW_H
#define DRAWINGW_H

#include <QWidget>
#include <QtGui>
#include <QMessageBox>

namespace Ui {
class DrawingW;
}

class DrawingW : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingW(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~DrawingW();

private:
    Ui::DrawingW *ui;
    int dx,dxs,dxt,dxtp;//velocity
    int dy,dys,dyt,dytp;
    //dx, dy - velocity circle
    //dys, dxs - velocity square
    //dyt, dyt - velocity triangle
    //dxtp,dytp - velocity trapezoid
    QRect circleBounds;
    QRect square;
    QPolygon  trig;
    QPolygon trapezoid;



private slots:
    void set_paramW(const int & speed,const bool & motion);//True - Up-Down; False - Left-Right
    void stop_objects();
};

#endif // DRAWINGW_H
