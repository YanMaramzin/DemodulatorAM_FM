#include "FileManager.h"


fileManager::fileManager(const std::string &fileName):fileName(fileName)
{}
fileManager::~fileManager()
{}
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

void fileManager::SaveSignal(const std::vector<float>& savedSignal, const std::string& fileName)
{
    std::ofstream file(fileName,std::ios::binary);
    file.write((char*)&savedSignal,savedSignal.size());
    file.close();
}

void writeToFile(std::ofstream &file,int value,int size){
    file.write(reinterpret_cast<char*>(&value),size);
}
void fileManager::SaveWAV(const std::vector<float>& savedSignal, const std::string& fileName,const int sampleRate,const int bitDepth)
{
    std::ofstream file(fileName,std::ios::binary);
    //Header chunk
    file<<"RIFF";
    file<<"----";
    file<<"WAVE";

    //Format chunk
    file<<"fmt ";
    writeToFile(file,16,4);
    writeToFile(file,1,2);
    writeToFile(file,1,2);
    writeToFile(file,sampleRate,4);
    writeToFile(file,sampleRate*bitDepth/8,4);
    writeToFile(file,bitDepth/8,2);
    writeToFile(file,bitDepth,2);

    //Data chunk
    file<<"data";
    file<<"----";


    int preAudioPosition=file.tellp();
    auto maxAmplitude=pow(2,bitDepth-1)-1;
    for(size_t i=0;i<savedSignal.size();i++)
    {
     if(savedSignal[i])
     {
         int intSample=static_cast<int>(savedSignal[i]*maxAmplitude);
         writeToFile(file,intSample,2);
     }

    }
    int postAudioPosition=file.tellp();
    writeToFile(file,postAudioPosition-preAudioPosition,4);
    file.seekp(4,std::ios::beg);
    writeToFile(file,postAudioPosition-8,4);

}
