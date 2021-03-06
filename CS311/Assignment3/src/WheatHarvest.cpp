/*
File Name: WheatHarvest.cpp
Author: Austin Major
Student ID: N675Q967
Assignment Number: 3
*/

//Source & Function Logic???
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include "Ticket.h"

int main()
{
	double inputGrossWeight, inputTareWeight, inputMoistureLevel, inputForeignMaterial;
	std::vector<Ticket> tickets;
	double netBushels = 0, grossBushels = 0;
	bool duplicate = false;

	while (true) {
		//Flush cin buffer if not first entry
		if (tickets.size() > 0) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::string ticketNumber;

		std::cout << "Ticket Number " << tickets.size() + 1 <<  " (alphanumeric): ";
		std::getline(std::cin, ticketNumber);

		if (ticketNumber == "") {
			break;
		}

		std::cout << "Gross weight (lbs): ";
		std::cin >> inputGrossWeight;

		std::cout << "Tare weight (lbs): ";
		std::cin >> inputTareWeight;

		std::cout << "Moisture level (%): ";
		std::cin >> inputMoistureLevel;

		std::cout << "Foreign material (%): ";
		std::cin >> inputForeignMaterial;

		Ticket myTicket(ticketNumber, inputGrossWeight, inputTareWeight, inputMoistureLevel, inputForeignMaterial);

		//compares tickets via for loop and returns error if duplicate
		if (tickets.size() > 0) {
			duplicate = false;
			for (unsigned int i = 0; i < tickets.size(); i++) {
				if (tickets[i] == myTicket) {
					duplicate = true;
					break;
				}
			}
		}
		if (duplicate) {
			std::cout << std::endl << "Error: Duplicate ticket encourntered, ticket ignored!" << std::endl;
		} else {
			tickets.push_back(myTicket);
		}
		
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for(unsigned int i = 0; i < tickets.size(); i++) {
		grossBushels += tickets[i].calculateGrossBushels();
		netBushels += tickets[i].calculateNetBushels();

		std::cout << tickets[i] << std::endl;
	}

	std::cout.precision(2);
	std::cout << std::fixed << "Wheat Harvest Summary Totals" << std::endl;
	std::cout << "\t" << grossBushels << " Gross Bushels" << std::endl;
	std::cout << "\t" << netBushels << " Net Bushels" << std::endl;
}

//friend function	
std::ostream& operator<<(std::ostream &os, const Ticket &t) {
	os << t.toString();
	return os;
}