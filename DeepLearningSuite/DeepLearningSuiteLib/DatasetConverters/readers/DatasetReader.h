//
// Created by frivas on 22/01/17.
//

#ifndef SAMPLERGENERATOR_DATASETREADER_H
#define SAMPLERGENERATOR_DATASETREADER_H

#include <string>
#include <Common/Sample.h>
#include <boost/shared_ptr.hpp>
#include <Common/EvalMatrix.h>

class DatasetReader {
public:
    DatasetReader();
    virtual bool getNextSample(Sample &sample);
    void filterSamplesByID(std::vector<std::string> filteredIDS);
    void overWriteClasses(const std::string& from, const std::string& to);
    int getNumberOfElements();
    void resetReaderCounter();
    bool getSampleBySampleID(Sample** sample, const std::string& sampleID);
    bool getSampleBySampleID(Sample** sample, const long long int sampleID);
    void printDatasetStats();
    virtual bool appendDataset(const std::string& datasetPath, const std::string& datasetPrefix="");
    void addSample(Sample sample);
    std::string getClassNamesFile();

protected:
    std::vector<Sample> samples;
    //std::string datasetPath;
    int readerCounter;
    std::string classNamesFile;
    std::vector<std::string> classNames;
};


typedef boost::shared_ptr<DatasetReader> DatasetReaderPtr;

#endif //SAMPLERGENERATOR_DATASETREADER_H
