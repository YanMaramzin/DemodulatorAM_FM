#include <Filter.h>
#include <algorithm>

std::vector<float> FilterMovingAverageNonRec::filtration(std::vector<float> &in,int windowSize){

    std::vector<float> filtSig;
    filtSig.reserve(in.size());
    float sum=0;
    for(int i=0; i<in.size();i++)
    {
        sum += in[i];
        if (i >= windowSize)
            sum -= in[i-windowSize];
        filtSig[i] = sum/windowSize;
    }
    return filtSig;
}

std::vector<float> FilterMovingAverageRec::filtration(std::vector<float> &in,int windowSize)
{
    std::vector<float> filtSig;
    filtSig.reserve(in.size());
    filtSig.push_back(filtSig[0]);
    for(int i=1; i<in.size();i++)
    {
        if(i<windowSize)
        filtSig.push_back(filtSig[i-1]+in[i]/windowSize);
        else
        filtSig.push_back(filtSig[i-1]+(in[i]-in[i-windowSize])/windowSize);
    }
    return filtSig;
}
