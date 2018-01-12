/*
 * asend.h
 *
 *  Created on: Jan 5, 2018
 *      Author: joosep
 */

#ifndef ASEND_H_
#define ASEND_H_

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
	bool operator==(const asend& other);
};

#endif /* ASEND_H_ */
