#include "valem.h"

#include <iostream>

/**
 * Valemi võrldusoperaator
 */
bool operator<(const valem& val1, const valem& val2){
	if (val1.rida.size() != val2.rida.size()){
		return val1.rida.size() < val2.rida.size();
	} else {
		return val1.toString() < val2.toString();
	}
}

valem::valem(){
	//meelega tyhi
}

/**
 * Konstrueeri valem stringist
 */
valem::valem(std::string valemStr){
	for(unsigned int i=0;i<valemStr.size();i++){
		if (valemStr[i] == 'U' || valemStr[i] == 'L' ||
				valemStr[i] == 'F' ||valemStr[i] == 'R' ||
				valemStr[i] == 'D' ||valemStr[i] == 'B'){
			if (i < valemStr.size()-1 && valemStr[i+1]=='*'){
				rida.push_back(std::make_pair(valemStr[i],false));
				i++;
			} else {
				rida.push_back(std::make_pair(valemStr[i],true));
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
