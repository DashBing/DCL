//
// strlib.hpp
//
//         By DPFramework
//
//         Copyright (c) DashBing
//

/*
    This file is outdated, try using 'strplus. hpp'

	Warn: This file is dangrous

*/

#pragma once
#ifndef _INC_STRLIB
#define _INC_STRLIB

#include <string.h>
#include <ctype.h>

namespace strlib {
	namespace chletter {
		enum chletter_mode {upper, lower};
		char* upper(char *string) {
			int len;
			int tmp;
			char *rets;
			strcpy(rets, string);
			len = strlen(rets);
			for (int i = 0; i < len; i++) {
				if (isalpha(rets[i])) {
					tmp = toupper(rets[i]);
					rets[i] = (char)tmp;
				}
			}
			return(rets);
		}
		char* lower(char* string) {
			int len;
			int tmp;
			char* rets;
			strcpy(rets, string);
			len = strlen(rets);
			for (int i = 0; i < len; i++) {
				if (isalpha(rets[i])) {
					tmp = tolower(rets[i]);
					rets[i] = (char)tmp;
				}
			}
			return(rets);
		}
		char* chleter(char* string, enum chletter_mode mode){
			switch (mode){
			case 0:
				return(upper(string));
			case 1:
				return(lower(string));
			default:
				return(upper(string));
			}
		}
	}
	namespace stringcmp {
		bool stringcmp(char* stringA, char* stringB) {
			int lena;
			//int lenb;
			//int i;
			int n = 0;
			lena = strlen(stringA);
			//lenb = strlib::depends::string_h::strlen(stringB);
			if (lena == strlen(stringB)) {
				for (int i = 0; i < lena; i++) {
					if (stringA[i] == stringB[i]) {
						n++;
					}
				}
				if (n == lena) {
					return(true);
				}
				else {
					return(false);
				}
			}
			else {
				return(false);
			}
		}
	}
}

namespace std {
	using namespace strlib;
	using namespace strlib::stringcmp;
	using namespace strlib::chletter;
}

#endif
