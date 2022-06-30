#include <Filter.h>

Filter::Filter(std::vector<float> s,TypeFilter type,int windowSize):sig(s),type(type),windowSize(windowSize)
{}
Filter::~Filter()
{

}
std::vector<float> Filter::filtration()
{
    std::vector<float> fSig;
    if(type==NONREC)
    {
        float buf[sig.size()];
        float sum=0;
        for(int i=0;i<windowSize;i++)
            {
                sum+=sig[i];
                buf[i]=sum/(i+1);
            }
        for (int i=windowSize; i<sig.size(); i++)
            {
                sum-=sig[i-windowSize];
                sum+=sig[i];
                buf[i]=sum/windowSize;
            }
        for (int i=0; i<sig.size(); i++)
            fSig.push_back(buf[i]);

    }
    else
    {

    }
    return fSig;
}
