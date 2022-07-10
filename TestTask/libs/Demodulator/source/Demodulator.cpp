#include "Demodulator.h"
#include <algorithm>
#include <numeric>

std::vector<float> DemodulatorAM::Demodulate (std::vector<Complex<float>> &in) {

        std::vector<float> demodSignal;
        demodSignal.reserve(in.size());


        for(size_t i=0;i<in.size();i++)
           {
            demodSignal.push_back(in[i].abs());
           }

        auto max=*std::max_element(demodSignal.begin(),demodSignal.end());
        auto mean=std::accumulate(demodSignal.begin(),demodSignal.end(),0.0)/demodSignal.size();

        for(size_t i=0;i<in.size();i++)
        {
            demodSignal[i]-=mean;
            demodSignal[i]/=max;
        }
        return demodSignal;
}


std::vector<float> DemodulatorFM::Demodulate(std::vector<Complex<float>> &in){
    std::vector<float> demodSignal;
    demodSignal.reserve(in.size());
    float A,B,A1,B1,W;

        for(size_t i=0;i<in.size()-1;i++)
        {

          A=in[i].real();
          B=in[i].imag();
          A1=in[i+1].real()-in[i].real();
          B1=in[i+1].imag()-in[i].imag();
          W=(B1*A-A1*B)/(pow(A,2)+pow(B,2));
          demodSignal.push_back(W);
        }
        return demodSignal;
}

