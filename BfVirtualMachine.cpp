#include "BfVirtualMachine.h"



BfVirtualMachine::BfVirtualMachine()
{
}


BfVirtualMachine::~BfVirtualMachine()
{
}

void BfVirtualMachine::execute(std::vector<char>& commands)
{
	//The instruction pointer is made. Starts at zero and goes to the end of the program.
	//That is, unless there are loops, which will move the instruction pointer around as well.
	for (std::vector<char>::size_type instrPtr = 0; instrPtr < commands.size(); instrPtr++)
	{
		switch (commands[instrPtr])
		{
		case '>':
			_cellPtr++;	//incrememnt cell pointer
			break;
		case '<':
			_cellPtr--;	//decriment cell pointer
			break;
		case '+':
			_cells[_cellPtr]++;	//increment number at cell pointer
			break;
		case '-':
			_cells[_cellPtr]--; //decriment number at cell pointer
			break;
		case '.':
			std::cout << _cells[_cellPtr];	//output value at cell pointer
			break;
		case ',':	//read char from standard input into value at cell pointer.
			char in;
			scanf_s(" %c", &in);
			_cells[_cellPtr] = in;
			break;
		case '[':	//Loop is starting
			if (_cells[_cellPtr] == 0)	//analyze the value at the cell pointer. If it is zero, do not execute the loop contents.
			{
				//We are not executing, so we have to get to the closing bracket before we start executing again.
				int deep = 1;	//Deep is how many brackets deep we are. This is so every opening bracket is paired with a closing
								//bracket so the code doesn't start getting executed too soon.
								//One left bracket has already been found, so this starts at 1.

				while (deep > 0)//move the instruction pointer until we are out of the bracket scope that we determined the contents'
								//should not be executed.
				{
					instrPtr++;
					switch (commands[instrPtr])
					{
					case '[':
						deep++;
						break;
					case ']':
						deep--;
					}
				}
			}
			else
			{
				//We are executing the contents of this loop, so we push the original location of the instruction pointer on the stack
				//so it can go back once it hits the cooresponding closing bracket.
				_instPtrRet.push(instrPtr);
			}
			break;
		case ']':
			//Move the instruction pointer to the location of the cooresponding opening bracket.
			instrPtr = _instPtrRet.top();
			//remove location from stack
			_instPtrRet.pop();
			//move the instruction pointer back one, so the next time around the big loop it will analyze the "loop condition" again.
			//(see line 43)
			instrPtr--;
		}
	}
}
