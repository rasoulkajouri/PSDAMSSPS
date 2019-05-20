#include "../include/masterHeader.h"
#include "../include/masterStructure.h"
#include "../include/functions.h"

void message(int x){
  switch(x){ 
    case 0:
      std::cout << std::string((100), '-') << '\n';
      std::cout << " This code simulates a dry active matter system of self-propelled swimmers.\n"<<
									 " This code has written by Rasoul Kajouri,\n"<<
									 " I'm eager to see your suggestions and notes about this Code,\n"<<
									 " You can contact me by rasoulkajouri[at]gmail.com,\n"<<
									 " \u00A9 Copyleft, All lefts reserved.\n"<<
									 " Thank you so much :)\n";
      std::cout << std::string((100), '-') << '\n';
      break;
		case 1:
			std::cout << std::string((100), '-') << '\n';
			std::cout << " Enetr your initial velues at the follwing:\n";
			break;
		case 2:
			std::cout << std::string((100),'-') << '\n';
			std::cout << " Code is searching the \'primaryValues\' file, the file's name must be without format sign.\n"
								<< " Also, you should put the file into \'input\' directory.\n"
								<< " you must put the collection of values as the following pattern\n"
								<< " 1. Number of swimmer\n 2. Length\n 3. Width\n 4. Time series [for instance: 5000 sec]\n"
								<< " 5. Noise Sterngth\n 6. Coupling Strength\n 7. Time step [for instance: 0.1 sec]\n"
								<< " 8. Mean of the frequence distro.\n"
								<< " 9. variance of the frequence dirstro. [the type distro. is Gaussian]\n" 
								<< " 10. Orientation interaction radius\n 11. Phase interaction radius\n"
								<< " 12. View field of swimmers\n 13. epsilon\n 14. speed of swimmers\n";
			break;
		case 3:
			std::cout << " You did not insert the third argument to choose the mechanism of initialization!\n"
								<< " Therefore, we have to begin again. for more info. read the tutorial.\n";
			std::cout << std::string((100),'-') << std::endl;
			break;
		case 4:
			std::cout << std::string((100),'^') << std::endl;
			std::cout << " Hello MPI ?   Fatal Error!!!\n"
								<< " MPI_Init returened Nonzero value to machine !!!\n"
								<< " Are you sure MPICH package is installed ?\n";
			break;
		case 5:
			std::cout << std::string((100),'-') << std::endl;
			std::cout << " The code is priting the order parameter's values into \"output\" directory.\n";
			break;
		case 6:
			std::cout << std::string((100),'-') << std::endl;
			std::cout << " The code is calculating the suscebility of order parameter.\n";
			break;
		case 7:
			std::cout << std::string((100), '-') << std::endl;
			std::cout << " The code is writing the swimmers positions into \'position.xyz\' file" << std::endl;
			break;
		case 8:
			std::cout << std::string((100), '-') << std::endl;
			std::cout << " The whole of the inserted initial values has written on a text file into \'output\' directory.\n";
			break;
    }
  }
