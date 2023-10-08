#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QtCore>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    camera = new cameraPreview(this);
//    CameraStateFlage=false;
    centerwindow = new halconqtwindow(this);
    centerwindow->openwindow(400,400);
    ui->Camera_Layout->addWidget(centerwindow);

//    connect(camera,SIGNAL(cameraImagesend(HalconCpp::HImage*)),this,SLOT(PreviewImageRecived(HalconCpp::HImage*)));







    ///////////////////////////////////////////////////////////////
    Counter_Reject_D4=1;
   Counter_Reject_D5=1;
    for (int i = 0; i <= 1; ++i) {

        ui->comboBox_camera->model()->setData(ui->comboBox_camera->model()->index(i, 0), QColor("black"), Qt::BackgroundColorRole);
        ui->comboBox_camera->model()->setData(ui->comboBox_camera->model()->index(i, 0), QColor("white"), Qt::TextColorRole);
        ui->comboBox_camera->view()->window()->setStyleSheet("border : 1px solid gray; border-radius: 5px;");
        ui->comboBox_statistic->model()->setData(ui->comboBox_statistic->model()->index(i, 0), QColor("black"), Qt::BackgroundColorRole);
         ui->comboBox_statistic->model()->setData(ui->comboBox_statistic->model()->index(i, 0), QColor("white"), Qt::TextColorRole);
         ui->comboBox_statistic->view()->window()->setStyleSheet("border : 1px solid gray; border-radius: 5px;");
    }

    powersystemflag=false;
   plot_d4 = new newplotclass;
    plot_d4->setparameter(580,270,21,5,16,16.15,15.85);
    ui->gridLayout_D4->addWidget(plot_d4);

    plot_d5 = new newplotclass;
     plot_d5->setparameter(580,269,21,5,16,16.15,15.85);
     ui->gridLayout_D5->addWidget(plot_d5);

      pie = new pieview;
      BAR = new barview;
        QChartView *PiechartView = new QChartView(pie);
        QChartView *BarchartView = new QChartView(BAR);
        Statisticview = PiechartView;

            //************ PIE VIEW **************//
          AcceptCount = 1;
          RejectCount = 1;
          PiechartView->setRenderHint(QPainter::Antialiasing);
          ui->Statistic_MonitorLayout->addWidget(PiechartView);
          PiechartView->setBackgroundBrush(QBrush(QColor(44,44,44)));


          pie->series->slices().at(0)->setValue(AcceptCount);
          pie->series->slices().at(1)->setValue(RejectCount);
          pie->series->slices().at(0)->setLabel("Acc : "+QString::number(AcceptCount));
          pie->series->slices().at(1)->setLabel("Rej : "+QString::number(RejectCount));
          //************ BAR VIEW **************//

          BarchartView->setRenderHint(QPainter::Antialiasing);
//          ui->Statistic_MonitorLayout->addWidget(BarchartView);
          ////////////////////////////////////////////////////////////////////////
          QSqlDatabase db;
          db=QSqlDatabase :: addDatabase("QSQLITE");
             db.setDatabaseName("TivanEX.db");
//               db.setDatabaseName("Mydatabase.db");
         db.open();

}
void MainWindow::PreviewImageRecived(HalconCpp::HImage *im)
{
    Hlong Width,Height;
    im->GetImageSize(&Width,&Height);
    centerwindow->WinfoeID().SetPart(HalconCpp::HTuple(0),HalconCpp::HTuple(0),HalconCpp::HTuple(Height-1),HalconCpp::HTuple(Width-1));
    im->DispImage(centerwindow->WinfoeID());
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_backtosetting_pressed()
{
//ui->btn_backtosetting->setGeometry(ui->btn_backtosetting->x()-1,ui->btn_backtosetting->y()+3,ui->btn_backtosetting->width()-2,ui->btn_backtosetting->height()-2);
    ui->btn_backtosetting->setGeometry(ui->btn_backtosetting->x(),ui->btn_backtosetting->y(),ui->btn_backtosetting->width()-2,ui->btn_backtosetting->height()-2);
}

void MainWindow::on_btn_backtosetting_released()
{
//ui->btn_backtosetting->setGeometry(ui->btn_backtosetting->x()+1,ui->btn_backtosetting->y()-3,ui->btn_backtosetting->width()+2,ui->btn_backtosetting->height()+2);
    ui->btn_backtosetting->setGeometry(ui->btn_backtosetting->x(),ui->btn_backtosetting->y(),ui->btn_backtosetting->width()+2,ui->btn_backtosetting->height()+2);
}
////////////////////// btn_power_clicked
void MainWindow::on_btn_power_clicked()
{
    QSqlQuery q;
//    q.exec("UPDATE  Machin_Setting SET D4_Sensitivity='90'WHERE Id=1");
//     ui->doubleSpinBox->setValue(q.exec("SELECT D4_Sensitivity FROM Machin_Setting WHERE Id=1 "));
//ui->doubleSpinBox->setValue(q.exec("SELECT Num FROM Value WHERE Id=2"));
    if(powersystemflag==false){
//        camera->Cond=1;
//        camera->start();
        powersystemflag=true;
        ui->btn_power->setStyleSheet("border-image: url(:/resource/Image/System Control On.png);");
    }else{
//        camera->Cond=0;
//        camera->closFrame();
        powersystemflag=false;
        ui->btn_power->setStyleSheet("border-image: url(:/resource/Image/System Control Off.png);");

    }
//    if(CameraStateFlage){
//        camera->Cond=0;
//        camera->closFrame();
//        CameraStateFlage=false;
//    }else{
//        camera->Cond=1;
//        camera->start();
//        CameraStateFlage=true;
//    }
   }

void MainWindow::on_btn_power_pressed()
{
//    ui->btn_power->setGeometry(ui->btn_power->x()+2,ui->btn_power->y()+2,ui->btn_power->width()-2,ui->btn_power->height()-2);
    ui->btn_power->setGeometry(ui->btn_power->x(),ui->btn_power->y(),ui->btn_power->width()-2,ui->btn_power->height()-2);

// ui->doubleSpinBox->setValue(q.exec("SELECT D4_Sensitivity FROM Machine_Setting "));
}

void MainWindow::on_btn_power_released()
{
//    ui->btn_power->setGeometry(ui->btn_power->x()-2,ui->btn_power->y()-2,ui->btn_power->width()+2,ui->btn_power->height()+2);
    ui->btn_power->setGeometry(ui->btn_power->x(),ui->btn_power->y(),ui->btn_power->width()+2,ui->btn_power->height()+2);
//    QSqlQuery q;
//    ui->doubleSpinBox->setValue(q.exec("SELECT D4_Sensitivity FROM Machine_Setting "));
//    ui->doubleSpinBox_2->setValue(q.exec("SELECT D5_Sensitivity FROM Machine_Setting "));
//ui->doubleSpinBox->setValue(q.exec("SELECT Num FROM Value WHERE Id=2"));
}
///////////////////////////////////////////////////////
void MainWindow::on_btn_save_pressed()
{
     ui->btn_save->setGeometry(ui->btn_save->x(),ui->btn_save->y(),ui->btn_save->width()-2,ui->btn_save->height()-2);
}

void MainWindow::on_btn_save_released()
{
    ui->btn_save->setGeometry(ui->btn_save->x(),ui->btn_save->y(),ui->btn_save->width()+2,ui->btn_save->height()+2);
}

void MainWindow::on_btn_reset_pressed()
{
    ui->btn_reset->setGeometry(ui->btn_reset->x(),ui->btn_reset->y(),ui->btn_reset->width()-2,ui->btn_reset->height()-2);
}

void MainWindow::on_btn_reset_released()
{
    ui->btn_reset->setGeometry(ui->btn_reset->x(),ui->btn_reset->y(),ui->btn_reset->width()+2,ui->btn_reset->height()+2);
}
/////////////////////////////////////////////////////////////////

void MainWindow::on_btn_backtosetting_clicked()
{
    BAR->set0->replace(0,Counter_Reject_D4/RejectCount*100);
   BAR->set1->replace(0,Counter_Reject_D5/RejectCount*100);

    plot_d4->setData(ui->doubleSpinBox->value());
    plot_d5->setData(ui->doubleSpinBox_2->value());

   if(plot_d4->satausData()==true)
    {


    pie->series->slices().at(0)->setLabel("Acc : "+QString::number(AcceptCount++));
    pie->series->slices().at(0)->setValue(AcceptCount);
    }
   if (plot_d5->satausData()==true)
    {
      pie->series->slices().at(0)->setLabel("Acc : "+QString::number(AcceptCount++));
       pie->series->slices().at(0)->setValue(AcceptCount);

    }
    if (plot_d5->satausData()==false)
    {
         Counter_Reject_D5++;
        pie->series->slices().at(1)->setLabel("Rej : "+QString::number(RejectCount++));
         pie->series->slices().at(1)->setValue(RejectCount);
    }
   if (plot_d4->satausData()==false)
    {
        Counter_Reject_D4++;
         pie->series->slices().at(1)->setLabel("Rej : "+QString::number(RejectCount++));
          pie->series->slices().at(1)->setValue(RejectCount);
    }

}

void MainWindow::on_comboBox_statistic_currentIndexChanged(int index)
{
    QChartView *MainchartView;

    if(!ui->Statistic_MonitorLayout->isEmpty())
        ui->Statistic_MonitorLayout->removeWidget(Statisticview);
    switch (index) {
    case 0 :
        MainchartView = new QChartView(pie);
        break;
    case 1:
        MainchartView = new QChartView(BAR);
        break;
    }
     MainchartView->setBackgroundBrush(QBrush(QColor(44,44,44)));
    MainchartView->setRenderHint(QPainter::Antialiasing);
    ui->Statistic_MonitorLayout->addWidget(MainchartView);
    Statisticview=MainchartView;
}

void MainWindow::on_btn_reset_clicked()
{
    AcceptCount=1;
    RejectCount=1;

    pie->series->slices().at(0)->setValue(AcceptCount);
    pie->series->slices().at(1)->setValue(RejectCount);
    BAR->set0->replace(0,Counter_Reject_D4/RejectCount*100);
   BAR->set1->replace(0,Counter_Reject_D5/RejectCount*100);

    pie->series->slices().at(0)->setLabel("Acc : "+QString::number(AcceptCount));
    pie->series->slices().at(1)->setLabel("Rej : "+QString::number(RejectCount));
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    QSqlQuery q;
     q.exec("UPDATE  Machine_Setting SET D4_Sensitivity='"+QString::number(arg1)+"'WHERE Id=1");
//     qDebug()<<QString::number(arg1);
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    QSqlQuery q;
 q.exec("UPDATE  Machine_Setting SET D5_Sensitivity='"+QString::number(arg1)+"'WHERE Id=1");
}
