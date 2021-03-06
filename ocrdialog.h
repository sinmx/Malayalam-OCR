#ifndef OCRDIALOG_H
#define OCRDIALOG_H

#include <QDialog>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/ml.hpp>

#include <vector>

#include "contourwithdata.h"

namespace Ui {
class OCRDialog;
}

class OCRDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OCRDialog(QWidget *parent = 0,
                       cv::Mat classificationNumbers = 0,
                       cv::Mat trainingImagesAsFlattenedFloats = 0,
                       int minContourArea = 100,
                       int imageWidth = 20,
                       int imageHeight = 30);
    ~OCRDialog();

private:
    Ui::OCRDialog *ui;
    cv::Mat image;
    cv::Mat classificationNumbers, trainingImagesAsFlattenedFloats;

    int minContourArea;
    int imageWidth;
    int imageHeight;

    std::vector<ContourWithData> allContoursWithData;
    std::vector<ContourWithData> validContoursWithData;
    std::vector<std::vector<cv::Point>> ptContours;
    std::vector<cv::Vec4i> v4iHierarchy;
    std::string strFinalStringNumbers;

    // Ptr array for KNearest machine learning algorithm
    cv::Ptr<cv::ml::KNearest> kNearest(cv::ml::KNearest::create());
};

#endif // OCRDIALOG_H
