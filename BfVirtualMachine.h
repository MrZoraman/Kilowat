#pragma once

#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>

/*
	This is the "virtual machine". It keeps track of the cells, the cell pointer.
	The instruction pointer is kept track in the execute() method.
*/
class BfVirtualMachine
{
private:
	//This is the cell pointer
	int _cellPtr = 0;
	//These are the cells. As per "specification", there are (at least) 30,000 of them.
	unsigned char _cells[30000] = { 0 };
	//This is the stack of locations the pointer needs to return to. Each left bracket
	//means a loop is starting, so the vm puts the location right before the start of the
	//loop on this stack, so when the end of the loop is reached, the instruction pointer
	//can go back to the beginning of the loop to re-analyze if the loop needs to be run
	//again.
	std::stack<std::vector<int>::size_type> _instPtrRet;
public:
	BfVirtualMachine();
	~BfVirtualMachine();
	//Runs the BF code.
	void execute(std::vector<char>&);
};

