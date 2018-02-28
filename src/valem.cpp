#include "valem.h"

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
