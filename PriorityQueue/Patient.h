#pragma once
#include "Ailment.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

class Patient
{
	std::string name_;
	LinkedList<Ailment> ailments_;
	Ailment::score_t score_;

public:
	
	/* Constructors */
	Patient(std::string name);

	/* Methods */

	void add_ailment(Ailment ailment);

	// Getters
	const std::string get_name() const;
	LinkedList<Ailment> get_ailments();
	const Ailment::score_t get_score() const;

};

