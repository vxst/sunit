/*
 * Copyright (C) 2016  Shan Ting <vxst@vxst.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sunit.h"
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <string>

using namespace std;

static char* title = NULL;
static FILE* logfile = NULL;
static map<string, double> probability;
static map<string, int> truth_count;
static map<string, int> all_count;

namespace sunit{
	void test_start(const char* name){
		title = new char[strlen(name)+1];
		strcpy(title, name);
		fprintf(stderr, "\e[0;32mStart Testing %s\e[0m\n", name);
	}

	void test_start_with_log(const char* name, const char* filename){
		title = new char[strlen(name)+1];
		logfile = fopen(filename, "a");
		strcpy(title, name);
		fprintf(stderr, "\e[0;32mStart Testing %s\e[0m\n", name);
	}

	void test_end(){
		for(auto i = probability.begin(); i!=probability.end(); i++){
			double result_probability = (double)truth_count[i->first]/(double)all_count[i->first];
			if(i->second > result_probability){
				fprintf(stderr, "\e[0;31mError Testing(likely) %s %s, %.2lf%% success rate less than %.2lf%%\e[0m\n",
						title, i->first.c_str(), result_probability * 100.0, i->second * 100.0);
				if(logfile)
					fprintf(logfile, "Error Testing(likely) %s %s, %.2lf%% success rate less than %.2lf%%\n",
							title, i->first.c_str(), result_probability * 100.0, i->second * 100.0);
			}

		}
		fprintf(stderr, "\e[0;32mStop Testing %s\e[0m\n", title);

		delete[] title;
		title = NULL;
		if(logfile != NULL){
			fclose(logfile);
			logfile = NULL;
		}
	}

	void test(const char* what, bool right){
		if(not right){
			fprintf(stderr, "\e[0;31mError Testing %s %s\e[0m\n", title, what);
			if(logfile)
				fprintf(logfile, "Error Testing %s %s\n", title, what);
		}
	}

	static bool fequal(double a, double b){
		if(fabs(a) < 1e-12 || fabs(b) < 1e-12)
			return (fabs(a) < 1e-12 && fabs(b) < 1e-12);
		return fabs(a/b-1.0) < 1e-12;
	}

	void test_fequal(const char* what, double a, double b){
		if(!fequal(a, b)){
			fprintf(stderr, "\e[0;31mError Testing %s %s, %.3lf != %.3lf\e[0m\n", title, what, a, b);
			if(logfile)
				fprintf(logfile, "Error Testing %s %s, %.3lf != %.3lf\n", title, what, a, b);
		}
	}

	void test_likely(const char* what_c_str, double prob, bool truth){
		string what = string(what_c_str);
		if(truth)
			truth_count[what]++;
		all_count[what]++;
		probability[what]=prob;
	}
}
