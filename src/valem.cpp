#include "valem.h"

#include <cstddef>
#include <iostream>
#include <unordered_map>

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

valem::valem(char kylg, bool suund){
	append(kylg, suund);
}

/**
 * Lisa valemi samm
 * @param kask -- käsusümbol
 * @param suund
 */
void valem::append(char kylg, bool suund){
	rida.push_back(*(new kask {kylg, suund}));
}

/**
 * Lisa valemi samm
 * @param kask -- käsusümbol
 * @param suund
 */
void valem::append(kask k){
	rida.push_back(k);
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
		res += rida[i].toString();
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

	template <>
	struct hash<kask>{
		std::size_t operator()(const kask& k) const{
		    using std::hash;

			return hash<string>()(k.toString());
		}
	};
}

//---------------- Käsk ----------------------------------------

kask::kask(char k, bool e) {
	kylg = k;
	edasi = e;
}

kask::kask(char k) {
	kylg = k;
	edasi = true;
}

bool kask::operator==(const kask &other) {
	return (kylg == other.kylg && edasi == other.edasi);
}

std::string kask::toString() const {
	std::string res {kylg};
	res += (edasi ? ' ' : '*');
	return res;
}
