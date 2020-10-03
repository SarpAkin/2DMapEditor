#include <iostream>
#include <filesystem>
#include <string>
int main()
{
    #if 0
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();
	return 0;
    #endif
	for(auto& file : std::filesystem::directory_iterator("src"))
    {
        std::cout << file.path().string() << std::endl;
    }
}