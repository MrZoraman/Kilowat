#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

/*
Step 1: Open the file
Step 2: Read the file's contents into memory
Step 3: Close the file
Step 4: Remove comments
Step 5: Load the code into another place in memory
Step 6: Delete original contents from memory
Step 7: Ready for consuming
*/


/*
This is the "PreProcessor." It strips the source file of all comments and newlines and puts the instructions into a vector.
*/
class PreProcessor
{
private:
	//The name of the file on the disk
	std::string _fileName;
	//The vector of commands, to be returned with getCommands()
	std::vector<char> _commands;
	//Removes comments from the source file
	void decommentize(std::vector<char>&, std::vector<char>&);
	//Checks if a char is a command or a comment
	bool isCommand(char);
public:
	PreProcessor(std::string);
	~PreProcessor();
	//Parses the source file
	void parse();
	//Gets the vector of commands
	std::vector<char>& getCommands();
};

