#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Complex.h"
#include <string>
#include <vector>



class FileManager {
    public:
    template<typename T>
    std::vector<Complex<float>> ReadFile(const std::string &fileName)
    {
        std::ifstream file(fileName,std::ios::binary);
        std::vector<Complex<float>> sig;

        if(!file.is_open())
        {
            std::cout<<"Error"<<std::endl;
        }
        else
        {

            file.seekg (0, file.end);

            int length = file.tellg();

            sig.reserve(length/(2*sizeof (T)));
            file.seekg (0, file.beg);
            T * buffer = new T [length];
            // read data as a block:
            file.read ((char *)buffer,length);
            for(size_t i=0;i<length/sizeof(T);i+=2)
             {
                Complex<float> tmp(buffer[i],buffer[i+1]);
                sig.push_back(tmp);
             }
            file.close();

            delete[] buffer;
        }
        return sig;
    }
    void SaveSignal(const std::vector<Complex<float>>& savedSignal, const std::string& fileName);
    void SaveWAV(const std::vector<float>& savedSignal, const std::string& fileName, const int sampleRate,const int bitDepht);


};


#endif // FILEMANAGER_H
