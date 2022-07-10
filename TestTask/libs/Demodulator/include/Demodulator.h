#ifndef DEMODULATOR_H
#define DEMODULATOR_H

#include "/media/sf_General/DemodulatorAM_FM/TestTask/libs/FileManager/include/FileManager.h"
#include <memory>


//enum class Modulation{
//    AM,
//    FM
//};

class Demodulator {
public:
    virtual std::vector<float> Demodulate(std::vector<Complex<float>> &in) = 0;

//    class Factory {
//    public:
//        std::unique_ptr<Demodulator> Create(Modulation modulation);
//    };
};

// TODO: class DemodulatorAM
class DemodulatorAM: public Demodulator
{
    public:
        std::vector<float> Demodulate(std::vector<Complex<float>> &in) override;
};
// TODO: class DemodulatorFM
class DemodulatorFM: public Demodulator
{
    public:
        std::vector<float> Demodulate( std::vector<Complex<float>> &in) override;
};


#endif // DEMODULATOR_H
