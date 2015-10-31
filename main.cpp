#include <iostream>
#include <string>

#include "PreProcessor.h"
#include "BfVirtualMachine.h"

int main(int argc, char** argv)
{
	//make sure a filename was passed in
	if (argc < 2)
	{
		std::cerr << "Not enough arguments!" << std::endl;
		std::cin.get();
		return 1;
	}

	std::string fileName = argv[1];

	//make the preprocessor and have it do its thing
	PreProcessor preProcessor = PreProcessor(fileName);
	preProcessor.parse();

	//make the virtual machine and have it do its thing
	BfVirtualMachine vm = BfVirtualMachine();
	vm.execute(preProcessor.getCommands());

	//Let the user know that the execution is complete
	std::cout << std::endl << std::endl <<  "Execution complete." << std::endl;
	std::cout << std::endl;
	system("pause");//pause so I can see what happened in visual studio
	return 0;
}