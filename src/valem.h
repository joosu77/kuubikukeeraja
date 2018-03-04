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

class kask {
public:
	// millist külge keerata "ULFRDB"
	char kylg;
	// kui true, siis edasi, muidu tagasi
	bool edasi;

	kask(char k);
	kask(char k, bool e);
	// võrdle käsku teisega
	bool operator==(const kask &other);
	// trüki käsk stringi
	std::string toString() const;
};

class valem {
	public:

		// valemiobjekt stringist mis koosneb pöördeid tähistatavate käskude jadast
		// ja tärnidest. Muid sümboleid ognoreeritakse
		valem(const std::string& valemStr);
		// tühi valem
		valem();
		// valem ühe käsuga
		valem(char kylg, bool suund);
		// lisa valemile käsk
		void append(char kylg, bool suund);
		// lisa valemile kõik stringis olevad käsud
		void append(const std::string &valemStr);
		// lisa valemile käsk
		void append(kask &k);
		// lisa valemile käsk
		void prepend(kask &k);
		// eemalda viimane käsk
		void remove_last();
		// tagasta käsk ideksiga idx
		// kui indeks on negatiivne, siis tagastatakse lõpust
		kask& get(int idx);
		// kontrollib, kas valemis on mõni käsk
		bool tyhi() const;
		// trüki valem standardväljundisse
		void print();
		// trüki valem stringi
		std::string toString() const;
		// sammude arv valemis
		int size() const;
		// võrdle valemit teisega
		bool operator==(const std::string &other);
		// kopeeri teise valemi sisu siia
		valem &operator=(const valem&);
	private:
		// valemi sammud paaridena
		// * esimen eelement on täht hulgast TODO: pane hulk
		// * teine element on suund TODO: kirjuta, mida true tähendab
		std::vector<kask> rida;

};

bool operator<(const valem& val1, const valem& val2);

#endif /* VALEM_H_ */
