/*
 * asend.h
 *
 *  Created on: Jan 5, 2018
 *      Author: joosep
 */

#ifndef ASEND_H_
#define ASEND_H_

#include <string>

class asend {
public:
	int kuljed[6][3][3];

	// algväärtusab asendi nii et igal küle ruudul
	// on vastava ruudu number
	asend();

	// teeb koopia kuubist other
	asend(asend *other);

	// koopiaga omistamine
	asend& operator=(const asend& other);

	// kahe asendi võrdlus
	bool operator==(const asend& other) const;

	// kahe asendi võrdlus
	bool operator<(const asend& other) const;

	//
	std::string toString() const;
};

namespace std {

	template <>
	struct hash<asend>{
		std::size_t operator()(const asend& k) const{
			std::size_t val = 0;
			int shift { 0 };
			for (int i = 0; i < 6; i++) {
				for (int o = 0; o < 3; o++) {
					for (int u = 0; u < 3; u++) {
						val = (val << shift) | k.kuljed[i][o][u];
						shift += 3;
					}
				}
			}

			return val;
		}
	};
}

#endif /* ASEND_H_ */
