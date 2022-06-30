#include <Filter.h>

Filter::Filter(std::vector<float> s,TypeFilter type,int windowSize):sig(s),type(type),windowSize(windowSize)
{}
std::vector<float> Filter::filtration()
{
    std::vector<float> fSig;
    if(type==NONREC)
    {

        for(int i=0;i<sig.size();i++)
            {
                fSig[i]=(sig[i])/windowSize;
            }
    }
    else
    {

    }
    return fSig;
}
