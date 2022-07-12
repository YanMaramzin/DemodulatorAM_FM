#include "FileManager.h"
#include "Filter.h"
#include "Downsample.h"
#include "Demodulator.h"
#include <cmath>
#include <algorithm>



int main()
{
       FileManager fileManager;
       std::vector<Complex<float>> signalAM=fileManager.ReadFile<int32_t>("../DemodulatorAmFm/AM.dat");
       std::vector<Complex<float>> signalFM=fileManager.ReadFile<float>("../DemodulatorAmFm/FM.bin");


       int bitDepth=16;
       //Работа АМ-демодулятора
       int fsAM=16000;
       DemodulatorAM AM;
       std::vector<float> demodAM=AM.Demodulate(signalAM);
       fileManager.SaveWAV(demodAM,"DemodAM.wav",fsAM,bitDepth);


       //Работа ЧМ-демодулятора
       int fsFM=500000;
       int frequencyReduction=5;
       DemodulatorFM FM;
       std::vector<float> demodFM=FM.Demodulate(signalFM);

       Downsampler dw;
       demodFM=dw.downsample(demodFM,frequencyReduction,20,fsFM);
       fileManager.SaveWAV(demodFM,"DemodFM.wav",fsFM/frequencyReduction,bitDepth);

       int windowSize=5;
       //Нерекурсивный фильтр
        FilterMovingAverageNonRec FiltNonRec;
        std::vector<float> filtSig=FiltNonRec.filtration(demodFM,windowSize);
       //Рекурсивный фильтр
        FilterMovingAverageRec FiltRec;
        std::vector<float> filtSig1=FiltRec.filtration(demodFM,windowSize);

        for(size_t i=0; i<50;i++)
            std::cout<<demodFM[i]<<" "<<filtSig[i]<<" "<<filtSig1[i]<<std::endl;

       return 0;
}
