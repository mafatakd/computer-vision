#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE TargetIdentification
#include "histogram.h"
#include <boost/test/unit_test.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
using namespace boost;

BOOST_AUTO_TEST_CASE(hist_test){
    vector<int> n;
    n.push_back(3);
    string telemetry_path=boost::unit_test::framework::master_test_suite().argv[2];
    string filePath=boost::unit_test::framework::master_test_suite().argv[1];
    ofstream fout(telemetry_path);
    fout<<"time,timeError,lat,lon,latError,lonError,pitch,roll,pitchRate,rollRate,yawRate,altitude,heading,altError,headingError,photonum"<<endl;
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<15;j++){
            fout<<j<<",";
        }
        fout<<i<<endl;
    }
    PictureImport* input=new PictureImport(telemetry_path,filePath,n);
    vector<Mat> result=histogram_recreator(input);
    for(int i=0;i<result.size();i++){
        namedWindow("display",WINDOW_NORMAL);
        resizeWindow("display", 1000, 1000);
        imshow("display",result.at(i));
        waitKey(0);
    }
}
