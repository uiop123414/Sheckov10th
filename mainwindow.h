#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QMessageBox>
#include <QObject>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *ShowButton;
    QPushButton *ChooseButton;
    QPushButton *StopButton;
    QPushButton *AnimateButton;
    QPushButton *ExitButton;
    float speed;
    bool motion;//True - Up-Down; False - Left-Right

public slots:
    void ExitSlot();
    void ChooseSlot();
    void AnimateSlot();
    void StopSlot();
    void ShowSlot();


signals:
    void ExitSignal();


};

#endif // MAINWINDOW_H
