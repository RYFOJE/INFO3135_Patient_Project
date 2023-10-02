﻿#pragma once
#include "Ailment.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

class Patient
{
	std::string name_;
	LinkedList<Ailment> ailments_;

public:
	
	Patient(std::string name);

	void add_ailment(Ailment ailment);

	// Getters
	const std::string get_name() const;

};
