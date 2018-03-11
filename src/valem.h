/*
 * valem.h
 *
 *  Created on: Jan 5, 2018
 *      Author: joosep
 */

#include <string>
#include <utility>
#include <vector>
#include <map>

#ifndef VALEM_H
#define VALEM_H

class kask {
public:
	// millist külge keerata "ULFRDB"
	char kylg;
	// kui true, siis edasi, muidu tagasi
	bool edasi;

	kask(char k);
	kask(char k, bool e);
	// võrdle käsku teisega
	bool operator==(const kask &other) const;
	// trüki käsk stringi
	std::string toString() const;
	//väljastab vastaskülje vastupidise pöörde
	kask vastandKask();
};

class valem {
	public:
		// valemi sammud paaridena
		// * esimen eelement on täht hulgast TODO: pane hulk
		// * teine element on suund TODO: kirjuta, mida true tähendab
		std::vector<kask> rida;

		// valemiobjekt stringist mis koosneb pöördeid tähistatavate käskude jadast
		// ja tärnidest. Muid sümboleid ognoreeritakse
		valem(std::string);
		// tühi valem
		valem();
		// valem ühe käsuga
		valem(char kylg, bool suund);
		// lisa valemile käsk
		void append(char kylg, bool suund);
		// lisa valemile kõik stringis olevad käsud
		void append(std::string valemStr);
		// lias valimile käsk
		void append(kask k);
		// trüki valem standardväljundisse
		void print();
		// trüki valem stringi
		std::string toString() const;
		// sammude arv valemis
		int size();
		// võrdle valemit teisega
		bool operator==(const std::string &other) const;
		bool operator<(const valem &other) const;
		// kopeeri teise valemi sisu siia
		valem &operator=(const valem&);
		// teeb valemist selle asendi lahenduse, kuhu algne valem viib
		void pooraYmber();
	private:


};

#endif /* VALEM_H_ */
