#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
 //   QTimer *timer;
    int minimal=0;
    int minimal_sec=0;
    int minimal_row=0;
    QTimer *timer_decrease;
private slots:
    void clock_ends();
    void starttimer(int ms);
    int count_timers();
    void startClock();
    void tim_minimal();
    void tim_update();
    void tim_end();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
