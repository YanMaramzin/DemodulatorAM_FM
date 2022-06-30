#include "Demodulator.h"

demodulator::demodulator(const std::vector<Complex<float>> sig,Modulation s):sig(sig),mod(s)
{}
std::vector<float> demodulator::demodulate(){
    std::vector<float> demodSignal;
    if(mod==AM)
    {
        for(size_t i=0;i<sig.size();i++)
            demodSignal[i]=sig[i].abs();

    }
    else {
         float A;
         float B;
         for(size_t i=0;i<sig.size()-1;i++)
         {
           A=sig[i+1].real()-sig[i].real();
           B=sig[i+1].imag()-sig[i].imag();

           demodSignal[i]=(B*sig[i].real()-A*sig[i].imag())/(sig[i].abs()*sig[i].abs());
         }

    }
        return demodSignal;
}
