#include <Filter.h>
#include <algorithm>
#include <cmath>

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
    filtSig.push_back(in[0]/windowSize);
    for(int i=1; i<in.size();i++)
    {
        if(i<windowSize)
        filtSig.push_back(filtSig[i-1]+in[i]/windowSize);
        else
        filtSig.push_back(filtSig[i-1]+(in[i]-in[i-windowSize])/windowSize);
    }
    return filtSig;
}

FilterLowPass::FilterLowPass(int lengthFilter):lengthFilter(lengthFilter){}

std::vector<float> FilterLowPass::filtration(std::vector<float> &in, float inpuSampleRate, float passFreq, float suppressFreq)
{
    std::vector<float> filtSig(in.size());
    filtSig.reserve(in.size());
    float * H  = new float [lengthFilter]; //Импульсная характеристика фильтра
    float * H_id  = new float [lengthFilter];; //Идеальная импульсная характеристика
    float * W  = new float [lengthFilter]; //Весовая функция

    //Расчет импульсной характеристики фильтра
    float Fc = (passFreq + suppressFreq) / (2 * inpuSampleRate);

    for (int i=0;i<lengthFilter;i++)
    {
        if (i==0) H_id[i] = 2*M_PI*Fc;
        else H_id[i] = sinl(2*M_PI*Fc*i )/(M_PI*i);
       // весовая функция Блекмена
        W [i] = 0.42 + 0.5 * cosl((2*M_PI*i) /( lengthFilter-1)) + 0.08 * cosl((4*M_PI*i) /( lengthFilter-1));
        H [i] = H_id[i] * W[i];
    }

    //Нормировка импульсной характеристики
    float SUM=0;
    for (int i=0; i<lengthFilter; i++) SUM +=H[i];
    for (int i=0; i<lengthFilter; i++) H[i]/=SUM;

    //Фильтрация входных данных
    for (int i=0; i<in.size(); i++)
    {

        for (int j=0; j<lengthFilter-1; j++)
        if(i-j>=0)
        filtSig[i]+= H[j]*in[i-j];
    }
    delete [] H;
    delete [] H_id;
    delete [] W;

    return filtSig;
}
