#include <Filter.h>
#include <algorithm>

Filter::Filter(std::vector<float> s,TypeFilter type,int windowSize):sig(s),type(type),windowSize(windowSize)
{}
Filter::~Filter()
{

}


std::vector<float> Filter::filtration()
{
      std::vector<float> fSig(sig.size(),0.0);
      float sum = 0;
      for ( int i = 0; i < sig.size(); i++ )
        {
           sum += sig[i];
           if ( i >= windowSize ) sum -= sig[i-windowSize];
           fSig[i] = sum / std::min( i + 1, windowSize );
         }
      return fSig;


//    float buf[sig.size()];
//    float sum=0;
//    std::vector<float> fSig;
//    if(type==REC)
//    {
//        for(int i=0;i<windowSize;i++)
//            {
//                sum+=sig[i];
//                buf[i]=sum/(i+1);
//            }
//        for (int i=windowSize; i<sig.size(); i++)
//            {
//                sum=sig[i-windowSize];
//                sum+=sig[i];
//                buf[i]=sum/windowSize;
//            }
//        for (int i=0; i<sig.size(); i++)
//            fSig.push_back(buf[i]);


//    }
//    else
//    {
//        for(int i=0;i<windowSize;i++)
//            {
//                sum+=sig[i];
//                buf[i]=sum/(i+1);
//            }
//        for (int i=windowSize; i<sig.size(); i++)
//            {
//                sum+=(sig[i]-sig[i-windowSize]);
//                buf[i]=sum/windowSize;
//            }
//        for (int i=0; i<sig.size(); i++)
//            fSig.push_back(buf[i]);
//      }

}
