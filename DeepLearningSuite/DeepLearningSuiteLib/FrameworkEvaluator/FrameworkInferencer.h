//
// Created by frivas on 29/01/17.
//

#ifndef SAMPLERGENERATOR_FRAMEWORKEVALUATOR_H
#define SAMPLERGENERATOR_FRAMEWORKEVALUATOR_H

#include <cv.h>
#include <boost/shared_ptr.hpp>
#include <Common/Sample.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <algorithm>

class FrameworkInferencer{
public:
    FrameworkInferencer();
    ~   FrameworkInferencer();
    Sample detect(const cv::Mat& image);
    int getMeanDurationTime();
    virtual Sample detectImp(const cv::Mat& image) =0;

protected:
    std::string classNamesFile;

private:
    std::vector<long> durationVector;
};




typedef boost::shared_ptr<FrameworkInferencer> FrameworkInferencerPtr;


#endif //SAMPLERGENERATOR_FRAMEWORKEVALUATOR_H
