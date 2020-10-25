#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QtMultimedia/QMediaPlayer>
#include <QWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::tim_end(){
    if (!ui->checkBox->isChecked()){
    QMessageBox ent;
    ent.setText("Timer ends");
    QApplication::beep();
    ent.exec();
    }

//    QMediaPlayer player;
//    player.setMedia(QUrl::fromLocalFile("/romulan_alarm.wav"));
 //   player.setVolume(10);
//    player.play();
}
int MainWindow::count_timers(){
    int k=0;
    for (int i=0;i<ui->listWidget_timer->count();i++){
        QTime time;
        QString str;
        str=ui->listWidget_timer->item(i)->text();
        qDebug()<<str;
        time= QTime::fromString(str,"hh:mm:ss");
        if ((time.hour()*3600+time.minute()*60+time.second())==0)
        k++;
    }

    return k;
}
void MainWindow::tim_minimal(){
    QTime minimal_time(23,59,59,0);
    QString str;
        int sec=0;
    QTime time;
    for (int i=0;i<ui->listWidget_timer->count();i++){
       str=ui->listWidget_timer->item(i)->text();
       time= QTime::fromString(str,"hh:mm:ss");
       if (minimal_time.hour()>=time.hour()){
           if (minimal_time.minute()>=time.minute()){
               if (minimal_time.second()>time.second()&& time.second()!=0){
                   sec=0;
           minimal_time=time;
           qDebug() <<"AAO "<<minimal_time.second();
           sec+=minimal_time.hour()*3600+minimal_time.minute()*60+minimal_time.second();
           minimal=100/sec;
           minimal_sec=sec;
           minimal_row=i;
           }
       }
       }
       }
}
void MainWindow::tim_update(){
    QTime time;
    QString str;
    int k=0;
    for (int i=0;i<ui->listWidget_timer->count();i++){
       str=ui->listWidget_timer->item(i)->text();
       qDebug()<<str;
       time= QTime::fromString(str,"hh:mm:ss");
       if ((time.hour()*3600+time.minute()*60+time.second())!=0)
       time = time.addSecs(-1);
       else k++;
       if (i==minimal_row){
          ui->progressBar->setValue((minimal_sec-time.second())*minimal);
          if (time.second()==0) ui->progressBar->setValue(100);
       }
       ui->listWidget_timer->item(i)->setText(time.toString());
       }
    if (k==ui->listWidget_timer->count()) timer_decrease->stop();
    ui->label->setText("Number of timers: " + QString::number(ui->listWidget_timer->count()-k,10));
    ui->label_2->setText("Fastest timer №" + QString::number(minimal_row+1,10));
}
void MainWindow::starttimer(int ms){
 /*   QTimer *timer=new QTimer(this);
    QTimer *timer_decrease=new QTimer(this);
    ui->listWidget_timer->addItem(ui->time_current->time().toString());
    connect(timer_decrease,SIGNAL(timeout()),this,SLOT(tim_update()));
    connect(timer,SIGNAL(timeout()),this,SLOT(tim_end()));
    timer_decrease->start(1000);
    timer->setSingleShot(1);
    timer->start(ms);*/
    QTimer *timer=new QTimer(this);
    if (ui->listWidget_timer->count()==0 || count_timers()==ui->listWidget_timer->count()){
    timer_decrease=new QTimer(this);
    connect(timer_decrease,SIGNAL(timeout()),this,SLOT(tim_update()));
    timer_decrease->start(1000);
    }
    ui->listWidget_timer->addItem(ui->time_current->time().toString());
    tim_minimal();
    connect(timer,SIGNAL(timeout()),this,SLOT(tim_end()));
    timer->setSingleShot(1);
    timer->start(ms);

}
void MainWindow::clock_ends(){
    if (!ui->checkBox->isChecked()){
    QMessageBox ent2;
    ent2.setText("Wake up");
    QApplication::beep();
    ent2.exec();
    }
}
void MainWindow::startClock(){
    QTime time;
    QTimer *clock=new QTimer(this);
    connect(clock, SIGNAL(timeout()),this,SLOT(clock_ends()));
    ui->listWidget_clocks->addItem(ui->time_current->time().toString());
    clock->setSingleShot(1);
    int cur_time=time.currentTime().hour()*3600 + time.currentTime().minute()*60 + time.currentTime().second();
    clock->start(abs(ui->time_current->time().hour()*3600+ui->time_current->time().minute()*60+ui->time_current->time().second()-cur_time)*1000);
    qDebug() << abs(ui->time_current->time().hour()*3600+ui->time_current->time().minute()*60+ui->time_current->time().second()-cur_time);
}

void MainWindow::on_pushButton_clicked()
{

  //  QTime time(ui->time_current->time());

//    if (time.hour()!=0 && time.minute()!=0){
    if(ui->time_current->time().toString()!="00:00:00" ) {
  //  QTime tim = ui->timeEdit->time();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                 "Choose action",
                                 "Press Yes to add timer, No to add clock",
                                 QMessageBox::Yes|QMessageBox::No);
   if (reply == QMessageBox::Yes) {
                starttimer((ui->time_current->time().hour()*3600+ui->time_current->time().minute()*60+ui->time_current->time().second())*1000);
               } else if (reply == QMessageBox::No) {
                    startClock();
               }
    }
    else {
        QMessageBox ent;
        ent.setText("You can't interract with 0:00 time");
        ent.exec();
    }

}