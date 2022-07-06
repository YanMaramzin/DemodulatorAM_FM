#include "Demodulator.h"
#include <algorithm>

demodulator::demodulator(std::vector<Complex<float>> &sig):sig(sig)
{}
demodulator::~demodulator()
{}
std::vector<float> demodulator::demodulateAM(){
    std::vector<float> demodSignal;

        for(size_t i=0;i<sig.size();i++)
            demodSignal.push_back(sig[i].abs());
        float max=*std::max_element(demodSignal.begin(),demodSignal.end());
        for(size_t i=0;i<demodSignal.size();i++)
        {
            demodSignal[i]=demodSignal[i]/max;
        }

        return demodSignal;
}

std::vector<float> demodulator::demodulateFM()
{
    std::vector<float> demodSignal;
    float A,B,A1,B1,W;

    for(size_t i=0;i<sig.size()-1;i++)
    {

      A=sig[i].real();
      B=sig[i].imag();
      A1=sig[i+1].real()-sig[i].real();
      B1=sig[i+1].imag()-sig[i].imag();
      if(A || B)
        {
          W=(B1*A-A1*B)/(pow(A,2)+pow(B,2));
          demodSignal.push_back(W);
        }
      else
      {
          return demodSignal;
      }
    }
}
