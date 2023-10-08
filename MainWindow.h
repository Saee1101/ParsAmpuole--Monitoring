#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "barview.h"
#include "camerapreview.h"
#include "halconqtwindow.h"
#include "newplotclass.h"
#include"pieview.h"
#include <QMainWindow>
#include <QPieLegendMarker>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDriver>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
bool powersystemflag;
 newplotclass *plot_d4;
 newplotclass *plot_d5;

 pieview * pie;
   barview *BAR;
 QChartView *Statisticview;
int AcceptCount ;
int RejectCount ;
double Counter_Reject_D4;
double Counter_Reject_D5;
QPieLegendMarker *pieMarker ;
////////////////////////////////////camera
   cameraPreview * camera;
//   bool CameraStateFlage;
   halconqtwindow *centerwindow;
private slots:
void PreviewImageRecived(HalconCpp::HImage*);
    void on_btn_backtosetting_pressed();

    void on_btn_backtosetting_released();

    void on_btn_power_clicked();

    void on_btn_power_pressed();

    void on_btn_power_released();

    void on_btn_save_pressed();



    void on_btn_save_released();

    void on_btn_reset_pressed();

    void on_btn_reset_released();

    void on_btn_backtosetting_clicked();

    void on_comboBox_statistic_currentIndexChanged(int index);

    void on_btn_reset_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
