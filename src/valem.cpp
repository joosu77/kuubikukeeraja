#include "valem.h"

#include <iostream>

/**
 * Valemi võrdlusoperaator
 */
bool operator<(const valem& val1, const valem& val2){
	if (val1.rida.size() != val2.rida.size()){
		return val1.rida.size() < val2.rida.size();
	} else {
		return val1.toString() < val2.toString();
	}
}

valem& valem::operator=(const valem& val2){
	rida.empty();
	rida = val2.rida;
	return *this;
}

valem::valem(){
	//meelega tyhi
}

valem::valem(char kask, bool suund){
	append(kask, suund);
}

/**
 * Lisa valemi samm
 * @param kask -- käsusümbol
 * @param suund
 */
void valem::append(char kask, bool suund){
	rida.push_back(std::make_pair(kask,suund));
}

int valem::size() {
	return rida.size();
}

/**
 * Konstrueeri valem stringist
 */
valem::valem(std::string valemStr){
	append (valemStr);
}

/**
 * Konstrueeri valem stringist
 */
void valem::append(std::string valemStr){
	for(unsigned int i=0;i<valemStr.size();i++){
		if (valemStr[i] == 'U' || valemStr[i] == 'L' ||
				valemStr[i] == 'F' ||valemStr[i] == 'R' ||
				valemStr[i] == 'D' ||valemStr[i] == 'B'){
			if (i < valemStr.size()-1 && valemStr[i+1]=='*'){
				append(valemStr[i],false);
				i++;
			} else {
				append(valemStr[i],true);
			}
		}
	}
}

/**
 * Valem stringiks
 */
std::string valem::toString() const {
	std::string res {};
	for (unsigned int i=0;i<rida.size();i++){
		res += rida[i].first;
		res += (rida[i].second?' ':'*');
	}
	return res;
}

void valem::print(){
	std::cout << "Prindin valemit: " << toString() << "\n";
}

bool valem::operator==(const std::string &other) {
	return (toString() == other);
}

namespace std {
	template <>
	struct hash<valem>{
		std::size_t operator()(const valem& k) const{
		    using std::hash;

			return hash<string>()(k.toString());
		}
	};
}
