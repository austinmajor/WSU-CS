/*
File Name: Output.h
Author: Austin Major
Student ID: N675Q967
Assignment Number: 5
*/

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Tickets.h"

class Output {
public:
	// Output list of tickets
	static void outputTickets(const Tickets& tickets);

	// Output summary of totals for list of tickets
	static void outputSummary(const Tickets& tickets);

private:
	// Default constructor (use private to prevent creation)
	Output();
};

#endif
