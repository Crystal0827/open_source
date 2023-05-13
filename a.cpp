#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main ()
{
     string pattern_jpg; 
     vector<cv::String> img_files;
      pattern_jpg = "/media/crystal/Data/Test_project/Example/*.jpg"; // “*” 代指这类图片的名称，其后跟图片格式。
     cv::glob(pattern_jpg,img_files); //  
   glob()函数是用来收集一个文件夹中某类图片的，第一个参数是将图片地址及格式输入一个string变量中；第二个参数是结果，即你所需要的图片。用此函数后只需按一次F5和多次任意键即可识别全部图片。
     for(int i = 0;i<img_files.size();i++)
     {
      if(img_files[i].empty())
      {
          cout<<"请确认是否输入正确";
      }
      
    Mat img1,img2,img3,img4,img5,result;
    img1 = imread(img_files[i]);
    medianBlur(img1,img2,11); //个人认为11较好；
    Rect c;
    floodFill(img2,Point(1,1),Scalar(0,0,0),&c,Scalar(25,25,25),Scalar(25,25,25),FLOODFILL_FIXED_RANGE); //第二个参数是漫水起始点，第三个参数是水的颜色；第四五个参数是决定谁被漫水，表示在起始点颜色前提下的上下的浮动范围；第六个自己查看官网，比较依赖于自己的需求。
    Mat struct1 = getStructuringElement(0,Size(7,7)); //从此开始都是基本操作，不过多解释。
    erode(img2,img3,struct1);
    dilate(img3,img4,struct1);
    Canny(img4,img5,250,350,3); 
    vector<vector<Point>>contours;
    findContours(img5,contours,0,3);
    for(int i = 0;i<contours.size();i++)
      {
        double area = contourArea(contours[i]);
        if(area>1200) /*面积过滤*/ {
              approxPolyDP(contours[i],result,8,true);
              RotatedRect rrect = minAreaRect(contours[i]);
              Point2f center = rrect.center;
              
              Rect rect = boundingRect(contours[i]);
              rectangle(img1,rect,Scalar(0,255,0),0.25,8,0);
              if(result.rows==3){
                putText(img1,"triangle",rect.tl(),0,0.5,Scalar(0,0,255),1,8);
              }
              if(result.rows==4){
                putText(img1,"rectangle",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==5){
                putText(img1,"poly-5",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==6){
                putText(img1,"poly-6",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==7){
                putText(img1,"poly-7",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==8){
                putText(img1,"poly-8",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==9){
                putText(img1,"poly-9",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==10){
                putText(img1,"poly-10",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==11){
                putText(img1,"poly-11",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              
        }
        if(area>400&&area<1200){
        approxPolyDP(contours[i],result,1.8,true);
        Rect rect = boundingRect(contours[i]);
              rectangle(img1,rect,Scalar(0,255,0),0.25,4,0);
              if(result.rows==3){
                putText(img1,"triangle",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==4){
                putText(img1,"rectangle",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==5){
                putText(img1,"poly-5",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==6){
                putText(img1,"poly-6",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==7){
                putText(img1,"poly-7",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==8){
                putText(img1,"poly-8",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==9){
                putText(img1,"poly-9",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==10){
                putText(img1,"poly-10",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
              if(result.rows==11){
                putText(img1,"poly-11",rect.tl(),0,1,Scalar(0,0,255),1,8);
              }
      }
      }
      
      imshow("show1",img1
      );
      waitKey(0);
       
     }
     return 0;}
      
     
     
 
  

