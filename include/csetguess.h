/*
 * csetguess.h
 *
 *  Created on: 2011/11/19
 *      Author: psi
 */

#ifndef CSETGUESS_H_
#define CSETGUESS_H_

enum CSET_GUESS_CHARSETS {
	UNKNWON=-1,
	SJIS=0,
	Shift_JIS=0,
	EUC=1,
	EUC_JP=1,
	JIS=2,
	ISO_2022_JP=2,
	UTF8=3,
};

enum CSET_GUESS_CHARSETS cset_guess(const unsigned char* data, unsigned int len);

#endif /* CSETGUESS_H_ */
