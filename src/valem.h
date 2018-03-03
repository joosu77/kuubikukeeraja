/*
 * valem.h
 *
 *  Created on: Jan 5, 2018
 *      Author: joosep
 */

#include <string>
#include <utility>
#include <vector>

#ifndef VALEM_H
#define VALEM_H

class valem{
	public:

		// valemi sammud paaridena
		// * esimen eelement on täht hulgast TODO: pane hulk
		// * teine element on suund TODO: kirjuta, mida true tähendab
		std::vector <std::pair <char, bool> > rida;

		// valemiobjekt stringist mis koosneb pöördeid tähistatavate käskude jadast
		// ja tärnidest. Muid sümboleid ognoreeritakse
		valem(std::string);
		// tühi valem
		valem();
		// valem ühe käsuga
		valem(char kask, bool suund);
		// lisa valemile käsk
		void append(char kask, bool suund);
		// lisa valemile kõik stringis olevad käsud
		void append(std::string valemStr);
		// trüki valem standardväljundisse
		void print();
		// trüki valem stringi
		std::string toString() const;
		// sammude arv valemis
		int size();
		// võrdle valemit teisega
		bool operator==(const std::string &other);
		// kopeeri teise valemi sisu siia
		valem &operator=(const valem&);
};

bool operator<(const valem& val1, const valem& val2);

#endif /* VALEM_H_ */
