#ifndef CAMERAPREVIEW_H
#define CAMERAPREVIEW_H

#include <QObject>
#include <QThread>
#include <QImage>
#include "HalconCpp.h"
#include "HDevThread.h"
using namespace HalconCpp;
using namespace std;
//DShowLib::Grabber        grabber1;
class cameraPreview : public QThread
{
    Q_OBJECT
public:
    explicit cameraPreview(QObject *parent = nullptr);
void run();
QImage im;
int Cond=1;
HFramegrabber  *grabber;
 bool grabberexistFlag=false;
 bool GrabbingModeFlag=true;
void closFrame();
void cameraSetting();
void DefaultSetting();
bool singleFrameFlag=false;
string  Campturename = "1";
 HImage imageread;
bool HImage2QImage(HalconCpp::HImage &from, QImage &to);
cameraPreview *camera;
signals:
void cameraImagesend(HalconCpp::HImage*);
};

#endif // CAMERAPREVIEW_H
