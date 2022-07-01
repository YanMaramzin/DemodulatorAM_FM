#include "FileManager.h"

std::vector<Complex<float>> fileManager::ReadFile(const std::string &fileName)
{
    std::ifstream file(fileName,std::ios::binary);
    std::vector<float> buff;
    std::vector<Complex<float>> sig;

    if(!file.is_open())
    {
        std::cout<<"Error"<<std::endl;
    }
    else
    {
        float tmp;
        for(size_t i=0;file.read((char*)&tmp,sizeof(tmp));i++)
        {
            buff.push_back(tmp);
        }

        for(size_t i=0;i<buff.size()-1;i++)
        {
            Complex<float> b(buff[i],buff[i+1]);
            sig.push_back(b);
        }


    }
    file.close();

    return sig;
}

void fileManager::SaveSignal(const std::vector<Complex<float>>& savedSignal, const std::string& fileName)
{
    std::ofstream file(fileName,std::ios::binary);
    for(size_t i=0;file.write((char*)&savedSignal[i],sizeof(float));i++)
    {}
    file.close();
}
