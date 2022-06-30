#ifndef DEMODULATOR_H
#define DEMODULATOR_H

#include "/media/sf_General/DemodulatorAM_FM/TestTask/libs/FileManager/include/FileManager.h"

enum Modulation{
    AM,
    FM
};

class demodulator{
    public:
        demodulator(std::vector<Complex<float>> sig,Modulation s);
        ~demodulator();
        std::vector<float> demodulate();
    private:
        Modulation mod;
        std::vector<Complex<float>> sig;
};

#endif // DEMODULATOR_H
