#include "valem.h"

#include <iostream>

/**
 * Valemi võrldusoperaator
 */
bool operator<(const valem& val1, const valem& val2){
	if (val1.rida.size() != val2.rida.size()){
		return val1.rida.size() < val2.rida.size();
	} else {
		int sum1=0;
		int sum2=0;
		for (unsigned int i=0;i<val1.rida.size();i++){
			sum1 *= 12;
			sum2 *= 12;
			std::string poorded = "ULFRDB";
			sum1 += poorded.find(val1.rida[i].first);
			sum1 += (val1.rida[i].second)?(0):(6);
			sum2 += poorded.find(val2.rida[i].first);
			sum2 += (val2.rida[i].second)?(0):(6);
		}
		return sum1 < sum2;
	}
}

valem::valem(){
	//meelega tyhi
}

valem::valem(std::string valemStr){
	for(int i=0;i<valemStr.size();i++){
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

std::string valem::toString(){
	std::string res {};
	for (int i=0;i<rida.size();i++){
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
