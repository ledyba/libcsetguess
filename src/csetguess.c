/*
 * csetguess.c
 *
 *  Created on: 2011/11/19
 *      Author: psi
 */

#include <math.h>
#include "../include/csetguess.h"
#include "data.h"

#ifndef FALSE
#define FALSE (1!=0)
#endif

#ifndef TRUE
#define TRUE (1==1)
#endif

static int is_ascii(char c){
	return (c >= 0x20 && c <= 0x7e) || c == 0x09 || c == 0x0a || c == 0x0c || c == 0x0d;
}

enum CSET_GUESS_CHARSETS cset_guess(const unsigned char* data, unsigned int len){
	enum CSET_GUESS_CHARSETS answer = UNKNWON;
	unsigned int charCount = 0;
	int i,j;
	double score[TARGET_ENCODINGS];
	double max_score = 0;
	int lastAscii;

	if(len <= 0){
		return answer;
	}

	for(i=0;i<TARGET_ENCODINGS;i++){
		score[i] = 0;
	}

	lastAscii = is_ascii(data[0]);
	for(i=1;i<len;i++){
		int nowAscii = is_ascii(data[i]);
		if(!(lastAscii && nowAscii)){
			int nonZero = FALSE;
			for(j=0;j<TARGET_ENCODINGS;j++){
				const struct ENCODE_DIC *dic = &dictionary[j];
				unsigned char vdat =dic->vector[data[i-1]][data[i]];
				if(vdat != 0){
					score[j] += pow(dic->base, vdat);
					nonZero |= TRUE;
				}
			}
			if(nonZero){
				charCount++;
				if(charCount >= 100){
					goto ret;
				}
			}
		}
		lastAscii = nowAscii;
	}
	ret:
	for(i=0;i<TARGET_ENCODINGS;i++){
		if(max_score < score[i]){
			max_score = score[i];
			answer = i;
		}
	}
	return answer;
}
