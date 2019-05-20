#include "../include/masterHeader.h"

void swimmer :: getBackValueClass(){
	std::cout << 
		" 1. Numbers of swimmers: " << num << '\n' <<
		" 2. Box's length: " << length << '\n' <<
		" 3. Box's width: " << width << '\n' <<
		" 4. System's noise strength: " << noiseStrength << '\n' <<
		" 5. System's coupling strength: " << couplingStrength << '\n'
		<< std::string((100),'-') << std::endl;
}
