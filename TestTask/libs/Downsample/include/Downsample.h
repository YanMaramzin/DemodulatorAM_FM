#ifndef DOWNSAMPLE_H
#define DOWNSAMPLE_H
#include <vector>
#include <math.h>
#include "../../Filter/include/Filter.h"


class Downsampler{

    public:
        std::vector<float> downsample(std::vector<float> &in,int frequencyReductionFactor, int lengthFilter,float inpuSampleRate);
};

#endif // DOWNSAMPLE_H



















