#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Complex.h"
#include <string>
#include <vector>

namespace fileManager {

   std::vector<Complex<float>> ReadFile(const std::string &fileName);
   void SaveSignal(const std::vector<Complex<float>>& savedSignal, const std::string& fileName);
}


#endif // FILEMANAGER_H
