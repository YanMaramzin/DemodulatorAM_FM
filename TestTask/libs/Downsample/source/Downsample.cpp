#include "Downsample.h"

std::vector<float> downsample(std::vector<float> sig,int down)
{
    std::vector<float> downSig;
    for(int i=0;i<sig.size();i+=down)
        downSig.push_back(sig[i]);
    return downSig;
}
