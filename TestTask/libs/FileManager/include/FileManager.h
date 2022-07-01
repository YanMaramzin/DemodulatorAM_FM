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
    void SaveSignal(const std::vector<Complex<float>>& savedSignal, const std::string& fileName);

    private:
    std::string fileName;
};


#endif // FILEMANAGER_H
