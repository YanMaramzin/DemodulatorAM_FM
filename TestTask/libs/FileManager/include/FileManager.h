#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Complex.h"
#include <string>
#include <vector>


class fileManager {
    public:
    fileManager(const std::string &fileName);
    ~fileManager();

    std::vector<Complex<float>> ReadFile();
    void SaveSignal(const std::vector<float>& savedSignal, const std::string& fileName);
    void SaveWAV(const std::vector<float>& savedSignal, const std::string& fileName, const int sampleRate,const int bitDepht);

    private:
    std::string fileName;
};


#endif // FILEMANAGER_H
