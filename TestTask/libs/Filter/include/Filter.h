#ifndef FILTER_H
#define FILTER_H
#include <vector>


class Filter{
   public:
        virtual std::vector<float> filtration(std::vector<float> &in,int windowSize)=0;

};

class FilterMovingAverageNonRec: public Filter{
    public:
        std::vector<float> filtration(std::vector<float> &in,int windowSize) override;
};


class FilterMovingAverageRec: public Filter{
    public:
        std::vector<float> filtration(std::vector<float> &in,int windowSize) override;
};

class FilterLowPass{
    int lengthFilter;

    public:
    FilterLowPass(int lengthFilter);
    std::vector<float> filtration(std::vector<float> &in, float inpuSampleRate, float passFreq,float suppressFreq);
};

#endif // FILTER_H
