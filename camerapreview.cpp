#include "camerapreview.h"
#include<QtCore>
#include<QMessageBox>
#include<QFileDialog>
//#include "SelectRejection.hpp"
//#include "CurveType.hpp"
//#include "FoamType.hpp"
cameraPreview::cameraPreview(QObject *parent) : QThread(parent)
{

}



void cameraPreview::run()
{
    // HImage imageread;
    // Hlong width,height;
    HString type;
    type="byte";

   grabber= new HFramegrabber("GigEVision2", 0, 0, 0, 0, 0, 0, "progressive", -1, "default",
                              -1, "false", "default", "", 0, -1);
//    grabber= new HFramegrabber("GigEVision2", 0, 0, 0, 0, 0, 0, "progressive", -1, "default",
//                               -1, "false", "default", "00305344ed9d_Basler_acA130060gm", 0, -1);
qDebug()<<"yasss"<<endl;
    grabberexistFlag=true;

//    grabber->SetFramegrabberParam ("GainAuto", "Off");
//    grabber->SetFramegrabberParam("GainSelector", "AnalogAll");
//    //  grabber->SetFramegrabberParam("GainRaw", nullptr);
//    //   grabber->SetFramegrabberParam ("GainRaw", 0.0);
//    //   grabber->SetFramegrabberParam ("Width", 1281);
//    //    grabber->SetFramegrabberParam ("Height", 1025);
//    //    grabber->SetFramegrabberParam ("AcquisitionMode", "Continuous");
//    if(GrabbingModeFlag==0)
//        grabber->SetFramegrabberParam ( "TriggerMode", "Off");
//    else
//        grabber->SetFramegrabberParam ( "TriggerMode", "On");
//    grabber->SetFramegrabberParam ( "TriggerSource", "Line1");
//    grabber->SetFramegrabberParam ( "TriggerDelayAbs", 1000);
//    //    grabber->SetFramegrabberParam ( "ExposureMode", "Timed");
//    grabber->SetFramegrabberParam ( "ExposureAuto", "Off");
//    grabber->SetFramegrabberParam ( "ExposureTimeAbs", 450.0);
//    //    grabber->SetFramegrabberParam ( "ShutterMode", "Global");
//    //    grabber->SetFramegrabberParam ( "volatile", "disable");
//    //    grabber->SetFramegrabberParam ( "image_height", 1025);
//    // grabber->SetFramegrabberParam("grab_timeout", -1);
//    //  grabber->SetFramegrabberParam("grab_timeout", 1000);
    grabber->GrabImageStart(-1);
    while (Cond == 1) {
        //imageread.GrabImageAsync(*grabber,-1);
        try
        {
            //   imageread.GrabImage(*grabber);
            imageread.GrabImageAsync(*grabber,-1);
            //     imageread .ReadImage("D:/build-ParsAmpoulMM_V1-Desktop_Qt_5_14_0_MSVC2017_32bit-Debug/filename.png");
        }
        catch (HException except)
        {
            qDebug()<<"exception timeout";
            continue;
        }
        // imageread.GetImageSize(&width,&height);
        //     HImage2QImage(imageread,im);
        // im=QImage(static_cast<unsigned char *>(imageread.GetImagePointer1(&type,&width,&height)),width,height,QImage::Format_Grayscale8);
        emit cameraImagesend(&imageread);
//        if(singleFrameFlag){
//             imageread.WriteImage("tiff",0,Campturename.c_str());
//            Cond=0;
//        }
        // imageread.WriteImage("jpeg 100",0,"string");
        // im.save("filename.png");
    }
    qDebug()<<"theard timeout";
}

void cameraPreview::closFrame()
{
    if(grabberexistFlag)
        grabber->Clear();

}

void cameraPreview::cameraSetting()
{
    if(grabberexistFlag)
        grabber->Clear();
}

void cameraPreview::DefaultSetting()
{
    if(grabberexistFlag)
        grabber->Clear();
}
bool cameraPreview::HImage2QImage(HalconCpp::HImage &from, QImage &to)
{ 
    return true;
}
