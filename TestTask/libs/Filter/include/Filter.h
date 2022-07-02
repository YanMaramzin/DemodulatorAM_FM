#ifndef FILTER_H
#define FILTER_H

#include <vector>

enum TypeFilter{
    REC,
    NONREC
};

class Filter{
   public:
        Filter(std::vector<float> s,TypeFilter type,int windowSize);
        ~Filter();
        std::vector<float> filtration();
   private:
        TypeFilter type;
        std::vector<float> sig;
        const int windowSize;
};

#endif // FILTER_H
