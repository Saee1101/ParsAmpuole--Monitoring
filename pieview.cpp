#include "pieview.h"

pieview::pieview(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
    series = new QPieSeries();

    series->append("accept",0);
    series->append("reject",0);
series->setPieSize(0.9);
series->setHorizontalPosition(0.4);
series->setVerticalPosition(0.5);
//![1]

//![2]
//!


    setBackgroundBrush(QBrush(QColor(44,44,44)));

    series->slices().at(0)->setBrush(Qt::green);
    series->slices().at(1)->setBrush(Qt::red);
    addSeries(series);
   // legend()->hide();
    legend()->setLabelBrush(QBrush(QColor(255,255,255)));
     legend()->setAlignment(Qt::AlignRight);
     //          setLabelFont(QFont("Arial", 8));
     legend()->setFont(QFont("Arial", 10));

//     legend()->setLabelBrush(QBrush(QColor("transparent")));
    series->slices().at(0)->setLabelBrush(QBrush(QColor(255,255,255)));
    series->slices().at(1)->setLabelBrush(QBrush(QColor(255,255,255)));
}
