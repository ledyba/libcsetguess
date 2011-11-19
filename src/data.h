/*
 * data.h
 *
 *  Created on: 2011/11/19
 *      Author: psi
 */

#ifndef DATA_H_
#define DATA_H_

#define VECTOR_SIZE (8)
#define CHR_SHIFT (5)
struct ENCODE_DIC{
		const double base;
		const unsigned char vector[VECTOR_SIZE][VECTOR_SIZE];
};

#define TARGET_ENCODINGS (4)
const struct ENCODE_DIC dictionary[TARGET_ENCODINGS];

#endif /* DATA_H_ */
