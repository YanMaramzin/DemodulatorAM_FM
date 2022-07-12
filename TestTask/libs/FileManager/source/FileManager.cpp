#include "FileManager.h"



void FileManager::SaveSignal(const std::vector<Complex<float>>& savedSignal, const std::string& fileName)
{
    std::ofstream file(fileName,std::ios::binary);

    for(size_t i=0;i<savedSignal.size();i++)
        file.write((char*)&savedSignal[i],sizeof(Complex<float>));
    file.close();
}

void FileManager::writeToFile(std::ofstream &file,int value,int size){
    file.write(reinterpret_cast<char*>(&value),size);
}
void FileManager::SaveWAV(const std::vector<float>& savedSignal, const std::string& fileName,const int sampleRate,const int bitDepth)
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
         int intSample=static_cast<int>(savedSignal[i]*maxAmplitude);
         writeToFile(file,intSample,2);
    }
    int postAudioPosition=file.tellp();
    writeToFile(file,postAudioPosition-preAudioPosition,4);
    file.seekp(4,std::ios::beg);
    writeToFile(file,postAudioPosition-8,4);

}
