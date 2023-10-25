#pragma once
#include "Ailment.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

class Patient
{
	std::string name_;
	LinkedList<Ailment> ailments_;
	score_t score_;

public:
	
	/* Constructors */
	Patient(std::string name);

	/* Methods */

	void add_ailment(Ailment ailment);

	// Getters
	const std::string get_name() const;
	LinkedList<Ailment> get_ailments();
	const score_t get_score() const;


	/* Operators */
	auto operator==(const Patient& other) const {
		return (score_ == other.get_score());
	}
	auto operator>(const Patient& other) const {
		return (score_ > other.get_score());
	}
	auto operator<(const Patient& other) const {
		return (score_ < other.get_score());
	}

};

