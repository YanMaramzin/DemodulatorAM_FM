#include "FileManager.h"

fileManager::fileManager(const std::string &fileName):fileName(fileName)
{

}
fileManager::~fileManager(){}
std::vector<Complex<float>> fileManager::ReadFile()
{
    std::ifstream file(fileName,std::ios::binary);
    std::vector<Complex<float>> sig;

    if(!file.is_open())
    {
        std::cout<<"Error"<<std::endl;
    }
    else
    {
          file.seekg(0,file.end);
          int lenght=file.tellg();
          float * buff=new float [lenght];

          file.seekg(0,file.beg);
          file.read((char *)buff,lenght);
          for(size_t i=0;i<lenght-2;i+=2)
          {
              Complex<float> tmp(buff[i],buff[i+1]);
              sig.push_back(tmp);
          }

          file.close();
          delete [] buff;
    }


    return sig;
}

void fileManager::SaveSignal(const std::vector<Complex<float>>& savedSignal, const std::string& fileName)
{
    std::ofstream file(fileName,std::ios::binary);
    file.write((char*)&savedSignal,savedSignal.size());
    file.close();
}
