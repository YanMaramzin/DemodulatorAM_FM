#ifndef FILTER_H
#define FILTER_H

#include <vector>


class Filter{
   public:
        virtual std::vector<float> filtration(std::vector<float> &in,int windowSize)=0;
};

class FilterMovingAverageNonRec: public Filter{
    public:
        std::vector<float> filtration(std::vector<float> &in,int windowSize) override;
};


class FilterMovingAverageRec: public Filter{
    public:
        std::vector<float> filtration(std::vector<float> &in,int windowSize) override;
};


#endif // FILTER_H
