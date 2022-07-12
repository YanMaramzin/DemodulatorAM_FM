#include "Downsample.h"


std::vector<float> Downsampler::downsample(std::vector<float> &in,int frequencyReductionFactor,int lengthFilter,float inpuSampleRate)
{
    std::vector<float> filtSig;
    std::vector<float> decimateSignal;
    filtSig.reserve(in.size());
    FilterLowPass filter(lengthFilter);
    filtSig=filter.filtration(in,inpuSampleRate,inpuSampleRate/frequencyReductionFactor,inpuSampleRate-inpuSampleRate/frequencyReductionFactor);
    decimateSignal.reserve(filtSig.size());


    for(int i=0;i<in.size();i+=frequencyReductionFactor)
        decimateSignal.push_back(filtSig[i]);
    return decimateSignal;
}
