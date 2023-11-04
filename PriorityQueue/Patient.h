#pragma once
#include "Ailment.h"
#include "LinkedList.h"
#include <string>
#include <iostream>


/**
 * @brief The Patient class will hold the data for each patient in the hospital
*/
class Patient
{
	std::string name_;
	LinkedList<Ailment> ailments_;
	score_t score_; // TODO - calculate score based on ailments only when adding to priority queue

public:
	
	/* Constructors */

	/**
	 * @brief		Creates a patient with a name
	 * @param name	The name of the patient
	 */
	Patient(std::string name);

	/* Methods */

	/**
	 * @brief			Adds an ailment to the patient and calculates the patient's new risk score
	 * @param ailment	The ailment to add
	 */
	void add_ailment(Ailment ailment);

	// GETTERS
	const std::string get_name() const;
	LinkedList<Ailment>& get_ailments();
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

