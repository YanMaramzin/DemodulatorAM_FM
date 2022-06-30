#include <FileManager.h>


int main()
{
    std::vector<Complex<float>> sig=fileManager::ReadFile("/home/yan/file1EuropaPlus.bin");
    for(size_t i=0;i<sig.size();i++)
        std::cout<<sig[i];
    return 0;
}
