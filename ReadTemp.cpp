/*** 
 * @Author: Eureke
 * @Date: 2023-04-01 11:33:53
 * @LastEditTime: 2023-04-01 15:03:18
 * @Description: 读取DS18B20温度文件函数
 */
#include <string>
#include <iostream>
#include <fstream>

// opendir
#include <dirent.h>
#include <sys/types.h>

// regex
#include <regex>


void FindTempDevices() {
	// open devices directory
	// const char* dirname = "/sys/bus/w1/devices";
	// const char* dirname = "D:/Desktop/2_PGT/2 term/Big Data/lecture";
	const char* dirname = "D:/Desktop/2_PGT";
	
	DIR* dir = nullptr;
	if(!(dir = opendir(dirname))) {
		std::cerr << "Opendir error!\n";
	}
	dirent* subpath = nullptr;
	while ((subpath = readdir(dir))) {
		// std::cout << subpath->d_name << std::endl;
		// find DS18B20 directory
		std::string pattern("^28-.*$");
		std::regex reg(pattern);
		// match
		if (std::regex_match(subpath->d_name, reg)) {
			std::string filepath{static_cast<const std::string>(dirname) 
														+ '/' + static_cast<const std::string>(subpath->d_name)};
			std::cout << filepath << std::endl;
		} else {
			std::cerr << "Can't find DS18B20 device directory!\n";
		}
		
		
		
	}

	// const std::string fp{dirname};
	// std::ifstream finput(fp);
}

int main() {
	FindTempDevices();
	return 0;
}